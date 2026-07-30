#include "entitymanager.h"

Entity::Entity(uint32_t index, uint32_t generation) : index(index), generation(generation) {}

uint32_t Entity::getIndex() const { return index; }
uint32_t Entity::getGeneration() const { return generation; }

bool Entity::operator==(const Entity& other) const { return index == other.index && generation == other.generation; }
bool Entity::operator!=(const Entity& other) const { return !(*this == other); }

Entity EntityManager::createEntity() {
    if (m_freeIndices.empty()) {
        m_generations.push_back(1);
        return Entity(static_cast<uint32_t>(m_generations.size() - 1), 1);
    } else {
        uint32_t index = m_freeIndices.back();
        m_freeIndices.pop_back();
        return Entity(index, m_generations[index]);
    }
}
bool EntityManager::destroyEntity(Entity entity) {
    if (!isValid(entity)) {
        return false;
    }
    m_freeIndices.push_back(entity.index);
    m_generations[entity.index]++;
    return true;
}
bool EntityManager::isValid(Entity entity) const {
    if (entity == INVALID_ENTITY) {
        return false;
    }
    if (entity.index >= static_cast<uint32_t>(m_generations.size())) {
        return false;
    }
    return m_generations[entity.index] == entity.generation;
}

size_t EntityManager::aliveCount() const { return m_generations.size() - m_freeIndices.size(); }
void EntityManager::clear() {
    m_generations.clear();
    m_freeIndices.clear();
}