#include "skilldescription.h"

C_SkillDescription::C_SkillDescription()
{

}

QString C_SkillDescription::getSkillDescriptionFromSkillLevel(QString level) const
{
    if(level == "1")
        return Level1;
    else if(level == "2")
        return Level2;
    else if(level == "3")
        return Level3;
    else if(level == "4A")
        return Level4A;
    else if(level == "4B")
        return Level4B;
    else if(level == "5A")
        return Level5A;
    else if(level == "5B")
        return Level5B;
    else if(level == "6A")
        return Level6A;
    else if(level == "6B")
        return Level6B;
    else
        return "No Description Found";
}
