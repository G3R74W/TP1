#include "Reader.h"

Reader::Reader(std::string firstName, std::string lastName)
    : _firstName(firstName), _lastName(lastName) {
  _reader_id = _firstName[1] + _lastName;
}
// getters
std::string Reader::get_name() {
  std::string full_name = _firstName + " " + _lastName;
  return full_name;
}

std::vector<int> Reader::get_borrowed_books() {
  // returns a vector containing the isbn numbers of all the borrowed books
  return _borrowed_books;
}

//setters
void Reader::add_borrowed_book(int isbn) {
  _borrowed_books.push_back(isbn);
}
// operator overloading
std::ostream &operator<<(std::ostream &os, const Reader &r) {
  os << "----------------------\n";
  os << "     READER INFO      \n";
  os << "----------------------\n";
  os << "\n";

  os << "First name : ";
  os << r._firstName;
  os << "\n";

  os << "Last name : ";
  os << r._lastName;
  os << "\n";

  os << "Reader id : ";
  os << r._reader_id;
  os << "\n";

  os << "Total number of books borrowed : ";
  os << r._borrowed_books.size();
  os << "\n";
  os << "Borrowed books isbn : ";
  if (r._borrowed_books.size() == 0) {
    os << "N/A";
    os << "\n";
  }
  for (int i = 0; i < r._borrowed_books.size(); i++) {
    os << r._borrowed_books[i];
    os << "\n";
  }

  os << "----------------------\n";
  os << "\n";

  return os;
}