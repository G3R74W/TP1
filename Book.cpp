#include "Book.h"

//constructor
Book::Book(std::string title, std::string language, std::string genre, Date publication, Author author)
: _title(title), _language(language), _genre(genre), _publication(publication), _author(author)
{
  //create isbn
}
  
//getters
Date Book::get_publication(){
  return _publication;
}
Author Book::get_author(){
  return _author;
}
int Book::get_isbn(){
  return _isbn;
}
std::string Book::get_title(){
  return _title;
}
std::string Book::get_language(){
  return _language;
}
std::string Book::get_genre(){
  return _genre;
}
std::vector<std::string> Book::get_borrow_list(){
  return _borrow_list;
}

//setters
void Book::add_borrow_list(std::string borrow_id){
  _borrow_list.push_back(borrow_id);
}

//operator overloading
friend std::ostream &operator<<(std::ostream &os, const Book &b){
  os << "----------------------\n";
  os << "      BOOK INFO       \n";
  os << "----------------------\n";
  os << "\n";

  os << "Title : ";
  os << b._title;
  os << "\n";

  os << "Author : ";
  os << b._author;
  os << "\n";

  os << "Genre : ";
  os << b._genre;
  os << "\n";

  os << "Language : ";
  os << b._genre;
  os << "\n";

  os << "Release date : ";
  os << b._publication;
  os << "\n";

  os << "----------------------";
  return os;
}