#include "dialogbox_action.h"
#include "ui_dialogbox_action.h"
#include "dialogbox_details.h"
#include <QDebug>

dialogbox_action::dialogbox_action(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dialogbox_action)
{
    this->setFixedSize(412,107);
    this->setWindowFlags(Qt::CustomizeWindowHint /*| Qt::FramelessWindowHint*/);
    ui->setupUi(this);

}

dialogbox_action::~dialogbox_action()
{
    delete ui;
}

void dialogbox_action::InitializeActionType(QString actionName)
{
    ui->label->setText(actionName);
}

void dialogbox_action::InitializeComboboxList()
{

}

void dialogbox_action::InitializeActionItemModel(QStandardItemModel *model)
{
    ActionItem = model;
    ui->comboBox->setModel(model);
}

void dialogbox_action::on_pushButton_clicked()
{
    int currentRow = ui->comboBox->currentIndex();
    int itemID = ActionItem->item(currentRow,1)->text().toInt();
    QString itemName = ActionItem->item(currentRow,0)->text();
    emit SelectedActionItem(itemID,itemName);
    emit DialogBoxClosed(true);
    close();
}

