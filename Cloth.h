#pragma once

#include "Product.h"

class Cloth : public Product
{

	std::string Size;
	std::string Color;

public:
	Cloth();
	Cloth(std::string name, std::string brand, float price, std::string size, std::string color, float quantity);
	float Get_Discount(struct tm time_of_purchase, float price_x_quantity);
	void Print(float total, float discount);
};