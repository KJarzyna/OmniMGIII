#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>
#include <QtCore>
#include <QtGui>
#include <QSpinBox>
#include "mainwindow.h"
#include <QString>
#include "Headers/Actions/actions.h"
#include "Headers/ItemModificator/itemmodificator.h"

#include <dialogbox_difficultyreason.h>
#include <dialogbox_action.h>
#include <dialogbox_warning_generic.h>
#include <dialogbox_postcalculation.h>

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

    QVector<C_ItemModificator> ItemAndDifficulty;
    QVector<C_ItemModificator> AdditionalItemAndDifficulty;
    QVector<C_ItemModificator> ItemAndAccuracy;
    QVector<C_ItemModificator> ItemAndCritical;
    QVector<C_ItemModificator> ItemAndActionCost;
    QVector<C_ItemModificator> ItemAndDamage;

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
    int criticalTreshold;

    //Damage related
    QVector<int> dice_results;

private slots:
    void GetDifficultyReasonSlot(QString reason);
    void GetSelectedActionItemSlot(int id, QString name);
    void ActionDialogBoxClosed(bool db_closed);
    void GetDiceResults(QVector<int> dices);
    void DiceDialogBoxClosed();

    void on_pushButton_AccMod_add_clicked();
    void on_pushButton_AccMod_remove_clicked();
    void on_pushButton_DmgMod_add_clicked();
    void on_pushButton_DmgMod_add_2_clicked();
    void on_comboBox_select_player_activated(int index);
    void on_comboBox_select_difficultylevel_activated(const QString &arg1);
    void on_comboBox_select_action_activated(int index);
    void on_pushButton_calculate_clicked();
    void on_comboBox_select_target_activated(int index);

    void on_pushButton_continue_calculations_clicked();

    void on_pushButton_approve_clicked();

    void on_pushButton_disapprove_clicked();

private:
    Ui::calculator *ui;

    void InitializeDmgModTable();
    void InitializeAccModTable();
    void InitializePlayersComboBox();
    void InitializeActionsComboBox();
    void InitializeTargetsComboBox();
    void InitializePlayerStats();

    void setEnableAfterFirstCalculations(bool status);
    void setEnableAfterSecondCalculations(bool status);
    void setEnableAllInput(bool status);

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
    int GetPlayersOmnibladeID(int playerID);
    int GetPlayersArmorCriticalChanceModifier(int playerID);
    bool isPlayerHasShield(int playerID);


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
    int GetActionAccModifierForActionIDandPlayerID(int actionID, int playerID);

    bool isActionHasSuccessCheck(int actionID);
    bool isActionWeaponRelated(int actionID);
    bool isActionSkillRelated(int actionID);
    bool isActionAmmoRelated(int actionID);
    bool isActionMeeleeRelated(int actionID);
    bool isActionNeedTarget(int actionID);
    bool isActionNeedDifficultyCheck(int actionID);


    //Difficulty related
    void setDifficultyInStats(QString level, QString reason);
    int GetDifficultyValueFromName(QString diff_name);
    int GetDifficultyModifierFromValue(int val);
    int GetFinalDifficultyValueForActionID(int actionID);
    QString GetDifficultyNameFromValue(int val);

    //

    bool ReadDataFromFiles();

    //Weapon related
    QString GetWeaponTypeFromWeaponID(int ID);
    QString GetWeaponNameFromWeaponID(int ID);
    int GetWeaponAccFromWeaponID(int id);
    int GetOmnibladeAccFromOmnibladeID(int id);
    int GetAmmoLeftInPlayersWeapon(int playerID, int weaponID);
    int GetWeaponDamageToArmorFromWeaponID(int ID);
    int GetWeaponDamageToShieldFromWeaponID(int ID);
    int GetWeaponBaseDamageFromWeaponID(int ID);
    int GetOmnibladeDamageFromOmnibladeID(int ID);

    //GET
    QString GetEffectNameFromEffectID(int ID);
    QString GetGeneratorNameFromGeneratorID(int ID);

    //Skill related
    QString GetSkillNameFromSkillID(int ID);
    QString GetSkillTypeFromSkillID(int ID);
    QString GetSkillLevelFromSkillID(int ID);
    QString GetSkillTargetFromSkillID(int ID);
    int GetSkillAccFromSkillID(int ID);
    int GetSkillCostFromSkillID(int ID);
    int GetSkillStunChanceFromSkillID(int ID);
    int GetSkillKnockoutChanceFromSkillID(int ID);
    int GetSkillChillChanceFromSkillID(int ID);
    int GetSkillFlameChanceFromSkillID(int ID);
    int GetSkillUpliftChanceFromSkillID(int ID);
    int GetSkillDamageToArmorFromSkillID(int ID);
    int GetSkillDamageToShieldFromSkillID(int ID);



    //Text related
    void setVisualTextToWidget(QString text);
    void setVisualTextToSecondWidget(QString text);
    QString GetVisualTextFromSelectedInfo();
    QString GetFinalVisualTextFromSelectedInfo();
    QString GetVisualHeader();
    QString GetVisualSuccessCheck();
    QString GetVisualCriticalCheck();
    QStringList GetVisualEffectCheck();
    QString GetVisualCalculationSteps();

    //Critical related

    //Calculations related
    void setSuccessTreshold(int treshold);
    void setCriticalTreshold(int treshold);
    void CalculateSuccessTresholdForActionID(int actionID);
    void CalculateCriticalTresholdForActionID(int actionID);
    void PopUpWarning(QString text);
    bool CheckForWarnings();

    int GetSumOfAccModifiers();
    int GetSumOfDmgModifiers();
    int GetBaseSuccessTreshold(int actionID);
    QString GetDiceTypeForActionID(int actionID);

    //Calculations part 2 related
    void PopUpDicesQuestion();
    QString GetVisualSuccessResult();
    QString GetVisualDamageResult();
    int GetNumberOfSuccess();
    int GetBaseDamageDealt();
    int GetModifiedBaseDamageDealt();
    int GetFinalDamageDealt();
    bool isCriticalHit();


};

#endif // CALCULATOR_H
