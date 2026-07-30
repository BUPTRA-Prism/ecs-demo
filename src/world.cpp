#include "world.h"

Entity World::createEntity() { return m_entityManager.createEntity(); }
bool World::destroyEntity(Entity entity) { return m_entityManager.destroyEntity(entity); }
bool World::isValid(Entity entity) const { return m_entityManager.isValid(entity); }
size_t World::aliveCount() const { return m_entityManager.aliveCount(); }
void World::clear() { m_entityManager.clear(); }