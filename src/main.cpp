// src/main.cpp
#include "../include/InventoryManager.h"
#include <iostream>

int main() {
    InventoryManager manager;
    int choice;

    while (true) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add a new product\n";
        std::cout << "2. Make a sale\n";
        std::cout << "3. Make a bill\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addProduct();
                break;
            case 2:
                manager.makeSale();
                break;
            case 3:
                manager.makeBill();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
