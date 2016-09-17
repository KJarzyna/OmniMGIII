#include "dialogbox_activeeffect.h"
#include "ui_dialogbox_activeeffect.h"
#include "Headers/ActiveEffects/activeeffect.h"
#include "Headers/Player/playeractiveeffect.h"

DialogBox_ActiveEffect::DialogBox_ActiveEffect(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogBox_ActiveEffect)
{
    this->setFixedSize(373,233);
    this->setWindowFlags(Qt::CustomizeWindowHint /*| Qt::FramelessWindowHint*/);
    ui->setupUi(this);
}

DialogBox_ActiveEffect::~DialogBox_ActiveEffect()
{
    delete ui;
}

void DialogBox_ActiveEffect::on_pushButton_confirm_clicked()
{
    SelectedActiveEffects = ReturnSelectedEffectList();
    emit sendActiveEffectList(SelectedActiveEffects);
    close();
}

void DialogBox_ActiveEffect::AddEffectsToRightList(QVector<C_ActiveEffect> vector)
{

    for (int i=0;i<vector.size();i++)
        ui->listWidget_activeEffect_Right->addItem(vector.at(i).Name);

}

void DialogBox_ActiveEffect::AddEffectsToLeftList(QVector<C_ActiveEffect> vector, QVector<C_PlayerActiveEffect> player_vector, int playerID)
{

    for (int i=0;i<player_vector.size();i++)
    {
        if(player_vector.at(i).PlayerID == playerID)
        {
            for(int j=0;j<vector.size();j++)
                if(vector.at(j).ID == player_vector.at(i).EffectID)
                {
                     ui->listWidget_activeEffect_Left->addItem(vector.at(j).Name);
                     int row = 0;
                     for(int k=0;k<ui->listWidget_activeEffect_Right->count();k++)
                         if(ui->listWidget_activeEffect_Right->item(k)->text() == vector.at(j).Name)
                             row = k;
                     ui->listWidget_activeEffect_Right->takeItem(row);
                }
        }

    }


}

void DialogBox_ActiveEffect::AddEffectFromRightToLeft()
{
    if(!ui->listWidget_activeEffect_Right->selectedItems().isEmpty())
    {
        ui->listWidget_activeEffect_Left->addItem(ui->listWidget_activeEffect_Right->currentItem()->text());
        ui->listWidget_activeEffect_Right->takeItem(ui->listWidget_activeEffect_Right->currentRow());
    }

}

void DialogBox_ActiveEffect::AddEffectFromLeftToRight()
{
    if(!ui->listWidget_activeEffect_Left->selectedItems().isEmpty())
    {
        ui->listWidget_activeEffect_Right->addItem(ui->listWidget_activeEffect_Left->currentItem()->text());
        ui->listWidget_activeEffect_Left->takeItem(ui->listWidget_activeEffect_Left->currentRow());
    }

}

QStringList DialogBox_ActiveEffect::ReturnSelectedEffectList()
{
    QStringList list;
    for (int i=0;i<ui->listWidget_activeEffect_Left->count();i++)
    {
        list.append(ui->listWidget_activeEffect_Left->item(i)->text());
    }

    //if(list.isEmpty()) list.append("Brak aktywnych efektów.");

    return list;
}


void DialogBox_ActiveEffect::on_pushButton_activeEffect_FromRightToLeft_clicked()
{
    AddEffectFromRightToLeft();
}

void DialogBox_ActiveEffect::on_pushButton_activeEffect_FromLeftToRight_clicked()
{
    AddEffectFromLeftToRight();
}


