#include <iostream>

enum class Color { red, blue, green };
enum class TrafficLight { green, yellow, red };

TrafficLight &operator++(TrafficLight &cur) {
  switch (cur) {
  case TrafficLight::green:
    return cur = TrafficLight::yellow;
  case TrafficLight::yellow:
    return cur = TrafficLight::red;
  case TrafficLight::red:
    return cur = TrafficLight::green;
  }
}

// Rather than having to type TrafficLight::x each time, can be abbreviated in a
// scope
TrafficLight &operator--(TrafficLight &cur) {
  // C++ 20 feature
  using enum TrafficLight;

  switch (cur) {
  case green:
    return cur = red;
  case yellow:
    return cur = green;
  case red:
    return cur = yellow;
  }
}

// If you do not want the need for explicit conversion, remove the class from
// enum class
//  This creates a plain enum
//  These are entered into the same scope as the name of their enum and
//  implicitly comvert to their integer values

enum PlainColor { red, green, blue };

int main(int argc, char *argv[]) {
  std::cout << "This Program is working as intended" << std::endl;
  Color col = Color::red; // Instantiates a color of red;
  TrafficLight light = TrafficLight::red;

  // We can also initialize an enum with a value from it's underlying type

  Color x = Color{2};
  Color y{1};

  // We can also go the other way

  int z = int(Color::red);
  std::cout << "z is: " << z << std::endl;

  // Using plain enums:
  PlainColor plain_enum = PlainColor::blue;
  std::cout << "Blue is represented as number: " << plain_enum << std::endl;

  return 0;
}
