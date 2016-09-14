#ifndef READWRITEDATA_H
#define READWRITEDATA_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <Headers/Player/player.h>
#include <Headers/Skill/skill.h>
#include <Headers/Player/playerskills.h>
#include <Headers/Skill/skilllist.h>
#include <Headers/Weapon/weaponlist.h>
#include <Headers/Weapon/weapon.h>
#include <Headers/Player/playerweapons.h>
#include <Headers/Weapon/wpnmodlist.h>
#include <Headers/Armor/armor.h>
#include <Headers/Armor/armorlist.h>
#include <Headers/Player/playerarmor.h>
#include <Headers/Armor/armmodlist.h>
#include <Headers/Player/playerarmormods.h>
#include <Headers/Generator/generators.h>
#include <Headers/Player/playergenerators.h>
#include <Headers/Omni/omnikeys.h>
#include <Headers/Player/playeromnikeys.h>
#include <Headers/Omni/omnikeymods.h>
#include <Headers/Player/playeromnikeymods.h>
#include <Headers/Omni/omniblades.h>
#include <Headers/Player/playeromniblades.h>
#include <Headers/Omni/omniblademods.h>
#include <Headers/Player/playeromniblademods.h>
#include <Headers/ActiveEffects/activeeffect.h>
#include <Headers/Player/playeractiveeffect.h>
#include <QFile>
#include <QDebug>

class ReadWriteData
{
public:
    ReadWriteData();

    //GENERAL
    bool ReadPlayersFromFileAndLoadToVector(QString filename, QVector<C_Player> &vector);

    bool WritePlayersFromVectorToFile(QVector<C_Player> &vector, QString filename);

    //SKILLS

    bool ReadSkillsFromFileAndLoadToVector(QString filename, QVector<C_Skill> &vector);
    bool ReadPlayerSkillFromFileAndLoadToVector(QString filename, QVector<C_PlayerSkill> &vector);
    bool ReadSkillListFromFileAndLoadToVector(QString filename, QVector<C_SkillList> &vector);

    bool WriteSkillsFromVectorToFile(QVector<C_Skill> &vector, QString filename);
    bool WritePlayerSkillFromVectorToFile(QVector<C_PlayerSkill> &vector, QString filename);
    bool WriteSkillListFromVectorToFile(QVector<C_SkillList> &vector, QString filename);

    //WEAPONS
    bool ReadWeaponListFromFileAndLoadToVector(QString filename, QVector<C_WeaponList> &vector);
    bool ReadWeaponsFromFileAndLoadToVector(QString filename, QVector<C_Weapon> &vector);
    bool ReadPlayerWeaponsFromFileAndLoadToVector(QString filename, QVector<C_PlayerWeapon> &vector);

    bool WritePlayerWeaponsFromVectorToFile(QVector<C_PlayerWeapon> &vector, QString filename);


    //WEAPON MODS
    bool ReadWpnModListFromFileAndLoadToVector(QString filename, QVector<C_WpnModList> &vector);

    //ARMOR
    bool ReadArmorListFromFileAndLoadToVector(QString filename, QVector<C_ArmorList> &vector);
    bool ReadArmorsFromFileAndLoadToVector(QString filename, QVector<C_Armor> &vector);
    bool ReadPlayerArmorsFromFileAndLoadToVector(QString filename, QVector<C_PlayerArmor> &vector);

    bool WritePlayerArmorsFromVectorToFile(QVector<C_PlayerArmor> &vector, QString filename);

    //ARMOR MODS
    bool ReadArmorModListFromFileAndLoadToVector(QString filename, QVector<C_ArmModList> &vector);
    bool ReadPlayerArmorModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerArmorMods> &vector);

    bool WritePlayerArmorModsFromVectorToFile(QVector<C_PlayerArmorMods> &vector, QString filename);

    //GENERATORS
    bool ReadGeneratorsFromFileAndLoadToVector(QString filename, QVector<C_Generators> &vector);
    bool ReadPlayerGeneratorsFromFileAndLoadToVector(QString filename, QVector<C_PlayerGenerators> &vector);

    bool WritePlayerGeneratorsFromVectorToFile(QVector<C_PlayerGenerators> &vector, QString filename);

    //OMNIKEYS
    bool ReadOmnikeysFromFileAndLoadToVector(QString filename, QVector<C_Omnikeys> &vector);
    bool ReadPlayerOmnikeysFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnikeys> &vector);

    bool WritePlayerOmnikeysFromVectorToFile(QVector<C_PlayerOmnikeys> &vector, QString filename);

    //OMNIKEY MODS
    bool ReadOmnikeyModsFromFileAndLoadToVector(QString filename, QVector<C_OmnikeyMods> &vector);
    bool ReadPlayerOmnikeyModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnikeyMods> &vector);

    bool WritePlayerOmnikeyModsFromVectorToFile(QVector<C_PlayerOmnikeyMods> &vector, QString filename);

    //OMNIBLADES
    bool ReadOmnibladesFromFileAndLoadToVector(QString filename, QVector<C_Omniblades> &vector);
    bool ReadPlayerOmnibladesFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmniblades> &vector);

    bool WritePlayerOmnibladesFromVectorToFile(QVector<C_PlayerOmniblades> &vector, QString filename);

    //OMNIBLADES MODS
    bool ReadOmnibladeModsFromFileAndLoadToVector(QString filename, QVector<C_OmnibladeMods> &vector);
    bool ReadPlayerOmnibladeModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnibladeMods> &vector);

    bool WritePlayerOmnibladeModsFromVectorToFile(QVector<C_PlayerOmnibladeMods> &vector, QString filename);

    //ACTIVE EFFECTS
    bool ReadActiveEffectsFromFileAndLoadToVector(QString filename, QVector<C_ActiveEffect> &vector);
    bool ReadPlayerActiveEffectsFromFileAndLoadToVector(QString filename, QVector<C_PlayerActiveEffect> &vector);

    bool WritePlayerActiveEffectsFromVectorToFile(QVector<C_PlayerActiveEffect> &vector, QString filename);

    bool CreateFileBackup(QString filename);
};

#endif // READWRITEDATA_H
