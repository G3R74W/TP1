#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Reader.h"
#include "Borrow.h"
#include "Author.h"

class Library{
private:
  std::string _name;
  //total number of books in the library
  int _nbr_books;
  //number of registered readers
  int _nbr_registered;
  //vector containing all the books owned by the library
  std::vector<Book> _book_list;
  //vector containing all the readers
  std::vector<Reader> _registered_readers;
  //vector containing the list of the borrowed books making them unavailable
  std::vector<Borrow> _borrow_list;
  //vector contains all the authors 
  std::vector<Author> _author_list;
  
public:
  Library(std::string name, std::vector<Book> book_list, std::vector<Author> author_list, std::vector<Reader> registered_readers);
  //getters
  int get_nbr_books();
  std::vector<Book> get_book_list();
  std::vector<Reader> get_registered_readers();
  std::vector<Book> get_borrow_list();
  std::vector<Author> get_author_list();

  //setters
  void add_book(Book &b);
  void add_reader(Reader &r);
  void add_author(Author &a);
  void add_borrow(Borrow &q);

  //operator overloading
  friend std::ostream &operator<<(std::ostream &os, const Library &l);

  void borrow_book();
  void return_book();
};

