#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Author.h"
#include "Book.h"
#include "Reader.h"
#include "Borrow.h"

int main(){
  //creating first book
  //publication date
  Date d(9, 1, 1900);
  
  //Author
  //date of birth
  Date db(11,20,1828);
  Author a("leon", "tolstoi", db);
  
  Book b("first title", "english", "science fiction", d, a);

  std::cout << b;

  //creating the first reader
  Reader r("tobi", "wendl");
  std::cout << r;

  //creating the first book loan

  //creating the borrow date
  Date bw_date(12, 24, 2022);
  Borrow bw(bw_date, r, b);
  std::cout<<bw;
  
  return 0;
}