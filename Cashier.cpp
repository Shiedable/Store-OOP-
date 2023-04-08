#include <iostream>
#include <iomanip>

#include "Cashier.h"

void cashier::print_receipt(std::vector<Product*> cart, time_t current_time)
{
	float subtotal = 0;
	float discount_total = 0;

	float total_price_per_product = 0;
	float discount_temp;

	struct tm* time_of_purchase = gmtime(&current_time);



	std::cout << "Date: " << ctime(&current_time) << std::endl;
	std::cout << "-----------Products-----------" << std::endl;

	for (int i = 0; i < cart.size(); i++)
	{
		total_price_per_product = cart[i]->Get_Price_X_Quantity();
		discount_temp = cart[i]->Get_Discount(*time_of_purchase, total_price_per_product);
		cart[i]->Print(total_price_per_product, discount_temp);

		subtotal = subtotal + total_price_per_product;
		discount_total = discount_total + discount_temp;
	}

	std::cout << "\n------------------------------\n";
	std::cout << "SUBTOTAL: $" << std::fixed << std::setprecision(2) << subtotal << std::endl;
	std::cout << "DISCOUNT: -" << std::fixed << std::setprecision(2) << discount_total << "\n\n";
	std::cout << "TOTAL: $" << std::fixed << std::setprecision(2) << (float)subtotal - (float)discount_total << std::endl;
}
