#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>
#include <unordered_map>

std::unordered_map<int, quint64> lastPressedMap;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 新建Username和Password的输入框
    lineEditUsername = new LineEdit(this);
    lineEditPassword = new LineEdit(this);

    // 接收Username的按键按下事件
    connect(
        lineEditUsername, &LineEdit::onKeyPressEvent,
        this, &MainWindow::onKeyPressEvent
    );

    // 接收Password的按键按下事件
    connect(
        lineEditPassword, &LineEdit::onKeyPressEvent,
        this, &MainWindow::onKeyPressEvent
    );

    // 接收Username的按键弹起事件
    connect(
        lineEditUsername, &LineEdit::onKeyReleaseEvent,
        this, &MainWindow::onKeyReleaseEvent
    );

    // 接收Password的按键弹起事件
    connect(
        lineEditPassword, &LineEdit::onKeyReleaseEvent,
        this, &MainWindow::onKeyReleaseEvent
    );

    // 把两个输入框分别放在对应布局中
    ui->horizontalLayoutUsername->addWidget(lineEditUsername);
    ui->horizontalLayoutPassword->addWidget(lineEditPassword);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{

}

QString MainWindow::getCurrentTime()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}

void MainWindow::onKeyPressEvent(QKeyEvent* event)
{
    qDebug() << "按键" << event->key()
             << " 于内部时间" << event->timestamp()
             << " 实际时间" << getCurrentTime()
             << " 被按下";
    lastPressedMap[event->key()] = event->timestamp();
}

void MainWindow::onKeyReleaseEvent(QKeyEvent* event)
{
    quint64 lastPressed = lastPressedMap[event->key()];
    qDebug() << "按键" << event->key()
             << " 于内部时间" << event->timestamp()
             << " 实际时间" << getCurrentTime()
             << " 被松开。"
             << " 总共按了"
             << (event->timestamp() - lastPressed)
             << "毫秒";
}
