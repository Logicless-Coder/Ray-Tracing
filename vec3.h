#ifndef _VEC3_INCLUDED_
#define _VEC3_INCLUDED_

#include <ostream>

class Vec3 {
public:
  double x, y, z;

  Vec3();
  Vec3(double);
  Vec3(double, double, double);

  Vec3 operator-() const;

  Vec3 *operator+=(const Vec3);
  Vec3 *operator*=(const double);
  Vec3 *operator/=(const double);

  double length() const;
  double length_sq() const;

  friend std::ostream &operator<<(std::ostream &, const Vec3 &);

  Vec3 operator+(const Vec3 &);
  Vec3 operator-(const Vec3 &);
  Vec3 operator*(const Vec3 &);

  Vec3 operator*(double t) const;
  friend Vec3 operator*(double, const Vec3 &);
  Vec3 operator/(double t) const;

  double dot(const Vec3 &, const Vec3 &);
  Vec3 cross(const Vec3 &, const Vec3 &);

  Vec3 unit_vector() const;
};

using Point = Vec3;
using Color = Vec3;

#endif // !_VEC3_INCLUDED_
