#include <iostream>
#include "InventoryManager.h"
#include <vector>


class InventoryManager {
private:
    static const int MAX_PRODUCTS = 100; // Maximum number of products
    Product inventory[MAX_PRODUCTS];
    int productCount = 0; // Current number of products

public:
    bool addProduct(int id, const std::string& name, double price, int quantity, int minQuantity) {
        if (productCount >= MAX_PRODUCTS) return false; // Inventory is full
        inventory[productCount++] = {id, name, price, quantity, minQuantity};
        return true;
    }

    Product* searchProduct(int id) {
        for (int i = 0; i < productCount; i++) {
            if (inventory[i].productID == id) {
                return &inventory[i];
            }
        }
        return nullptr; // Product not found
    }

    double makeBill(const std::vector<std::pair<int, int>>& productsPurchased) {
        double totalCost = 0.0;
        for (const auto& purchase : productsPurchased) {
            Product* product = searchProduct(purchase.first);
            if (product != nullptr && product->quantity >= purchase.second) {
                product->quantity -= purchase.second;
                totalCost += product->price * purchase.second;
                if (product->quantity < product->minQuantity) {
                    std::cout << "Manager notified: Product " << product->productName << " is below minimum quantity.\n";
                }
            }
        }
        return totalCost;
    }
};
