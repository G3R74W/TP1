#include "Library.h"

Library::Library(std::string name, std::vector<Book> &book_list,
                 std::vector<Author> &author_list,
                 std::vector<Reader> &registered_readers)
    : _name(name), _book_list(book_list), _author_list(author_list),
      _registered_readers(registered_readers) {
  _nbr_registered = _registered_readers.size();
  _nbr_books = _book_list.size();
}

// getters
int Library::get_nbr_books() { return _nbr_books; }

std::vector<Book> Library::get_book_list() { return _book_list; }

std::vector<Reader> Library::get_registered_readers() {
  return _registered_readers;
}

std::vector<Borrow> Library::get_borrow_list() { return _borrow_list; }

// setters
void Library::add_book(Book &b) {
  // adds book to library
  _book_list.push_back(b);
  _nbr_books++;
}

void Library::add_reader(Reader &r) {
  // adds registered reader to the library data base
  _registered_readers.push_back(r);
  _nbr_registered++;
}

void Library::add_author(Author &a) {
  // adds author to the library data base
  _author_list.push_back(a);
}

void Library::add_borrow(Borrow &q) {
  // adds book to the borrowed books list
  _borrow_list.push_back(q);
}

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

  os << "Books owned : \n";
  for (int i = 0; i < l._book_list.size(); i++) {
    os << l._book_list[i];
  }

  os << "Authors : \n";
  for(int j=0; j<l._author_list.size();j++){
    os << l._author_list[j];
  }

  os << "Registered readers : \n";
  for (int k = 0; k < l._registered_readers.size(); k++) {
    os << l._registered_readers[k];
  }

  os << "----------------------\n";
  return os;
}

void Library::borrow_book() {
  std::cout << "Emprunter un livre : \n";
  std::cout << "Entrez votre nom puis votre prénom : \n";
  std::string lastname, firstname;
  std::cin >> lastname >> firstname;
  std::string fullname = firstname + " " + lastname;
  int exist = -1;
  for (int i = 0; i < _registered_readers.size(); i++) {
    std::string name = _registered_readers[i].get_name();
    if (fullname == name) {
      exist = i;
    }
  }
  if (exist == -1) {
    Reader r(firstname, lastname);
    add_reader(r);
  }
  for (int j = 0; j < _book_list.size(); j++) {
    std::cout << _book_list[j] << std::endl;
  }
  int isbn;
  int test;
  int wanted;
  bool x = false;
  do {
    std::cout << " Enter the isbn of the wanted book. \n";
    std::cin >> isbn;
    for (int k = 0; k < _book_list.size(); k++) {
    test = _book_list[k].get_isbn();
    if (test == isbn) {
      x = _book_list[k].get_available();
      if(x == true){
      wanted = k;
      }
    }
  }
  } while (isbn < 256189340 || x == false);
  std::cout << "Entrer the date of borrow (day / month / year) : \n";
  int day, month, year;
  std::cin >> day >> month >> year;
  Date d(month, day, year);
  if (exist != -1) {
    Borrow b(d, _registered_readers[exist], _book_list[wanted]);
    std::string id_reader = firstname[1] + lastname;
    _book_list[wanted].add_borrow_list(id_reader);
    _registered_readers[exist].add_borrowed_book(isbn);
    add_borrow(b);
    std::cout << "Borrow is effective \n";
  } else {
    int h = _registered_readers.size() - 1;
    Borrow b(d, _registered_readers[h], _book_list[wanted]);
    std::string id_reader = firstname[1] + lastname;
    _book_list[wanted].add_borrow_list(id_reader);
    _registered_readers[h].add_borrowed_book(isbn);
    add_borrow(b);
    std::cout << "Borrow is effective \n";
  }
}

void Library::return_book() {
  std::cout << "Rendre un livre : \n";
  std::cout << "Entrez votre nom puis votre prénom : \n";
  std::string lastname, firstname;
  std::cin >> lastname >> firstname;
  int isbn;
  bool exist;
    std::cout << "Entrez l'isbn du livre rendu : \n";
    std::cin >> isbn;
    //if(isbn >= 256189340){
      for(int i=0; i < _borrow_list.size(); i++){
        Book b = _borrow_list[i].get_book();
        int real_isbn = b.get_isbn();
        if(isbn == real_isbn){
          _borrow_list[i].set_away(lastname, firstname);
          exist = _borrow_list[i].get_away();
          if (exist == false) {
            _borrow_list.erase(_borrow_list.begin() + i);
          }
        }
      }
    }
    /*else{
      std::cout << "L'isbn entre n'est pas valide. \n";
    }*/
//}

void Library::percentage(){
  std::cout <<"number of books borrowed : " << _borrow_list.size() <<  std::endl;
  
}