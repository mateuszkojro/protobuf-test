#include "example.pb.h"
#include <iostream>
#include <string>

int main() {
  example::Person person;
  person.set_name("Mateusz");
  person.set_fraction(12.1);
  for (int i = 0; i < 10; i++) {
    auto phone = person.add_phones();
    phone->set_number(std::to_string(i));
    phone->set_type(example::Person::PhoneType::Person_PhoneType_WORK);
  }
  std::cout << person.DebugString() << std::endl;
}