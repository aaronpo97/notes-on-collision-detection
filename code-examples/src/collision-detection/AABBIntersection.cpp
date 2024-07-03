#include "Vec2.h"
#include <iostream>

struct AABB {
  Vec2  topLeft;
  float width;
  float height;
};

bool checkAABBIntersection(const AABB &a, const AABB &b) {
  Vec2 bottomRightA = {a.topLeft.x + a.width, a.topLeft.y + a.height};
  Vec2 bottomRightB = {b.topLeft.x + b.width, b.topLeft.y + b.height};

  const bool horizontalOverlap =
      a.topLeft.x < bottomRightB.x && bottomRightA.x > b.topLeft.x;

  const bool verticalOverlap =
      a.topLeft.y < bottomRightB.y && bottomRightA.y > b.topLeft.y;

  const bool AABBIntersects = horizontalOverlap && verticalOverlap;

  return AABBIntersects;
}

int main() {
  AABB a = {{3, 3}, 5, 7};
  AABB b = {{7, 6}, 5, 10};

  if (checkAABBIntersection(a, b)) {
    std::cout << "AABBs intersect." << std::endl;
  } else {
    std::cout << "AABBs do not intersect." << std::endl;
  }

  return 0;
}
