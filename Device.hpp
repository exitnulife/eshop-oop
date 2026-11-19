#pragma once
#include "Product.hpp"

//spolecny zaklad pro zarizeni s ulozistem
class Device : public Product {
protected:
    int storageGb;
public:
    Device(int id, const std::string& name, double price, int stockQuantity, int storageGb);
    virtual ~Device();

    int getStorageGb() const;

    virtual std::string getDescription() const override;
};