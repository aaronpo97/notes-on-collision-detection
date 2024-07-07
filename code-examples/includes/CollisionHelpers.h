#include "Vec2.h"
#include <cmath>
#ifndef COLLISION_HELPERS_H
#define COLLISION_HELPERS_H

namespace CollisionHelpers {
  struct Circle {
    Vec2  center;
    float radius;
  };

  inline bool checkCollision(const Circle &c1, const Circle &c2) {
    const float dx         = c2.center.x - c1.center.x;
    const float dy         = c2.center.y - c1.center.y;
    const float distance   = std::sqrt(dx * dx + dy * dy);
    const float sumOfRadii = c1.radius + c2.radius;

    const bool collision = distance < sumOfRadii;
    return collision;
  }
} // namespace CollisionHelpers

#endif // COLLISION_HELPERS_H
