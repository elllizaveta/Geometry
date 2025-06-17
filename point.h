#ifndef LA_LA_LA_LA
#define LA_LA_LA_LA
#include "IShape.h"

namespace geometry {
  class Point : public IShape {
   public:
    int64_t x;
    int64_t y;

    Point();
    Point(int64_t a, int64_t b);
    ~Point() override = default;

    Point& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Point* Clone() const override;
    std::string ToString() const override;
  };
  
  Vector operator-(const Point& end, const Point& start);

}  // namespace geometry

#endif