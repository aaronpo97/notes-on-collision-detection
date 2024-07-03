#include "Vec2.h"
#include <cmath>
#include <iostream>

struct Circle {
  Vec2  center;
  float radius;
};

bool checkCollision(const Circle &c1, const Circle &c2) {
  const float dx         = c2.center.x - c1.center.x;
  const float dy         = c2.center.y - c1.center.y;
  const float distance   = std::sqrt(dx * dx + dy * dy);
  const float sumOfRadii = c1.radius + c2.radius;

  const bool collision = distance < sumOfRadii;
  return collision;
}

int main() {
  Circle c1 = {{5, 4}, 2};
  Circle c2 = {{7, 7}, 3};
  if (checkCollision(c1, c2)) {
    std::cout << "Collision detected!" << std::endl;
  } else {
    std::cout << "No collision detected." << std::endl;
  }
  return 0;
}
