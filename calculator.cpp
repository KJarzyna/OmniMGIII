#include "calculator.h"
#include "ui_calculator.h"
#include "QDebug"

calculator::calculator(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    InitializeAccModTable();
    InitializeDmgModTable();

}

calculator::~calculator()
{
    delete ui;
}

void calculator::InitializeAccModTable()
{
    ui->tableWidget_AccMod->setColumnWidth(0,300);
    ui->tableWidget_AccMod->setColumnWidth(1,50);
    ui->tableWidget_AccMod->horizontalHeader()->setStretchLastSection(true);

}

void calculator::InitializeDmgModTable()
{
    ui->tableWidget_DmgMod->setColumnWidth(0,300);
    ui->tableWidget_DmgMod->setColumnWidth(1,50);
    ui->tableWidget_DmgMod->horizontalHeader()->setStretchLastSection(true);

}

void calculator::on_pushButton_AccMod_add_clicked()
{
    ui->tableWidget_AccMod->insertRow(ui->tableWidget_AccMod->rowCount());
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_AccMod->setItem(ui->tableWidget_AccMod->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-100);
    spinbox->setMaximum(100);
    ui->tableWidget_AccMod->setCellWidget(ui->tableWidget_AccMod->rowCount()-1,1,spinbox);
}

void calculator::on_pushButton_AccMod_remove_clicked()
{
    int selected_row = ui->tableWidget_AccMod->currentRow();
    ui->tableWidget_AccMod->removeRow(selected_row);
}

void calculator::on_pushButton_DmgMod_add_clicked()
{
    ui->tableWidget_DmgMod->insertRow(ui->tableWidget_DmgMod->rowCount());
    ui->tableWidget_DmgMod->setItem(ui->tableWidget_DmgMod->rowCount()-1,0,new QTableWidgetItem(""));
    ui->tableWidget_DmgMod->setItem(ui->tableWidget_DmgMod->rowCount()-1,1,new QTableWidgetItem(5));

    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setMinimum(-20000);
    spinbox->setMaximum(20000);
    ui->tableWidget_DmgMod->setCellWidget(ui->tableWidget_DmgMod->rowCount()-1,1,spinbox);
}

void calculator::on_pushButton_DmgMod_add_2_clicked()
{
    int selected_row = ui->tableWidget_DmgMod->currentRow();
    ui->tableWidget_DmgMod->removeRow(selected_row);
}
