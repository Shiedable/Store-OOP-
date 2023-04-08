#pragma once

#include "Product.h"

class Appliance : public Product
{

	std::string Model;
	std::string ProductionDate;
	float Weight;

public:
	Appliance();
	Appliance(std::string name, std::string brand, float price, std::string model, std::string prod_date, float weight, float quantity);
	float Get_Discount(struct tm time_of_purchase, float price_x_quantity);
	void Print(float total, float discount);
};

