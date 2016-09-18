#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>
#include <QtCore>
#include <QtGui>
#include <QSpinBox>
#include "mainwindow.h"
#include <QString>
#include <calculator-actions.h>
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

    QString difficulty_reason;

    int selectedPlayerID;
    int selectedActionItemID;
    QString selectedActionItemName;

    QString playerFinal;
    QString selectedActionFinal;
    QString actionCostFinal;
    QString targetFinal;
    int successTresholdFinal;


private slots:
    void on_pushButton_AccMod_add_clicked();
    void on_pushButton_AccMod_remove_clicked();
    void on_pushButton_DmgMod_add_clicked();
    void on_pushButton_DmgMod_add_2_clicked();
    void on_comboBox_select_player_activated(int index);
    void on_comboBox_select_difficultylevel_activated(const QString &arg1);

    void GetDifficultyReasonSlot(QString reason);
    void GetSelectedActionItemSlot(int id, QString name);

    void on_comboBox_select_action_activated(int index);

    void on_pushButton_calculate_clicked();

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
    void setPlayerStats(int playerID);
    void setPlayerActiveEffects(int playerID);
    int PlayersArmorCostReduction(int playerID);

    //Actions related
    QStandardItemModel* GetItemModelBasedOnSelectedAction(int actionID);
    QStandardItemModel* GetItemModelForWeaponType(QString weaponType);
    QStandardItemModel* GetItemModelForAllPlayerWeapons();
    QStandardItemModel* GetItemModelForAllPlayerGenerators();
    QStandardItemModel* GetItemModelForAllPlayerSkills();
    QStandardItemModel* GetItemModelForGelUsage();
    QStandardItemModel* GetItemModelForSpecialAmmo();

    void OpenAdditionalDialogBox(int actionID);
    void SetActionCost();

    bool ReadDataFromFiles();

    QString GetPlayerNameFromPlayerID(int playerID);
    QString GetEffectNameFromEffectID(int ID);
    int GetCurrentActionID();
    QString GetWeaponTypeFromWeaponID(int ID);
    QString GetWeaponNameFromWeaponID(int ID);
    QString GetGeneratorNameFromGeneratorID(int ID);
    QString GetSkillNameFromSkillID(int ID);
    QString GetSkillTypeFromSkillID(int ID);
    QString GetSkillLevelFromSkillID(int ID);
    int GetSkillCostFromSkillID(int ID);
    int GetActionCostFromActionID(int ID);

    //Calculations related
    void setPlayerFinal();
    void setActionFinal();
    void setActionCostFinal();
    void setTargetFinal();
    void setSuccessTresholdFinal();
    void ChangeActionCost(QString newCost);
};

#endif // CALCULATOR_H
