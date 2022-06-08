#include "world.h"
#include "entityHandle.h"

World::World(std::unique_ptr<EntityManager> entityManager): entityManager(std::move(entityManager)) {}

EntityHandle World::createEntity()
{
    return {entityManager->createEntity(), this};
}

void World::destroyEntity(Entity entity)
{   
    for(auto & system : systems)
    {
        system->unRegisterEntity(entity);
    }
    entityManager->destroyEntity(entity);
}

void World::init()
{
    for(auto & system : systems)
    {
        system->init();
    }
}

void World::update(int dt)
{
    for(auto & system : systems)
    {
        system->update(dt);
    }
}

void World::render()
{
    for(auto & system : systems)
    {
        system->render();
    }
}

void World::addSystem(std::unique_ptr<System> system)
{   
    system->registerWorld(this);
    systems.push_back(std::move(system));
}

void World::updateEntityMask(Entity const & entity, ComponentMask oldMask)
{
    ComponentMask newMask = entityMasks[entity];
    for(auto & system : systems)
    {
        ComponentMask systemSignature = system->getSignature();
        if(newMask.isNewMatch(oldMask, systemSignature)) 
        {
             system->registerEntity(entity);
        }
        else if(newMask.isNoLongerMatched(oldMask, systemSignature))
        {
            system->unRegisterEntity(entity);
        }

    }
}