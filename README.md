# AppleShopOstrava – e-shop v C++

Konzolová simulace e-shopu s elektronikou. Semestrální projekt z předmětu Objektově orientované programování (VŠB-TUO).

## Autor
Michal Španiel (SPA0211)

## Co program umí
- katalog 15 produktů (telefony, notebooky, příslušenství) se stavem skladu
- více zákazníků, přepínání mezi nimi; prémiový zákazník má slevu a věrnostní body
- košík: přidání a odebrání zboží, rezervace kusů na skladě
- vytvoření objednávky s výpočtem ceny po slevě
- úvodní demo a následně interaktivní menu

## Použité principy OOP
- 9 tříd: `Product`, `Device`, `Smartphone`, `Laptop`, `Accessory`, `Customer`, `PremiumCustomer`, `Cart`, `Order`
- dědičnost (`Product` → `Device` → `Smartphone` / `Laptop`, `Customer` → `PremiumCustomer`)
- abstraktní třída a polymorfismus (čistě virtuální `getDescription()`, pozdní vazba přes ukazatele na základní třídu)
- přetížený konstruktor, statický čítač instancí
- dynamické pole v košíku s vlastní správou paměti

## Překlad a spuštění
```bash
g++ -std=c++17 -Wall *.cpp -o eshop
./eshop
```

## Struktura
Každá třída má vlastní `.hpp` a `.cpp`, `main.cpp` obsahuje pouze `main()`. Pomocné funkce (výpis katalogu, načítání vstupu) jsou v `Utils`.
