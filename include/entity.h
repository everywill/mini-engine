#ifndef MINI_ENGINE_ENTITY_H
#define MINI_ENGINE_ENTITY_H
struct Entity
{
    int id;

    bool operator<(const Entity& e2)
    {
        return id < e2.id;
    }
};

#endif