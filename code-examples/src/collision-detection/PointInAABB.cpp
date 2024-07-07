#include "Vec2.h"
#include <iostream>

struct AABB {
  Vec2  topLeft;
  float width;
  float height;
};

bool checkPointInAABB(const Vec2 &point, const AABB &rect) {

  const bool pointXCoordIsRightOfLeftEdge = point.x > rect.topLeft.x;

  const bool pointXCoordIsLeftOfRightEdge =
      point.x < rect.topLeft.x + rect.width;

  const bool pointYCoordIsBelowTopEdge = point.y > rect.topLeft.y;

  const bool pointYCoordIsAboveBottomEdge =
      point.y < rect.topLeft.y + rect.height;

  const bool pointInAABB =
      pointXCoordIsRightOfLeftEdge && pointXCoordIsLeftOfRightEdge &&
      pointYCoordIsBelowTopEdge && pointYCoordIsAboveBottomEdge;
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