#include "Product.hpp"
#include <iostream>

Product::Product(int p_id, std::string p_name, double p_price, int p_quantity) 
    : id(p_id), name(p_name), price(p_price), quantity(p_quantity) {}

void Product::displayProduct() const {
	std::cout << "ID: " << id
	          << " | Name: " << name 
	          << " | Price: " << price 
	          << " | Quantity: " << quantity << std::endl;
}

// Getter functions

int Product::getId() const { return id; }
const std::string& Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
int Product::getLowStockThreshold() const { return lowStockThreshold; }

// Setter functions

void Product::setQuantity(int newQty) {
	if(newQty >= 0) {
	    quantity = newQty;
	}
}

void Product::setPrice(double newPrice) {
	if(newPrice >= 0) {
	    price = newPrice;
	}
}