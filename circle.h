#ifndef ILYA_TOGE_NICHEGO_NE_DELAET
#define ILYA_TOGE_NICHEGO_NE_DELAET
#include "IShape.h"
#include "point.h"

namespace geometry {
  class Circle : public IShape {
   public:
    Point center;
    int64_t r;
    
    Circle() = default;
    Circle(const Point&, int64_t);
    Circle(const Circle&);
    ~Circle() override = default;

    Circle& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Circle* Clone() const override;
    std::string ToString() const override;
    bool PerimetrContainPoint(const Point&) const;
  };
}  // namespace geometry

#endif