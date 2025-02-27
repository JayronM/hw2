#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <set>
#include <string>
#include <sstream>

class Book : public Product{
public:
  Book(std::string name, double price,int qty, std::string isbn, std::string author);
  
  std::set<std::string> keywords()const override;
  std::string displayString() const override;
  void dump(std::ostream& os) const override;

private:
  std::string isbn_;
  std::string author_;
};
#endif