#pragma once
#include "Product.hpp"
#include <vector>
#include <string>

class Inventory {

	private:

	  std::vector <Product> productList;

	public:
	  
	  void addProduct(int p_id, const std::string& p_name, double p_price, int p_quantity);

	  void displayInventory() const;

	  bool isProductExists(int searchId) const;

	  void searchProduct(int searchId) const;
	
	  void checkLowStock() const;

	  void saveToFile();

	  void loadFromFile();

	  void editProduct(int editId, double newPrice, int newQty);

	  void deleteProduct(int deleteId);

	  void sortByPrice();
	  
	  void sortByQuantity();
	  
};