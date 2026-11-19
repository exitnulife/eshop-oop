#pragma once
#include <string>
#include "Product.hpp"

//nacte cele cislo ze standardniho vstupu, osetri chybny vstup
int readInt(const std::string& prompt);

//vypise cely katalog produktu pres Product*, polymorfismus
void printCatalog(Product** catalog, int size);

//najde produkt v katalogu podle ID, vraci nullptr pokud nenalezen
Product* findById(Product** catalog, int size, int id);
