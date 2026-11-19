#include "Device.hpp"
//6) DEDICNOST: Device dedi z Product, spolecna mezivrstva pro Smartphone a Laptop
//9) PROTECTED: storageGb je protected, Smartphone a Laptop ho pouzivaji primo v getDescription()

Device::Device(int id, const std::string& name, double price, int stockQuantity, int storageGb)
    : Product(id, name, price, "Zarizeni", stockQuantity), storageGb(storageGb) {}

Device::~Device() {}

int Device::getStorageGb() const {
    return storageGb;
}

std::string Device::getDescription() const {
    return ""; //Device sam o sobe neni koncovy produkt, implementaci maji Smartphone a Laptop
}