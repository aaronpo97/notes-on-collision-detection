#include "Vec2.h"
#include <iostream>

struct AABB {
  Vec2  c;
  float width;
  float height;
};

bool checkPointInAABB(const Vec2 &point, const AABB &rect) {
  const bool pointInAABB =
      point.x > rect.c.x && point.x < rect.c.x + rect.width &&
      point.y > rect.c.y && point.y < rect.c.y + rect.height;

  return pointInAABB;
}

int main() {
  AABB rect  = {{5, 5}, 10, 10};
  Vec2 point = {6, 6};
  if (checkPointInAABB(point, rect)) {
    std::cout << "Point lies within AABB." << std::endl;
  } else {
    std::cout << "Point lies outside AABB." << std::endl;
  }
  return 0;
}