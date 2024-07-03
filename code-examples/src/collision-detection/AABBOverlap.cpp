#include "Vec2.h"
#include <iostream>

struct AABB {
  Vec2  center;
  float width;
  float height;
};

bool checkAABBOverlap(const AABB &a, const AABB &b) {
  const auto delta   = Vec2(std::abs(a.center.x - b.center.x),
                            std::abs(a.center.y - b.center.y));
  const auto overlap = Vec2((a.width / 2) + (b.width / 2) - delta.x,
                            (a.height / 2) + (b.height / 2) - delta.y);

  const bool overlapX = overlap.x > 0;
  const bool overlapY = overlap.y > 0;

  const bool AABBsIntersect = overlapX && overlapY;

  return AABBsIntersect;
}

int main() {
  AABB a = {{3, 3}, 5, 7};
  AABB b = {{7, 6}, 5, 10};

  if (checkAABBOverlap(a, b)) {
    std::cout << "AABBs intersect." << std::endl;
  } else {
    std::cout << "AABBs do not intersect." << std::endl;
  }

  return 0;
}