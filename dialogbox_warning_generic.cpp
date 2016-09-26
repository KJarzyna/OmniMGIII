#include "dialogbox_warning_generic.h"
#include "ui_dialogbox_warning_generic.h"

dialogbox_warning_generic::dialogbox_warning_generic(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_warning_generic)
{
    this->setFixedSize(400,111);
    ui->setupUi(this);
}

dialogbox_warning_generic::~dialogbox_warning_generic()
{
    delete ui;
}

void dialogbox_warning_generic::setWarningLabel(QString text)
{
    ui->label->setText(text);
}

void dialogbox_warning_generic::on_pushButton_clicked()
{
    close();
}
