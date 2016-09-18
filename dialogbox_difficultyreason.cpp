#include "dialogbox_difficultyreason.h"
#include "ui_dialogbox_difficultyreason.h"

dialogbox_difficultyreason::dialogbox_difficultyreason(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_difficultyreason)
{
    this->setFixedSize(315,118);
    this->setWindowFlags(Qt::CustomizeWindowHint /*| Qt::FramelessWindowHint*/);
    ui->setupUi(this);
}

dialogbox_difficultyreason::~dialogbox_difficultyreason()
{
    delete ui;
}

void dialogbox_difficultyreason::on_pushButton_clicked()
{
    QString reason;
    reason = ui->lineEdit->text();
    emit reasonSignal(reason);
    close();
}
