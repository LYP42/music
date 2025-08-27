#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMediaPlayer>

#include<QString>
#include<QPushButton>

#include <QMediaPlayer>
#include<QSoundEffect>
#include <QUrl>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
enum PLAYMODE
{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE
};
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    //处理槽函数播放暂停
    void handlePlaySlot();
    //播放模式
    void handleModeSlot();
    //处理下一首
    void handleNextSlot();
    //处理上一首
    void handlePrevSlot();
    //处理音乐列表
    void handleListSlot();


private:
    Ui::Widget *ui;
    //设置按钮样式
    void setToolButtonStyle(QPushButton *button,const QString&filename);
    //初始化按钮
    void initButtons();
    //设置背景
    void setBackGround(const QString& filename);
    //音乐播放器
    QMediaPlayer*m_player;
    //加载指定文件夹
    void loadAppointMusicDir(const QString&filepath);
    //当前播放模式
    PLAYMODE m_mode;
    //播放音乐
    void startPlayMusic();
    //音乐绝对路径文件夹
    QString m_musicDir;
    //列表存在的状态
    bool m_isShowFlag;
    //显示动画
    void showAnimation(QWidget*window);
    //隐藏动画
    void hideAnimation(QWidget*window);
    //控制音量大小
    void m_volume(int value);



};
#endif // WIDGET_H
