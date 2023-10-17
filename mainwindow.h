#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>

#include "lineedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();

    /**
     * @brief 当键盘某键被按下时调用
     * @param event
     */
    void onKeyPressEvent(QKeyEvent* event);

    /**
     * @brief 当键盘某键弹起时调用
     * @param event
     */
    void onKeyReleaseEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    LineEdit* lineEditUsername;
    LineEdit* lineEditPassword;

    /**
     * @brief 获取当前时间
     * @return
     */
    QString getCurrentTime();

};
#endif // MAINWINDOW_H
