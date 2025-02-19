// include preproc stuff if part of  namespace uses this instead of .h
// eg c++ std
#include <iostream>
#include <limits>
#include <ostream>
#include <string>

// eg c std
// #include <stdlib.h>

// eg user defined
// #include "myfile.h"

// globals at top of file;
float pi = 3.14159265;

// classes
class MyClass {
public:
  MyClass();
  MyClass(MyClass &&) = default;
  MyClass(const MyClass &) = default;
  MyClass &operator=(MyClass &&) = default;
  MyClass &operator=(const MyClass &) = default;
  ~MyClass();

private:
};

MyClass::MyClass() {}

MyClass::~MyClass() {}

int GetLargerNumber(int num1, int num2) {

  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }
}

int main(int argc, char *argv[]) {

  // could put "using namespace std;" to avoid the  prefix needed;
  // explicit makes things a little easier
  std::cout << "Here is some text.\n";

  // these are some standard in functions in c++, changing limits and clearing.
  std::cin.clear(); // clear stdin
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                  '\n'); // ignore anything but enter
  std::cin.get();        // grab a character

  // double colon is a "scope resolution operator"... basically the same as
  // "x.y()" in Java
  //:: at start means look in global namespace, X:: means look in namespace of X
  //: for thing after.
  // no leading :: means "use our current namespace" within context of code.

  // string is weird in cpp
  std::string message = "Hello World!";

  // std::endl does "flush output stream", like enter but not
  std::cout << message + "\n" << std::endl;

  // variables tend to be lowercase
  long user_id = 0;

  // user defined class names should be uppercase
  // LinkedList

  for (int i = 1; i <= 100; i++) {
    std::string word = "";
    if (i % 3 == 0) {
      word += "Fizz";
    }

    if (i % 5 == 0) {
      word += "Buzz";
    }

    if (word.length() == 0) {
      word = "None!";
    }

    std::cout << word << "\n";
  }

  // can you manual flush like this? Empty buffer and write to out
  std::cout << std::endl;

  // I want to check post inc-dec-rement stuff
  int a = 3;
  int sum = 0;
  for (; a < 7; ++a) {
    sum += a;
  }
  for (; a > 0; --a) {
    sum += a;
  }

  for (; a < 7; a++) {
    sum += a;
  }
  for (; a > 0; a--) {
    sum += a;
  }

  std::cout << sum << std::endl;

  return 0;
}
