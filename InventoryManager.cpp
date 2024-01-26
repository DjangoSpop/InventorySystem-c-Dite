// InventoryManager.cpp

#include "InventoryManager.h"

// Product constructor
Product::Product(int id, std::string name, double price, int quantity, int minQty)
    : productID(id), productName(name), price(price), quantityStored(quantity), minQuantity(minQty) {}

// InventoryManager constructor
InventoryManager::InventoryManager() : numProducts(0) {}

// Private method to find a product by ID
int InventoryManager::findProductByID(int productID) {
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].productID == productID) {
            return i;
        }
    }
    return -1; // Not found
}

// Method to add a product
void InventoryManager::addProduct(int id, std::string name, double price, int quantity, int minQty) {
    if (numProducts >= MAX_INVENTORY_SIZE) {
        std::cout << "Inventory is full." << std::endl;
        return;
    }
    if (findProductByID(id) != -1) {
        std::cout << "Product ID already exists." << std::endl;
        return;
    }
    inventory[numProducts++] = Product(id, name, price, quantity, minQty);
}

// Method to search for a product
void InventoryManager::searchProduct(int productID) {
    int index = findProductByID(productID);
    if (index != -1) {
        std::cout << "Product found: " << inventory[index].productName << std::endl;
    } else {
        std::cout << "Product not found." << std::endl;
    }
}

// ... Implement other methods as needed ...
