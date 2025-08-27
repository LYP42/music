#include "widget.h"
#include "./ui_widget.h"
#include<QMediaDevices>
#include<QAudioDevice>
#include<QAudioOutput>
#include<QMovie>
#include<QIcon>
//图片
#include<QPixmap>
#include<QPalette>
#include<QDebug>
//文件系统
#include<QDir>
#include<QFile>
#include <QFileInfo>
//对话框
#include<QMessageBox>
//时间函数
#include<time.h>
//动画
#include<QPropertyAnimation>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    m_mode(ORDER_MODE),
    m_isShowFlag(false),
     ui(new Ui::Widget)

{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("音乐播放器");

    m_player=new QMediaPlayer(this);
    //固定窗口大小
   // setFixedSize(860,640);
    setWindowIcon(QIcon(":/icon/m_music.png"));
    setBackGround(":/icon/beijin.jpg");
    //按钮初始化
    initButtons();
    m_player->setSource(QUrl("D:/student/QT/daima/testm/musicList/yi.mp3"));
    QAudioOutput * audioOutput=new QAudioOutput(this);
    m_player->setAudioOutput(audioOutput);
    //获取当前媒体的时长
    connect(m_player,&QMediaPlayer::durationChanged,this,[=](qint64 duration){
        ui->totalLabel->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg(duration/1000%60));
    ui->horizontalSlider->setRange(0,duration);
    });
    //获取当前播放时长
    connect(m_player,&QMediaPlayer::positionChanged,this, [=](qint64 pos){
        ui->curLabel->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0')).arg(pos/1000%60));
        ui->horizontalSlider->setValue(pos);
    });
   // 拖动滑块，让音乐播放进度改变
    connect(ui->horizontalSlider,&QSlider::sliderMoved,m_player,&QMediaPlayer::setPosition);
    audioOutput->setVolume(0.5);
    connect(ui->volume, &QSlider::valueChanged, this, [=](int value) {
        audioOutput->setVolume(value / 100.0);  // 滑块值→音量比例转换
    });


   // m_player->play();
   // 加载音乐文件夹
    m_musicDir="D:/student/QT/daima/testm/musicList/";
    loadAppointMusicDir(m_musicDir);
    //随机数种子
    srand(time(NULL));
}
//设置背景
void Widget::setBackGround(const QString&filename)
{
    //创建照片
    QPixmap pixmap(filename);
    //获取当前窗口的大小
    QSize windowSize=this->size();
    //将图片缩放到当前窗口大小
    QPixmap scalePixmap=pixmap.scaled(windowSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    //创建QPattle对象并设置背景图
    QPalette pattel=this->palette();
    pattel.setBrush(QPalette::Window,QBrush(scalePixmap));
    //将调色板应用到窗口上

    this->setPalette(pattel);

}
//设置按钮样式
void Widget::setToolButtonStyle(QPushButton *button,const QString&filename)
{

    //设置按钮大小
  // button->setFixedSize(50,30);
    //添加图片
    button->setIcon(QIcon(filename));
    //设置透明色同时去掉边框
  // button->setStyleSheet("background-color: transparent; border: none;");


}
//初始化按钮
void Widget::initButtons()
{
    setToolButtonStyle(ui->prevBtn,":/icon/prev.png");
    setToolButtonStyle(ui->nextBtn,":/icon/next.png");
    setToolButtonStyle(ui->playBtn,":/icon/play.png");
    setToolButtonStyle(ui->modeBtn,":/icon/order.png");
    setToolButtonStyle(ui->listBtn,":/icon/music.png");

    ui->musicList->setStyleSheet("QListWidget{"
                                 "border:none;"
                                 "border-radius:20px;"
                                 "background-color:rgba(255,255,255,0.5);}");
    //初始化隐藏列表
    ui->musicList->hide();

    connect(ui->playBtn,&QPushButton::clicked,this,&Widget::handlePlaySlot);
    connect(ui->modeBtn,&QPushButton::clicked,this,&Widget::handleModeSlot);
    connect(ui->nextBtn,&QPushButton::clicked,this,&Widget::handleNextSlot);
    connect(ui->prevBtn,&QPushButton::clicked,this,&Widget::handlePrevSlot);
     connect(ui->listBtn,&QPushButton::clicked,this,&Widget::handleListSlot);


}

//控制音量大小
void  Widget::m_volume(int value)
{

}



//显示动画
void  Widget::showAnimation(QWidget*window)
{
    QPropertyAnimation animation(window,"pos");
    //动画持续时间
    animation.setDuration(500);
    //起始坐标
    animation.setStartValue(QPoint(this->width(),0));
    //结束坐标
    animation.setEndValue(QPoint(this->width()-ui->musicList->width(),0));
    animation.start();
    QEventLoop loop;
    //等待动画结束
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}
//隐藏动画
void  Widget::hideAnimation(QWidget*window)
{

 }
//处理音乐列表
void  Widget::handleListSlot()
{
    if(m_isShowFlag==false)
    {
        ui->musicList->show();
        //动画方式出现
        showAnimation( ui->musicList);
        m_isShowFlag=true;
    }
    else
    {
        ui->musicList->hide();
        m_isShowFlag=false;
    }

}
//播放音乐
void Widget::startPlayMusic()
{
    QString musicName=ui->musicList->currentItem()->text();
    //音乐绝对路径
    QString musicAbsPath=m_musicDir+musicName+".mp3";
    //加载音乐
    m_player->setSource(QUrl( musicAbsPath));
    //处理播放音乐
    handlePlaySlot();

}
//处理上一首
void Widget::handlePrevSlot()
{ int currentRow=ui->musicList->currentRow();
    int prevRow=0;
    if(m_mode==ORDER_MODE)
    {
        prevRow= currentRow-1;
        if(prevRow<0)
        {
            prevRow=ui->musicList->count()-1;
        }
    }
    else if(m_mode==RANDOM_MODE)
    {
        int cnt=0;
        do
        {
            cnt++;
            prevRow=rand()%ui->musicList->count();
        }while(currentRow==prevRow&&cnt<=3);

    }
    else if(m_mode==CIRCLE_MODE)
    {
        prevRow=currentRow;
    }
    ui->musicList->setCurrentRow(prevRow);
//播放音乐
    startPlayMusic();
}

//处理下一首
void Widget::handleNextSlot()
{//播放的行当前行
    int currentRow=ui->musicList->currentRow();
    int nextRow=0;
    if(m_mode==ORDER_MODE)
    {
        nextRow=(currentRow+1)%ui->musicList->count();
    }
    else if(m_mode==RANDOM_MODE)
    {int cnt=0;
        do
        {
            cnt++;
            nextRow=rand()%ui->musicList->count();
        }while(currentRow==nextRow&&cnt<=3);

    }
    else if(m_mode==CIRCLE_MODE)
    {
        nextRow=currentRow;
    }
    ui->musicList->setCurrentRow( nextRow);
    //播放音乐
    startPlayMusic();
}
//处理模式
void Widget::handleModeSlot()
{
    if(m_mode==ORDER_MODE)//顺序播放
    {
        m_mode=RANDOM_MODE;//随机播放
        ui->modeBtn->setIcon(QIcon(":/icon/random.png"));
    }
    else if(m_mode==RANDOM_MODE)
    {
        m_mode=CIRCLE_MODE;//单曲循环
         ui->modeBtn->setIcon(QIcon(":/icon/single.png"));
    }
    else if(m_mode==CIRCLE_MODE)
    {
        m_mode=ORDER_MODE;
         ui->modeBtn->setIcon(QIcon(":/icon/order.png"));
    }
}

//处理播放暂停
void Widget::handlePlaySlot()
{
    if(m_player->playbackState()==QMediaPlayer::PlayingState)
    {
        m_player->pause();
        ui->playBtn->setIcon(QIcon(":/icon/play.png"));


    }
    else
    {
        m_player->play();
         ui->playBtn->setIcon(QIcon(":/icon/stop.png"));

    }
}
//加载指定文件夹
void Widget::loadAppointMusicDir(const QString&filepath)
{
    QDir dir(filepath);
    if(dir.exists()==false)
    {
        QMessageBox::warning(this,"文件夹","文件夹打开失败");
        return;
    }
    QFileInfoList fileList=dir.entryInfoList(QDir::Files);
    for(const auto& element:fileList)
    {
        //判断后缀是否为MP3文件
        if(element.suffix()=="mp3")
        {
            ui->musicList->addItem(element.baseName());
        }
    }
    //默认第一行
    ui->musicList->setCurrentRow(0);
}

 Widget::~Widget()
 {
     delete ui;
 }
