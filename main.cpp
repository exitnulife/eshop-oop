#include <iostream>
#include "Utils.hpp"
#include "Smartphone.hpp"
#include "Laptop.hpp"
#include "Accessory.hpp"
#include "Customer.hpp"
#include "PremiumCustomer.hpp"
#include "Cart.hpp"
#include "Order.hpp"
//1a) 9 TRID: Product, Device, Smartphone, Laptop, Accessory, Customer, PremiumCustomer, Cart, Order
//1b) kazda trida v samostatnem .hpp + .cpp; main.cpp obsahuje pouze main()
//2) instance: 15x produkt, 3x zakaznik + kosiky a objednavky nize
//11) POLYMORFISMUS, Product* drzi Smartphone, Laptop i Accessory

int main() {
    std::cout << "///////////////////////////////////////////" << std::endl;
    std::cout << "   AppleShopOstrava - Premium re-seller   " << std::endl;
    std::cout << "///////////////////////////////////////////" << std::endl;

    const int CATALOG_SIZE = 15;
    Product* catalog[CATALOG_SIZE] = {
        //id; name; price; stock; battery; storage; OS
        new Smartphone( 1, "iPhone 16 Pro Max", 39990.0, 3, 4685, 256, "iOS"),
        new Smartphone( 2, "iPhone 16 Pro", 33990.0, 4, 3582, 128, "iOS"),
        new Smartphone( 3, "iPhone 16", 26990.0, 5, 3561, 128, "iOS"),
        new Smartphone( 4, "iPhone 16e", 17990.0, 6, 3279, 128, "iOS"),
        new Smartphone( 5, "iPhone 15 - na dily", 1990.0, 2, 3274, 128), //pouziti pretizeneho konstruktoru, vynechano OS, nastavi se default "bez OS"
        //id; name; price; stock; ram; processor; display
        new Laptop ( 6, "MacBook Pro 16 M4 Max", 119990.0, 2, 512, 48, "Apple M4 Max", 162),
        new Laptop ( 7, "MacBook Pro 14 M4 Pro", 79990.0,  3, 512, 24, "Apple M4 Pro", 142),
        new Laptop ( 8, "MacBook Pro 14 M4", 52990.0,  4, 512, 16, "Apple M4", 142),
        new Laptop ( 9, "MacBook Air 15 M3", 42990.0,  4, 256, 16, "Apple M3", 153),
        new Laptop (10, "MacBook Air 13 M2", 27990.0,  5, 256,  8, "Apple M2", 136),
        //id; name; price; stock; type
        new Accessory (11, "AirPods Pro 2", 6490.0,  6, "Sluchatka"),
        new Accessory (12, "AirPods 4", 3990.0,  8, "Sluchatka"),
        new Accessory (13, "Apple Watch Series 10", 12990.0, 4, "Hodinky"),
        new Accessory (14, "Apple Polishing Cloth", 999999.0, 5, "Hadrik"),
        new Accessory (15, "MagSafe Nabijecka 25W", 990.0, 10, "Nabijecka"),
    };

    //6) 7) DEDICNOST + POZDNI VAZBA, Customer* drzi Customer i PremiumCustomer
    //5) Customer::instanceCount se automaticky aktualizuje v ctor/dtor
    const int CUSTOMER_COUNT = 3;
    Customer* customers[CUSTOMER_COUNT] = {
        new Customer (1, "Jan Novak", "jan@email.cz"),
        new Customer (2, "Petra Svobodova", "petra@email.cz"),
        new PremiumCustomer (3, "Eva Horakova", "eva@email.cz", 15.0)
    };

    // 5)STATIC, vypise pocet aktivnich instanci (Customer + PremiumCustomer dohromady)
    std::cout << "Registrovanych zakazniku: " << Customer::getInstanceCount() << std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //demo
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "    DEMO    " << std::endl;

    //vypis katalogu pres polymorfismus - printInfo() vola virtualni getDescription()
    printCatalog(catalog, CATALOG_SIZE);

    //kosik 1: Jan Novak - prida zbozi, jedno odebere, vytvori objednavku
    Cart demoCart1(customers[0]->getId());
    demoCart1.addItem(catalog[0]);  //iPhone 16 Pro Max
    demoCart1.addItem(catalog[11]); //AirPods 4
    demoCart1.addItem(catalog[14]); //MagSafe
    demoCart1.removeItem(15); //MagSafe odebran, vracen na sklad
    std::cout << std::endl << customers[0]->getName() << " - ";
    demoCart1.printContents();
    Order demoOrder1(customers[0], demoCart1);
    std::cout << "  --> "; demoOrder1.printInfo();

    //kosik 2: Eva Horakova (PremiumCustomer, 15% sleva)
    Cart demoCart2(customers[2]->getId());
    demoCart2.addItem(catalog[6]);  //MacBook Pro 14 M4 Pro
    demoCart2.addItem(catalog[12]); //Apple Watch
    std::cout << std::endl << customers[2]->getName() << " - ";
    demoCart2.printContents();
    std::cout << "  Po sleve " << customers[2]->getDiscount() << "%: " << demoCart2.getTotalPriceWithDiscount(customers[2]->getDiscount()) << " Kc" << std::endl;
    Order demoOrder2(customers[2], demoCart2);
    std::cout << "  --> "; demoOrder2.printInfo();

    //vernostni body pres virtualni metodu - pozdni vazba
    customers[2]->addLoyaltyPoints((int)(demoOrder2.getTotalPrice()) / 100);

    //vypis zakazniku pres polymorfismus - printInfo() a getCustomerType() pozdni vazba
    std::cout << std::endl << "Prehled zakazniku:" << std::endl;
    for (int i = 0; i < CUSTOMER_COUNT; i++) {
        customers[i]->printInfo();
    }

    std::cout << "    KONEC DEMA    " << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //menu
    int activeIdx = 0; //index do pole customers[]
    Cart* cart = new Cart(customers[activeIdx]->getId());

    bool running = true;
    while (running) {
        std::cout << std::endl;
        std::cout << "MENU:" << std::endl;
        std::cout << "Prihlaseny " << customers[activeIdx]->getCustomerType() << " - " << customers[activeIdx]->getName() << std::endl;
        std::cout << "1: Zobrazit katalog" << std::endl;
        std::cout << "2: Pridat produkt do kosiku" << std::endl;
        std::cout << "3: Odebrat produkt z kosiku" << std::endl;
        std::cout << "4: Zobrazit kosik" << std::endl;
        std::cout << "5: Vytvorit objednavku" << std::endl;
        std::cout << "6: Prepnout zakaznika" << std::endl;
        std::cout << "0: Konec" << std::endl;

        int choice = readInt("Volba: ");

        switch (choice) {
        case 1:
            printCatalog(catalog, CATALOG_SIZE);
            break;
        case 2: {
            printCatalog(catalog, CATALOG_SIZE);
            int id = readInt("ID produktu (0 = zpet): ");
            if (id == 0) {
                break;
            }
            Product* product = findById(catalog, CATALOG_SIZE, id);
            if (product == nullptr) {
                std::cout << "Produkt nenalezen." << std::endl;
                break;
            }
            if (cart->addItem(product)) {
                std::cout << "  OK: \"" << product->getName() << "\" pridano do kosiku." << std::endl;
            }
            break;
        }
        case 3: {
            cart->printContents();
            if (cart->getCount() == 0) {
                break;
            }
            int id = readInt("ID produktu k odebrani (0 = zpet): ");
            if (id == 0) {
                break;
            }
            if (cart->removeItem(id)) {
                std::cout << "  OK: Produkt odebran, kus vracen na sklad." << std::endl;
            } else {
                std::cout << "Produkt s timto ID neni v kosiku." << std::endl;
            }
            break;
        }
        case 4:
            std::cout << std::endl;
            cart->printContents();
            if (cart->getCount() > 0) {
                double discount = customers[activeIdx]->getDiscount();
                if (discount > 0.0) {
                    std::cout << "  --> Po slevě " << discount << "%: " << cart->getTotalPriceWithDiscount(discount) << " Kc" << std::endl;
                }
            }
            break;
        case 5: {
            if (cart->getCount() == 0) {
                std::cout << "Kosik je prazdny." << std::endl;
                break;
            }
            cart->printContents();
            double disc = customers[activeIdx]->getDiscount();
            std::cout << "  Celkem k uhrade: " << cart->getTotalPriceWithDiscount(disc) << " Kc" << std::endl;
            int confirm = readInt("Potvrdit objednavku? (1=ano / 0=ne): ");
            if (confirm == 1) {
                Order* order = new Order(customers[activeIdx], *cart); //confirmed je false, destruktor košíku hodí všechny rezervace na sklad
                order->printInfo();
                std::cout << "  Objednavka prijata." << std::endl;

                if (customers[activeIdx]->getDiscount() > 0.0) {
                    int pts = (int)(order->getTotalPrice()) / 100;
                    customers[activeIdx]->addLoyaltyPoints(pts);
                    std::cout << "  Pridano " << pts << " vernostnich bodu." << std::endl;
                }
                delete order;
                delete cart;
                cart = new Cart(customers[activeIdx]->getId());
            }
            break;
        }
        case 6: {
            std::cout << std::endl << "Dostupni zakaznici:" << std::endl;
            for (int i = 0; i < CUSTOMER_COUNT; i++) {
                std::cout << "  [" << (i + 1) << "] ";
                customers[i]->printInfo();
            }
            int idx = readInt("Vyberte zakaznika (cislo): ") - 1;
            if (idx < 0 || idx >= CUSTOMER_COUNT) {
                std::cout << "Neplatna volba." << std::endl;
                break;
            }
            if (idx == activeIdx) {
                std::cout << "Jiz jste prihlaseni jako tento zakaznik." << std::endl;
                break;
            }
            //stary kosik se zahodi, destruktor vrati rezervace na sklad
            delete cart;
            activeIdx = idx;
            cart = new Cart(customers[activeIdx]->getId());
            std::cout << "  Prihlaseni jako: " << customers[activeIdx]->getName() << std::endl;
            break;
        }
        case 0:
            running = false;
            break;
        default:
            std::cout << "Neplatna volba." << std::endl;
        }
    }

    //clean
    delete cart;
    for (int i = 0; i < CUSTOMER_COUNT; i++) {
        delete customers[i];
    }
    for (int i = 0; i < CATALOG_SIZE; i++) {
        delete catalog[i];
    }

    std::cout << std::endl << "Aktivnich zakazniku po ukonceni: " << Customer::getInstanceCount() << std::endl;
    std::cout << "Konec programu" << std::endl;

    return 0;
}