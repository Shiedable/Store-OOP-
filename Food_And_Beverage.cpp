#include "Food_And_Beverage.h"
#include <time.h>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <math.h>

Food_And_Beverage::Food_And_Beverage():Product()
{
	ExpirationDate = '\0';
}

Food_And_Beverage::Food_And_Beverage(std::string name, std::string brand, float price, std::string exp_date, float quantity):Product(name, brand, price, quantity)
{
	ExpirationDate = exp_date;
}

float Food_And_Beverage::Get_Discount(struct tm time_of_purchase, float price_x_quantity)
{
	int yy, mm, dd, hh, min, ss;
	const char* ExpDate = ExpirationDate.c_str();
	sscanf_s(ExpDate, "%d-%d-%d %d:%d:%d", &yy, &mm, &dd, &hh, &min, &ss);

	struct tm exp_date;

	exp_date.tm_year = yy - 1900;
	exp_date.tm_mon = mm - 1;
	exp_date.tm_mday = dd;
	exp_date.tm_hour = hh;
	exp_date.tm_min = min;
	exp_date.tm_sec = ss;

	time_t day_diff = exp_date.tm_mday - time_of_purchase.tm_mday;
	time_t month_diff = exp_date.tm_mon - time_of_purchase.tm_mon;
	time_t year_diff = exp_date.tm_year - time_of_purchase.tm_year;

	if (year_diff || month_diff || day_diff < 1)
	{
		return (float)price_x_quantity * (float)((float)70/(float)100);;
	}
	if (day_diff < 6)
	{
		return (float)price_x_quantity * (float)((float)30/(float)100);;
	}
	return 0;

}

void Food_And_Beverage::Print(float total, float discount)
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