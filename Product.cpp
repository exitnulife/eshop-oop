#include "Product.hpp"
#include <iostream>
//6) DĚDIČNÁ HIERARCHIE 3 TŘÍDY = Product -> Device -> Smartphone, Laptop, Accessory
//10) ABSTRAKTNÍ TŘÍDA
//11) POLYMORFISMUS

Product::Product(int id, const std::string& name, double price, const std::string& category, int stockQuantity) : id(id), name(name), price(price), category(category), stockQuantity(stockQuantity) {}

Product::~Product() {}

int Product::getId() const { 
    return id; 
}
std::string Product::getName() const { 
    return name; 
}
double Product::getPrice() const {
    return price; 
}
std::string Product::getCategory() const { 
    return category; 
}
int Product::getStockQuantity() const { 
    return stockQuantity;
 }

bool Product::reserveStock() {
    if (stockQuantity <= 0) {
        return false;
    }
    stockQuantity--;
    return true;
}

void Product::releaseStock() {
    stockQuantity++;
}

void Product::printInfo() const {
    std::cout << "[" << category << "] " << name << " | " << price << " Kc" << " | Sklad: " << stockQuantity << " ks" << std::endl;
    std::cout << "    " << getDescription() << std::endl;
}
