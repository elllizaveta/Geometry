#include "../circle.h"

#include "../point.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
  int64_t SquarePow(const int64_t& x) {
    return x * x;
  }

  Circle::Circle(const Point& point, int64_t chiselka)
      : center(point), r(chiselka) {}

  Circle::Circle(const Circle& other) : center(other.center), r(other.r) {}

  Circle& Circle::Move(const Vector& vector) {
    center.Move(vector);
    return *this;
  }

  bool Circle::ContainsPoint(const Point& point) const {
    return (point - center).LenghtSquared() <= r * r;
  }

  bool Circle::PerimetrContainPoint(const Point& point) const {
    return (SquarePow(center.x - point.x) + SquarePow(center.y - point.y)) == SquarePow(r);
  }

  bool Circle::CrossesSegment(const Segment& seg) const {
    if (PerimetrContainPoint(seg.x) || PerimetrContainPoint(seg.y)) {
      return true;
    }
    if (ContainsPoint(seg.x) && ContainsPoint(seg.y)) {
      return false;
    }
    if (ContainsPoint(seg.x) || ContainsPoint(seg.y)) {
      return true;
    }
    return (static_cast<int64_t>(seg.PointSegmentDistance(center)) <= r);
  }

  Circle* Circle::Clone() const {
    auto copy = new Circle(*this);
    return copy;
  }

  std::string Circle::ToString() const {
    std::string output = "Circle(";
    output += center.ToString() + ", " + std::to_string(r) + ")";
    return output;
  }

}  // namespace geometry