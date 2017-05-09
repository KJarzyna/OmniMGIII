#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>
#include <QtCore>
#include <QtGui>
#include <QSpinBox>
#include <QCloseEvent>
#include "mainwindow.h"
#include <QString>
#include "Headers/Actions/actions.h"
#include "Headers/ItemModificator/itemmodificator.h"
#include "Headers/ActiveEffects/skillactiveeffects.h"
#include "skilldescription.h"

#include <dialogbox_difficultyreason.h>
#include <dialogbox_action.h>
#include <dialogbox_warning_generic.h>
#include <dialogbox_postcalculation.h>
#include <dialogbox_activeeffect.h>
#include <dialogbox_details.h>

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
    QVector<C_Race> Races;
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
    QVector<C_SkillActiveEffects> SkillActiveEffects;
    QVector<C_Actions> Actions;
    QVector<C_SkillDescription> SkillDescriptions;

    QVector<C_ItemModificator> WidgetItemAndDifficulty; //Widget Difficulty Modificators
    QVector<C_ItemModificator> WidgetItemAndDifficulty_M;
    QVector<C_ItemModificator> WidgetItemAndDamage; //Widget Difficulty Modificators
    QVector<C_ItemModificator> WidgetItemAndDamage_M;

    QVector<C_ItemModificator> ItemAndDifficulty; //Equipment Difficulty Modificators ->
    QVector<C_ItemModificator> ItemAndAccuracy;
    QVector<C_ItemModificator> ItemAndCritical;
    QVector<C_ItemModificator> ItemAndActionCost;
    QVector<C_ItemModificator> ItemAndDamage; // <-


    QVector<C_ItemModificator> AdditionalItemAndDifficulty;
    QVector<C_ItemModificator> AdditionalItemAndDamage;
    QVector<C_ItemModificator> AdditionalItemAndActionCost;
    QVector<C_ItemModificator> AdditionalItemAndCritical;
    QVector<C_ItemModificator> AdditionalItemAndShield;

    QVector<C_ItemModificator> SumItemAndDifficulty; // Sum of all additional modificators
    QVector<C_ItemModificator> SumItemAndDamage;
    QVector<C_ItemModificator> SumItemAndActionCost;
    QVector<C_ItemModificator> SumItemAndCritical;

    QVector<QString> AdditionalFabuleOffText;

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

    bool playerStatsChanged; //not used yet (for rework)
    bool targetStatsChanged; //not used yet (For rework)

    //Damage related
    QVector<int> dice_results;

signals:
    void CalculatorClosed();

private slots:
    void GetDifficultyReasonSlot(QString reason);
    void GetSelectedActionItemSlot(int id, QString name);
    void ActionDialogBoxClosed(bool db_closed);
    void GetDiceResults(QVector<int> dices);
    void DiceDialogBoxClosed();
    void CalculationsApproved(bool approved);
    void ActiveEffectDialogBoxConfirmed(QStringList list);

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
    void on_pushButton_deleteEffect_clicked();
    void on_pushButton_addEffect_clicked();
    void on_checkBox_sukces_check_M_clicked(bool checked);
    void on_pushButton_AccMod_add_M_clicked();
    void on_pushButton_AccMod_remove_M_clicked();
    void on_pushButton_DmgMod_add_M_clicked();
    void on_pushButton_DmgMod_remove_M_clicked();
    void on_comboBox_select_player_M_activated(int index);
    void on_tabWidget_calculation_type_currentChanged(int index);
    void on_pushButton_approve_M_clicked();
    void on_pushButton_disapprove_M_clicked();

    void on_pushButton_copy_clicked();

    void on_pushButton_copy_2_clicked();

private:
    Ui::calculator *ui;

    //MANUAL
    void InitializeDmgModTable_Manual();
    void InitializeAccModTable_Manual();
    void InitializeTestVisibility_Manaul(bool state);
    void InitializePlayersComboBoxDamage_Manual();
    void ResetAdditionalDifficulty();
    void ResetAdditionalDamage();
    QString GetVisualTextFromSelectedInfo_Manual();
    QString GetVisualHeader_Manual();
    QString GetVisualDmgHeader_Manual();
    QString GetVisualSuccessCheck_Manual();
    QString GetVisualCalculationSteps_Difficulty_Manual();
    QString GetVisualCalculationSteps_Damage_Manual();
    QString GetVisualTargetArmorAndShieldLeftResult_Manual();
    int GetSumOfWidgetDiffModifiers_Manual();
    int GetSumOfWidgetDamageModifiers_Manual();
    int GetFinalDamageTaken_Manual();

    //AUTOMATIC
    void InitializeManualAutomatic();
    void InitializeDmgModTable();
    void InitializeAccModTable();
    void InitializePlayersComboBox();
    void InitializeActionsComboBox();
    void InitializeTargetsComboBox();
    void InitializePlayerStats();
    void InitializeDifficultyLevel();

    void setEnableAfterFirstCalculations(bool status);
    void setEnableAfterSecondCalculations(bool status);
    void setEnableAllInput(bool status);

    void ResetAction();
    void ResetTarget();
    void ResetDifficulty();

    void OpenDetailsWindow(QString type);

    //Target related
    void RemovePlayerFromTargetModel(int playerID);
    void AddPlayerToTargetModel(int playerID);

    //Player related
    QString GetPlayerNameFromPlayerID(int playerID);
    QString GetPlayerSpecializationSkill(int playerID);
    QStringList GetPlayerActiveEffects(int playerID);
    QVector<int> GetPlayerActiveEffectsIDs(int playerID);
    void setPlayerCurrentArmor(int playerID, int value);
    void setPlayerCurrentShield(int playerID, int value);
    void setPlayerBarrier(int playerID, int value);
    void reloadPlayerWeapon(int playerID, int weaponID);
    void subtractAmmoFromPlayerWeapon(int playerID, int weaponID);
    int GetPlayersArmorCostReduction(int playerID);
    int GetPlayersArmorWpnAccModifier(int playerID);
    int GetPlayersArmorSkillAccModifier(int playerID);
    int GetPlayersArmorWpnDiffLevelModifier(int playerID);
    int GetPlayersArmorSkillDiffLevelModifier(int playerID);
    int GetPlayersArmorMeeleeDiffLevelModifier(int playerID);
    int GetPlayerSkillMastery(int playerID, QString skillType);
    int GetPlayerEvasiveness(int playerID);
    int GetPlayersOmnibladeID(int playerID);
    int GetPlayersArmorCriticalChanceModifier(int playerID);
    int GetPlayerMaxShield(int playerID);
    int GetPlayerMaxArmor(int playerID);
    bool isPlayerHasShield(int playerID);
    bool isPlayerHasBarrier(int playerID);
    bool isPlayerHasEffect(int playerID, int effectID);


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
    bool isActionDealDamage(int actionID);


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
    int GetLightMeeleeDamageFromPlayerRace(int playerID);
    int GetHeavyMeeleeDamageFromPlayerRace(int playerID);

    //GET

    QString GetGeneratorNameFromGeneratorID(int ID);
    int GetPlayerTechnoBuffFromOmnikey(int playerID);
    int GetLightDamageFromRaceID(int ID);
    int GetHeavyDamageFromRaceID(int ID);
    int GetAreaDamageFromRaceID(int ID);
    int GetEvasivenessFromRaceID(int ID);
    int GetRaceIDFromRaceName(QString name);


    //Skill related
    QString GetSkillNameFromSkillID(int ID);
    QString GetSkillTypeFromSkillID(int ID);
    QString GetSkillLevelFromSkillID(int ID);
    QString GetSkillTargetFromSkillID(int ID);
    QString GetSkillDescriptionFromSkillLevel(int skillID, QString level);
    QString GetSkillDescriptionFromSkillID(int skillID);
    int GetSkillDescriptionIDFromSkillID(int skillID);
    QStringList SplitSkillLevelFull(QString skillLevel);
    int GetSkillAccFromSkillID(int ID);
    int GetSkillCostFromSkillID(int ID);
    int GetSkillDamageToArmorFromSkillID(int ID);
    int GetSkillDamageToShieldFromSkillID(int ID);
    int GetSkillBarrierFromSkillID(int ID);
    int GetSkillSelfShieldDrainFromSKillID(int skillID);
    bool isSkillWorksWithShields(int ID);


    //Effect related
    void AddEffectToPlayer(int playerID, int effectID);
    void RemoveEffectFromPlayer(int playerID, int effectID);
    void RemoveAllEffectsFromPlayer(int playerID);
    QString GetEffectNameFromEffectID(int ID);
    int GetEffectIDFromEffectName(QString name);
    int GetSkillEffectChanceFromSkillID(int SkillID, int EffectID);
    QVector<int> GetSkillEffectsFromSkillID(int skillID);
    bool isSkillEffectApplicableToPlayer(int playerID, int skillID);
    bool isPlayerHasAmmoActive(int playerID);
    int GetPlayerActiveAmmoID(int playerID);

    //Text related
    void setVisualTextToWidget(QString text);
    void setVisualTextToSecondWidget(QString text);
    void setVisualPlayerStats(int playerID);
    void setVisualPlayerActiveEffects(int playerID);
    QString GetVisualTextFromSelectedInfo();
    QString GetFinalVisualTextFromSelectedInfo();
    QString GetVisualHeader();
    QString GetVisualSuccessCheck();
    QString GetVisualCriticalCheck();
    QStringList GetVisualEffectCheck();
    QStringList GetVisualEffectSuccess();
    QString GetVisualCalculationSteps();
    QString GetVisualCalculationSteps_Damage();
    QString GetVisualCalculationSteps_Difficulty();
    QString GetVisualCalculationSteps_Cost();
    QString GetVisualCalculationSteps_Critical();
    QString GetVisualCalculationSteps_Accuracy();
    QString GetVisualCalculationSteps_Additional();
    QString GetVisualTargetArmorAndShieldLeftResult();
    QString GetVisualTargetEffects();
    QString ConvertVisualTextToCitadelFormat(QString text);

    //ADDITIONAL EFFECTS
    void PerformAdditionalEffects();
    void PerformAdditionalEffectsAfterHit();

    //Calculations related
    void setSuccessTreshold(int treshold);
    void setCriticalTreshold(int treshold);
    void CalculateSuccessTresholdForActionID(int actionID);
    void CalculateCriticalTresholdForActionID(int actionID);
    void CalculateFinalActionCostForActionID(int actionID);
    void PopUpWarning(QString text);
    void SumAllDifficultyModificators();
    void SumAllDamageModificators();
    void SumAllActionCostModificators();
    bool CheckForWarnings();

    int GetSumOfWidgetDiffModifiers();
    int GetSumOfWidgetDmgModifiers();
    int GetSumOfAdditionalDiffModifiers();
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
    int GetPlayerShieldCurrentAfterDamage(int playerID, int damage);
    int GetPlayerBarrierAfterDamage(int playerID, int damage);
    int GetPlayerArmorCurrentAfterDamage(int playerID, int damage);

    //After Calculations
    void ImplementAfterCalculationChanges();

    bool isCriticalHit();
    bool isAutomaticModeSelected();
    int getManualModeTypeSelected();

    void SaveAll();

    void closeEvent(QCloseEvent *event);

};

#endif // CALCULATOR_H
