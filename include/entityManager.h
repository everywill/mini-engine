#ifndef MINI_ENGINE_ENTITY_MANAGER_H
#define MINI_ENGINE_ENTITY_MANAGER_H
#include "entity.h";

class EntityManager {
public:
    Entity createEntity();
    void destroyEntity(Entity e);

private:
    int lastEntityId = 0;
};
#endif