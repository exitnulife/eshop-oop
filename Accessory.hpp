#pragma once
#include "Product.hpp"

class Accessory : public Product {
private:
    std::string accessoryType;
public:
    Accessory(int id, const std::string& name, double price, int stockQuantity, const std::string& accessoryType);
    virtual ~Accessory();
    std::string getAccessoryType() const;
    virtual std::string getDescription() const override;
};