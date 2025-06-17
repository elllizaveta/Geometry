#include "../polygon.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
  Polygon::Polygon(const std::vector<Point>& polygon) : points(polygon) {
  }

  Polygon::Polygon(const Polygon& other) : points(other.points) {
  }

  Polygon& Polygon::Move(const Vector& vector) {
    for (size_t i = 0; i < points.size(); ++i) {
      points[i].Move(vector);
    }
    return *this;
  }

  bool Polygon::ContainsPoint(const Point& point) const {
    const int64_t chiselka = 1e7;
    Point center_point = {chiselka + 1, point.y + 1};
    Segment center_line = {center_point, point};
    bool count_is_even = true;
    for (size_t i = 0; i < points.size(); ++i) {
      Segment line = {points[i], points[(i + 1) % points.size()]};
      if (center_line.CrossesSegment(line)) {
        if (line.ContainsPoint(point)) {
          return true;
        }
        if (center_line.ContainsPoint(line.x)) {
          continue;
        }
        count_is_even = !count_is_even;
      }
    }
    return !count_is_even;
  }

  bool Polygon::CrossesSegment(const Segment& seg) const {
    for (size_t i = 0; i < points.size(); ++i) {
      Segment edge = {points[i], points[(i + 1) % points.size()]};
      if (edge.CrossesSegment(seg)) {
        return true;
      }
    }
    return false;
  }

  Polygon* Polygon::Clone() const {
    auto copy = new Polygon(*this);
    return copy;
  }

  std::string Polygon::ToString() const {
    std::string output = "Polygon(";
    for (auto point : points) {
      output += point.ToString() + ", ";
    }
    output.pop_back();
    output.pop_back();
    output.push_back(')');
    return output;
  }

}  // namespace geometry