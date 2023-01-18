#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Book.h"
#include "Reader.h"

class Borrow {
private :
  Date _borrow_date;
  Reader * _reader;
  Book * _book;
  bool _away;
public :
  Borrow(Date borrow_date, Reader &reader, Book &book);

  //getter
  Date get_borrow_date();
  Reader get_reader();
  Book get_book();
  bool get_away();
  void set_away(std::string lastname, std::string firstname);

  //operator overloading
  friend std::ostream &operator<<(std::ostream &os, const Borrow &bw);
  
};