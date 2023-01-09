#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Author.h"

class Book {

private:
  std::string _title;
  std::string _language;
  std::string _genre;
  int _isbn;
  //vector contains ids
  std::vector<std::string> _borrow_list;
  Date _publication;
  Author _author;

public:
  //constructor
  Book(std::string title, std::string language, std::string genre, Date publication, Author author);
  
  //getters
  Date get_publication();
  Author get_author();
  int get_isbn();
  std::string get_title();
  std::string get_language();
  std::string get_genre();
  std::vector<std::string> get_borrow_list();

  //setters
  void add_borrow_list();

  //operator overloading
  friend std::ostream &operator<<(std::ostream &os, const Book &b);
};