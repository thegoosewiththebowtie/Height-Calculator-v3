#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "heightprocessing.h"
#include "about.h"
void delay(int i)
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("Height Calculator v.3");
    ui -> menuFile ->addAction("Quit", this, SLOT(CloseApp()));
    QMenu* menuUnits = new QMenu;
    menuUnits->setTitle("Units");
    QActionGroup* uts = new QActionGroup(this);
    QAction* nu = new QAction;
    nu -> setText("Normal Units");
    nu -> setCheckable(true);
    nu -> setChecked(true);
    connect(nu, SIGNAL(triggered(bool)), this, SLOT(NormalUnits()));
    uts->addAction(nu);
    menuUnits->addAction(nu);
    QAction* fu = new QAction;
    fu -> setText("Freedom Units🦅🦅🦅");
    fu -> setCheckable(true);
    connect(fu, SIGNAL(triggered(bool)), this, SLOT(FreedomUnits()));
    uts->addAction(fu);
    menuUnits->addAction(fu);
    ui -> menuView ->addMenu(menuUnits);
    ui -> menuAbout ->addAction("About", this, SLOT(OpenAbout()));
}
void MainWindow::CloseApp(){
    this->close();
}
void MainWindow::FreedomUnits(){
    isFreedomUnits = true;
}
void MainWindow::NormalUnits(){
    isFreedomUnits = false;
}
void MainWindow::OpenAbout(){
    about* abt = new about;
    abt -> show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetWelcomeScreen(){
    QString hcv3 = "Height Calculator v.3";
    QString totw = "by Triangle on The Wall Organization";
    QString bfmp = "Better. Faster. More precize.";
    QString lt = "and with longer terms and conditions.";
    QString qt = "its on qt! :3";
    QString eula = "Please, accept our terms and conditions so we could get started!";
    ui->MainText->setText("");
    ui->totw->setText("");
    ui->bfm->setText("");
    ui->tac->setText("");
    ui->aioqt->setText("");
    ui->patac->setVisible(false);
    for (QChar c : hcv3){
        ui->MainText -> setText(ui->MainText ->text() + c);
        delay(200);
    }
    delay(1000);
    ui->totw->setText(totw);
    delay(1000);
    for (QChar c : bfmp){
        ui->bfm -> setText(ui->bfm ->text() + c);
        if(c == '.'){
         delay(1000);
        }
    }
    ui->tac->setText(lt);
    delay(1000);
    ui->aioqt->setText(qt);
    ui->patac->setVisible(true);
    ui->commandLinkButton ->setEnabled(true);
}
void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
}
void MainWindow::on_commandLinkButton_clicked()
{
    if (ui->tosacc->isChecked() == false){
        for (int i = 0; i < 15; ++i) {
            ui->patac->setVisible(false);
            delay(100);
            ui->patac->setVisible(true);
            delay(100);
        }
    } else {
        HeightProcessing* ghi = new HeightProcessing(nullptr, isFreedomUnits);
        ghi -> show();
        ghi ->AwaitingInput();
    }
}


void MainWindow::on_MainWindow_windowTitleChanged(const QString &title)
{

}

