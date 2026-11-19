#pragma once
#include "Device.hpp"

class Laptop : public Device {
private:
    int ramGb;
    std::string processor;
    int screenInch;

public:
    Laptop(int id, const std::string& name, double price, int stockQuantity, int storageGb, int ramGb, const std::string& processor, int screenInch);
    virtual ~Laptop();

    int getRamGb() const;
    std::string getProcessor() const;
    int getScreenInch() const;

    virtual std::string getDescription() const override;
};