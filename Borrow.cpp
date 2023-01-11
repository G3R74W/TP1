#include "Borrow.h"

Borrow::Borrow(Date borrow_date, Reader reader, Book book)
    : _borrow_date(borrow_date), _reader(reader), _book(book) {
      _away = true;
      _book.set_available(_away);
    }

// getter
Date Borrow::get_borrow_date() { return _borrow_date; }
Reader Borrow::get_reader() { return _reader; }
Book Borrow::get_book() { return _book; }
bool Borrow::get_away() { return _away;}

// setter
void Borrow::set_away(std::string lastName, std::string firstName){
    std::string fullname = firstName + " " + lastName;
    std::string reserv_name = _reader.get_name();
    if(fullname == reserv_name){
      _away = false;
      _book.set_available(_away);
    }
    else{
      std::cout << "Cette réservation n'est pas à ce nom. \n";
      }
}

// operator overloading
std::ostream &operator<<(std::ostream &os, const Borrow &bw) {
  os << "----------------------\n";
  os << "----------------------\n";
  os << "----------------------\n";
  os << "       LOAN INFO      \n";
  os << "----------------------\n";
  os << "\n";

  os << "Borrowed book : \n";
  os << bw._book;
  os << "\n";

  os << "Date the book was borrowed : ";
  os << bw._borrow_date;
  os << "\n";

  os << "Reader : \n";
  os << bw._reader;

  os << "----------------------\n";
  os << "----------------------\n";
  return os;
}