// src/InventoryManager.cpp
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
    InventoryManager() : numProducts(0) {}
    void addProduct();
    void makeSale();
    void makeBill();
    void checkLowStock();
    void displayAllProducts();
    int searchProduct(int id);
    static const int MAX_PRODUCTS = 100;
    Product inventory[MAX_PRODUCTS];
    int numProducts;
    // Additional private methods or variables
};
void InventoryManager::addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        std::cout << "Inventory is full. Cannot add more products.\n";
        return;
    }

    Product newProduct;
    std::cout << "Enter product ID: ";
    std::cin >> newProduct.productID;
    std::cin.ignore(); // To consume the '\n' left in the input stream
    std::cout << "Enter product name: ";
    getline(std::cin, newProduct.productName); // Allows spaces in product name
    std::cout << "Enter price: ";
    std::cin >> newProduct.price;
    std::cout << "Enter quantity: ";
    std::cin >> newProduct.quantity;
    std::cout << "Enter minimum quantity: ";
    std::cin >> newProduct.minQuantity;

    inventory[numProducts++] = newProduct;
    std::cout << "Product added successfully!\n";
}

int InventoryManager::searchProduct(int id) {
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].productID == id) {
            return i;
        }
    }
    return -1; // Product not found
}

void InventoryManager::makeBill() {
      int productId, quantity;
    double totalCost = 0.0;
    char moreItems = 'y';

    while (moreItems == 'y' || moreItems == 'Y') {
        std::cout << "Enter product ID: ";
        std::cin >> productId;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        int index = searchProduct(productId);
        if (index != -1 && inventory[index].quantity >= quantity) {
            inventory[index].quantity -= quantity;
            double cost = inventory[index].price * quantity;
            totalCost += cost;
            std::cout << quantity << " x " << inventory[index].productName << " = $" << cost << std::endl;

            if (inventory[index].quantity < inventory[index].minQuantity) {
                std::cout << "Manager notified: Product " << inventory[index].productName << " is below minimum quantity.\n";
            }
        } else {
            std::cout << "Product ID " << productId << " not found or insufficient quantity.\n";
        }

        std::cout << "Add more items? (y/n): ";
        std::cin >> moreItems;
    }

    std::cout << "Total bill: $" << totalCost << std::endl;
}

void InventoryManager::checkLowStock() {
    bool lowStockFound = false;

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].quantity < inventory[i].minQuantity) {
            std::cout << "Low Stock Alert for Product " << inventory[i].productName << ": Quantity is below the minimum limit." << std::endl;
            lowStockFound = true;
        }
    }

    if (!lowStockFound) {
        std::cout << "No low stock issues found." << std::endl;
    }
}

void InventoryManager::displayAllProducts() {
    if (numProducts == 0) {
        std::cout << "No products in the inventory." << std::endl;
    } else {
        std::cout << "List of All Products in Inventory:" << std::endl;
        for (int i = 0; i < numProducts; i++) {
            std::cout << "Product ID: " << inventory[i].productID << std::endl;
            std::cout << "Product Name: " << inventory[i].productName << std::endl;
            std::cout << "Price: $" << inventory[i].price << std::endl;
            std::cout << "Quantity Stored: " << inventory[i].quantity << std::endl;
            std::cout << "Minimum Quantity: " << inventory[i].minQuantity << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
}
void InventoryManager::makeSale() {
    // Assume this method processes the sale of a single product
    // Implementation can be similar to parts of makeBill but for a single item
       int id, quantitySold;
    std::cout << "Enter product ID: ";
    std::cin >> id;
    int index = searchProduct(id);

    if (index == -1) {
        std::cout << "Product not found.\n";
        return;
    }

    std::cout << "Enter quantity sold: ";
    std::cin >> quantitySold;
    
    if (inventory[index].quantity < quantitySold) {
        std::cout << "Not enough inventory for a sale.\n";
        return;
    }

    inventory[index].quantity -= quantitySold;
    std::cout << "Sale processed. Product updated.\n";

    if (inventory[index].quantity < inventory[index].minQuantity) {
        std::cout << "Manager notified: Product " << inventory[index].productName << " is below minimum quantity.\n";
    }
}
