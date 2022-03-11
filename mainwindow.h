#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QVector>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include "Headers/Player/player.h"
#include "Headers/Skill/skill.h"
#include "Headers/Skill/skilllist.h"
#include "Headers/Player/playerskills.h"
#include "Headers/ReadWriteData/readwritedata.h"
#include "Headers/Weapon/weapon.h"
#include "Headers/Weapon/weaponlist.h"
#include "Headers/Player/playerweapons.h"
#include "Headers/Armor/armor.h"
#include "Headers/Armor/armorlist.h"
#include "Headers/Player/playerarmor.h"
#include "Headers/Armor/armmodlist.h"
#include "Headers/Player/playerarmormods.h"
#include "Headers/Generator/generators.h"
#include "Headers/Player/playergenerators.h"
#include "Headers/Omni/omnikeys.h"
#include "Headers/Player/playeromnikeys.h"
#include "Headers/Omni/omnikeymods.h"
#include "Headers/Player/playeromnikeymods.h"
#include "Headers/Omni/omniblades.h"
#include "Headers/Player/playeromniblades.h"
#include "Headers/Omni/omniblademods.h"
#include "Headers/Player/playeromniblademods.h"
#include "Headers/ActiveEffects/activeeffect.h"
#include "Headers/Player/playeractiveeffect.h"

#include "itemdescription.h"
#include "skilldescription.h"

#include "dialogbox_activeeffect.h"
#include "dialogbox_yesno_generic.h"
#include "dialogbox_details.h"
#include "calculator.h"
#include "race.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVector<C_Player> Players;
    QVector<C_SkillList> SkillList;
    QVector<C_Skill> Skills;
    QVector<C_PlayerSkill> PlayerSkills;
    QVector<C_Weapon> Weapons;
    QVector<C_WeaponList> WeaponList;
    QVector<C_PlayerWeapon> PlayerWeapons;
    QVector<C_WpnModList> WpnModList;
    QVector<C_Armor> Armors;
    QVector<C_ArmorList> ArmorList;
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
    QVector<C_Race> Races;

    QVector<C_SkillDescription> SkillDescriptions;

    QVector<C_ItemDescription> armor_desc;
    QVector<C_ItemDescription> armormod_desc;
    QVector<C_ItemDescription> omnikey_desc;
    QVector<C_ItemDescription> omniblade_desc;
    QVector<C_ItemDescription> generator_desc;
    QVector<C_ItemDescription> omnikeymod_desc;
    QVector<C_ItemDescription> omniblademod_desc;
    QVector<C_ItemDescription> weaponmod_desc;

    QStandardItemModel *PlayersModel; //Column 1 for Name, column 2 (hidden) for ID
    QStandardItemModel *RaceModel;

private slots:
    void on_pushButton_skill_add_clicked();
    void on_pushButton_skill_remove_clicked();
    void on_pushButton_calculate_skills_clicked();
    void on_actionZapisz_triggered();
    void on_pushButton_weapon_add_clicked();
    void on_pushButton_weapon_remove_clicked();
    void on_pushButton_mod_add_clicked();
    void on_pushButton_mod_remove_clicked();
    void on_pushButton_armor_add_clicked();
    void on_pushButton_armor_remove_clicked();
    void on_pushButton_mod_armor_add_clicked();
    void on_pushButton_mod_armor_remove_clicked();
    void on_pushButton_generator_add_clicked();
    void on_pushButton_generator_remove_clicked();
    void on_comboBox_omnikey_name_activated(const QString &arg1);
    void on_comboBox_omnikey_submod_name_activated(const QString &arg1);
    void on_comboBox_omniblade_type_activated(const QString &arg1);
    void on_comboBox_omniblade_mod_name_activated(const QString &arg1);
    //void on_lineEdit_gen_charges_left_textEdited(const QString &arg1);
    void on_pushButton_reloadAll_clicked();
    void on_treeWidget_weapon_list_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_pushButton_add_activeEffect_clicked();
    void addActiveEffectsToWidgetList(QStringList list);
    void on_tableWidget_wpn_ammo_cellChanged(int row, int column);
    void on_comboBox_select_player_activated(const QString &arg1);
    void on_lineEdit_player_name_textEdited(const QString &arg1);
    void on_pushButton_addNewPlayer_clicked();
    void on_pushButton_deletePlayer_clicked();
    void on_actionOmni_Kalkulator_triggered();
    void CalculatorModuleSlot(bool savesignal);
    void on_lineEdit_player_class_textEdited(const QString &arg1);
    void on_comboBox_player_type_activated(const QString &arg1);
    void on_lineEdit_shield_current_textEdited(const QString &arg1);
    void on_lineEdit_shield_full_textEdited(const QString &arg1);
    void on_lineEdit_armor_current_textEdited(const QString &arg1);
    void on_lineEdit_armor_full_textEdited(const QString &arg1);
    void on_listWidget_armors_list_itemDoubleClicked(QListWidgetItem *item);
    void RefreshMainModule();
    void on_tableWidget_weapons_cellDoubleClicked(int row, int column);
    void on_listWidget_armormods_list_itemDoubleClicked(QListWidgetItem *item);
    void on_tableWidget_generators_cellDoubleClicked(int row, int column);
    void on_tableWidget_skills_cellDoubleClicked(int row, int column);

    void on_comboBox_player_race_activated(const QString &arg1);

    void on_tableWidget_weapons_preview_cellDoubleClicked(int row, int column);

    void on_tableWidget_skills_preview_cellDoubleClicked(int row, int column);

    void on_listWidget_armors_list_preview_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_armormods_list_preview_itemDoubleClicked(QListWidgetItem *item);

    void on_tableWidget_generators_preview_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    //GENERAL
    void ClearAllTabs();
    void ClearGeneralTab();
    void ClearConfgurationTab();
    int GetActivePlayerID();
    int FindLastUsedPlayerID();
    void AddNewPlayerToVector(QString playerName, int playerID);
    void AddNewPlayerToModel(QString playerName, int playerID);
    void DeletePlayerFromVector(int playerID);
    void DeletePlayerFromModel(int playerID);
    void SaveAll();

    //INITIALIZATION RELATED
    void InitializeWeaponTableSize();
    void InitializeSkillTableSize();
    void InitializeGeneratorTableSize();
    void InitializeSkillListTreeWidget();
    void InitializeSkillListSpecialization();
    void InitializeWeaponListTreeWidget();
    void InitializeWpnModListTreeWidget();
    void InitializeArmorListTreeWidget();
    void InitializeArmorModList();
    void InitializeGeneratorList();
    void InitializeOmnikeyList();
    void InitializeOmnikeyModsList();
    void InitializeOmnibladesList();
    void InitializeOmnibladeModsList();
    void InitializeAmmoLeftList();
    void InitializePlayerList();
    void InitializeRaceList();

    //SKILL RELATED
    void AddSkillToTable();
    void AddSkillToPlayer(int skillID, int playerID);
    void RemoveSkillFromTable();
    void RemoveSkillFromPlayer(int skillID, int playerID);
    void RemoveSpecializationFromPlayer(int playerID);
    void ClearSkillTable();
    void LoadPlayerSkillsIntoTable(int playerID);
    void CalculatePlayerMasteries(int playerID);
    void SetMasteriesToZero();
    void SetSpecializationToDefault();

    //WEAPON RELATED
    void ClearWeaponTable();
    void AddWeaponToTable();
    void AddWeaponToPlayer(int weaponID, int playerID);
    void RemoveWeaponFromTable();
    void RemoveWeaponFromPlayer(int weaponID, int playerID);
    void LoadPlayerWeaponsIntoTable(int playerID);

    //WEAPON MOD RELATED
    void AddWpnModToTable(int selected_col);
    void RemoveWpnModFromTable();
    void AddWpnModToPlayer(int wpnModID, int weaponID, int playerID);
    void RemoveWpnModFromPlayer(int weaponID, int playerID);
    bool isModTypeGoodWithWpnType(int weaponModID, int weaponID);

    //AMMO RELATED
    void ClearAmmoTable();
    void AddWeaponToAmmoTable();
    void RemoveWeaponFromAmmoTable();
    void LoadPlayerAmmoIntoTable(int playerID);


   //ARMOR RELATED
    void ClearArmorList();
    void AddArmorToList();
    void AddArmorToPlayer(int armorID, int playerID);
    void RemoveArmorFromList();
    void RemoveArmorFromPlayer(int armorID, int playerID);
    void LoadPlayerArmorsList(int playerID);

    //ARMOR MOD RELATED
    void ClearArmorModList();
    void AddArmorModToList();
    void AddArmorModToPlayer(int armorModID, int playerID);
    void RemoveArmorModFromList();
    void RemoveArmorModFromPlayer(int armorID, int playerID);
    void LoadPlayerArmorModsList(int playerID);

    //GENERATOR RELATED
    void ClearGeneratorTable();
    void AddGeneratorToTable();
    void AddGeneratorToPlayer(int generatorID, int playerID);
    void RemoveGeneratorFromTable();
    void RemoveGeneratorFromPlayer(int generatorID, int playerID);
    void LoadPlayerGeneratorIntoTable(int playerID);
    void SetGeneratorChargesToZero();

    //OMNIKEYS RELATED
    void AddOmnikeyToPlayer(int omnikeyID, int playerID);
    void RemoveOmnikeyFromPlayer(int playerID);
    void LoadPlayerOmnikey(int playerID);
    void SetOmnikeyToDefault();

    //OMNIKEY MOD RELATED
    void AddOmnikeyModToPlayer(int omnikeyModID, int playerID);
    void RemoveOmnikeyModFromPlayer(int playerID);
    void LoadPlayerOmnikeyMod(int playerID);
    void SetOmnikeyModToDefault();

    //OMNIBLADE RELATED
    void AddOmnibladeToPlayer(int omnibladeID, int playerID);
    void RemoveOmnibladeFromPlayer(int playerID);
    void LoadPlayerOmniblade(int playerID);
    void SetOmnibladeToDefault();

    //OMNIBLADE MOD RELATED
    void AddOmnibladeModToPlayer(int omnibladeModID, int playerID);
    void RemoveOmnibladeModFromPlayer(int playerID);
    void LoadPlayerOmnibladeMod(int playerID);
    void SetOmnibladeModToDefault();

    //EFFECT RELATED
    void AddEffectToPlayer(int effectID, int playerID);
    void RemoveEffectsFromPlayer(int playerID);

    //READ FILES
    bool ReadDataFromFiles();

    //LOADING TABS
    void LoadPlayerGeneralTab(int playerID);
    void LoadPlayerSpecialization(int playerID);
    void LoadPlayerMasteries(int playerID);
    void LoadPlayerSkillsTab(int playerID);
    void LoadPlayerWeaponsTab(int playerID);
    void LoadPlayerArmorsTab(int playerID);
    void LoadPlayerEquipementTab(int playerID);

    void LoadGeneratorCharges(int playerID);
    void LoadPlayer(int id);

    void SavePlayerNotesToVector(int playerID);
    int currentlySelectedPlayerID;

    //---check if still used----
    void SaveGeneralTab(int playerID);
    void SaveGeneralTabToVector(int playerID);
    void SaveSkillsTab (int playerID);
    void SaveSkillsTabToVector(int playerID);

    //
    void RemoveAllPlayerSkillsFromVector(int playerID);
    void AddAllPlayerSkillsToVector(int playerID);

    //GENERAL GET FUNCTIONS
    int GetPlayerIndex(int playerID);
    int GetPlayerMasteryPoints(int playerID, QString mastery);
    QString GetPlayerSpecializationType(int playerID);
    QString GetSkillNameFromSkillID(int skillID);
    QString GetSkillLevelFromSkillID(int skillID);
    int GetSkillIDFromSkillNameAndLevel(QString skillName, QString skillLevel);
    QString GetActionCostFromCost(int cost);
    QString GetWpnModNameFromWpnModID(int modid);
    int GetWeaponIDFromWeaponName(QString weaponName);
    QString GetWeaponNameFromWeaponID(int weaponID);
    int GetCurrentAmmoInPlayerWeaponFromWeaponID(int weaponID, int playerID);
    int GetWpnModIDFromWpnModName(QString modName);
    int GetArmorIDFromArmorName(QString armorName);
    QString GetArmorNameFromArmorID(int armorID);
    int GetArmorModIDFromArmorModName(QString armorModName);
    QString GetArmorModNameFromArmorModID(int armorModID);
    int GetGeneratorIDFromGeneratorName(QString generatorName);
    QString GetGeneratorNameFromGeneratorID(int generatorID);
    int GetOmnikeyIDFromOmnikeyName(QString Name);
    int GetOmnikeyModIDFromOmnikeyModName(QString Name);
    int GetOmnibladeIDFromOmnibladeName(QString Name);
    int GetOmnibladeModIDFromOmnibladeModName(QString Name);
    int GetMaxAmmoOfWeaponFromWeaponName(QString Name);
    int GetEffectIDFromEffectName(QString name);
    QString GetOmnikeyNameFromOmnikeyID(int ID);
    QString GetOmnikeyModNameFromOmnikeyModID(int ID);
    QString GetOmnibladeNameFromOmnibladeID(int ID);
    QString GetOmnibladeModNameFromOmnibladeModID(int ID);
    QString GetEffectNameFromEffectID(int ID);

    //DETAILS
    QString GetVisualItemDescriptionFromItemID(int itemID, QVector<C_ItemDescription> item_container, QString item_type);
    QString GetItemDescriptionFromItemID(int itemID, QVector<C_ItemDescription> item_container);
    void ShowItemDetails(int itemID, QVector<C_ItemDescription> c_desc, QString item_type);
    void ShowSkillDetails(int itemID);

    QString GetSkillDescriptionFromSkillLevel(int skillID, QString level);
    QStringList SplitSkillLevelFull(QString skillLevel);
    QString GetSkillDescriptionFromSkillID(int skillID);
    int GetSkillDescriptionIDFromSkillID(int skillID);

    //CALCULATOR RELATED
    void Reload(int playerID, int weaponID);
    void ReloadAll(int playerID, int selected_row);

    bool PlayerHasSkill(int playerID, QString skillName);
    bool PlayerHasArmor(int playerID, int armorID);
    bool PlayerHasArmorMod(int playerID, int armorModID);

    void OpenCalculatorModule();

};

#endif // MAINWINDOW_H
