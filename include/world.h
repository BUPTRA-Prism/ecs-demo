#pragma once

#include "entitymanager.h"

class World {
private:
    EntityManager m_entityManager;

public:
    World() = default;

    Entity createEntity();
    bool destroyEntity(Entity entity);
    bool isValid(Entity entity) const;
    size_t aliveCount() const;
    void clear();
};