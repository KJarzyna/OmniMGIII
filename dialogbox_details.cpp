#include "dialogbox_details.h"
#include "ui_dialogbox_details.h"

dialogbox_details::dialogbox_details(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_details)
{
    this->setFixedSize(451,631);
    this->setGeometry(10,10,451,631);
    this->setWindowFlags(Qt::CustomizeWindowHint /*| Qt::FramelessWindowHint*/);
    ui->setupUi(this);
}

dialogbox_details::~dialogbox_details()
{
    delete ui;
}

void dialogbox_details::on_pushButton_clicked()
{
    close();
}

void dialogbox_details::setDetailsText(QString text)
{
    ui->label->setText(text);
}


