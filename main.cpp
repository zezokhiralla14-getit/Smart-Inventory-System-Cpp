#include "Inventory.hpp"
#include <iostream>
#include <string>

int main() {

  Inventory myInventory;
  myInventory.loadFromFile();

  int choice;
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
    std::cout << "Choose ( 1 - 8 ) : ";
    std::cin >> choice;
    std::cout << std::endl;

    switch (choice) {

      case 1: {

        int id, qty;
        std::string name;
        double price;

        std::cout << "Enter product's id : ";
        std::cin >> id;

        if (myInventory.isProductExists(id)) {
            std::cout << "\n--> Error: A product with ID [" << id << "] already exists! Please try again with a unique ID.\n" << std::endl;
            break;
        }

        std::cout << "Enter product's name : ";
        std::cin >> name;
        std::cout << "Enter product's price : ";
        std::cin >> price;
        std::cout << "Enter product's quantity : ";
        std::cin >> qty;

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

        int searchId;

        std::cout << std::endl;
        std::cout << "Enter the ID you're looking for : ";
        std::cin >> searchId;

        myInventory.searchProduct(searchId);

        break;

      }

      case 4: {

        int editId;
        std::cout << "Enter the product's ID you want to edit : ";
        std::cin >> editId;

        if(myInventory.isProductExists(editId)) {

            double newPrice;
            int newQty;
            std::cout << "Enter the new price : ";
            std::cin >> newPrice;
            std::cout << "Enter the new quantity : ";
            std::cin >> newQty;

            myInventory.editProduct(editId, newPrice, newQty);

        } else {

            std::cout << std::endl;
            std::cout << "--> Sorry, The product is not found" << std::endl;
            std::cout << std::endl;

        }
        
        break;

      }

      case 5: {

        int deleteId;

        std::cout << "Enter the product's ID you want to delete : ";
        std::cin >> deleteId;

        myInventory.deleteProduct(deleteId);

        break;

      }
      
      case 6: {

        int sortChoice;

        std::cout << "1. Sort by price" << std::endl;
        std::cout << "2. Sort by quantity" << std::endl;
        std::cout << std::endl;
        std::cout << "Choose ( 1 or 2 ) : ";
        std::cin >> sortChoice;

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
