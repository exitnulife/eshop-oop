#pragma once
#include <string>

class Product {
protected:
    int id;
    std::string name;
    double price;
    std::string category;
    int stockQuantity;  //pocet kusu na sklade
public:
    Product(int id, const std::string& name, double price, const std::string& category, int stockQuantity);
    virtual ~Product();

    int getId() const;
    std::string getName() const;
    virtual double getPrice() const;
    std::string getCategory() const;
    int getStockQuantity() const;

    //rezervace pri vlozeni do kosiku, vraci false pokud neni skladem
    bool reserveStock();
    //uvolneni rezervace pri odebrani z kosiku
    void releaseStock();

    virtual std::string getDescription() const = 0; //produkt to sám neimplementuje, musi to implementovat odvozene tridy
    virtual void printInfo() const;
};
