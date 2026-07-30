#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

class EntityManager;
class World;

class Entity {
private:
    uint32_t index;
    uint32_t generation;

    friend class EntityManager;

    explicit Entity(uint32_t index, uint32_t generation);

public:
    uint32_t getIndex() const;
    uint32_t getGeneration() const;
    bool operator==(const Entity& other) const;
    bool operator!=(const Entity& other) const;
};

class EntityManager {
private:
    std::vector<uint32_t> m_generations;
    std::vector<uint32_t> m_freeIndices;

    friend class World;

    EntityManager() = default;
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    Entity createEntity();
    bool destroyEntity(Entity entity);
    bool isValid(Entity entity) const;
    size_t aliveCount() const;
    void clear();
};