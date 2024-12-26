#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("WindowsVista"));
    MainWindow mainwindow;
    mainwindow.show();
    mainwindow.SetWelcomeScreen();
    return a.exec();
}
