#include "Product.h"

Product::Product()
{
	Name = '\0';
	Brand = '\0';
	PricePerUnit = 0.0f;
	Quantity = 0.0f;
}

Product::Product(std::string name, std::string brand, float ppu, float quantity)
{
	Name = name;
	Brand = brand;
	PricePerUnit = ppu;
	Quantity = quantity;
}

float Product::Get_Discount(tm time_of_purchase, float price_x_quantity)
{
	return 0.0f;
}

void Product::Print(float total, float discount)
{
}

float Product::Get_Price_X_Quantity()
{
	return (float)PricePerUnit * (float)Quantity;
}


