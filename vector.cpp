#include "../vector.h"
#include <cmath>
#include "vector.h"

namespace geometry {
  Vector::Vector() : x(0), y(0) {
  }

  Vector::Vector(int64_t a, int64_t b) : x(a), y(b) {
  }

  Vector Vector::operator+() const {
    return *this;
  }

  Vector Vector::operator-() const {
    Vector copy = *this;
    copy.x *= -1;
    copy.y *= -1;
    return copy;
  }

  Vector& Vector::operator+=(const Vector& other) {
    x += other.x;
    y += other.y;
    return *this;
  } 

  Vector& Vector::operator-=(const Vector& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  Vector& Vector::operator*=(const int64_t& other) {
    x *= other;
    y *= other;
    return *this;
  }

  Vector& Vector::operator/=(const int64_t& other) {
    x /= other;
    y /= other;
    return *this;
  }

  Vector operator*(const Vector& vector, const int64_t& k) {
    Vector ans = vector;
    return ans *= k;
  }

  Vector operator*(const int64_t& k, const Vector& vector) {
    Vector ans = vector;
    return ans *= k;
  }

  Vector operator/(const Vector& vector, const int64_t& k) {
    Vector ans = vector;
    return ans /= k;
  }

  Vector operator-(const Vector& first, const Vector& second) {
    Vector ans = first;
    return ans -= second;
  }

  Vector operator+(const Vector& first, const Vector& second) {
    Vector ans = first;
    return ans += second;
  }

  bool Vector::operator==(const Vector& other) const {
    return (x == other.x) && (y == other.y);
  }

  bool Vector::Collinear(const Vector& other) const {
    return (x * other.y == y * other.x);
  }

  bool Vector::SameDirection(const Vector& other) const {
    if (!Collinear(other)) {
      return false;
    }
    if ((x == 0 && y == 0) || (other.x == 0 && other.y == 0)) {
      return true;
    }
    return ((x > 0) == (other.x > 0)) && ((y > 0) == (other.y > 0));
  }

  int64_t Vector::operator^(const Vector& other) const {
    return x * other.y - y * other.x;
  }

  bool Vector::IsRightRotate(const Vector& other) const {
    return (*this ^ other) > 0;
  }

  int64_t Vector::LenghtSquared() const {
    return x * x + y * y;
  }

  std::string Vector::ToString() const {
    return "Vector(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

}  // namespace geometry