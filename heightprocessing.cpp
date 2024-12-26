#include "heightprocessing.h"
#include "ui_heightprocessing.h"
#include "heightprocessing.h"
#include <QTime>
#include <QTimer>
#include <string>
#include <QTextFormat>
bool isfd;
void delay2(int i)
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
HeightProcessing::HeightProcessing(QWidget *parent, bool isFreedomUnits)
    : QWidget(parent)
    , ui(new Ui::HeightProcessing)
{
    ui->setupUi(this);
    isfd = isFreedomUnits;
    if(isFreedomUnits){
        ui->FreedomSlider->setEnabled(true);
        ui->FreedomSlider->setMaximum(8);
        ui->NormalSlider->setEnabled(true);
        ui->NormalSlider->setMaximum(11);
    }
}
void HeightProcessing::AwaitingInput(){
    do{
        ui->ProcessInfo->setText("Awaiting input");
        delay2(1000);
        for (int var = 0; var < 3; ++var) {
            ui->ProcessInfo->setText(ui->ProcessInfo->text() + ".");
            delay2(1000);
        }
    }while(!breakwt);
}

HeightProcessing::~HeightProcessing()
{
    delete ui;
}


void HeightProcessing::on_NormalSlider_sliderMoved(int position)
{
    double resnum;
    if(isfd){
    resnum = std::stod(std::to_string(ui->FreedomSlider->value())+"."+std::to_string(position));
    } else {
        resnum = position+100;
    }
    ui->infnum->display(resnum);
}


void HeightProcessing::on_FreedomSlider_sliderMoved(int position)
{
    double resnum;
    resnum = std::stod(std::to_string(position)+"."+std::to_string((ui->NormalSlider->value())));
    ui->infnum->display(resnum);

}


void HeightProcessing::on_pushButton_2_clicked()
{
    this->close();
}


void HeightProcessing::on_pushButton_clicked()
{
    ui->NormalSlider->setEnabled(false);
    ui->FreedomSlider->setEnabled(false);
    int numn = ui->NormalSlider->value();
    int freedomnum = ui->FreedomSlider->value();
    ui ->pushButton->setEnabled(false);
    breakwt = true;
    ui ->progressBar->setMaximum(100);
    ui ->ProcessInfo->setText("");
    ui->ProcessInfo->setAlignment(Qt::AlignLeft);
    int sd;
    std::string st = "[=======================]";
    for (int i = 0; i < 100; ++i) {
        if(rand()%6 ==1){
            delay2(rand()%5000);
        }else{
            delay2(rand()%500);
        }
        ui->progressBar->setValue(i);
        switch (i) {
        case 0:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Sending data...\n");
            break;
        case 1:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"[");
            break;
        case 25:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"]\n");
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Decrypting data...\n");
            break;
        case 34:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Analyzing data...\n");
            break;
        case 51:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Getting ready for calculations...\n");
            break;
        case 64:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Calculating...\n");
            break;
        case 71:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Scolding our scientists for being too slow...\n");
            break;
        case 75:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Calculating your height...\n");
            break;
        case 84:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Rechecking your height...\n");
            break;
        case 89:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Evaluating your height...\n");
            break;
        case 99:
            ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"Recieving data...\n");
            for(char s : st){
                ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+s);
                delay2(rand()%1000);
            }
            break;
        default:
            if(i>1&&i<25){
                ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"=");
            }
            break;
        }
    }
    delay2(3000);
    ui ->progressBar->setValue(100);
    ui ->ProcessInfo->setText("");
    QFont qf;
    qf.setPointSize(42);
    ui->ProcessInfo->setFont(qf);
    ui->ProcessInfo->setAlignment(Qt::AlignCenter);
    ui->ProcessInfo->setAlignment(Qt::AlignTop);
    ui->ProcessInfo->setWordWrap(true);
    ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"<p>Your height is...</p>");
    delay2(3000);
    ui->ProcessInfo->setAlignment(Qt::AlignLeft);
    ui->ProcessInfo->setAlignment(Qt::AlignTop);
    for (int var = 0; var < 25; ++var) {
        ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"<span style=\" font-size:24pt;\">ARE YOU READY‽‽‽</span>");
        delay2(5);
    }
    delay2(3000);
    ui ->ProcessInfo->setText("");
    ui->ProcessInfo->setAlignment(Qt::AlignLeft);
    ui->ProcessInfo->setAlignment(Qt::AlignTop);
    ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"<p><span style=\" font-size:24pt;\">Its somewhere in between of...</span></p>");
    delay2(3000);
    QString out ="";
    if(isfd){
        out = ((ui ->ProcessInfo->text())+QString::number(freedomnum-rand()%3)+"'"+QString::number(numn-rand()%3)+" and "
                           +QString::number(freedomnum+rand()%3)+"'"+QString::number(numn<=8?(numn-rand()%3):11));

    } else {
        out = ((ui ->ProcessInfo->text())+QString::number(numn-rand()%100)+" and "
                                 +QString::number(numn<=8?(numn+rand()%100):11));
    }
    ui ->ProcessInfo->setText("<p>"+out+"</p>");
    delay2(100);
    ui->ProcessInfo->setFont(qf);
    QString f = ui ->ProcessInfo->text()+ "<p></p><p></p><p></p><p align=\"left\"><span style=\" font-size:24pt;\">Are you satisfied with our job?</span></p>";
    ui ->ProcessInfo->setText(f);
    ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"<p align=\"left\"><span style=\" font-size:24pt;\">Your answer was*: ABSOLUTELY! I LOVE TOTW ORG! GLORY TO THE THREE CORNERS!</span></p>");
    delay2(1000);
    ui->ProcessInfo->setFont(qf);
    ui ->ProcessInfo->setText(ui ->ProcessInfo->text()+"<p></p><p></p><p></p><p align=\"left\"><span style=\" font-size:12pt;\">*-your answer was predetermined during your acceptance of ToTW TAC</span></p>");
    ui->NormalSlider->setEnabled(true);
    ui->FreedomSlider->setEnabled(true);
        ui ->pushButton->setEnabled(true);
}

