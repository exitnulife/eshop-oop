#include "Cart.hpp"
#include <iostream>
//3) DYNAMICKÉ POLE UKAZATELŮ

Cart::Cart(int customerId, int initialCapacity) : capacity(initialCapacity), count(0), customerId(customerId), confirmed(false) {
    items = new Product*[capacity];
    for (int i = 0; i < capacity; i++) {
        items[i] = nullptr;
    }
}

Cart::~Cart() {
    //pokud kosik nebyl potvrzen jako objednavka, vracime na sklad
    if (!confirmed) {
        releaseAllReservations();
    }
    delete[] items;
}

//3)PRIDAT/MAZAT: pokud je pole plne, zdvoji kapacitu
void Cart::resize(int newCapacity) {
    Product** newItems = new Product*[newCapacity];
    for (int i = 0; i < count; i++) {
        newItems[i] = items[i];
    }
    for (int i = count; i < newCapacity; i++) {
        newItems[i] = nullptr;
    }
    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

//3)PRIDAT: rezervuje kus ze skladu, pri plnem poli vola resize (capacity * 2)
bool Cart::addItem(Product* product) {
    if (!product->reserveStock()) {
        std::cout << " \"" << product->getName() << "\" neni skladem." << std::endl;
        return false;
    }
    if (count == capacity) {
        resize(capacity * 2);
    }
    items[count++] = product;
    return true;
}

//odebere produkt podle ID, vrátí kus na sklad, přeskládá pole
bool Cart::removeItem(int productId) {
    for (int i = 0; i < count; i++) {
        if (items[i]->getId() == productId) {
            items[i]->releaseStock();   //kus se vraci na sklad
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            items[count - 1] = nullptr;
            count--;
            return true;
        }
    }
    return false;
}

int Cart::getCount() const {
    return count;
}

double Cart::getTotalPrice() const {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i]->getPrice();
    }
    return total;
}

double Cart::getTotalPriceWithDiscount(double discountPercent) const {
    return getTotalPrice() * (1.0 - discountPercent / 100.0);
}

void Cart::printContents() const {
    std::cout << "Kosik (" << count << " polozek):" << std::endl;
    if (count == 0) {
        std::cout << "  Kosik je prazdny." << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << "  " << (i + 1) << ". [" << items[i]->getCategory() << "] " << items[i]->getName() << " | " << items[i]->getPrice() << " Kc" << std::endl;
    }
    std::cout << "  --> Celkem: " << getTotalPrice() << " Kc" << std::endl;
}

Product* Cart::getItem(int index) const {
    if (index >= 0 && index < count) {
        return items[index];
    }
    return nullptr;
}

void Cart::confirm() {
    confirmed = true; 
}

void Cart::releaseAllReservations() {
    for (int i = 0; i < count; i++) {
        if (items[i] != nullptr) {
            items[i]->releaseStock();
        }
    }
    count = 0;
}
