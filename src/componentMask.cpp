#include "componentMask.h"

bool ComponentMask::matches(ComponentMask systemMask)
{
    return ((mask & systemMask.mask) == systemMask.mask);
}

bool ComponentMask::isNewMatch(ComponentMask oldMask, ComponentMask systemMask)
{
    return matches(systemMask) && !oldMask.matches(systemMask);
}

bool ComponentMask::isNoLongerMatched(ComponentMask oldMask, ComponentMask systemMask)
{
    return !matches(systemMask) && oldMask.matches(systemMask);
}