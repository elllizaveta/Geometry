#include "../segment.h"

#include "../point.h"
#include "../line.h"
#include <cmath>

namespace geometry {
  Segment::Segment(const Point& a, const Point& b) : x(a), y(b) {}

  Segment::Segment(const Segment& other) : x(other.x), y(other.y) {}

  Segment& Segment::Move(const Vector& vector) {
    x.Move(vector);
    y.Move(vector);
    return *this;
  }

  bool Segment::ContainsPoint(const Point& point) const {
    return point.CrossesSegment(*this);
  }

  bool Segment::CrossesSegment(const Segment& other) const {
    if (ContainsPoint(other.x) || ContainsPoint(other.y) ||
        other.ContainsPoint(x) || other.ContainsPoint(y)) {
      return true;
    }
    return !SameHalf(other) && !other.SameHalf(*this);
  }

  int64_t Segment::OrientedAreaX2(const Point& point) const {
    return (x.x - point.x) * (y.y - point.y) - (y.x - point.x) * (x.y - point.y);
  }

  bool Segment::SameHalf(const Segment& other) const {
    return OrientedAreaX2(other.x) * OrientedAreaX2(other.y) >= 0;
  }

  Segment* Segment::Clone() const {
    auto copy = new Segment(*this);
    return copy;
  }

  std::string Segment::ToString() const {
    return "Segment(" + x.ToString() + ", " + y.ToString() + ")";
  }

  double Segment::PointSegmentDistance(const Point& point) const {
    Vector v_a = point - x;
    Vector v_b = point - y;
    Vector v = y - x;
    if (v_a.x * v.x + v_a.y * v.y <= 0) {
      return sqrt(v_a.x * v_a.x + v_a.y * v_a.y);
    }
    if (v_b.x * v.x + v_b.y * v.y >= 0) {
      return sqrt(v_b.x * v_b.x + v_b.y * v_b.y);
    }
    Line line(x, y);
    return line.PointLineDistance(point);
  }

}  // namespace geometry