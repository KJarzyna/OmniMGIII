#ifndef WEAPON_H
#define WEAPON_H
#include<QString>

class C_Weapon
{
public:
    C_Weapon();

    int WeaponID;
    QString WeaponName;
    QString WeaponType;
    int DmgBase;
    int AdditionalDmgToArmor;
    int AdditionalDmgToShield;
    int Acc;
    int Cost;
    int AmmoPerShot;
    int AmmoMaxInClip;
    int Recoil;
    int AdditionalCritChance;

};

#endif // WEAPON_H
