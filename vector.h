#ifndef YA_PISHU_TO_CHTO_YA_HOCHU
#define YA_PISHU_TO_CHTO_YA_HOCHU
#include <string>
#include <vector>
#include "vector.h"

// Vector
namespace geometry {
  struct Vector {
   public:
    int64_t x;
    int64_t y;

    Vector();
    Vector(int64_t, int64_t); 
    Vector(const Vector&) = default;
    ~Vector() = default;

    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    Vector& operator*=(const int64_t&);
    Vector& operator/=(const int64_t&);
    Vector operator+() const;
    Vector operator-() const;
    int64_t operator^(const Vector&) const;
    bool IsRightRotate(const Vector&) const;
    bool operator==(const Vector&) const;
    bool Collinear(const Vector&) const;
    bool SameDirection(const Vector&) const;
    int64_t LenghtSquared() const;
    std::string ToString() const;
  };

  Vector operator*(const Vector&, const int64_t&);
  Vector operator*(const int64_t&, const Vector&);
  Vector operator/(const Vector&, const int64_t&);
  Vector operator-(const Vector&, const Vector&);
  Vector operator+(const Vector&, const Vector&);

}  // namespace geometry

#endif