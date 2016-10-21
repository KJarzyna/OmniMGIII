#include "calculator.h"
#include "ui_calculator.h"

int calculator::GetCurrentActionID()
{
    int currentRow = ui->comboBox_select_action->currentIndex();
    int actionID = comboboxActionModel->item(currentRow,1)->text().toInt();
    return actionID;
}

int calculator::GetActionCostFromActionID(int ID)
{
    int cost = 99;
    for(int i=0;i<Actions.size();i++)
        if(Actions.at(i).ID == ID)
            cost = Actions.at(i).Cost;
    return cost;
}

QString calculator::GetActionTypeFromActionCost(int cost)
{
    if(cost >= 3 && cost < 125)
        return "AD";
    else if(cost < 3)
        return "AM";
    else
       return "AD+AM";
}

int calculator::GetActionCostAfterCalculations(int actionID)
{
    int cost = 100;
    if(actionID != 7)
        cost = GetActionCostFromActionID(actionID);
    else
        cost = GetSkillCostFromSkillID(selectedActionItemID);

    if(GetPlayersArmorCostReduction(selectedPlayerID) != 0)
        cost = cost + GetPlayersArmorCostReduction(selectedPlayerID);

    return cost;
}

int calculator::GetActionAccModifierForActionIDandPlayerID(int actionID, int playerID)
{
    if(isActionWeaponRelated(actionID))
        return GetPlayersArmorWpnAccModifier(playerID);
    else if(isActionSkillRelated(actionID))
        return GetPlayersArmorSkillAccModifier(playerID);
    else if(isActionAmmoRelated(actionID))
        return GetPlayersArmorSkillAccModifier(playerID);
    else
        return 0;

}

void calculator::setSelectedActionCostName(QString actionType)
{
    selectedActionCostName = actionType;
}

void calculator::setActionCostInStats(QString actionType)
{
    ui->label_action_cost_2->setText(actionType);
}

void calculator::OpenAdditionalActionDialogBoxForActionID(int actionID)
{
    int currentActionID = actionID;
    dialogbox_action *box = new dialogbox_action();
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->InitializeActionType(ui->comboBox_select_action->currentText());

    QStandardItemModel *model = GetItemModelBasedOnSelectedAction(currentActionID);
    box->InitializeActionItemModel(model);
    box->show();
    connect(box,SIGNAL(SelectedActionItem(int,QString)),this,SLOT(GetSelectedActionItemSlot(int,QString)));
    connect(box,SIGNAL(DialogBoxClosed(bool)),this,SLOT(ActionDialogBoxClosed(bool)));
}

void calculator::ActionDialogBoxClosed(bool db_closed)
{
    if(db_closed)
    {
        int actionID = GetCurrentActionID();
        int actionCost = GetActionCostAfterCalculations(actionID);
        QString actionType = GetActionTypeFromActionCost(actionCost);

        setSelectedActionCostName(actionType);
        setActionCostInStats(actionType);
        setSelectedActionName();
        setActionNameInStats(selectedActionName);

        if(isActionNeedTarget(actionID))
            ui->comboBox_select_target->setEnabled(true);
        else
            ui->comboBox_select_target->setEnabled(false);

        if(isActionNeedDifficultyCheck(actionID))
            ui->comboBox_select_difficultylevel->setEnabled(true);
        else
            ui->comboBox_select_difficultylevel->setEnabled(false);
    }
}

void calculator::setSelectedActionName()
{
    selectedActionName = ui->comboBox_select_action->currentText();
    int currentActionID = GetCurrentActionID();

    //check if action need to be more specific
    if(currentActionID >-1 && currentActionID <10 || currentActionID == 13 || currentActionID == 14 || currentActionID > 16 && currentActionID < 20)
    {
        if(selectedActionItemName != "Brak")
            selectedActionName = selectedActionName + ": " + selectedActionItemName;
        else
            selectedActionName = "-";
    }

}

void calculator::setActionNameInStats(QString actionName)
{
    ui->label_action_name_2->setText(actionName);
}

bool calculator::isActionHasSuccessCheck(int actionID)
{
    if(actionID > -1 && actionID < 5) // Get base success for weapons (base weapon + weapon acc + armor modifiers)
        return true;
    else if(actionID == 7 || actionID == 18) // Get base success for skills (base skill mastery + armor modifiers)
        return true;
    else if(actionID > 9 && actionID < 13) // Get base success for omniblades (base of player evasiveness + weapon acc)
        return true;
    else if(actionID == 19) // // Get base success for special ammo activation (base battle mastery + armor modifiers)
        return true;
    else
       return false;
}

bool calculator::isActionWeaponRelated(int actionID)
{
    if(actionID > -1 && actionID < 5)
        return true;
    else
       return false;
}

bool calculator::isActionSkillRelated(int actionID)
{
    if(actionID == 7 || actionID == 18) // Get base success for skills (base skill mastery + armor modifiers)
        return true;
    else
       return false;
}

bool calculator::isActionMeeleeRelated(int actionID)
{
    if(actionID > 9 && actionID < 13) // Get base success for omniblades (base of player evasiveness + weapon acc)
        return true;
    else
       return false;
}

bool calculator::isActionAmmoRelated(int actionID)
{
    if(actionID == 19) // Get base success for ammo (base skill mastery + armor modifiers)
        return true;
    else
       return false;
}

bool calculator::isActionNeedTarget(int actionID)
{
    if(isActionWeaponRelated(actionID))
        return true;
    else if(isActionMeeleeRelated(actionID))
        return true;
    else if(isActionSkillRelated(actionID))
    {
        if(GetSkillTargetFromSkillID(selectedActionItemID) == "target")
            return true;
        else
            return false;
    }
    else if((actionID == 8 || actionID == 9) && selectedActionItemID == 1)
        return true;
    else
       return false;
}

bool calculator::isActionNeedDifficultyCheck(int actionID)
{
    if(isActionWeaponRelated(actionID))
        return true;
    else if(isActionMeeleeRelated(actionID))
        return true;
    else if(isActionSkillRelated(actionID))
        return true;
    else if(isActionAmmoRelated(actionID))
        return true;
    else
       return false;
}

bool calculator::isActionDealDamage(int actionID)
{
    if(isActionWeaponRelated(actionID))
        return true;
    else if(isActionMeeleeRelated(actionID))
        return true;
    else if(isActionSkillRelated(actionID))
        return true;
    else if(isActionAmmoRelated(actionID))
        return false;
    else
       return false;
}

QStandardItemModel* calculator::GetItemModelBasedOnSelectedAction(int actionID)
{

    switch(actionID)
    {
    case 0:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("PC");
        return model;
        break;
    }
    case 1:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("PM");
        return model;
        break;
    }
    case 2:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("KS");
        return model;
        break;
    }
    case 3:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("KW");
        return model;
        break;
    }
    case 4:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("Strz");
        return model;
        break;
    }
    case 5:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 6:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerGenerators();
        return model;
        break;
    }
    case 7:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerSkills();
        return model;
        break;
    }
    case 8:
    {
        QStandardItemModel *model = GetItemModelForGelUsage();
        return model;
        break;
    }
    case 9:
    {
        QStandardItemModel *model = GetItemModelForGelUsage();
        return model;
        break;
    }
    case 13:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 14:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerWeapons();
        return model;
        break;
    }
    case 17:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerGenerators();
        return model;
        break;
    }
    case 18:
    {
        QStandardItemModel *model = GetItemModelForAllPlayerSkills();
        return model;
        break;
    }
    case 19:
    {
        QStandardItemModel *model = GetItemModelForSpecialAmmo();
        return model;
        break;
    }
    default:
    {
        QStandardItemModel *model = GetItemModelForWeaponType("IntentionallyWrongType"); //returns empty model
        return model;
        break;
    }

    }

}

QStandardItemModel* calculator::GetItemModelForWeaponType(QString weaponType)
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,2,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == selectedPlayerID && GetWeaponTypeFromWeaponID(PlayerWeapons.at(i).WeaponID) == weaponType)
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerWeapons.at(i).WeaponID));
            itemIDVector.append(PlayerWeapons.at(i).WeaponID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerWeapons()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == selectedPlayerID)
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerWeapons.at(i).WeaponID));
            itemIDVector.append(PlayerWeapons.at(i).WeaponID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerGenerators()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerGenerators.size();i++)
        if(PlayerGenerators.at(i).PlayerID == selectedPlayerID)
        {
            itemNameVector.append(GetGeneratorNameFromGeneratorID(PlayerGenerators.at(i).GeneratorID));
            itemIDVector.append(PlayerGenerators.at(i).GeneratorID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForAllPlayerSkills()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerSkills.size();i++)
        if(PlayerSkills.at(i).PlayerID == selectedPlayerID)
        {
            QString skillName = GetSkillNameFromSkillID(PlayerSkills.at(i).SkillID);
            skillName.append(" (");
            skillName.append(GetSkillLevelFromSkillID(PlayerSkills.at(i).SkillID));
            skillName.append(")");
            itemNameVector.append(skillName);
            itemIDVector.append(PlayerSkills.at(i).SkillID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}

QStandardItemModel* calculator::GetItemModelForGelUsage()
{
    QStandardItemModel *model = new QStandardItemModel(2,2,this);
    model->setItem(0,0, new QStandardItem("Na sobie"));
    model->setItem(0,1, new QStandardItem("0"));
    model->setItem(1,0, new QStandardItem("Na celu"));
    model->setItem(1,1, new QStandardItem("1"));

    return model;
}

QStandardItemModel* calculator::GetItemModelForSpecialAmmo()
{
    QVector<QString> itemNameVector;
    QVector<int> itemIDVector;
    QStandardItemModel *empty_model = new QStandardItemModel(1,1,this);
    empty_model->setItem(0,0, new QStandardItem("Brak")); //model returned if player don't have any items
    empty_model->setItem(0,1, new QStandardItem("-1")); //model returned if player don't have any items

    for(int i=0;i<PlayerSkills.size();i++)
        if(PlayerSkills.at(i).PlayerID == selectedPlayerID && GetSkillTypeFromSkillID(PlayerSkills.at(i).SkillID) == "Amunicja")
        {
            itemNameVector.append(GetWeaponNameFromWeaponID(PlayerSkills.at(i).SkillID));
            itemIDVector.append(PlayerSkills.at(i).SkillID);
        }
    if(!itemNameVector.isEmpty())
    {
        QStandardItemModel *model = new QStandardItemModel(itemNameVector.size(),2,this);
        for(int i=0;i<itemNameVector.size();i++)
        {
            model->setItem(i,0, new QStandardItem(itemNameVector.at(i)));
            model->setItem(i,1, new QStandardItem(QString::number(itemIDVector.at(i))));
        }
        return model;
    }
    else
        {
        return empty_model;
        }
}



