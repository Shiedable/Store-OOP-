#pragma once

#include "Product.h"

class Food_And_Beverage : public Product
{
	std::string ExpirationDate;

public:
	Food_And_Beverage();
	Food_And_Beverage(std::string name, std::string brand, float price, std::string exp_date, float quantity);
	float Get_Discount(struct tm time_of_purchase, float price_x_quantity);
	void Print(float total, float discount);
};

