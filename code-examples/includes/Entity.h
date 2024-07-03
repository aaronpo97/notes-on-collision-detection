#include "Components.h"
class Entity {
private:
  friend class EntityManager;
  bool        m_active = true;
  size_t      m_id     = 0;
  std::string m_tag    = "default";

  Entity(const size_t id, const std::string &tag);

public:
  // component pointers
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CShape>     cShape;
  std::shared_ptr<CCollision> cCollision;

  // private member access functions
  bool               isActive() const;
  const std::string &getTag() const;
  size_t             getId() const;
  void               destroy();
};