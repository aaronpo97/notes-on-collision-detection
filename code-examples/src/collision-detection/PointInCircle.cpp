#include "Vec2.h"
#include <cmath>
#include <iostream>

struct Circle {
  Vec2  center;
  float radius;
};

bool pointInCircle(const Vec2 &point, const Circle &circle) {
  const float dx       = point.x - circle.center.x;
  const float dy       = point.y - circle.center.y;
  const float distance = std::sqrt(dx * dx + dy * dy);
  const bool  inside   = distance < circle.radius;
  return inside;
}

int main() {
  Circle circle = {{6, 6}, 3};
  Vec2   point  = {8, 6};
  if (pointInCircle(point, circle)) {
    std::cout << "Point lies within circle." << std::endl;
  } else {
    std::cout << "Point lies outside circle." << std::endl;
  }
  return 0;
}
