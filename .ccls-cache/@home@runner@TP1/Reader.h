#pragma once
#include <iostream>
#include <string>
#include <vector>

class Reader {
private:
  std::string _firstName;
  std::string _lastName;
  std::string _reader_id;
  // vector contains isbn list of books borrowed by the reader
  std::vector<int> _borrowed_books;

public:
  Reader(std::string firstName, std::string lastName);
  // getters
  std::string get_name();
  std::vector<int> get_borrowed_books();

  //setters
  void add_borrowed_book(int isbn);
  // operator overloading
  friend std::ostream &operator<<(std::ostream &os, const Reader &r);
};
