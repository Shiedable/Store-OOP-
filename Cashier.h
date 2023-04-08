#pragma once

#include <vector>
#include <ctime>
#include "Cloth.h"
#include "Appliance.h"
#include "Food_And_Beverage.h"

class cashier
{
public:
	void print_receipt(std::vector<Product*> cart, time_t current_time);
};

