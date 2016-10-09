#include "calculator.h"
#include "ui_calculator.h"

QString calculator::GetWeaponTypeFromWeaponID(int ID)
{
    QString WeaponType = "Unknown Weapon ID!";
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == ID)
            WeaponType = Weapons.at(i).WeaponType;
    return WeaponType;

}

QString calculator::GetWeaponNameFromWeaponID(int ID)
{
    QString name = "Unknown Weapon ID!";
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == ID)
            name = Weapons.at(i).WeaponName;
    return name;
}

void calculator::setSuccessTreshold(int treshold)
{
    successTreshold = treshold;
}

int calculator::GetWeaponAccFromWeaponID(int id)
{
    int WeaponAcc = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == id)
            WeaponAcc = Weapons.at(i).Acc;
    return WeaponAcc;
}

int calculator::GetOmnibladeAccFromOmnibladeID(int id)
{
    int WeaponAcc = 0;
    for(int i=0;i<Omniblades.size();i++)
        if(Omniblades.at(i).ID == id)
            WeaponAcc = Omniblades.at(i).Acc;
    return WeaponAcc;
}

int calculator::GetAmmoLeftInPlayersWeapon(int playerID, int weaponID)
{
    for(int i=0;i<PlayerWeapons.size();i++)
        if(PlayerWeapons.at(i).PlayerID == playerID && PlayerWeapons.at(i).WeaponID == weaponID)
            return PlayerWeapons.at(i).AmmoLeft;
}

int calculator::GetWeaponDamageToArmorFromWeaponID(int id)
{
    int output = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == id && Weapons.at(i).AdditionalDmgToArmor != 0)
        {
            C_ItemModificator item;
            item.name = "Dodatkowe obrażenia broni przeciwko pancerzowi";
            item.value = Weapons.at(i).AdditionalDmgToArmor;
            ItemAndDamage.append(item);

            output = Weapons.at(i).AdditionalDmgToArmor;
        }
    return output;
}

int calculator::GetWeaponDamageToShieldFromWeaponID(int id)
{
    int output = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == id && Weapons.at(i).AdditionalDmgToShield != 0)
        {
            C_ItemModificator item;
            item.name = "Dodatkowe obrażenia broni przeciwko tarczom";
            item.value = Weapons.at(i).AdditionalDmgToShield;
            ItemAndDamage.append(item);

            output = Weapons.at(i).AdditionalDmgToShield;
        }
    return output;
}

int calculator::GetWeaponBaseDamageFromWeaponID(int id)
{
    int output = 0;
    for(int i=0;i<Weapons.size();i++)
        if(Weapons.at(i).WeaponID == id)
            output = Weapons.at(i).DmgBase;
    return output;
}

int calculator::GetOmnibladeDamageFromOmnibladeID(int id)
{
    int output = 0;
    for(int i=0;i<Omniblades.size();i++)
        if(Omniblades.at(i).ID == id)
            output = Omniblades.at(i).Dmg;
    return output;
}

