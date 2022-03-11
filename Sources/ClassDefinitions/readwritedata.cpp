#include "Headers/ReadWriteData/readwritedata.h"
#include <QTextCodec>

ReadWriteData::ReadWriteData()
{

}

//READ PLAYERS
bool ReadWriteData::ReadPlayersFromFileAndLoadToVector(QString filename, QVector<C_Player> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Player player;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                player.PlayerID = cells.at(0).toInt();
                player.PlayerName = cells.at(1);
                player.PlayerRace = cells.at(2);
                player.PlayerClass = cells.at(3);
                player.PlayerType = cells.at(4);
                player.ArmorCurrent = cells.at(5).toInt();
                player.ArmorMax = cells.at(6).toInt();
                player.ShieldCurrent = cells.at(7).toInt();
                player.ShieldMax = cells.at(8).toInt();
                player.BarrierCurrent = cells.at(9).toInt();
                player.ActiveEffects = cells.at(10);
                player.SpecializationSkill = cells.at(11);
                player.MasteryBattle = cells.at(12).toInt();
                player.MasteryBiotic = cells.at(13).toInt();
                player.MasteryTechno = cells.at(14).toInt();
                player.MasterySpec = cells.at(15).toInt();
                player.Notes = cells.at(16);
                vector.append(player);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() <<  filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ RACES
bool ReadWriteData::ReadRacesFromFileAndLoadToVector(QString filename, QVector<C_Race> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Race race;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                race.ID = cells.at(0).toInt();
                race.Name = cells.at(1);
                race.HeavyDamage = cells.at(2).toInt();
                race.LightDamage = cells.at(3).toInt();
                race.AreaDamage = cells.at(4).toInt();
                race.HitChance = cells.at(5).toInt();

                vector.append(race);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() <<  filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ SKILLS
bool ReadWriteData::ReadSkillsFromFileAndLoadToVector(QString filename, QVector<C_Skill> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Skill skill;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                skill.SkillID = cells.at(0).toInt();
                skill.SkillName = cells.at(1);
                skill.SkillLevel = cells.at(2);
                skill.SkillDmgToArmor = cells.at(3).toInt();
                skill.SkillDmgToShield = cells.at(4).toInt();
                skill.Cost = cells.at(5).toInt();
                skill.Acc = cells.at(6).toInt();
                skill.AdditionalBarrier = cells.at(7).toInt();
                skill.SelfShieldDrain = cells.at(8).toInt();
                skill.SkillType = cells.at(9);
                skill.SkillDescriptionID = cells.at(10).toInt();
                skill.SkillTarget = cells.at(11);
                vector.append(skill);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerSkillFromFileAndLoadToVector(QString filename, QVector<C_PlayerSkill> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerSkill skill;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                skill.PlayerID = cells.at(0).toInt();
                skill.SkillID = cells.at(1).toInt();
                vector.append(skill);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadSkillListFromFileAndLoadToVector(QString filename, QVector<C_SkillList> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_SkillList skill;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                skill.SkillName = cells.at(0);
                skill.SkillType = cells.at(1);
                vector.append(skill);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadSkillsDescriptionsFromFileAndLoadToVector(QString filename, QVector<C_SkillDescription> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_SkillDescription skill;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                skill.ID = cells.at(0).toInt();
                skill.Base = cells.at(1);
                skill.Level1 = cells.at(2);
                skill.Level2 = cells.at(3);
                skill.Level3 = cells.at(4);
                skill.Level4A = cells.at(5);
                skill.Level4B = cells.at(6);
                skill.Level5A = cells.at(7);
                skill.Level5B = cells.at(8);
                skill.Level6A = cells.at(9);
                skill.Level6B = cells.at(10);
                vector.append(skill);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ WEAPONS
bool ReadWriteData::ReadWeaponListFromFileAndLoadToVector(QString filename, QVector<C_WeaponList> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_WeaponList weapon;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                weapon.WeaponName = cells.at(0);
                weapon.WeaponType = cells.at(1);
                vector.append(weapon);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadWeaponsFromFileAndLoadToVector(QString filename, QVector<C_Weapon> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Weapon weapon;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                weapon.WeaponID = cells.at(0).toInt();
                weapon.WeaponName = cells.at(1);
                weapon.WeaponType = cells.at(2);
                weapon.DmgBase = cells.at(3).toInt();
                weapon.AdditionalDmgToArmor = cells.at(4).toInt();
                weapon.AdditionalDmgToShield = cells.at(5).toInt();
                weapon.Acc = cells.at(6).toInt();
                weapon.Cost = cells.at(7).toInt();
                weapon.AmmoPerShot = cells.at(8).toInt();
                weapon.AmmoMaxInClip = cells.at(9).toInt();
                weapon.Recoil = cells.at(10).toInt();
                weapon.AdditionalCritChance = cells.at(11).toInt();
                vector.append(weapon);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerWeaponsFromFileAndLoadToVector(QString filename, QVector<C_PlayerWeapon> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerWeapon weapon;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                weapon.PlayerID = cells.at(0).toInt();
                weapon.WeaponID = cells.at(1).toInt();
                weapon.ModID = cells.at(2).toInt();
                weapon.AmmoLeft = cells.at(3).toInt();
                vector.append(weapon);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ WEAPON MODS
bool ReadWriteData::ReadWpnModListFromFileAndLoadToVector(QString filename, QVector<C_WpnModList> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_WpnModList mod;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                mod.ModID = cells.at(0).toInt();
                mod.ModName = cells.at(1);
                mod.ModType = cells.at(2);
                vector.append(mod);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ ARMORS
bool ReadWriteData::ReadArmorListFromFileAndLoadToVector(QString filename, QVector<C_ArmorList> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_ArmorList armor;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                armor.ArmorName = cells.at(0);
                armor.ArmorType = cells.at(1);
                vector.append(armor);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadArmorsFromFileAndLoadToVector(QString filename, QVector<C_Armor> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Armor armor;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                armor.ArmorID = cells.at(0).toInt();
                armor.ArmorName = cells.at(1);
                armor.ArmorType = cells.at(2);
                armor.AdditionalArmor = cells.at(3).toInt();
                armor.AdditionalShield = cells.at(4).toInt();
                armor.ActionSkillCost = cells.at(5).toInt();
                armor.AdditionalCritChance = cells.at(6).toInt();
                armor.AdditionalCritDmg = cells.at(7).toInt();
                armor.AdditionalWpnDmg = cells.at(8).toInt();
                armor.AdditionalSkillDmg = cells.at(9).toInt();
                armor.AdditionalMeeleeDmg = cells.at(10).toInt();
                armor.WpnLevelDifficulty = cells.at(11).toInt();
                armor.MeeleeLevelDifficulty = cells.at(12).toInt();
                armor.SkillLevelDifficulty = cells.at(13).toInt();
                armor.AdditionalSkillAcc = cells.at(14).toInt();
                armor.AdditionalWpnAcc = cells.at(15).toInt();
                vector.append(armor);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerArmorsFromFileAndLoadToVector(QString filename, QVector<C_PlayerArmor> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerArmor armor;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                armor.PlayerID = cells.at(0).toInt();
                armor.ArmorID = cells.at(1).toInt();
                vector.append(armor);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ ARMOR MODS
bool ReadWriteData::ReadArmorModListFromFileAndLoadToVector(QString filename, QVector<C_ArmModList> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_ArmModList armor;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                armor.ModID = cells.at(0).toInt();
                armor.ArmorModName = cells.at(1);
                vector.append(armor);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadItemDescriptionsFromFileAndLoadToVector(QString filename, QVector<C_ItemDescription> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_ItemDescription item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Description = cells.at(1);

                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() <<  filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerArmorModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerArmorMods> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerArmorMods armor;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                armor.PlayerID = cells.at(0).toInt();
                armor.ArmorModID = cells.at(1).toInt();
                vector.append(armor);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ GENERATORS
bool ReadWriteData::ReadGeneratorsFromFileAndLoadToVector(QString filename, QVector<C_Generators> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Generators generator;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                generator.GeneratorID = cells.at(0).toInt();
                generator.GeneratorName = cells.at(1);
                generator.ShieldPower = cells.at(2).toInt();
                generator.Charges = cells.at(3).toInt();
                generator.Recharge = cells.at(4).toInt();
                generator.HasAbility = cells.at(5);
                vector.append(generator);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerGeneratorsFromFileAndLoadToVector(QString filename, QVector<C_PlayerGenerators> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerGenerators generator;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                generator.PlayerID = cells.at(0).toInt();
                generator.GeneratorID = cells.at(1).toInt();
                generator.ChargesLeft = cells.at(2).toInt();
                vector.append(generator);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ OMNIKEYS
bool ReadWriteData::ReadOmnikeysFromFileAndLoadToVector(QString filename, QVector<C_Omnikeys> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Omnikeys item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Name = cells.at(1);
                item.ShieldBuff = cells.at(2).toInt();
                item.TechnoBuff = cells.at(3).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerOmnikeysFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnikeys> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerOmnikeys item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.PlayerID = cells.at(0).toInt();
                item.OmnikeyID = cells.at(1).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ OMNIKEY MODS
bool ReadWriteData::ReadOmnikeyModsFromFileAndLoadToVector(QString filename, QVector<C_OmnikeyMods> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_OmnikeyMods item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Name = cells.at(1);
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerOmnikeyModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnikeyMods> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerOmnikeyMods item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.PlayerID = cells.at(0).toInt();
                item.OmnikeyModID = cells.at(1).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ OMNIBLADES
bool ReadWriteData::ReadOmnibladesFromFileAndLoadToVector(QString filename, QVector<C_Omniblades> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Omniblades item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Name = cells.at(1);
                item.Acc = cells.at(2).toInt();
                item.Dmg = cells.at(2).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerOmnibladesFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmniblades> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerOmniblades item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.PlayerID = cells.at(0).toInt();
                item.OmnibladeID = cells.at(1).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ OMNIBLADE MODS
bool ReadWriteData::ReadOmnibladeModsFromFileAndLoadToVector(QString filename, QVector<C_OmnibladeMods> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_OmnibladeMods item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Name = cells.at(1);
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerOmnibladeModsFromFileAndLoadToVector(QString filename, QVector<C_PlayerOmnibladeMods> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerOmnibladeMods item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.PlayerID = cells.at(0).toInt();
                item.OmnibladeModID = cells.at(1).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//READ ACTIVE EFFECTS
bool ReadWriteData::ReadActiveEffectsFromFileAndLoadToVector(QString filename, QVector<C_ActiveEffect> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_ActiveEffect item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.ID = cells.at(0).toInt();
                item.Name = cells.at(1);
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadPlayerActiveEffectsFromFileAndLoadToVector(QString filename, QVector<C_PlayerActiveEffect> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_PlayerActiveEffect item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.PlayerID = cells.at(0).toInt();
                item.EffectID = cells.at(1).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

bool ReadWriteData::ReadSkillActiveEffectsFromFileAndLoadToVector(QString filename, QVector<C_SkillActiveEffects> &vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_SkillActiveEffects item;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                item.SkillID = cells.at(0).toInt();
                item.EffectID = cells.at(1).toInt();
                item.EffectChance = cells.at(2).toInt();
                item.WorksWithShields = cells.at(3).toInt();
                vector.append(item);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//WRITE PLAYERS
bool ReadWriteData::WritePlayersFromVectorToFile(QVector<C_Player> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {
        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;PlayerName;PlayerRace;PlayerClass;PlayerType;ArmorCurrent;ArmorMax;ShieldCurrent;ShieldMax;BarrierCurrent;"
               "ActiveEffects;SpecializationSkill;MasteryBattle;MasteryBiotic;MasteryTechno;MasterySpec;Notes";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(vector.at(i).PlayerName);
            line.append(";");
            line.append(vector.at(i).PlayerRace);
            line.append(";");
            line.append(vector.at(i).PlayerClass);
            line.append(";");
            line.append(vector.at(i).PlayerType);
            line.append(";");
            line.append(QString::number(vector.at(i).ArmorCurrent));
            line.append(";");
            line.append(QString::number(vector.at(i).ArmorMax));
            line.append(";");
            line.append(QString::number(vector.at(i).ShieldCurrent));
            line.append(";");
            line.append(QString::number(vector.at(i).ShieldMax));
            line.append(";");
            line.append(vector.at(i).BarrierCurrent);
            line.append(";");
            line.append(vector.at(i).ActiveEffects);
            line.append(";");
            line.append(vector.at(i).SpecializationSkill);
            line.append(";");
            line.append(QString::number(vector.at(i).MasteryBattle));
            line.append(";");
            line.append(QString::number(vector.at(i).MasteryBiotic));
            line.append(";");
            line.append(QString::number(vector.at(i).MasteryTechno));
            line.append(";");
            line.append(QString::number(vector.at(i).MasterySpec));
            line.append(";");
            line.append(vector.at(i).Notes);
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE RACES
bool ReadWriteData::WriteRacesFromVectorToFile(QVector<C_Race> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {
        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "ID;Name;HeavyDamage;LightDamage;AreaDamage;HitChance";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).ID));
            line.append(";");
            line.append(vector.at(i).Name);
            line.append(";");
            line.append(QString::number(vector.at(i).HeavyDamage));
            line.append(";");
            line.append(QString::number(vector.at(i).LightDamage));
            line.append(";");
            line.append(QString::number(vector.at(i).AreaDamage));
            line.append(";");
            line.append(QString::number(vector.at(i).HitChance));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}


//WRITE SKILLS
bool ReadWriteData::WritePlayerSkillFromVectorToFile(QVector<C_PlayerSkill> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {
        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;SkillID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).SkillID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

bool ReadWriteData::WriteSkillListFromVectorToFile(QVector<C_SkillList> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {
        QTextStream out(&outputFile);
        out.flush();
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "SkillName;SkillType";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(vector.at(i).SkillName);
            line.append(";");
            line.append(vector.at(i).SkillType);
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE WEAPONS
bool ReadWriteData::WritePlayerWeaponsFromVectorToFile(QVector<C_PlayerWeapon> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;WeaponID;ModID;AmmoLeft";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).WeaponID));
            line.append(";");
            line.append(QString::number(vector.at(i).ModID));
            line.append(";");
            line.append(QString::number(vector.at(i).AmmoLeft));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE ARMORS
bool ReadWriteData::WritePlayerArmorsFromVectorToFile(QVector<C_PlayerArmor> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;ArmorID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).ArmorID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE ARMOR MODS
bool ReadWriteData::WritePlayerArmorModsFromVectorToFile(QVector<C_PlayerArmorMods> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;ArmorModID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).ArmorModID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE GENERATORS
bool ReadWriteData::WritePlayerGeneratorsFromVectorToFile(QVector<C_PlayerGenerators> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;GeneratorID;ChargesLeft";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).GeneratorID));
            line.append(";");
            line.append(QString::number(vector.at(i).ChargesLeft));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE OMNI RELATED
bool ReadWriteData::WritePlayerOmnikeysFromVectorToFile(QVector<C_PlayerOmnikeys> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;OmnikeyID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).OmnikeyID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

bool ReadWriteData::WritePlayerOmnikeyModsFromVectorToFile(QVector<C_PlayerOmnikeyMods> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;OmnikeyModID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).OmnikeyModID));

            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

bool ReadWriteData::WritePlayerOmnibladesFromVectorToFile(QVector<C_PlayerOmniblades> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;OmnibladeID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).OmnibladeID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

bool ReadWriteData::WritePlayerOmnibladeModsFromVectorToFile(QVector<C_PlayerOmnibladeMods> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;OmnibladeModID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).OmnibladeModID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}

//WRITE ACTIVE EFFECT

bool ReadWriteData::WritePlayerActiveEffectsFromVectorToFile(QVector<C_PlayerActiveEffect> &vector, QString filename)
{
    QFile outputFile(filename);
    QString line;

    if (CreateFileBackup(filename) && outputFile.remove() && outputFile.open(QIODevice::ReadWrite))
    {

        QTextStream out(&outputFile);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        out.setGenerateByteOrderMark(true);
        line = "PlayerID;EffectID";
        out << line << endl;

        for (int i=0; i<vector.size();i++)
        {
            line.clear();
            line.append(QString::number(vector.at(i).PlayerID));
            line.append(";");
            line.append(QString::number(vector.at(i).EffectID));
            out << line << endl;
        }

        outputFile.close();
        return true;
    }
    else
    {
        qDebug() << filename << ": Couldn't open file!";
        return false;
    }
}
//READ ACTIONS

bool ReadWriteData::ReadActionsFromFileAndLoadToVector(QString filename, QVector<C_Actions> & vector)
{
    vector.clear();
    QFile inputFile(filename);
    C_Actions action;

    if (inputFile.exists() && inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList cells = line.split(';');

            if (cells.size()>0)
            {
                action.ID = cells.at(0).toInt();
                action.Name = cells.at(1);
                action.Cost = cells.at(2).toInt();

                vector.append(action);
            }

        }

        if (!vector.isEmpty())
            vector.removeFirst();
        else
            qDebug() << "File " << filename << " is empty!";

        inputFile.close();
        return true;
    }
    else
    {
        qDebug() <<  filename << ": Couldn't open file or file doesn't exist!";
        return false;
    }

}

//BACKUP
bool ReadWriteData::CreateFileBackup(QString filename)
{
    //Creates backup of the old file in the newlocation
    QString old_filename = filename;
    QFile backupFile(old_filename);
    filename.insert(5, "Backup/");
    filename.chop(4);
    filename.append("_bckp.csv");
    if (backupFile.exists(filename))
        backupFile.remove(filename);

    if (backupFile.copy(old_filename,filename))
        return true;
    else
        return false;
}
