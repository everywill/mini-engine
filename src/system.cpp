#include "system.h"

void System::registerEntity(Entity const & entity)
{
    registeredEntities.push_back(entity);
}

void System::unRegisterEntity(Entity const & entity)
{
    for(auto it = registeredEntities.begin(); it != registeredEntities.end(); it++)
    {
        if(it->id == entity.id)
        {
            registeredEntities.erase(it);
            return;
        }
    }
}

ComponentMask System::getSignature() 
{
    return signature;
}