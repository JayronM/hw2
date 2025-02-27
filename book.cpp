#include "book.h"
#include "util.h"



Book::Book(std::string name, double price, int qty, std::string isbn, std::string author) : Product("book", name, price, qty), isbn_(isbn), author_(author){}

std::set<std::string> Book::keywords() const{
  
  std::set<std::string>keyWords = parseStringToWords(name_);
  std::set<std::string> authorWords = parseStringToWords(author_);

  keyWords.insert(authorWords.begin(), authorWords.end());
  keyWords.insert(isbn_);
  //keyWords.insert("book");

  // std::cout<<" Debug -book"<<name_ << " | keywords:";
  // for(const std::string& kw: keyWords){
  //   std::cout<< kw<<" ";
  // }
  // std::cout<<std::endl;
  return keyWords;
}
std::string Book::displayString() const{
  std::stringstream ss;
  ss<<name_<< "\n" <<"Author: "<<author_<<" ISBN: "<< isbn_<< "\n"<< price_ << " "<<qty_<<" left.";
  return ss.str();
}

void Book::dump(std::ostream& os) const{
  os << category_<<std::endl;
  os<< getName()<<std::endl;
  os<< getPrice()<<std::endl;
  os<< getQty()<<std::endl;
  os<<isbn_<<std::endl;
  os<< author_<<std::endl;
  os<<std::endl;
}