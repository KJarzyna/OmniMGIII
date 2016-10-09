#ifndef SKILL_H
#define SKILL_H
#include <QString>

class C_Skill
{
public:
    C_Skill();

    int SkillID;
    QString SkillName;
    QString SkillLevel;
    int SkillDmgToArmor;
    int SkillDmgToShield;
    int Cost;
    int Acc;
    int StunChance;
    int KnockoutChance;
    int ChillChance;
    int FlameChance;
    int UpliftChance;
    int SelfShieldDrain;
    QString SkillType;
    QString SkillDescription;
    QString SkillTarget;


};

#endif // SKILL_H
