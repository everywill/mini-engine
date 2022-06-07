#ifndef MINI_ENGINE_COMPONENT_MASK_H
#define MINI_ENGINE_COMPONENT_MASK_H

#include "component.h"

struct ComponentMask
{
    unsigned int mask = 0;

    template <typename ComponentType>
    void addComponent()
    {
        mask |= (1 << GetComponentFamily<ComponentType>());
    }

    template <typename ComponentType>
    void removeComponent()
    {
        mask &= ~(1 << GetComponentFamily<ComponentType>());
    }

    // current mask matched systemMask or not
    bool matches(ComponentMask systemMask);

    bool isNewMatch(ComponentMask oldMask, ComponentMask systemMask);

    bool isNoLongerMatched(ComponentMask oldMask, ComponentMask systemMask);
};

#endif