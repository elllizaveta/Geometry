#ifndef UUUUUU_AGAAAAAAA
#define UUUUUU_AGAAAAAAA
#include "IShape.h"

namespace geometry {
  class Line : public IShape {
   public:
    int64_t a;
    int64_t b;
    int64_t c;

    Line() = default;
    Line(int64_t, int64_t, int64_t);
    Line(const Point&, const Point&);
    Line(const Line&);
    ~Line() override = default;

    Line& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Line* Clone() const override;
    std::string ToString() const override;
    double PointLineDistance(const Point&) const;
  };
}  // namespace geometry

#endif