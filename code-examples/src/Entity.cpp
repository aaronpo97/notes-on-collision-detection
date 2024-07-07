
#include "../includes/Entity.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

Entity::Entity(const size_t id, const std::string &tag) :
    m_id(id), m_tag(tag) {}

const std::string &Entity::getTag() const {
  return m_tag;
}

size_t Entity::getId() const {
  return m_id;
}

void Entity::destroy() {
  m_active = false;
}

bool Entity::isActive() const {
  return m_active;
}