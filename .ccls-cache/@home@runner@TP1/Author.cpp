#include "Author.h"

Author::Author(std::string firstName, std::string lastName, Date birth_date)
    : _firstName(firstName), _lastName(lastName), _birth_date(birth_date) {
  // create author id
}

// getters
std::string Author::get_author_id() { return _author_id; }

// operator overloading
friend std::ostream &operator<<(std::ostream &os, const Author &a) {

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