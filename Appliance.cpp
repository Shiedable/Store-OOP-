#include "Appliance.h"
#include <iostream>
#include <iomanip>
Appliance::Appliance():Product()
{
    Model = '\0';
    ProductionDate = '\0';
    Weight = 0.0f;    
}

Appliance::Appliance(std::string name, std::string brand, float price, std::string model, std::string prod_date, float weight, float quantity):Product(name, brand, price, quantity)
{
	Model = model;
    ProductionDate = prod_date;
    Weight = weight;
}

float Appliance::Get_Discount(struct tm time_of_purchase, float price_x_quantity)
{
	if ((time_of_purchase.tm_wday == 6 || time_of_purchase.tm_wday == 0) && PricePerUnit > 999)
	{
		return (float)price_x_quantity * (float)((float)7/(float)100);;
	}

	return 0;
}

void Appliance::Print(float total, float discount)
{
	std::cout << std::endl;
	std::cout << Name << " " << Model << " " << Brand << std::endl;
    std::cout << std::fixed << std::setprecision(2) << Quantity << " x $" << PricePerUnit << " = $" << total << std::endl;
    if (discount != 0)
	{
		std::cout << "#discount: -$" << std::fixed << std::setprecision(2)  << discount<< std::endl;
	}
	std::cout << std::endl;
}


