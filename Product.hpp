#pragma once
#include <string> 

class Product {

    private:

        int id;
        std::string name;
	    double price;
	    int quantity;
	    int lowStockThreshold = 5; // Threshold for low stock warning
    
    public:

        Product(int p_id, std::string p_name, double p_price, int p_quantity);

        void displayProduct() const;

        // Getter functions

	    int getId() const;
	    const std::string& getName() const;
	    double getPrice() const;
	    int getQuantity() const;
	    int getLowStockThreshold() const;

	    // Setter functions

	    void setQuantity(int newQty);

	    void setPrice(double newPrice);

};