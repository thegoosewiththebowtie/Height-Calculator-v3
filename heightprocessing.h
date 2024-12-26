#ifndef HEIGHTPROCESSING_H
#define HEIGHTPROCESSING_H

#include <QWidget>

namespace Ui {
class HeightProcessing;
}

class HeightProcessing : public QWidget
{
    Q_OBJECT

public:
    explicit HeightProcessing(QWidget *parent = nullptr, bool isFreedomUnits = false);
    void AwaitingInput();
    bool breakwt = false;
    ~HeightProcessing();

private slots:

    void on_NormalSlider_sliderMoved(int position);

    void on_FreedomSlider_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::HeightProcessing *ui;
};

#endif // HEIGHTPROCESSING_H
