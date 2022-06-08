#include "entityManager.h"

Entity EntityManager::createEntity()
{
    return {lastEntity++};
}

void EntiryManager::destroyEntity(Entity e) {}