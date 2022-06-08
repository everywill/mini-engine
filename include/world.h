#ifndef MINI_ENGINE_WORLD_H
#define MINI_ENGINE_WORLD_H

#include <iostream>
#include <memory>
#include "entityManager.h"
#include "system.h"
#include "componentManager.h"
#include "componentMask.h"
#include "componentHandle.h"

struct EntityHandle;

class World 
{
public: 
    explicit World(std::unique_ptr<EntityManager> entityManager);
    // should be invoked after constructor, but before first render
    void init();
    // update state before each rendering
    void update(int dt);

    void render();

    EntityHandle createEntity();
    void destroyEntity(Entity e);

    void addSystem(std::unique_ptr<System> system);

    template <typename ComponentType>
    void addComponent(Entity const & entity, ComponentType && component)
    {
        ComponentManager<ComponentType> *manager = getComponentManager<ComponentType>();
        manager->addComponent(entity, component);

        ComponentMask oldMask = entityMasks[entity];
        entityMasks[entity].addComponent<ComponentType>();

        updateEntityMask(entity, oldMask);
    }

    template <typename ComponentType>
    void removeComponent(Entity const & entity)
    {
        ComponentManager<ComponentType> *manager = getComponentManager<ComponentType>();
        manager->destroyComponent(entity);

        ComponentMask oldMask = entityMasks[entity];
        entityMasks[entity].removeComponent<ComponentType>();

        updateEntityMask(entity, oldMask);
    }

    template <typename ComponentType, typename... Args>
    void unpack(Entity e, ComponentHandle<ComponentType> & handle, ComponentHandle<Args> & ...args)
    {
        ComponentManager<ComponentType> * mgr = getComponentManager<ComponentType>();
        handle = ComponentHandle<ComponentType>(e, mgr->lookup(e), mgr);

        // recurse
        unpack<Args...>(e, args...);
    }

    template <typename ComponentType>
    void unpack(Entity e, ComponentHandle<ComponentType> & handle)
    {   
        auto mgr = getComponentManager<ComponentType>();
        handle = ComponentHandle<ComponentType>(e, mgr->lookup(e), mgr);
    }

private:
    std::unique_ptr<EntityManager> entityManager;
    std::vector<std::unique_ptr<System> > systems;
    std::vector<std::unique_ptr<BaseComponentManager> > componentManagers;
    std::map<Entity, ComponentMask> entityMasks;

    template <typename ComponentType>
    ComponentManager<ComponentType> * getComponentManager()
    {
        int family = GetComponentFamily<ComponentType>();

        if(family >= componentManagers.size())
        {
            componentManagers.resize(family+1);
        }

        if(!componentManagers[family])
        {   
            componentManagers[family] = std::make_unique<ComponentManager<ComponentType>>();
        }

        return static_cast<ComponentManager<ComponentType> *>(componentManagers[family].get());
    }

    void updateEntityMask(Entity const & entity, ComponentMask oldMask);
};
#endif