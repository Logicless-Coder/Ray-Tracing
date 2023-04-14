#include <iomanip>
#include <iostream>
#include <ostream>

#include "color.h"
#include "ray.h"
#include "vec3.h"

Color ray_color(const Ray &r) {
  Vec3 unit_direction = r.direction().unit_vector();
  auto t = 0.5 * (unit_direction.y + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main(int argc, char *argv[]) {

  const double ASPECT_RATIO = 16.0 / 9;
  int IMAGE_WIDTH = 64, IMAGE_HEIGHT = 36;

  if (argc > 1) {
    IMAGE_WIDTH = atoi(argv[1]);
    IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);
  }

  const double VIEWPORT_HEIGHT = 2.0;
  const double VIEWPORT_WIDTH = VIEWPORT_HEIGHT * ASPECT_RATIO;
  const double FOCAL_LENGTH = 1.0;

  Point origin = Point();
  Vec3 horizontal = Vec3(VIEWPORT_WIDTH, 0, 0);
  Vec3 vertical = Vec3(0, VIEWPORT_HEIGHT, 0);
  Point lower_left_corner =
      origin - horizontal / 2.0 - vertical / 2.0 - Vec3(0, 0, FOCAL_LENGTH);

  std::cout << "P3\n";
  std::cout << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n";
  std::cout << "255\n";

  for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
    for (int i = 0; i < IMAGE_WIDTH; ++i) {
      std::cerr << "\rDone: " << std::setw(8) << i * 100.0 / (IMAGE_HEIGHT - 1)
                << "%" << std::flush;

      auto u = double(i) / (IMAGE_HEIGHT - 1);
      auto v = double(j) / (IMAGE_WIDTH - 1);

      Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      Color pixel = ray_color(r);
      print_color(std::cout, pixel);
    }
    std::cout << '\n';
  }
  std::cerr << std::endl;

  return 0;
}
