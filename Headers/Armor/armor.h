#ifndef ARMOR_H
#define ARMOR_H
#include <QString>

class C_Armor
{
public:
    C_Armor();

    int ArmorID;
    QString ArmorName;
    QString ArmorType;
    int AdditionalArmor;
    int AdditionalShield;
    int ActionSkillCost;
    int AdditionalCritChance;
    int AdditionalCritDmg;
    int AdditionalWpnDmg;
    int AdditionalSkillDmg;
    int AdditionalMeeleeDmg;
    int WpnLevelDifficulty;
    int MeeleeLevelDifficulty;
    int SkillLevelDifficulty;
    int AdditionalSkillAcc;
    int AdditionalWpnAcc;

};

#endif // ARMOR_H
