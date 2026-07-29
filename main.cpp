#include "Inventory.hpp"
#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value; // Valid numeric input received
        } else {
            std::cout << "--> Invalid input! Please enter a valid number.\n\n";
            std::cin.clear(); // 1. Clear the stream error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 2. Discard invalid characters from buffer
        }
    }
}

int main() {

  Inventory myInventory;
  myInventory.loadFromFile();

  while(true) {
    std::cout << "------ Smart Inventory System ------" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Add a new product" << std::endl;
    std::cout << "2. Show all products" << std::endl;
    std::cout << "3. Search for a product with its ID" << std::endl;
    std::cout << "4. Edit a product" << std::endl;
    std::cout << "5. Delete a product" << std::endl;
    std::cout << "6. Sort the products" << std::endl;
    std::cout << "7. LowStock check" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << std::endl;
    int choice = getValidInt("Choose ( 1 - 8 ) : ");

    switch (choice) {

      case 1: {

        int id, qty;
        std::string name;
        double price;

        id = getValidInt("Enter product's id : ");

        if (myInventory.isProductExists(id)) {
            std::cout << "\n--> Error: A product with ID [" << id << "] already exists! Please try again with a unique ID.\n" << std::endl;
            break;
        }

        std::cout << "Enter product's name : ";
        std::cin >> name;
        std::cout << "Enter product's price : ";
        std::cin >> price;
        qty = getValidInt("Enter product's quantity : ");

        myInventory.addProduct(id, name, price, qty);

        std::cout << std::endl;
        std::cout << "--> The product has been added successfully" << std::endl;
        myInventory.saveToFile();
        std::cout << std::endl;

        break;

      }
      
      case 2: {
        myInventory.displayInventory();
        break;
      }
      
      case 3: {
        std::cout << std::endl;
        int searchId = getValidInt("Enter the ID you're looking for : ");
        myInventory.searchProduct(searchId);
        break;
      }

      case 4: {

        int editId = getValidInt("Enter the product's ID you want to edit : ");

        if(myInventory.isProductExists(editId)) {
            double newPrice;
            int newQty;
            std::cout << "Enter the new price : ";
            std::cin >> newPrice;
            newQty = getValidInt("Enter the new quantity : ");
            myInventory.editProduct(editId, newPrice, newQty);

        } else {

            std::cout << std::endl;
            std::cout << "--> Sorry, The product is not found" << std::endl;
            std::cout << std::endl;

        }
        
        break;

      }

      case 5: {
        int deleteId = getValidInt("Enter the product's ID you want to delete : ");
        myInventory.deleteProduct(deleteId);
        break;
      }
      
      case 6: {

        int sortChoice;
        std::cout << "1. Sort by price" << std::endl;
        std::cout << "2. Sort by quantity" << std::endl;
        std::cout << std::endl;
        sortChoice = getValidInt("Choose ( 1 or 2 ) : ");

        if(sortChoice == 1) {

          myInventory.sortByPrice();
          std::cout << std::endl;
          std::cout << "--> The products have been sorted successfully" << std::endl;
          myInventory.displayInventory();
          
        } else if (sortChoice == 2) {
          
          myInventory.sortByQuantity();
          std::cout << std::endl;
          std::cout << "--> The products have been sorted successfully" << std::endl;
          myInventory.displayInventory();
          
        } else {
          std::cout << std::endl;
          std::cout << "Invalid choice,Please Enter 1 or 2" << std::endl;
          std::cout << std::endl;
          break;
        }

        break;

      }

      case 7: {
        myInventory.checkLowStock();
        std::cout << std::endl;
        break;
      }
      
      case 8: {
        myInventory.saveToFile();
        std::cout << "--> Thank you for using the system. GoodBye" << std::endl;
        return 0;
      }
      
      default: {
        std::cout << "Invalid choice! Please Enter a number from (1-8)" << std::endl;
        std::cout << std::endl;
      }
    }
  }
  return 0;
}
