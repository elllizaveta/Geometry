#ifndef TI_NICHEGO_NE_PONYALAAAAA
#define TI_NICHEGO_NE_PONYALAAAAA
#include "IShape.h"
#include "point.h"

namespace geometry {
  class Segment : public IShape {
   public:
    Point x;
    Point y;
    
    Segment() = default;
    Segment(const Point&, const Point&);
    Segment(const Segment&);
    ~Segment() override = default;

    Segment& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Segment* Clone() const override;
    std::string ToString() const override;
    double PointSegmentDistance(const Point&) const;

   private:
    bool SameHalf(const Segment&) const;
    int64_t OrientedAreaX2(const Point&) const;
  };
}  // namespace geometry

#endif