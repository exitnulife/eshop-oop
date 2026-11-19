#include "Smartphone.hpp"
//4) PŘETÍŽENÝ KONSTRUKTOR

Smartphone::Smartphone(int id, const std::string& name, double price, int stockQuantity, int batteryMah, int storageGb, const std::string& os)
    : Device(id, name, price, stockQuantity, storageGb), batteryMah(batteryMah), os(os) {
    category = "Smartphone";
}

//pretizeny konstruktor, defaultuje na "bez OS"
Smartphone::Smartphone(int id, const std::string& name, double price, int stockQuantity, int batteryMah, int storageGb)
    : Smartphone(id, name, price, stockQuantity, batteryMah, storageGb, "bez OS") {}

Smartphone::~Smartphone() {}

int Smartphone::getBatteryMah() const {
    return batteryMah;
}
std::string Smartphone::getOs() const {
    return os;
}

std::string Smartphone::getDescription() const {
    return "OS: " + os + ", Baterie: " + std::to_string(batteryMah) + " mAh" + ", Uloziste: " + std::to_string(storageGb) + " GB";
}