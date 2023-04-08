#include <vector>
#include <ctime>
#include "Cashier.h"

int main()
{

	std::vector<Product*> cart;

	cart.push_back(new Food_And_Beverage("apples", "BrandA", 1.50f, "2023-01-26", 3.0));
	cart.push_back(new Food_And_Beverage("milk", "BrandM", 1.50f, "2023-01-02", 3.0));
	cart.push_back(new Cloth("T-shirt", "BrandT", 15.99f, "M", "violet", 2.0));
	cart.push_back(new Appliance("laptop", "BrandL", 2345, "ModelL", "2021-03-03", 1.125, 1.0));

	time_t current_time = time(0);
	struct tm *time_of_purchase = gmtime(&current_time);
	cashier receipt;
	receipt.print_receipt(cart, current_time);

	for (int i = 0; i < cart.size(); i++)
		delete cart[i];
	cart.clear();

	return 0;
}