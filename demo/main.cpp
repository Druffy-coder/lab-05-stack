// Copyright 2022 Semenihin Dmitriy <SemenihinDmit@yandex.ru>

#include <fisex.hpp>

#include "iostream"
#include "secex.hpp"

class SomeType {
 private:
  int f;
  double ft;

 public:
  SomeType() {
    f = -1;
    ft = -1;
  }

  SomeType(int fi) {
    this->f = fi;
    this->ft = 0;
  }

  SomeType(int fi, double fth) {
    this->f = fi;
    this->ft = fth;
  }

  bool operator!() const {
    if (this->f != -1) {
      return false;
    }
    if (this->ft != -1) {
      return false;
    }
    return true;
  };


  SomeType& operator=(SomeType* right) noexcept {
    f = right->f;
    ft = right->ft;
    return *this;
  }


  SomeType& operator=(const SomeType& right) = default;


  void print() const {
    std::cout << f << " " << ft << std::endl;
  }


  std::string string() const {
    std::string a = std::to_string(f) + " " + std::to_string(ft);
    return a;
  }
};


int main() {
  StackSec<SomeType> stack2(SomeType{11 });
  stack2.head().print();
  stack2.push_emplace(22, 22.0);
  stack2.head().print();
  stack2.push_emplace(33, 33.0);
  stack2.head().print();
  stack2.push_emplace(44, 44.0);
  stack2.head().print();
  stack2.push_emplace(55);
  stack2.head().print();
  stack2 = StackSec<SomeType>(123);
  stack2.push_emplace(2223, 2223.0);
  stack2.push_emplace(3354, 3354.0);
  stack2.head().print();
  std::string a = stack2.head().string();
  std::cout << a << std::endl;
}
