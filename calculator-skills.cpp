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

int calculator::GetSkillEffectChanceFromSkillID(int SkillID, int EffectID)
{
    int output = 0;
    for(int i=0;i<SkillActiveEffects.size();i++)
        if(SkillActiveEffects.at(i).SkillID == SkillID && SkillActiveEffects.at(i).EffectID == EffectID)
            output = SkillActiveEffects.at(i).EffectChance;
    return output;
}

int calculator::GetSkillBarrierFromSkillID(int ID)
{
    int mod = 0;
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == ID)
            mod = Skills.at(i).AdditionalBarrier;
    return mod;
}

bool calculator::isSkillWorksWithShields(int ID)
{
    bool output = false;
    for(int i=0;i<SkillActiveEffects.size();i++)
        if(SkillActiveEffects.at(i).SkillID == ID)
            output = SkillActiveEffects.at(i).WorksWithShields;
    return output;
}

bool calculator::isSkillEffectApplicableToPlayer(int playerID, int skillID)
{
    if(isPlayerHasShield(playerID) && !isSkillWorksWithShields(skillID))
        return false;
    else
        return true;
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

QString calculator::GetSkillDescriptionFromSkillLevel(int skillID, QString level)
{
    for(int i=0;i<SkillDescriptions.size();i++)
        if(SkillDescriptions.at(i).getID() == skillID)
            return SkillDescriptions.at(i).getSkillDescriptionFromSkillLevel(level);
}

QStringList calculator::SplitSkillLevelFull(QString skillLevel)
{
    QStringList single_levels;
    QString levelFour, levelFive, levelSix;

    if(skillLevel.left(1) == "1")
        single_levels.append("1");
    else if(skillLevel.left(1) == "2")
    {
        single_levels.append("1");
        single_levels.append("2");
    }
    else if(skillLevel.left(1) == "3")
    {
        single_levels.append("1");
        single_levels.append("2");
        single_levels.append("3");
    }
    else if(skillLevel.left(1) == "4")
    {
        levelFour = skillLevel;
        single_levels.append("1");
        single_levels.append("2");
        single_levels.append("3");
        single_levels.append(levelFour);
    }
    else if(skillLevel.left(1) == "5")
    {
        levelFour = "4" + skillLevel.mid(1,1);
        levelFive = "5" + skillLevel.mid(2,1);
        single_levels.append("1");
        single_levels.append("2");
        single_levels.append("3");
        single_levels.append(levelFour);
        single_levels.append(levelFive);
    }
    else if(skillLevel.left(1) == "6")
    {

        levelFour = "4" + skillLevel.mid(1,1);
        levelFive = "5" + skillLevel.mid(2,1);
        levelSix = "6" + skillLevel.mid(3,1);
        single_levels.append("1");
        single_levels.append("2");
        single_levels.append("3");
        single_levels.append(levelFour);
        single_levels.append(levelFive);
        single_levels.append(levelSix);
    }

    return single_levels;

}

QString calculator::GetSkillDescriptionFromSkillID(int skillID)
{
    QString description_full = "";
    QString skillLevelFull = GetSkillLevelFromSkillID(skillID);
    QStringList skillLevelSingles = SplitSkillLevelFull(skillLevelFull);

    int descriptionID = GetSkillDescriptionIDFromSkillID(skillID);

    for(int i=0;i<SkillDescriptions.size();i++)
        if(SkillDescriptions.at(i).getID() == descriptionID)
        {
            description_full = "<center><font color=#FF8000>" + GetSkillNameFromSkillID(skillID) + "</font>";
            description_full += "<br>";
            description_full += "<i>" + SkillDescriptions.at(i).getSkillBaseDescription() + "</i></center>";
            description_full += "<br><br>";
        }
        else
        {
            description_full = "<center><font color=#FF8000>" + GetSkillNameFromSkillID(skillID) + "</font>";
            description_full += "<br>";
            description_full += "<i>Brak opisu do wyświetlenia</i></center>";
            description_full += "<br><br>";
        }


    for(int i=0;i<skillLevelSingles.count();i++)
        for(int j=0;j<SkillDescriptions.size();j++)
            if(SkillDescriptions.at(j).getID() == descriptionID)
            {
                description_full += "<font color=#FF8000>" + skillLevelSingles.at(i) + "</font><br>";
                description_full += SkillDescriptions.at(j).getSkillDescriptionFromSkillLevel(skillLevelSingles.at(i));
                description_full += "<br><br>";
            }
    return description_full;
}


int calculator::GetSkillDescriptionIDFromSkillID(int skillID)
{
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == skillID)
            return Skills.at(i).SkillDescriptionID;
}

int calculator::GetSkillSelfShieldDrainFromSKillID(int skillID)
{
    for(int i=0;i<Skills.size();i++)
        if(Skills.at(i).SkillID == skillID)
            return Skills.at(i).SelfShieldDrain;
}
