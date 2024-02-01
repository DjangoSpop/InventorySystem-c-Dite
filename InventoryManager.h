#ifndef INVENTORYMANGER_H
#define INVENTORYMANAGER_H

#include <string>
#include <vector>

// Define the Product struct
struct Product {
    int productID;
    std::string productName;
    double price;
    int quantity;
    int minQuantity;
};

// Define the InventoryManager class
class InventoryManager {
private:
    static const int MAX_PRODUCTS = 100; // Maximum number of products
    Product inventory[MAX_PRODUCTS];
    int productCount = 0; // Current number of products in inventory

public:
    bool addProduct(int id, const std::string& name, double price, int quantity, int minQuantity);
    Product* searchProduct(int id);
    double makeBill(const std::vector<std::pair<int, int>>& productsPurchased);
};

#endif // INVENTORY_H
