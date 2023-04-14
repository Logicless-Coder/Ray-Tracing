#ifndef _RAY_INCLUDED_
#define _RAY_INCLUDED_

#include "vec3.h"
class Ray {
private:
  Vec3 orig, dir;

public:
  Ray();
  Ray(const Point, const Vec3);

  Point at(const double);

  Vec3 origin() const;
  Vec3 direction() const;
};

#endif // !_RAY_INCLUDED_
