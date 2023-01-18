#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Author.h"
#include "Book.h"
#include "Borrow.h"
#include "Date.h"
#include "Library.h"
#include "Reader.h"

std::vector<int> find_author_books(Author &a, std::vector<Book> book_list) {
  // finds all the books written by an author
  // vector containing the positions of every book of the author
  std::vector<int> author_books;

  for (int i = 0; i < book_list.size(); i++) {
    Author auth = book_list[i].get_author();
    if (auth.get_author_id() == a.get_author_id()) {
      author_books.push_back(i);
    }
  }

  return author_books;
}

void display_author_books(Author &a, std::vector<Book> book_list) {
  // displays all the books of an author
  int l;
  std::string name = a.get_author_name();
  std::vector<int> positions = find_author_books(a, book_list);
  std::cout << "All the books of " << name << " we have : " << std::endl;
  for (int j = 0; j < positions.size(); j++) {
    l = positions[j];
    std::cout << book_list[l];
  }
}

void display_borrow_books(std::vector<Book> book_list) {
  float i = 0; // permet de compter le nombre de livre empruntes
  float j = book_list.size(); //recupere le nombre de livre total
  for (int k = 0; k < book_list.size(); k++) {
    bool check = book_list[k].get_available(); // recupere le booleen contenant l'information sur la disponibilite du livre
    if (check == false) {
      std::cout << book_list[k] << std::endl; // affiche le livre si il est emprunte et increment le compteur de 1
      i++;
    }
  }
  float percent = (i / j) * 100;
  std::cout << "Le pourcentage de livre empruntés est : " << percent << " %"
            << std::endl;
}

void display_borrow_book_reader(std::vector<Book> book_list, std::vector<Reader> reader_list) {
  std::cout << "Entrez nom puis prenom pour savoir quels livres sont les livres empruntes par ce lecteur: \n"; // permet de chercher la liste des livres empruntes par un lecteur en particulier
  std::string lastname, firstname;
  std::cin >> lastname >> firstname;
  std::string name = firstname + " " + lastname;
  int j;
  for(int i=0; i < reader_list.size(); i++){ // retrouve le lecteur dans la liste de ceux enregistres
    std::string name1 = reader_list[i].get_name();
    if(name1 == name){
      j = i;
    }
  }
  
  std::vector<int> isbn = reader_list[j].get_borrowed_books();
  for (int k = 0; k < book_list.size(); k++) {
    bool check = book_list[k].get_available();
    if (check == false) {
      for (int u = 0; u < isbn.size(); u++) {
        int test = book_list[k].get_isbn(); // recupere l'isbn de chaque livre emprunte pour le comparer avec les isbn des livres empruntes par le lecteur
        if (test == isbn[u]) {
          std::cout << book_list[k] << std::endl;
        }
      }
    }
  }
}

void reader_ranking(std::vector<Reader> &readers_list){
  //establishes ranking
  std::sort(readers_list.begin(), readers_list.end(), [](Reader &a, Reader &b) { return a.get_borrowed_books() < b.get_borrowed_books(); });
    std::cout << "displaying ranking : " << std::endl;
    int k=1;
    for(int i = readers_list.size()-1 ; i>=0; i--){
      std::cout<<k<< " : " << readers_list.at(i) << std::endl;
      k++;
    }
  }


int main() {
  // creating first book
  // publication date
  Date d(9, 1, 1900);

  // Author
  // date of birth
  Date db(11, 20, 1828);
  Author a("leon", "tolstoi", db);
  int isbn = 256189340;

  Book b("first title", "english", "science fiction", d, a, isbn);
  isbn++;

  std::cout << b;

  // creating the first reader
  Reader r("tobi", "wendl");
  std::cout << r;

  // creating the first book loan

  // creating the borrow date
  Date bw_date(12, 24, 2022);
  Borrow bw(bw_date, r, b);
  std::cout << bw;

  // creating 4 authors
  std::vector<Author> author_list;
  // birth dates
  Date db1(12, 12, 1821);
  Date db2(5, 22, 1885);
  Date db3(4, 9, 1821);
  Date db4(4, 2, 1840);

  Author a1("gustave", "flaubert", db1);
  author_list.push_back(a1);
  Author a2("victor", "hugo", db2);
  author_list.push_back(a2);
  Author a3("charles", "beaudelaire", db3);
  author_list.push_back(a3);
  Author a4("emile", "zola", db4);
  author_list.push_back(a4);

  // creating 10 books
  std::vector<Book> book_list;
  // publication dates
  Date d1(1, 20, 1900);
  Date d2(2, 19, 1901);
  Date d3(3, 18, 1902);
  Date d4(4, 17, 1903);
  Date d5(5, 16, 1904);
  Date d6(6, 15, 1905);
  Date d7(7, 14, 1906);
  Date d8(8, 13, 1907);
  Date d9(9, 12, 1908);
  Date d10(10, 11, 1909);

  Book b1("first title", "english", "science fiction", d1, a1, isbn);
  book_list.push_back(b1);
  isbn++;
  Book b2("second title", "french", "Fantasy", d2, a2, isbn);
  book_list.push_back(b2);
  isbn++;
  Book b3("third title", "german", "Romantic", d3, a3, isbn);
  book_list.push_back(b3);
  isbn++;
  Book b4("fourth title", "spanish", "Poetry", d4, a4, isbn);
  book_list.push_back(b4);
  isbn++;
  Book b5("fifth title", "french", "Poetry", d5, a1, isbn);
  book_list.push_back(b5);
  isbn++;
  Book b6("sixth title", "french", "Fantasy", d6, a2, isbn);
  book_list.push_back(b6);
  isbn++;
  Book b7("seventh title", "italian", "science fiction", d7, a3, isbn);
  book_list.push_back(b7);
  isbn++;
  Book b8("heighth title", "english", "science fiction", d8, a4, isbn);
  book_list.push_back(b8);
  isbn++;
  Book b9("ninth title", "french", "Fantasy", d9, a1, isbn);
  book_list.push_back(b9);
  isbn++;
  Book b10("tenth title", "english", "science fiction", d10, a2, isbn);
  book_list.push_back(b10);
  isbn++;

  // creating 3 readers
  std::vector<Reader> reader_list;

  /*Reader r1("othilie", "rota");
  reader_list.push_back(r1);*/
  Reader r2("toto", "azerty");
  reader_list.push_back(r2);
  Reader r3("tata", "qwerty");
  reader_list.push_back(r3);

  // creating the library
  Library l("library of Alexandria", book_list, author_list, reader_list);

  // std::cout << l;

  l.borrow_book();
  l.borrow_book();
  l.return_book();

  std::cout << "\n\n\n\n" << l << "\n\n\n\n\n";

  // find the books of a specific author
  // for example here we are going to display only the books of gustave flaubert
  display_author_books(a1, book_list);

  std::cout << "\n\n\n";
  std::cout << "borrowed books : " << std::endl;
  std::vector<Book> w = l.get_book_list();
  reader_list = l.get_registered_readers();
  display_borrow_books(w);
  std::cout << "\n\n\n";
  display_borrow_book_reader(w, reader_list);

  std::cout << "\n\n\n";
  reader_ranking(reader_list);
  return 0;
}