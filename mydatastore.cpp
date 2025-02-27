#include <iostream>

#include <vector>
#include <algorithm>
#include "product.h"
#include "user.h"
#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
  for(Product* p:products_){
    delete p;
  }
  for(User* u : users_){
    delete u;
  }
}

void MyDataStore::addProduct(Product* p){
  products_.push_back(p);
  std::set<std::string> keywords = p->keywords();
  for(const std::string& kw : keywords){
    keywordMap_[kw].insert(p);
  }
}

void MyDataStore::addUser(User* u){
  users_.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
  std::set<Product*> resultSet;
  if (terms.empty()) return{};

  bool firstTerm = true;

  for(size_t i =0; i < terms.size(); ++i){
    std::string term = convToLower(terms[i]);
    
    std::cout<<"debug search"<<term<<std::endl;

    if(keywordMap_.find(term)==keywordMap_.end()|| keywordMap_[term].empty()){
      if(type ==0) return{};
      continue;
    } 
    if(firstTerm){
      resultSet = keywordMap_[term];
      firstTerm = false;
    }else{
      if (type ==0){
        std::set<Product*> tempRes = setIntersection(resultSet, keywordMap_[term]);
        if (tempRes.empty()) continue;
        resultSet = tempRes; //and search
      }else{
        resultSet = setUnion(resultSet, keywordMap_[term]); //or search
      }
    } 
  }

  std::cout<<"debug search";
  for(Product* p :resultSet){
    std::cout <<p->getName()<<" | ";
  }
  std::cout<<std::endl;
return std::vector<Product*>(resultSet.begin(), resultSet.end());
}

void MyDataStore::dump(ostream& ofile){
  ofile <<"<products>"<<endl;
  for(Product* p : products_){
    p->dump(ofile);
  }
  ofile <<"</products>"<<endl;

  ofile <<"<users>"<<endl;
  for(User* u : users_){
    u->dump(ofile);
  }
  ofile <<"</users>"<<endl;

  ofile.flush();
}

User* MyDataStore::getUser(const string& username){
  for(User* u : users_){
    if(u->getName()==username){
      return u;
    }
  }
  return nullptr;
}

void MyDataStore::addToCart(const std::string& username, Product* p){
  User* user = getUser(username);
  if (!user){
    return;
}
  userCarts_[username].push_back(p);
}
std::vector<Product*> MyDataStore::getCartForUser(const std::string& username){
  User* user = getUser(username);
  if(!user){
    return{};
  }
  return userCarts_[username];
}
void MyDataStore::buyCart(const std::string& username){
  
  User* user= getUser(username);
  if(!user){
    return;
  }
  std::vector<Product*>& cart = userCarts_[username];
  std::vector<Product*> newCart;

  for(int i = 0; i<(int)cart.size(); i++){
    Product* p = cart[i];
    if(p->getQty() >0 && user->getBalance() >= p->getPrice()){
      p->subtractQty(1);
      user->deductAmount(p->getPrice());
    } else{
      newCart.push_back(p); //not purchased;
    }
  }
  cart=newCart;
}


Product* MyDataStore::getProductbyIndex(int index){
    if (index>=0 && index < (int)products_.size()){
      return products_[index];
    }
  
  return nullptr;
}
void MyDataStore::clearCart(const std::string& username){
  userCarts_[username].clear();
}

