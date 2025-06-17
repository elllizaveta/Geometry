#ifndef NADO_ODINAKOVIE_ILI_CHE
#define NADO_ODINAKOVIE_ILI_CHE
#include "vector.h"
#include <string>
#include <iostream>

// IShape

namespace geometry {
  class Point;
  class Segment;
  class IShape {
   public:
    virtual IShape& Move(const Vector&) = 0;
    virtual bool ContainsPoint(const Point&) const = 0;
    virtual bool CrossesSegment(const Segment&) const = 0;
    virtual IShape* Clone() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~IShape() = default;
  };
}  // namespace geometry

#endif