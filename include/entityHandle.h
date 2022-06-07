#ifndef MINI_ENGINE_ENTITY_HANDLE_H
#define MINI_ENGINE_ENTITY_HANDLE_H

#include "entity.h"
#include "world.h"

struct EntityHandle
{
public:
    Entity entity;
    World * world;

    void destroy()
    {
        world->destroyEntity(entity);
    }

    template <typename ComponentType>
    void addComponent(ComponentType && component)
    {
        world->addComponent<ComponentType>(entity, std::forward<ComponentType>(component));
    }

    template <typename ComponentType>
    void removeComponent()
    {
        world->removeComponent<ComponentType>(entity);
    }
};

#endif