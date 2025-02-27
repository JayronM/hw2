#include "clothing.h"


Clothing::Clothing(std::string name, double price, int qty, std::string size, std::string brand) : Product("clothing", name, price, qty), size_(size), brand_(brand){}

std::set<std::string> Clothing::keywords() const{
  std::set<std::string>keyWords;

  keyWords.insert("clothing");
  keyWords.insert(brand_);
  keyWords.insert(size_);
  return keyWords;
}
std::string Clothing::displayString() const{
  std::stringstream ss;
  ss<<name_<< " | " <<size_ << " | "<<brand_ << " | "<<price_ << " | "<<qty_;
  return ss.str();
}

void Clothing::dump(std::ostream& os) const{
  os<< "clothing" <<std::endl;
  os<< getName()<<std::endl;
  os<<getPrice()<<std::endl;
  os<<getQty()<<std::endl;
  os<< size_<<std::endl;
  os<< brand_ <<std::endl;
}