// include/InventoryManager.h
#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <string>
#include <iostream>

struct Product {
    int productID;
    std::string productName;
    double price;
    int quantity;
    int minQuantity;
};

class InventoryManager {
public:
    InventoryManager();
    void addProduct();
    void makeSale();
    void makeBill();
    int searchProduct(int id);
    static const int MAX_PRODUCTS = 100;
    Product inventory[MAX_PRODUCTS];
    int numProducts;
    // Additional private methods or variables
};

#endif // INVENTORY_MANAGER_H
// include/Product.h