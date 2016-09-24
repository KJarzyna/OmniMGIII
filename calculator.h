#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>
#include <QtCore>
#include <QtGui>
#include <QSpinBox>
#include "mainwindow.h"
#include <QString>
#include "Headers/Actions/actions.h"
#include <dialogbox_difficultyreason.h>
#include <dialogbox_action.h>

namespace Ui {
class calculator;
}

class calculator : public QFrame
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

    QVector<C_Player> Players;
    QVector<C_Skill> Skills;
    QVector<C_PlayerSkill> PlayerSkills;
    QVector<C_Weapon> Weapons;
    QVector<C_PlayerWeapon> PlayerWeapons;
    QVector<C_WpnModList> WpnModList;
    QVector<C_Armor> Armors;
    QVector<C_PlayerArmor> PlayerArmors;
    QVector<C_ArmModList> ArmModList;
    QVector<C_PlayerArmorMods> PlayerArmorMods;
    QVector<C_Generators> Generators;
    QVector<C_PlayerGenerators> PlayerGenerators;
    QVector<C_Omnikeys> Omnikeys;
    QVector<C_PlayerOmnikeys> PlayerOmnikeys;
    QVector<C_OmnikeyMods> OmnikeyMods;
    QVector<C_PlayerOmnikeyMods> PlayerOmnikeyMods;
    QVector<C_Omniblades> Omniblades;
    QVector<C_PlayerOmniblades> PlayerOmniblades;
    QVector<C_OmnibladeMods> OmnibladeMods;
    QVector<C_PlayerOmnibladeMods> PlayerOmnibladeMods;
    QVector<C_PlayerActiveEffect> PlayerActiveEffects;
    QVector<C_ActiveEffect> ActiveEffect;
    QVector<C_Actions> Actions;

    QStandardItemModel *tableModel;
    QStandardItemModel *comboboxPlayersModel;
    QStandardItemModel *comboboxTargetsModel;
    QStandardItemModel *comboboxActionModel;

    int selectedPlayerID;
    QString selectedPlayerName;

    QString selectedActionName;
    int selectedActionItemID;
    QString selectedActionItemName;
    QString selectedActionCostName;

    int selectedTargetID;
    QString selectedTargetName;

    QString difficulty_level_name;
    QString difficulty_reason;

    int successTreshold;


private slots:
    void GetDifficultyReasonSlot(QString reason);
    void GetSelectedActionItemSlot(int id, QString name);
    void ActionDialogBoxClosed(bool db_closed);

    void on_pushButton_AccMod_add_clicked();
    void on_pushButton_AccMod_remove_clicked();
    void on_pushButton_DmgMod_add_clicked();
    void on_pushButton_DmgMod_add_2_clicked();
    void on_comboBox_select_player_activated(int index);
    void on_comboBox_select_difficultylevel_activated(const QString &arg1);
    void on_comboBox_select_action_activated(int index);
    void on_pushButton_calculate_clicked();
    void on_comboBox_select_target_activated(int index);

private:
    Ui::calculator *ui;

    void InitializeDmgModTable();
    void InitializeAccModTable();
    void InitializePlayersComboBox();
    void InitializeActionsComboBox();
    void InitializeTargetsComboBox();
    void InitializePlayerStats();

    //Target related
    void RemovePlayerFromTargetModel(int playerID);
    void AddPlayerToTargetModel(int playerID);

    //Player related
    QString GetPlayerNameFromPlayerID(int playerID);
    void setPlayerStats(int playerID);
    void setPlayerActiveEffects(int playerID);
    int GetPlayersArmorCostReduction(int playerID);
    int GetPlayersArmorWpnAccModifier(int playerID);
    int GetPlayersArmorSkillAccModifier(int playerID);
    int GetPlayersArmorWpnDiffLevelModifier(int playerID);
    int GetPlayersArmorSkillDiffLevelModifier(int playerID);
    int GetPlayersArmorMeeleeDiffLevelModifier(int playerID);
    int GetPlayerSkillMastery(int playerID, QString skillType);
    QString GetPlayerSpecializationSkill(int playerID);
    int GetPlayerEvasiveness(int playerID);


    //Actions related
    QStandardItemModel* GetItemModelBasedOnSelectedAction(int actionID);
    QStandardItemModel* GetItemModelForWeaponType(QString weaponType);
    QStandardItemModel* GetItemModelForAllPlayerWeapons();
    QStandardItemModel* GetItemModelForAllPlayerGenerators();
    QStandardItemModel* GetItemModelForAllPlayerSkills();
    QStandardItemModel* GetItemModelForGelUsage();
    QStandardItemModel* GetItemModelForSpecialAmmo();

    void OpenAdditionalActionDialogBoxForActionID(int actionID);
    void setSelectedActionCostName(QString actionType);
    void setActionCostInStats(QString actionType);
    void setSelectedActionName();
    void setActionNameInStats(QString actionName);

    int GetCurrentActionID();
    int GetActionCostFromActionID(int ID);
    int GetActionCostAfterCalculations(int actionID);
    QString GetActionTypeFromActionCost(int cost);

    //Difficulty related
    void setDifficultyInStats(QString level, QString reason);
    int GetDifficultyValueFromName(QString diff_name);
    int GetDifficultyModifierFromValue(int val);
    int GetFinalDifficultyValueForActionID(int actionID);

    //

    bool ReadDataFromFiles();

    //Weapon related
    QString GetWeaponTypeFromWeaponID(int ID);
    QString GetWeaponNameFromWeaponID(int ID);
    int GetWeaponAccFromWeaponID(int id);
    int GetOmnibladeAccFromOmnibladeID(int id);

    //GET
    QString GetEffectNameFromEffectID(int ID);
    QString GetGeneratorNameFromGeneratorID(int ID);

    //Skill related
    QString GetSkillNameFromSkillID(int ID);
    QString GetSkillTypeFromSkillID(int ID);
    QString GetSkillLevelFromSkillID(int ID);
    int GetSkillCostFromSkillID(int ID);


    //Calculations related
    void setSuccessTreshold(int treshold);
    void CalculateSuccessTresholdForActionID(int actionID);
    int GetSumOfAccModifiers();
    int GetSumOfDmgModifiers();
    int GetBaseSuccessTreshold(int actionID);
};

#endif // CALCULATOR_H
