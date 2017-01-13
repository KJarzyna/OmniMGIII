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
    int AdditionalBarrier;
    int SelfShieldDrain;
    QString SkillType;
    int SkillDescriptionID;
    QString SkillTarget;


};

#endif // SKILL_H
