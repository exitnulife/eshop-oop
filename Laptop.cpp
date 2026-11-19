#include "Laptop.hpp"
//6) DEDICNOST: Laptop dedi z Device, Device dedi z Product, hierarchie 3 urovni
//11) POLYMORFISMUS: getDescription() prekryva abstraktni metodu z Product

Laptop::Laptop(int id, const std::string& name, double price, int stockQuantity, int storageGb, int ramGb, const std::string& processor, int screenInch)
    : Device(id, name, price, stockQuantity, storageGb), ramGb(ramGb), processor(processor), screenInch(screenInch) {
    category = "Notebook";
}

Laptop::~Laptop() {}

int Laptop::getRamGb() const {
    return ramGb;
}
std::string Laptop::getProcessor() const {
    return processor;
}
int Laptop::getScreenInch() const {
    return screenInch;
}

std::string Laptop::getDescription() const {
    return "RAM: " + std::to_string(ramGb) + " GB"
        + ", CPU: " + processor
        + ", Displej: " + std::to_string(screenInch / 10) + "." + std::to_string(screenInch % 10) + "\""
        + ", Uloziste: " + std::to_string(storageGb) + " GB";
}