#ifndef MINI_ENGINE_COMPONENT_MANAGER_H
#define MINI_ENGINE_COMPONENT_MANAGER_H

#include <memory>
#include "entityMap.h"

template <typename ComponentType>
struct ComponentData
{
    unsigned int size = 1;
    std::array<ComponentType, MAX_NUMBER_OF_COMPONENTS> *data;
};

class BaseComponentManager
{
public:
    BaseComponentManager() = default;
    ~BaseComponentManager() = default;
    BaseComponentManager(const BaseComponentManager &) = default;
    BaseComponentManager & operator=(const BaseComponentManager &) = default;
    BaseComponentManager(BaseComponentManager &&) = default;
    BaseComponentManager & operator=(BaseComponentManager &&) = default;
};

template <typename ComponentType>
class ComponentManager : public BaseComponentManager
{
public:
    using LookupType = ComponentType;

    ComponentManager()
    {
        componentData.data = static_cast<std::array<ComponentType, MAX_NUMBER_OF_COMPONENTS> *>(malloc(sizeof(ComponentType) * MAX_NUMBER_OF_COMPONENTS));
    }

    ComponentInstance addComponent(Entity e, ComponentType c)
    {
        ComponentInstance newInstance = componentData.size++;
        componentData.data->at(newInstance) = c;
        entityMap.add(e, newInstance);
        return newInstance;
    }

    void destroyComponent(Entity e)
    {
        ComponentInstance instance = entityMap.getInstance(e);

        // move last component to the deleted position
        ComponentInstance lastInstance = componentData.size - 1;
        componentData.data[instance] = componentData.data[lastInstance];
        Entity lastEntity = entityMap.getEntity(lastInstance);

        entityMap.remove(e);
        entityMap.update(lastEntity, instance);

        componentData.size --;
    }

    LookupType * lookup(Entity entity)
    {
        ComponentInstance instance = entityMap.getInstance(entity);
        return &(componentData.data->at(instance));
    }

private:
    ComponentData<ComponentType> componentData;
    EntityMap entityMap;
};

#endif