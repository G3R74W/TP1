#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Author.h"
#include "Book.h"

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
  return 0;
}