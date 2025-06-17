#ifndef MATVEY_FIGNEY_STRADAET_EMU_REJECT
#define MATVEY_FIGNEY_STRADAET_EMU_REJECT
#include "IShape.h"

namespace geometry {
  class Polygon : public IShape {
   public:
    std::vector<Point> points;

    Polygon() = default;
    explicit Polygon(const std::vector<Point>&);
    Polygon(const Polygon&);
    ~Polygon() override = default;

    Polygon& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Polygon* Clone() const override;
    std::string ToString() const override;
  };
}  // namespace geometry

#endif