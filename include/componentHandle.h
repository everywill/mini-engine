#ifndef MINI_ENGINE_COMPONENT_HANDLE_H
#define MINI_ENGINE_COMPONENT_HANDLE_H

#include "entity.h"
#include "componentManager.h"

template <typename ComponentType>
struct ComponentHandle
{
    using ExposedComponentType = typename ComponentManager<ComponentType>::LookupType;

    Entity owner;
    ExposedComponentType * component;
    ComponentManager<ComponentType> manager;

    ComponentHandle() {};
    ComponentHandle(Entity owner, ExposedComponentType *component, ComponentManager<ComponentType> * manager)
        : owner(owner), component(component), manager(manager) {};

    ExposedComponentType * operator->() const
    {
        return component;
    }

    void destroy() 
    {
        manager->destroyComponent(owner);
    }
};


#endif