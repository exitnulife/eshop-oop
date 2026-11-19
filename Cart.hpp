#pragma once
#include "Product.hpp"

class Cart {
private:
    Product** items;
    int capacity;
    int count;
    int customerId;
    bool confirmed; //pokud true, objednavka potvrzena, destruktor neuvolnuje sklad

    void resize(int newCapacity);

public:
    explicit Cart(int customerId, int initialCapacity = 4);
    ~Cart();

    //zkusi rezervovat kus ze skladu a prida do kosiku jen pokud je skladem
    bool addItem(Product* product);

    //odebere z kosiku a vrati kus zpet na sklad
    bool removeItem(int productId);

    int getCount() const;
    double getTotalPrice() const;
    double getTotalPriceWithDiscount(double discountPercent) const;
    void printContents() const;
    Product* getItem(int index) const;

    //oznaci kosik jako potvrzeny, destruktor uz neuvolni sklad
    void confirm();

    void releaseAllReservations();
};
