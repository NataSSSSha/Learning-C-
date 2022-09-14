#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Cost.h"
#include "CreditCard.h"
#include "DebetCard.h"
#include "Wallet.h"
#include <algorithm>
#include <map>
#include <fstream>


using namespace std;


class SystemFinance
{
	static SystemFinance* instance;
	SystemFinance() {}
	SystemFinance(const  SystemFinance&);

	map < string, int > Category = { {"ObligatoryPayments" , 0}, {"FoodStuff", 0}, {"HouseholdGoods", 0}, {"Technic", 0}, {"Pets", 0}, {"Child", 0},
									{"Car", 0}, {"Clothes", 0}, {"Other", 0} };

	string path = { "reports.txt" };

	ofstream fout;

public:

	static SystemFinance* getInstance()
	{
		if (!instance)
			instance = new SystemFinance();
		return instance;
	}

	vector <Cost> myCost;
	vector <DebetCard> myDebetCards;
	vector <CreditCard> myCreditCards;
	vector <Wallet> myWallets;

	int isSortCosts = false;

	DebetCard FindCardByName(string name);

	CreditCard FindCreditCardByName(string name);

	Wallet FindWalletByName(string name);

	void InfoOfCost(Cost cost);

	void QSortCosts(int left, int right);

	static bool Comp(pair<string, int>& a, pair<string, int>& b)
	{
		return a.second < b.second;
	}

	void ReportCostsDay();

	void ReportCostsWeek();

	void ReportCostsMonth();

	void ReportTOPCostsForWeek();
	
	void ReportTOPCostsForMonth();

	void SumOfCategory(Cost cost);

	void SortAndPrintCategory(map<string, int>& M);

	void ReportTOPCategoryForWeek();

	void ReportTOPCategoryForMonth();
};

 

