#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALL ACTIVE EFFECTS RELATED FUNCTIONS

void MainWindow::addActiveEffectsToWidgetList(QStringList list)
{
    int playerID = GetActivePlayerID();
    ui->listWidget_player_conditions->clear();
    for(int i=0;i<list.size();i++)
        ui->listWidget_player_conditions->addItem(list.at(i));

    RemoveEffectsFromPlayer(playerID);
    for(int i=0;i<list.size();i++)
    {
        AddEffectToPlayer(GetEffectIDFromEffectName(list.at(i)),playerID);
    }

}

int MainWindow::GetEffectIDFromEffectName(QString name)
{
    int ID = 9999;
    for(int i=0;i<ActiveEffect.size();i++)
    {
        if(ActiveEffect.at(i).Name == name)
            ID = ActiveEffect.at(i).ID;
    }
    return ID;
}

QString MainWindow::GetEffectNameFromEffectID(int ID)
{
    QString name = "NoName";
    for(int i=0;i<ActiveEffect.size();i++)
    {
        if(ActiveEffect.at(i).ID == ID)
            name = ActiveEffect.at(i).Name;
    }
    return name;
}

void MainWindow::AddEffectToPlayer(int effectID, int playerID)
{
    C_PlayerActiveEffect effect;
    effect.EffectID = effectID;
    effect.PlayerID = playerID;
    PlayerActiveEffects.append(effect);
}

void MainWindow::RemoveEffectsFromPlayer(int playerID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
    {
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
        {
            PlayerActiveEffects.remove(i);
            i--;
        }
    }
}
