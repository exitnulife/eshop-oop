#pragma once
#include <string>
#include "Cart.hpp"
#include "Customer.hpp"

class Order {
private:
    static int nextOrderId;

    int orderId;
    std::string customerName;
    std::string customerType;
    double totalPrice;
    std::string status;

public:
    //konstruktor potvrdi objednavku, rezervace v kosiku uz zustane (sklad snizeny)
    Order(Customer* customer, Cart& cart);
    ~Order();

    int getOrderId() const;
    double getTotalPrice() const;
    std::string getStatus() const;
    void setStatus(const std::string& newStatus);
    void printInfo() const;

    int getNextOrderId() const;
};
