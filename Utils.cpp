#include "Utils.hpp"
#include <iostream>

//načte celé číslo ze standardního vstupu, opakuje dokud uživatel nezadá platné číslo
int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        }
        std::cout << "  Zadejte cislo." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return value;
}

//vypíše celý katalog produktů, volá printInfo() na každém prvku přes Product*
void printCatalog(Product** catalog, int size) {
    std::cout << std::endl << "KATALOG (" << size << " produktu):" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "(" << (i + 1) << ") ";
        catalog[i]->printInfo();
    }
}

//projde katalog a vrátí ukazatel na produkt s daným ID, nebo nullptr pokud nenajde
Product* findById(Product** catalog, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (catalog[i]->getId() == id) {
            return catalog[i];
        }
    }
    return nullptr;
}