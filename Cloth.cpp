#include "Cloth.h"
#include <ctime>
#include <iostream>
#include <iomanip>

Cloth::Cloth():Product()
{
	Size = '\0';
	Color = '\0';
}

Cloth::Cloth(std::string name, std::string brand, float price, std::string size, std::string color, float quantity):Product(name, brand, price, quantity)
{	
	std::string size_map = "XS S M L XL";

	if (size_map.find(size) != std::string::npos)
	{
		Size = size;
	}
	else
	{
		Size = '\0';
	}
	Color = color;
}

float Cloth::Get_Discount(struct tm time_of_purchase, float price_x_quantity)
{

	if (time_of_purchase.tm_wday > 1)
	{
		return (float)price_x_quantity * (float)((float)10/(float)100);
	}

	return 0;
}

void Cloth::Print(float total, float discount)
{
	std::cout << std::endl;
	std::cout << Name << " " << Brand << std::endl;
	std::cout << std::fixed << std::setprecision(2) << Quantity << " x $" << PricePerUnit << " = $" << total << std::endl;
	if (discount != 0)
	{
		std::cout << "#discount: -$" << std::fixed << std::setprecision(2)  << discount<< std::endl;
	}
	std::cout << std::endl;
}
