#pragma once
#include "Device.hpp"

class Smartphone : public Device {
private:
    int batteryMah;
    std::string os;
public:
    Smartphone(int id, const std::string& name, double price, int stockQuantity, int batteryMah, int storageGb, const std::string& os);

    // pretizeny konstruktor, defaultuje na "bez OS"
    Smartphone(int id, const std::string& name, double price, int stockQuantity, int batteryMah, int storageGb);

    virtual ~Smartphone();

    int getBatteryMah() const;
    std::string getOs() const;

    virtual std::string getDescription() const override;
};