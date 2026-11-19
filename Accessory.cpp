#include "Accessory.hpp"
//6)DEDICNOST: Accessory dedi primo z Product
//11)POLYMORFISMUS: getDescription() prekryva abstraktni metodu z Product

Accessory::Accessory(int id, const std::string& name, double price, int stockQuantity, const std::string& accessoryType)
    : Product(id, name, price, "Prislusenstvi", stockQuantity), accessoryType(accessoryType) {}

Accessory::~Accessory() {}

std::string Accessory::getAccessoryType() const {
    return accessoryType;
}

std::string Accessory::getDescription() const {
    return "Typ: " + accessoryType;
}