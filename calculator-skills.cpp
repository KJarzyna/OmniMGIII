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

int calculator::GetSkillCostFromSkillID(int ID)
{
    int skillCost = 100;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            skillCost = Skills.at(i).Cost;
    return skillCost;
}
