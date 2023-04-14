#include "ray.h"
#include "vec3.h"

Ray::Ray() { orig = dir = Vec3(); }

Ray::Ray(const Point origin, const Vec3 direction) {
  orig = origin;
  dir = direction;
}

Point Ray::at(const double t) { return orig + t * dir; }

Vec3 Ray::origin() const { return orig; }

Vec3 Ray::direction() const { return dir; }
