#include "dialogbox_postcalculation.h"
#include "ui_dialogbox_postcalculation.h"

dialogbox_postcalculation::dialogbox_postcalculation(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_postcalculation)
{

    this->setFixedSize(510,126);
    this->setWindowFlags(Qt::CustomizeWindowHint /*| Qt::FramelessWindowHint*/);
    ui->setupUi(this);


}

dialogbox_postcalculation::~dialogbox_postcalculation()
{
    delete ui;
}

void dialogbox_postcalculation::InitializeDices(int num)
{
    //Hide or not 3 dices
    if(num != 4)
    {
        ui->spinBox_dice2->hide();
        ui->spinBox_dice3->hide();
        ui->spinBox_dice4->hide();
        ui->label->setText("Wynik na kości:");
    }
    else
        ui->label->setText("Wyniki na kościach:");
}

void dialogbox_postcalculation::on_pushButton_clicked()
{
    QVector<int> dice;

    dice.append(ui->spinBox_dice1->value());

    if(ui->spinBox_dice2->isHidden() == false)
    {
        dice.append(ui->spinBox_dice2->value());
        dice.append(ui->spinBox_dice3->value());
        dice.append(ui->spinBox_dice4->value());
    }

    emit DiceResults(dice);
    emit DialogBoxClosed();
    close();
}
