#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <vector>
#include <string>
#include <map>
#include <set>

class MyDataStore : public DataStore{
  public: 
    MyDataStore();
    virtual ~MyDataStore();

    virtual void addProduct(Product* p) override;
    virtual void addUser(User* u) override;
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    virtual void dump(std::ostream& ofile) override;
    
    User* getUser(const std::string& username);
    Product* getProductbyIndex(int index);

    void addToCart(const std::string& username, Product* p);
    void buyCart(const std::string& username);
    void clearCart(const std::string& username);
    std::vector<Product*> getCartForUser(const std::string& username);

  private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::map<std::string,std::vector<Product*>> userCarts_;
    std::map<std::string, std::set<Product*>> keywordMap_;
};

#endif 