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
