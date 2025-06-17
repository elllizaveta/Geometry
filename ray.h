#ifndef INCLUDEIT_BUDU_TOGE_VSE
#define INCLUDEIT_BUDU_TOGE_VSE
#include "IShape.h"
#include "point.h"

namespace geometry {
  class Ray : public IShape {
   public:
    Point start;
    Vector direction;
     
    Ray() = default;
    Ray(const Point&, const Vector&);
    Ray(const Point&, const Point&);
    Ray(const Ray&);
    ~Ray() override = default;

    Ray& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Ray* Clone() const override;
    std::string ToString() const override;
  };
}  // namespace geometry

#endif