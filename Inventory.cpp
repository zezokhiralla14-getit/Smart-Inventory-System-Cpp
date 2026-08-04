#include "Inventory.hpp"
#include <iostream>
#include <string>
#include <fstream> // File handling library
#include <sstream> // String stream library
#include <algorithm>
#include <cctype> // For std::tolower

std::string tolower(std::string str) {
  for (char& c : str) {
    c = std::tolower(c);
  }
  return str;
}

void Inventory::addProduct(int p_id, const std::string& p_name, double p_price, int p_quantity) {
    
    if(isProductExists(p_id)) {
        std::cout << "\n--> Error: Product with ID [" << p_id << "] already exists! Please use a unique ID";
        return;
    }
	
    productList.emplace_back(p_id, p_name, p_price, p_quantity);

}

void Inventory::displayInventory() const {

	if(productList.empty()) {
	  std::cout << std::endl;
	  std::cout << "--> The inventory is empty!!" << std::endl;
	  std::cout << std::endl;
	  return;
	}
		
	std::cout << std::endl;
	std::cout << "----- Products list in the inventory -----" << std::endl;
	std::cout << std::endl;
		
	for(const Product& p : productList) {
		p.displayProduct();
		std::cout << std::endl;
	}

}

bool Inventory::isProductExists(int searchId) const {
	for(const Product& p : productList) {
	  if(p.getId() == searchId) {
	    return true;
	  }
	}
	return false;
}

void Inventory::searchProduct(int searchId) const {

	for(const Product& p : productList) {
	  if(p.getId() == searchId) {
		std::cout << std::endl;
	    std::cout << "--> The product is found successfully" << std::endl;
		std::cout << std::endl;
		p.displayProduct();
	    std::cout << std::endl;
		return;
	  }
	}

	std::cout << std::endl;
	std::cout << "--> Sorry, The product is not found" << std::endl;
	std::cout << std::endl;

}

void Inventory::checkLowStock() const {
	  
	bool foundLowStock = false;

	for(const Product& p : productList) {
	    if(p.getQuantity() <= p.getLowStockThreshold()) {
	      std::cout << "--> Warning [" << p.getName() << "] is LowStocked !! You need to buy more of it" << std::endl;
		  foundLowStock = true;
	    }
	}
	
	if(!foundLowStock) {
	    std::cout << "--> There is NO LowStock product :)" << std::endl;
	}
}

void Inventory::saveToFile() {
          
        std::ofstream outFile("inventory.txt");

    if(!outFile) {
		std::cout << std::endl;
        std::cout << " --> There is an ERROR in inventory file" << std::endl;
		std::cout << std::endl;
	    return;
    }
	    
    for(const Product& p : productList) {

        outFile << p.getId() << ","
	    << p.getName() << ","
	    << p.getPrice() << ","
	    << p.getQuantity() << std::endl;

    }
	    
	outFile.close();
		
	std::cout << std::endl;
	std::cout << "--> The product has been saved successfully" << std::endl;
		
}

void Inventory::loadFromFile() {
          
	std::ifstream inFile("inventory.txt");

	if(!inFile) {
      return;
	}

	productList.clear();

	std::string line;

	while(std::getline(inFile, line)) {
	    std::stringstream ss(line);

	  std::string id_str, name, price_str, qty_str;

      std::getline(ss, id_str, ',');
      std::getline(ss, name, ',');
      std::getline(ss, price_str, ',');
      std::getline(ss, qty_str, ',');

	  int id = std::stoi(id_str); // stoi = string to int
      double price = std::stod(price_str); // stod = string to double
      int qty = std::stoi(qty_str);

      Product tempProduct(id, name, price, qty);

      productList.push_back(tempProduct);
	}

	    inFile.close();

	}

void Inventory::editProduct(int editId, double newPrice, int newQty) {

	for(Product& p : productList) {
		if(p.getId() == editId) {
			p.setPrice(newPrice);
			p.setQuantity(newQty);
			std::cout << std::endl;
			std::cout << "--> The product has been edited successfully" << std::endl;
			saveToFile();
			std::cout << std::endl;
			return;
		}
	}

}

void Inventory::deleteProduct(int deleteId) {

	for(auto target = productList.begin(); target != productList.end(); ++target ) {
		if(target->getId() == deleteId) {
			productList.erase(target);
			std::cout << std::endl;
			std::cout << "--> The product has been deleted successfully" << std::endl;
			saveToFile();
			std::cout << std::endl;
			return;
		} 
	}
		
	std::cout << std::endl;
	std::cout << "--> Sorry, The product is not found" << std::endl;
	std::cout << std::endl;

}

void Inventory::sortByPrice() {
	std::sort(productList.begin(), productList.end(), [](const Product& a, const Product& b) {
		return a.getPrice() < b.getPrice();
	}); 
}

void Inventory::sortByQuantity() {
	std::sort(productList.begin(), productList.end(), [](const Product& a, const Product& b) {
		return a.getQuantity() < b.getQuantity();
	}); 
}

void Inventory::searchByName(const std::string& searchName) const {
	std::string lowerSearchName = tolower(searchName);
	bool found = false;

	for(const Product& p : productList) {
		std::string lowerProductName = tolower(p.getName());
		if(lowerProductName.find(lowerSearchName) != std::string::npos) {
			if(!found) {
				std::cout << std::endl;
				std::cout << "--> The following products match your search:" << std::endl;
				std::cout << std::endl;
			}
			p.displayProduct();
			std::cout << std::endl;
			found = true;
		}
	}

	if(!found) {
		std::cout << std::endl;
		std::cout << "--> No products found matching your search." << std::endl;
		std::cout << std::endl;
	}
	
}