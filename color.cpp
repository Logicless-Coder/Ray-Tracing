#include <ostream>

#include "vec3.h"

void print_color(std::ostream &out, Color c) {
  out << static_cast<int>(255.999 * c.x) << ' '
      << static_cast<int>(255.999 * c.y) << ' '
      << static_cast<int>(255.999 * c.z) << '\n';
}
