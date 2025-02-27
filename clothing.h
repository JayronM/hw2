#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include <set>
#include <string>
#include <sstream>

class Clothing : public Product{
public:
  Clothing(std::string name, double price, int qty ,std::string size, std::string brand);
  
  std::set<std::string> keywords()const override;
  std::string displayString() const override;
  void dump(std::ostream& os) const override;
  
private:
  std::string size_;
  std::string brand_;
};
#endif