#ifndef MINI_ENGINE_SYSTEM_H
#define MINI_ENGINE_SYSTEM_H

#include <vector>
#include "entity.h"
#include "componentMask.h"

class System 
{
public:
    // tell compiler to generate default constructor/destructor
    System() = default;
    virtual ~System() = default;
    // tell compiler to generate default copy constructor/assignment
    System(const System &) = default;
    System & operator=(const System &) = default;
    // tell compiler to generate defult move constructor/assignment
    System(System &&) = default;
    System & operator=(System &&) = default;

    virtual void init() {};
    // update state every frame
    virtual void update(int dt) {};

    virtual void render() {};

    void registerEntity(Entity const & entity);

    void unRegisterEntity(Entity const & entity);

    ComponentMask getSignature();

protected:
    std::vector<Entity> registeredEntities;
    ComponentMask signature;
};
#endif