#include "Library.h"

Library::Library(std::string name, std::vector<Book> book_list, std::vector<Author> author_list, std::vector<Reader> registered_readers)
    : _name(name), _nbr_books(0), _nbr_registered(0), _book_list(book_list), _author_list(author_list), _registered_readers(registered_readers) {}

// getters
int Library::get_nbr_books() { return _nbr_books; }

std::vector<Book> Library::get_book_list() { return _book_list; }

std::vector<Reader> Library::get_registered_readers() {
  return _registered_readers;
}

std::vector<Book> Library::get_borrow_list() { return _borrow_list; }

// setters
void Library::add_book(Book &b) {
  // adds book to library
  _book_list.push_back(b);
  _nbr_books++;
}

void Library::add_reader(Reader &r) {
  //adds registered reader to the library data base
  _registered_readers.push_back(r);
  _nbr_registered++;
}

void Library::add_author(Author &a) { _author_list.push_back(a); }

void Library::add_borrow(Borrow &q) { _borrow_list.push_back(q);}

// operator overloading
std::ostream &operator<<(std::ostream &os, const Library &l) {
  os << "----------------------\n";
  os << "     LIBRARY INFO     \n";
  os << "----------------------\n";
  os << "\n";

  os << "Name : ";
  os << l._name;
  os << "\n";

  os << "Number of books : ";
  os << l._nbr_books;
  os << "\n";

  os << "Number of registered readers : ";
  os << l._nbr_registered;
  os << "\n";

  os << "----------------------\n";
  return os;
}

void Library::borrow_book() {
  std::cout << "Entrez votre nom puis votre prénom : \n";
  std::string lastname, firstname;
  std::cin >> lastname >> firstname;
  std::string fullname = firstname + " " + lastname;
  int exist = -1;
  for (int i = 0; i < _registered_readers.size(); i++) {
    std::string name = _registered_readers[i].get_name();
    if(fullname == name){
      exist = i;
    }
  }
  if (exist == -1){
    Reader r(firstname, lastname);
    add_reader(r);
  }
  for(int j =0; j < _book_list.size(); j++){
    std::cout << _book_list[j] << std::endl;
  }
  int isbn;
  do{
    std::cout << " Enter the isbn of the wanted book. \n";
    std::cin >> isbn;
  }while (isbn < 256189340);
  int test;
  int wanted;
  for(int k = 0; k < _book_list.size(); k++){
    test = _book_list[k].get_isbn();
    if (test == isbn){
      wanted = k;
    }
  }
  std::cout << "Entrer the date of borrow (day / month / year) : \n";
  int day, month, year;
  Date d (month, day, year);
  if (exist != -1){
    Borrow b(d, _registered_readers[exist], _book_list[wanted]);
    add_borrow(b);
    std::cout << "Borrow is effective \n";
    }
  else {
    int h = _registered_readers.size()-1;
    Borrow b(d, _registered_readers[h], _book_list[wanted]);
    add_borrow(b);
    std::cout << "Borrow is effective \n";
    }
}

void Library::return_book(){
  std::cout << "Entrez votre nom puis votre prénom : \n";
  std::string lastname, firstname;
  std::cin >> lastname >> firstname;
  bool exist;
  for(int i =0; i < _borrow_list.size(); i++){
    _borrow_list[i].set_away(lastname, firstname);
    exist = _borrow_list[i].get_away();
    if(exist == false){
      _borrow_list.erase(_borrow_list.begin()+i);
    }
  }
}