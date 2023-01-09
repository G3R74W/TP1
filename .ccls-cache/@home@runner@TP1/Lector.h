#pragma once
#include <iostream>
#include <string>
#include <vector>

class Reader{
private:
  std::string _firstName;
  std::string _lastName;
  //vector contains isbn list of books borrowed by the reader
  std::vector<int> _borrowed_books;
public:
};
