/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevBtn;
    QPushButton *playBtn;
    QPushButton *nextBtn;
    QPushButton *modeBtn;
    QPushButton *listBtn;
    QListWidget *musicList;
    QSlider *horizontalSlider;
    QSlider *volume;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *totalLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(672, 450);
        Widget->setMaximumSize(QSize(800, 800));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 400, 168, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 4, 0, 4);
        prevBtn = new QPushButton(layoutWidget);
        prevBtn->setObjectName("prevBtn");
        prevBtn->setMaximumSize(QSize(300, 300));
        prevBtn->setAutoDefault(false);

        horizontalLayout->addWidget(prevBtn);

        playBtn = new QPushButton(layoutWidget);
        playBtn->setObjectName("playBtn");
        playBtn->setMaximumSize(QSize(300, 300));

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QPushButton(layoutWidget);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setMaximumSize(QSize(300, 300));

        horizontalLayout->addWidget(nextBtn);

        modeBtn = new QPushButton(layoutWidget);
        modeBtn->setObjectName("modeBtn");
        modeBtn->setMaximumSize(QSize(300, 300));

        horizontalLayout->addWidget(modeBtn);

        listBtn = new QPushButton(layoutWidget);
        listBtn->setObjectName("listBtn");
        listBtn->setMaximumSize(QSize(300, 300));

        horizontalLayout->addWidget(listBtn);

        musicList = new QListWidget(Widget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(475, 0, 201, 311));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(40, 340, 321, 16));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        volume = new QSlider(Widget);
        volume->setObjectName("volume");
        volume->setGeometry(QRect(410, 270, 16, 160));
        volume->setOrientation(Qt::Orientation::Vertical);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 320, 321, 22));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        curLabel = new QLabel(widget);
        curLabel->setObjectName("curLabel");

        horizontalLayout_2->addWidget(curLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        totalLabel = new QLabel(widget);
        totalLabel->setObjectName("totalLabel");

        horizontalLayout_2->addWidget(totalLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        prevBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        modeBtn->setText(QString());
        listBtn->setText(QString());
        curLabel->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
        totalLabel->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
