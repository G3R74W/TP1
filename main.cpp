#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Author.h"
#include "Book.h"
#include "Reader.h"
#include "Borrow.h"
#include "Library.h"

int main(){
  //creating first book
  //publication date
  Date d(9, 1, 1900);
  
  //Author
  //date of birth
  Date db(11,20,1828);
  Author a("leon", "tolstoi", db);
  int isbn = 256189340;
  
  Book b("first title", "english", "science fiction", d, a, isbn);
  isbn ++;

  std::cout << b;

  //creating the first reader
  Reader r("tobi", "wendl");
  std::cout << r;

  //creating the first book loan

  //creating the borrow date
  Date bw_date(12, 24, 2022);
  Borrow bw(bw_date, r, b);
  std::cout<<bw;


  
  //creating 4 authors
  std::vector<Author> author_list;
  //birth dates
  Date db1(12,12,1821);
  Date db2(5,22,1885);
  Date db3(4,9,1821);
  Date db4(4,2,1840);

  Author a1("gustave","flaubert",db1);
  author_list.push_back(a1);
  Author a2("victor","hugo",db2);
  author_list.push_back(a2);
  Author a3("charles","beaudelaire",db3);
  author_list.push_back(a3);
  Author a4("emile","zola",db4);
  author_list.push_back(a4);
  

  //creating 10 books
  std::vector<Book> book_list;
  //publication dates
  Date d1(1,20,1900);
  Date d2(2,19,1901);
  Date d3(3,18,1902);
  Date d4(4,17,1903);
  Date d5(5,16,1904);
  Date d6(6,15,1905);
  Date d7(7,14,1906);
  Date d8(8,13,1907);
  Date d9(9,12,1908);
  Date d10(10,11,1909);

  Book b1("first title", "english", "science fiction", d1, a1, isbn);
  book_list.push_back(b1);
  isbn ++;
  Book b2("second title", "french", "Fantasy", d2, a2, isbn);
  book_list.push_back(b2);
  isbn ++;
  Book b3("third title", "german", "Romantic", d3, a3, isbn);
  book_list.push_back(b3);
  isbn ++;
  Book b4("fourth title", "spanish", "Poetry", d4, a4, isbn);
  book_list.push_back(b4);
  isbn ++;
  Book b5("fifth title", "french", "Poetry", d5, a1, isbn);
  book_list.push_back(b5);
  isbn ++;
  Book b6("sixth title", "french", "Fantasy", d6, a2, isbn);
  book_list.push_back(b6);
  isbn ++;
  Book b7("seventh title", "italian", "science fiction", d7, a3, isbn);
  book_list.push_back(b7);
  isbn ++;
  Book b8("heighth title", "english", "science fiction", d8, a4, isbn);
  book_list.push_back(b8);
  isbn ++;
  Book b9("ninth title", "french", "Fantasy", d9, a1, isbn);
  book_list.push_back(b9);
  isbn ++;
  Book b10("tenth title", "english", "science fiction", d10, a2, isbn);
  book_list.push_back(b10);
  isbn ++;

  //creating 3 readers
  std::vector<Reader> reader_list;

  Reader r1("othilie","rota");
  reader_list.push_back(r1);
  Reader r2("toto","azerty");
  reader_list.push_back(r2);
  Reader r3("tata","qwerty");
  reader_list.push_back(r3);

  //creating the library
  Library l("library of Alexandria", book_list, author_list, reader_list);

  
  
  

  
  
  return 0;
}