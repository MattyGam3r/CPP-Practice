// Union is a struct that has all members allocated at the same address
//  The union occupies as much space as the largest data member
//  A union can only hold one data member at a time
#include <iostream>
#include <string>
#include <variant>

enum class Type { str, num };

union Value {
  std::string s;
  int i;
};
struct Entry {
  std::string name;
  Type t;
  // If the type is a num, use i, otherwise use s
  Value val;
};

// Issues here, firstly, we have to maintain correspondance as a programmer
//  Here, using a class with correct accessing logic to abstract away the
//  difficulties is best here

// An std::variant stores a value of one of a set of alternative types
//  variants can be used to eliminate most direct uses of unions

struct newEntry {
  std::string name;
  std::variant<std::string, int> v;
};

void find(newEntry *pe) {
  if (std::holds_alternative<int>(pe->v)) {
    // It holds an int!
    std::cout << "we have an integer in here" << std::endl;
  } else if (std::holds_alternative<std::string>(pe->v)) {
    std::cout << "we have a string in here" << std::endl;
  }
}

int main() {
  newEntry newentry{"My Name", "I am a string type"};

  find(&newentry);
  // EXCPETED: "we have a string in here"

  newEntry intentry{"New name", 1};

  find(&intentry);
  // EXPECTED: "we have in int in here"

  return EXIT_SUCCESS;
}
