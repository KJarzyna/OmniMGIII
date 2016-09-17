#include "dialogbox_save_module.h"
#include "ui_dialogbox_save_module.h"

dialogbox_save_module::dialogbox_save_module(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_save_module)
{
    this->setFixedSize(400,206);
    ui->setupUi(this);
}

dialogbox_save_module::~dialogbox_save_module()
{
    delete ui;
}

void dialogbox_save_module::on_pushButton_yes_clicked()
{
    emit SaveSignal(true);
    close();
}



void dialogbox_save_module::on_pushButton_no_clicked()
{
    emit SaveSignal(false);
    close();
}
