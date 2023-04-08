#pragma once

#include<string>

class Product {
protected:
	std::string Name;
	std::string Brand;
	float PricePerUnit;
	float Quantity;
	
public:
	Product();
	Product(std::string name, std::string brand, float ppu, float quantity);
	virtual float Get_Discount(struct tm time_of_purchase, float price_x_quantity);
	virtual void Print(float total, float discount);
	float Get_Price_X_Quantity();
};