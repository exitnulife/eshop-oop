#include "Order.hpp"
#include <iostream>
//5)STATIC nextOrderId - automaticky inkrementuje ID kazde nove objednavky
int Order::nextOrderId = 1; //první objednávka dostane ID 1

Order::Order(Customer* customer, Cart& cart) : customerName(customer->getName()), customerType(customer->getCustomerType()), status("Prijata") {
    orderId = nextOrderId++;
    totalPrice = cart.getTotalPriceWithDiscount(customer->getDiscount());

    //potvrdime kosik, rezervace se stava definitivni, sklad zustane snizeny
    cart.confirm();
}

Order::~Order() {}

int Order::getOrderId() const { 
  return orderId; 
}
double Order::getTotalPrice() const { 
  return totalPrice; 
}
std::string Order::getStatus() const { 
  return status; 
}

void Order::setStatus(const std::string& newStatus) { 
  status = newStatus; 
}

void Order::printInfo() const {
    std::cout << "Objednavka #" << orderId << " | " << customerType << ": " << customerName << " | Celkem: " << totalPrice << " Kc" << " | Stav: " << status << std::endl;
}

int Order::getNextOrderId() const { 
    return nextOrderId; 
}
