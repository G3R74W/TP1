#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Date.h"

class Author{
private:
  std::string _firstName;
  std::string _lastName;
  std::string _author_id;
  Date _birth_date;

public:
  Author(std::string firstName, std::string lastName, Date birth_date);

  //getters
  std::string get_author_id();

  //operator overloading
  friend std::ostream &operator<<(std::ostream &os, const Author &a);
};