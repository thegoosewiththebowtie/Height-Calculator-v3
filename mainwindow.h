#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStyle>
#include <QStyleFactory>
#include <QApplication>
#include <QPushButton>
#include <QTime>
#include <QMainWindow>
#include <QTimer>
#include <QActionGroup>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetWelcomeScreen();
    bool isFreedomUnits = false;
    void showEvent(QShowEvent* event);
    bool GetFreedomUnits();
private slots:
    void on_commandLinkButton_clicked();
    void CloseApp();
    void FreedomUnits();
    void NormalUnits();
    void OpenAbout();
    void on_MainWindow_windowTitleChanged(const QString &title);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
