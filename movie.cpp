#include "movie.h"
#include "util.h"


Movie::Movie(std::string name, double price, int qty, std::string genre, std::string rating) : Product("movie",name, price, qty), genre_(genre), rating_(rating){}

std::set<std::string> Movie::keywords() const{
  std::set<std::string>keyWords = parseStringToWords(name_);

  keyWords.insert(convToLower(genre_));
  keyWords.insert(convToLower(rating_));
  return keyWords;
}
std::string Movie::displayString() const{
  std::stringstream ss;
  ss<<name_<< " | " <<genre_ << " | "<<rating_ << " | "<<price_ << " | "<<qty_;
  return ss.str();
}

void Movie::dump(std::ostream& os) const{
  os<< "<movie>" <<std::endl;
  os<<getName()<<std::endl;
  os<<getPrice()<<std::endl;
  os<<getQty()<<std::endl;
  os<<genre_<<std::endl;
  os<<rating_<<std::endl;
}