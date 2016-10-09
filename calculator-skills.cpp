#include "calculator.h"
#include "ui_calculator.h"

QString calculator::GetSkillNameFromSkillID(int ID)
{
    QString name = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            name = Skills.at(i).SkillName;
    return name;
}

QString calculator::GetSkillTypeFromSkillID(int ID)
{
    QString SkillType = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            SkillType = Skills.at(i).SkillType;
    return SkillType;

}

QString calculator::GetSkillLevelFromSkillID(int ID)
{
    QString SkillType = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            SkillType = Skills.at(i).SkillLevel;
    return SkillType;
}

QString calculator::GetSkillTargetFromSkillID(int ID)
{
    QString SkillTarget = "Unknown Skill ID!";
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            SkillTarget = Skills.at(i).SkillTarget;
    return SkillTarget;
}

int calculator::GetSkillAccFromSkillID(int ID)
{
    int mod = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            mod = Skills.at(i).Acc;
    return mod;
}

int calculator::GetSkillCostFromSkillID(int ID)
{
    int skillCost = 100;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            skillCost = Skills.at(i).Cost;
    return skillCost;
}

int calculator::GetSkillStunChanceFromSkillID(int ID)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            output = Skills.at(i).StunChance;
    return output;
}

int calculator::GetSkillKnockoutChanceFromSkillID(int ID)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            output = Skills.at(i).KnockoutChance;
    return output;
}

int calculator::GetSkillChillChanceFromSkillID(int ID)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            output = Skills.at(i).ChillChance;
    return output;
}

int calculator::GetSkillFlameChanceFromSkillID(int ID)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            output = Skills.at(i).FlameChance;
    return output;
}

int calculator::GetSkillUpliftChanceFromSkillID(int ID)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            output = Skills.at(i).UpliftChance;
    return output;
}

int calculator::GetSkillDamageToArmorFromSkillID(int id)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == id)
            output = Skills.at(i).SkillDmgToArmor;
    return output;
}

int calculator::GetSkillDamageToShieldFromSkillID(int id)
{
    int output = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == id)
            output = Skills.at(i).SkillDmgToShield;
    return output;
}
