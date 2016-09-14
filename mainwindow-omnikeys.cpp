#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALL OMNIKEYS RELATED FUNCTIONS

void MainWindow::AddOmnikeyToPlayer(int omnikeyID, int playerID)
{
    C_PlayerOmnikeys item;
    item.PlayerID = playerID;
    item.OmnikeyID = omnikeyID;
    PlayerOmnikeys.append(item);
}

void MainWindow::RemoveOmnikeyFromPlayer(int playerID)
{
    for(int i=0;i<PlayerOmnikeys.size();i++)
    {
        if(PlayerOmnikeys.at(i).PlayerID == playerID)
            PlayerOmnikeys.remove(i);
    }
}

int MainWindow::GetOmnikeyIDFromOmnikeyName(QString Name)
{
    int ID = 9999;
    for(int i=0;i<Omnikeys.size();i++)
    {
        if(Omnikeys.at(i).Name == Name )
            ID = Omnikeys.at(i).ID;
    }
    return ID;
}

//ALL OMNIKEY SUBMOD RELATED FUNCTIONS

void MainWindow::AddOmnikeyModToPlayer(int omnikeyModID, int playerID)
{
    C_PlayerOmnikeyMods item;
    item.PlayerID = playerID;
    item.OmnikeyModID = omnikeyModID;
    PlayerOmnikeyMods.append(item);
}

void MainWindow::RemoveOmnikeyModFromPlayer(int playerID)
{
    for(int i=0;i<PlayerOmnikeyMods.size();i++)
    {
        if(PlayerOmnikeyMods.at(i).PlayerID == playerID)
            PlayerOmnikeyMods.remove(i);
    }
}

int MainWindow::GetOmnikeyModIDFromOmnikeyModName(QString Name)
{
    int ID = 9999;
    for(int i=0;i<OmnikeyMods.size();i++)
    {
        if(OmnikeyMods.at(i).Name == Name )
            ID = OmnikeyMods.at(i).ID;
    }
    return ID;
}


//ALL OMNIBLADE RELATED FUNCTIONS

void MainWindow::AddOmnibladeToPlayer(int omnibladeID, int playerID)
{
    C_PlayerOmniblades item;
    item.PlayerID = playerID;
    item.OmnibladeID = omnibladeID;
    PlayerOmniblades.append(item);
}

void MainWindow::RemoveOmnibladeFromPlayer(int playerID)
{
    for(int i=0;i<PlayerOmniblades.size();i++)
    {
        if(PlayerOmniblades.at(i).PlayerID == playerID)
            PlayerOmniblades.remove(i);
    }
}

int MainWindow::GetOmnibladeIDFromOmnibladeName(QString Name)
{
    int ID = 9999;
    for(int i=0;i<Omniblades.size();i++)
    {
        if(Omniblades.at(i).Name == Name )
            ID = Omniblades.at(i).ID;
    }
    return ID;
}


//ALL OMNIBLADE MOD RELATED FUNCTIONS
void MainWindow::AddOmnibladeModToPlayer(int omnibladeModID, int playerID)
{
    C_PlayerOmnibladeMods item;
    item.PlayerID = playerID;
    item.OmnibladeModID = omnibladeModID;
    PlayerOmnibladeMods.append(item);
}

void MainWindow::RemoveOmnibladeModFromPlayer(int playerID)
{
    for(int i=0;i<PlayerOmnibladeMods.size();i++)
    {
        if(PlayerOmnibladeMods.at(i).PlayerID == playerID)
            PlayerOmnibladeMods.remove(i);
    }
}

int MainWindow::GetOmnibladeModIDFromOmnibladeModName(QString Name)
{
    int ID = 9999;
    for(int i=0;i<OmnibladeMods.size();i++)
    {
        if(OmnibladeMods.at(i).Name == Name )
            ID = OmnibladeMods.at(i).ID;
    }
    return ID;
}
