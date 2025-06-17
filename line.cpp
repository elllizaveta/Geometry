#include "../line.h"
#include "../vector.h"
#include "../point.h"
#include "../segment.h"
#include <cmath>

namespace geometry {
  Line::Line(int64_t x, int64_t y, int64_t z) : a(x), b(y), c(z) {
  }

  Line::Line(const Point& x, const Point& y) : a(y.y - x.y), b(x.x - y.x) {
    c = -(a * x.x + b * x.y);
  }

  Line::Line(const Line& other) : a(other.a), b(other.b), c(other.c) {
  }

  Line& Line::Move(const Vector& vector) {
    c -= a * vector.x + b * vector.y;
    return *this;
  }

  bool Line::ContainsPoint(const Point& point) const {
    return a * point.x + b * point.y + c == 0;
  }

  bool Line::CrossesSegment(const Segment& seg) const {
    return (a * seg.x.x + b * seg.x.y + c) * (a * seg.y.x + b * seg.y.y + c) <= 0;
  }

  Line* Line::Clone() const {
    auto copy = new Line(*this);
    return copy;
  }

  std::string Line::ToString() const {
    return "Line(" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ")";
  }

  double Line::PointLineDistance(const Point& point) const {
    auto res = (a * point.x + b * point.y + c) / (sqrt(a * a + b * b));
    return res > 0 ? res : -res;
  }

}  // namespace geometry