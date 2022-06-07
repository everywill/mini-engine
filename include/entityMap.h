#ifndef MINI_ENGINE_ENTITY_MAP_H
#define MINI_ENGINE_ENTITY_MAP_H

#include <array>
#include <map>
#include "entity.h"

const int MAX_NUMBER_OF_COMPONENTS = 1024;
using ComponentInstance = unsigned int;

struct EntityMap
{
    Entity getEntity(ComponentInstance instance)
    {
        return instanceToEntity.at(instance);
    }

    ComponentInstance getInstance(Entity entity)
    {
        return entityToInstance.at(entity);
    }

    void add(Entity e, ComponentInstance ins)
    {
        entityToInstance.insert({e, ins});
        instanceToEntity.at(ins) = e;
    }

    void update(Entity e, ComponentInstance ins)
    {
        entityToInstance.at(e) = ins;
        instanceToEntity.at(ins) = e;
    }

    void remove(Entity e)
    {
        entityToInstance.erase(e);
    }

private:
    std::map<Entity, ComponentInstance> entityToInstance;
    std::array<Entity, MAX_NUMBER_OF_COMPONENTS> instanceToEntity;
};

#endif