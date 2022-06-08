#include "entityManager.h"

Entity EntityManager::createEntity()
{
    return {lastEntityId++};
}

void EntityManager::destroyEntity(Entity e) {}