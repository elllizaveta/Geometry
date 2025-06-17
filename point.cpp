#include "../point.h"
#include "../vector.h"
#include "../ray.h"
#include "../segment.h"

namespace geometry {
  Point::Point() : x(0), y(0) {
  }

  Point::Point(int64_t a, int64_t b) : x(a), y(b) {
  }

  Vector operator-(const Point& end, const Point& start) {
    return {end.x - start.x, end.y - start.y};
  }

  Point& Point::Move(const Vector& vector) {
    x += vector.x;
    y += vector.y;
    return *this;
  }

  bool Point::ContainsPoint(const Point& point) const {
    return (point.x == x) && (point.y == y);
  }

  bool Point::CrossesSegment(const Segment& seg) const {
    if ((seg.x.x == seg.y.x) && (seg.x.y == seg.y.y)) {
      return ContainsPoint(seg.x); 
    }
    Ray a = {seg.y, seg.x};
    Ray b = {seg.x, seg.y};
    return a.ContainsPoint(*this) && b.ContainsPoint(*this);
  }

  Point* Point::Clone() const {
    auto copy = new Point(*this);
    return copy;
  }

  std::string Point::ToString() const {
    return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

}  // namespace geometry