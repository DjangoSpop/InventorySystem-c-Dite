// InventoryManager.h

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <iostream>
#include <string>

// Assuming a maximum of 100 products in the inventory
const int MAX_INVENTORY_SIZE = 100;

// Product class
class Product {
public:
    int productID;
    std::string productName;
    double price;
    int quantityStored;
    int minQuantity;

    Product(int id, std::string name, double price, int quantity, int minQty);
};

// InventoryManager class
class InventoryManager {
private:
    Product inventory[MAX_INVENTORY_SIZE];
    int numProducts;  // Number of products currently in the inventory

    int findProductByID(int productID);

public:
    InventoryManager();

    void addProduct(int id, std::string name, double price, int quantity, int minQty);
    void searchProduct(int productID);
    // ... Other methods ...
};

#endif // INVENTORYMANAGER_H
