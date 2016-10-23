#include "calculator.h"
#include "ui_calculator.h"

QString calculator::GetEffectNameFromEffectID(int ID)
{
    QString name = "NoName";
    for(int i=0;i<ActiveEffect.size();i++)
    {
        if(ActiveEffect.at(i).ID == ID)
            name = ActiveEffect.at(i).Name;
    }
    return name;
}

int calculator::GetEffectIDFromEffectName(QString name)
{
    int id = 9999;
    for(int i=0;i<ActiveEffect.size();i++)
        if(ActiveEffect.at(i).Name == name)
            id = ActiveEffect.at(i).ID;

    return id;
}

void calculator::AddEffectToPlayer(int playerID, int effectID)
{
    C_PlayerActiveEffect item;
    item.PlayerID = playerID;
    item.EffectID = effectID;
    PlayerActiveEffects.append(item);
}

QVector<int> calculator::GetSkillEffectsFromSkillID(int skillID)
{
    QVector<int> list;
    for(int i=0;i<SkillActiveEffects.size();i++)
        if(SkillActiveEffects.at(i).SkillID == skillID)
            list.append(SkillActiveEffects.at(i).EffectID);
    return list;
}

void calculator::RemoveAllEffectsFromPlayer(int playerID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID)
        {
            PlayerActiveEffects.remove(i);
            i--;
        }
}

void calculator::RemoveEffectFromPlayer(int playerID, int effectID)
{
    for(int i=0;i<PlayerActiveEffects.size();i++)
        if(PlayerActiveEffects.at(i).PlayerID == playerID && PlayerActiveEffects.at(i).EffectID == effectID)
        {
            PlayerActiveEffects.remove(i);
            i--;
        }
}

void calculator::PerformAdditionalEffects()
{
    if(isPlayerHasEffect(selectedPlayerID,0))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(0);
        item.value = 1;
        AdditionalItemAndDifficulty.append(item);
    }
    if(isPlayerHasEffect(selectedPlayerID,1))
    {
        C_ItemModificator item;
        item.name = GetEffectNameFromEffectID(0);
        item.value = 2;
        AdditionalItemAndDifficulty.append(item);
    }

}
