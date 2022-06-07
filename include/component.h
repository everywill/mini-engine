#ifndef MINI_ENGINE_COMPONENT_H
#define MINI_ENGINE_COMPONENT_H

#include <type_traits>

struct ComponentCounter
{
    static int familyCounter;
};

template <typename ComponentType>
struct Component
{
    static inline int family()
    {
        static int family = ComponentCounter::familyCounter++;
        return family;
    }
};

template <typename C>
static int GetComponentFamily()
{
    return Comnent<typename std::remove_const<C>::type>::family();
}
#endif