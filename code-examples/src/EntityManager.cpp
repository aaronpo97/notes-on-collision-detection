#include "Entity.h"
#include <memory>

// Store all entity objects in a vector.
typedef std::vector<std::shared_ptr<Entity>> EntityVector;

// Store separate vectors of Entity objects by their tag for quick
// retrieval.
typedef std::map<std::string, EntityVector> EntityMap;

class EntityManager {
  EntityVector m_entities;
  EntityVector m_toAdd;
  EntityMap    m_entityMap;
  size_t       m_totalEntities = 0;

public:
  EntityManager();
  std::shared_ptr<Entity> addEntity(const std::string &tag);
  EntityVector           &getEntities();
  EntityVector           &getEntities(const std::string &tag);
  void                    update();
};

EntityManager::EntityManager() :
    m_totalEntities(0) {}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
  auto e = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
  m_toAdd.push_back(e);
  return e;
}

EntityVector &EntityManager::getEntities() {
  return m_entities;
}
EntityVector &EntityManager::getEntities(const std::string &tag) {
  return m_entityMap[tag];
}

void EntityManager::update() {
  auto removeDeadEntities = [](EntityVector &entityVec) {
    entityVec.erase(
        std::remove_if(entityVec.begin(), entityVec.end(),
                       [](auto &entity) { return !entity->isActive(); }),
        entityVec.end());
  };

  // add all entities in the `m_toAdd` vector to the main entity vector
  for (const std::shared_ptr<Entity> &e : m_toAdd) {
    m_entities.push_back(e);
    m_entityMap[e->getTag()].push_back(e);
  }

  // Remove dead entities from the vector of all entities
  removeDeadEntities(m_entities);
  // Remove dead entities from each vector in the entity map
  for (auto &[tag, entityVec] : m_entityMap) {
    removeDeadEntities(entityVec);
  }
  m_toAdd.clear();
}
