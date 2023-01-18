#include "Author.h"

Author::Author(std::string firstName, std::string lastName, Date birth_date)
    : _firstName(firstName), _lastName(lastName), _birth_date(birth_date) {
  std::string birthYear = std::to_string(_birth_date.year());
  _author_id = _firstName[1] + _lastName + birthYear;
}

// getters
std::string Author::get_author_id() { return _author_id; }

std::string Author::get_author_name() {
  std::string full_name = _firstName + " " + _lastName;
  return full_name;
}
// operator overloading
std::ostream &operator<<(std::ostream &os, const Author &a) {

  os << "First name : ";
  os << a._firstName;
  os << "\n";

  os << "Last name : ";
  os << a._lastName;
  os << "\n";

  os << "Date of birth : ";
  os << a._birth_date;
  os << "\n";

  return os;
}