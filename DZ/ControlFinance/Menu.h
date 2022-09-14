#pragma once
#include <iostream>

static class Menu
{
public:

	static void ShowMenu()
	{
		std::cout << "Choose number\n"
			<< "1 - Add card or wallet\n"
			<< "2 - Write down income\n"
			<< "3 - Write down cost\n"
			<< "4 - Create report\n"
			<< "5 - Finish\n";
	}

	static void AddCard()
	{
		std::cout << "What type add?\n"
			<< "1 - debet card\n"
			<< "2 - credit card\n"
			<< "3 - wallet\n";
	}

	static void ShowCategory()
	{
		std::cout << "Choose the category of cost:\n"
			<< "1 - ObligatoryPayments,\n"
			<< "2 - FoodStuff,\n"
			<< "3 - HouseholdGoods,\n"
			<< "4 - Technic,\n"
			<< "5 - Pets,\n"
			<< "6 - Child,\n"
			<< "7 - Car,\n"
			<< "8 - Clothes,\n"
			<< "9 - Other.\n";
	}

	static void ShowReportInfo()
	{
		std::cout << "Choose number of report:\n"
			<< "1 - show all costs for the day\n"
			<< "2 - show all costs for the week\n"
			<< "3 - show all costs for the month\n"
			<< "4 - show TOP - 3 max costs for the week\n"
			<< "5 - show TOP - 3 max costs for the month\n"
			<< "6 - show TOP - 3 categories for the week\n"
			<< "7 - show TOP - 3 categories for the month\n";
	}
};

