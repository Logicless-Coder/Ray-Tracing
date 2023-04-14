#include "vec3.h"
#include <math.h>

Vec3::Vec3() { x = y = z = 0; }

Vec3::Vec3(double d) { x = y = z = 0; }

Vec3::Vec3(double _x, double _y, double _z) {
  x = _x;
  y = _y;
  z = _z;
}

Vec3 Vec3::operator-() const {
  Vec3 v = *this;
  v *= -1;
  return v;
}

Vec3 *Vec3::operator+=(const Vec3 other) {
  x += other.x;
  y += other.y;
  z += other.z;

  return this;
}

Vec3 *Vec3::operator*=(const double k) {
  x *= k;
  y *= k;
  z *= k;

  return this;
}

Vec3 *Vec3::operator/=(const double k) {
  x /= k;
  y /= k;
  z /= k;

  return this;
}

double Vec3::length() const { return sqrt(length_sq()); }

double Vec3::length_sq() const { return (x * x + y * y + z * z); }

std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
  return out << v.x << ' ' << v.y << ' ' << v.z;
}

Vec3 Vec3::operator+(const Vec3 &other) {
  return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) { return *this + -other; }

Vec3 Vec3::operator*(const Vec3 &other) {
  return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::operator*(double t) const { return Vec3(x * t, y * t, z * t); }
Vec3 operator*(double t, const Vec3 &other) { return other * t; }

Vec3 Vec3::operator/(double t) const { return Vec3(x / t, y / t, z / t); }

double Vec3::dot(const Vec3 &u, const Vec3 &v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vec3 Vec3::cross(const Vec3 &u, const Vec3 &v) {
  return Vec3(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
              u.x * v.y - u.y * v.x);
}

Vec3 Vec3::unit_vector() const { return *this / length(); }
