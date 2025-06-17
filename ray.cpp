#include "../ray.h"
#include "../segment.h"
#include "../vector.h"
#include "../line.h"
#include "../point.h"

namespace geometry {
  Ray::Ray(const Point& a, const Vector& b) : start(a), direction(b) {
  }

  Ray::Ray(const Point& a, const Point& b) : start(a), direction(b - a) {
  }

  Ray::Ray(const Ray& other) : start(other.start), direction(other.direction) {
  }

  Ray& Ray::Move(const Vector& vector) {
    start.Move(vector);
    return *this;
  }

  bool Ray::ContainsPoint(const Point& point) const {
    Point second = start;
    second.Move(direction);
    Line line = {start, second};
    if (!line.ContainsPoint(point)) {
      return false;
    }
    return (direction.SameDirection(point - start));
  }

  bool Ray::CrossesSegment(const Segment& seg) const {
    if (ContainsPoint(seg.x) || ContainsPoint(seg.y) ||
        seg.ContainsPoint(start)) {
      return true;
    }
    Vector a = (seg.x - start);
    Vector b = (seg.y - start);
    Vector c = direction;
    if (a.IsRightRotate(b) == 0 && a.IsRightRotate(c) == 0 && c.IsRightRotate(b) == 0) {
      return false;
    }
    return (a.IsRightRotate(b) == a.IsRightRotate(c)) && (c.IsRightRotate(b) == a.IsRightRotate(b));
  }

  Ray* Ray::Clone() const {
    auto copy = new Ray(*this);
    return copy;
  }

  std::string Ray::ToString() const {
    return "Ray(" + start.ToString() + ", " + direction.ToString() + ")";
  }

}  // namespace geometry