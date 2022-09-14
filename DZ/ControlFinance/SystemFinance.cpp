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
#include "SystemFinance.h"

using namespace std;

SystemFinance* SystemFinance::instance = nullptr;

DebetCard SystemFinance::FindCardByName(string name)
{
	for (int i = 0; i < myDebetCards.size(); i++)
	{
		if (myDebetCards[i].myName == name)
			return myDebetCards[i];
	}
}

CreditCard SystemFinance::FindCreditCardByName(string name)
{
	for (int i = 0; i < myCreditCards.size(); i++)
	{
		if (myCreditCards[i].myName == name)
			return myCreditCards[i];
	}
}

Wallet SystemFinance::FindWalletByName(string name)
{
	for (int i = 0; i < myWallets.size(); i++)
	{
		if (myWallets[i].name == name)
			return myWallets[i];
	}
}

void SystemFinance::InfoOfCost(Cost cost)
{
	cout << cost.time.day << "." << cost.time.month << "." << cost.time.year << " : " << cost.sum << endl;
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << cost.time.day << "." << cost.time.month << "." << cost.time.year << " : " << cost.sum << endl;
	fout.close();
}

void SystemFinance::ReportCostsDay()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report Costs Day\n";
	fout.close();

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	for (auto& cost : myCost)
	{
		if (cost.time.day == now->tm_mday && cost.time.month == now->tm_mon + 1 && cost.time.year == now->tm_year + 1900)
			InfoOfCost(cost);
	}
}

void SystemFinance::ReportCostsWeek()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report Costs Week\n";
	fout.close();

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	int dayOfWeek;
	for (auto& cost : myCost)
	{
		dayOfWeek = now->tm_wday;
		while (dayOfWeek >= 0)
		{
			if (now->tm_mday - dayOfWeek > 0 && cost.time.month == now->tm_mon + 1 && cost.time.year == now->tm_year + 1900)
			{
				if (cost.time.day == now->tm_mday - dayOfWeek)
					InfoOfCost(cost);
			}
			if (now->tm_mday - dayOfWeek <= 0)
			{
				if (now->tm_mon + 1 == 2 || now->tm_mon + 1 == 4 || now->tm_mon + 1 == 6 || now->tm_mon + 1 == 8 || now->tm_mon + 1 == 9
					|| now->tm_mon + 1 == 11)
				{
					if (cost.time.day == 31 + now->tm_mday - dayOfWeek && cost.time.month == now->tm_mon && cost.time.year == now->tm_year + 1900)
						InfoOfCost(cost);
				}
				if (now->tm_mon + 1 == 5 || now->tm_mon + 1 == 7 || now->tm_mon + 1 == 10 || now->tm_mon + 1 == 12)
				{
					if (cost.time.day == 30 + now->tm_mday - dayOfWeek && cost.time.month == now->tm_mon && cost.time.year == now->tm_year + 1900)
						InfoOfCost(cost);
				}
				if (now->tm_mon + 1 == 1 && cost.time.day == 31 + now->tm_mday - dayOfWeek && cost.time.month == 12 && cost.time.year == now->tm_year + 1900 - 1)
					InfoOfCost(cost);

				if (now->tm_mon + 1 == 3 && cost.time.day == 28 + now->tm_mday - dayOfWeek && cost.time.month == 12 && cost.time.year == now->tm_year + 1900)
					SumOfCategory(cost);
			}
			dayOfWeek--;
		}
	}	
}

void SystemFinance::ReportCostsMonth()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report Costs Month\n";
	fout.close();

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	for (auto& cost : myCost)
	{
		if (cost.time.month == now->tm_mon + 1 && cost.time.year == now->tm_year + 1900)
			InfoOfCost(cost);
	}
}

void SystemFinance::QSortCosts(int left, int right)
{
	int i = left;
	int j = right;		
	Cost mid = myCost[(left + right) / 2];
	isSortCosts = right;

	do
	{
		while (myCost[i].sum < mid.sum)
			i++;
		while (myCost[j].sum > mid.sum)
			j--;

		if (i <= j)
		{
			auto tmp = myCost[i];
			myCost[i] = myCost[j];
			myCost[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		QSortCosts(left, j);
	if (i < right)
		QSortCosts(i, right);
}

void SystemFinance::ReportTOPCostsForWeek()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report TOP Costs Week\n";
	fout.close();

	if (!isSortCosts)
		QSortCosts(0, myCost.size() - 1);

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	int dayOfWeek;

	for (int i = myCost.size() - 1; i < myCost.size() - 4; i--)
	{
		int dayOfWeek = now->tm_wday;
		while (dayOfWeek >= 0)
		{
			if (now->tm_mday - dayOfWeek > 0 && myCost[i].time.month == now->tm_mon + 1 && myCost[i].time.year == now->tm_year + 1900)
			{
				if (myCost[i].time.day == now->tm_mday - dayOfWeek)
					InfoOfCost(myCost[i]);
			}
			if (now->tm_mday - dayOfWeek <= 0)
			{
				if (now->tm_mon + 1 == 2 || now->tm_mon + 1 == 4 || now->tm_mon + 1 == 6 || now->tm_mon + 1 == 8 || now->tm_mon + 1 == 9
					|| now->tm_mon + 1 == 11)
				{
					if (myCost[i].time.day == 31 + now->tm_mday - dayOfWeek && myCost[i].time.month == now->tm_mon && myCost[i].time.year == now->tm_year + 1900)
						InfoOfCost(myCost[i]);
				}
				if (now->tm_mon + 1 == 5 || now->tm_mon + 1 == 7 || now->tm_mon + 1 == 10 || now->tm_mon + 1 == 12)
				{
					if (myCost[i].time.day == 30 + now->tm_mday - dayOfWeek && myCost[i].time.month == now->tm_mon && myCost[i].time.year == now->tm_year + 1900)
						InfoOfCost(myCost[i]);
				}
				if (now->tm_mon + 1 == 1 && myCost[i].time.day == 31 + now->tm_mday - dayOfWeek && myCost[i].time.month == 12 && myCost[i].time.year == now->tm_year + 1900 - 1)
					InfoOfCost(myCost[i]);

				if (now->tm_mon + 1 == 3 && myCost[i].time.day == 28 + now->tm_mday - dayOfWeek && myCost[i].time.month == 12 && myCost[i].time.year == now->tm_year + 1900)
					SumOfCategory(myCost[i]);
			}
			dayOfWeek--;
		}
	}
}

void SystemFinance::ReportTOPCostsForMonth()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report TOP Costs Month\n";
	fout.close();

	if (!isSortCosts)
		QSortCosts(0, myCost.size() - 1);

	time_t t = time(nullptr);
	tm* now = localtime(&t);

	for (int i = 0; i < 3; i++)
	{
		if (myCost[i].time.month == now->tm_mon + 1 && myCost[i].time.year == now->tm_year + 1900)
			InfoOfCost(myCost[i]);
	}
}

void SystemFinance::SumOfCategory(Cost cost)
{
	switch (cost.numberOfCategory)
	{
	case(1):
	{
		Category["ObligatoryPayments"] += cost.sum;
		break;
	}
	case(2):
	{
		Category["FoodStuff"] += cost.sum;
		break;
	}
	case(3):
	{
		Category["HouseholdGoods"] += cost.sum;
		break;
	}
	case(4):
	{
		Category["Technic"] += cost.sum;
			break;
	}
	case(5):
	{
		Category["Pets"] += cost.sum;
		break;
	}
	case(6):
	{
		Category["Child"] += cost.sum;
		break;
	}
	case(7):
	{
		Category["Car"] += cost.sum;
		break;
	}
	case(8):
	{
		Category["Clothes"] += cost.sum;
		break;
	}
	case(9):
	{
		Category["Other"] += cost.sum;
		break;
	}
	default:
		break;
	}
}

void SystemFinance::SortAndPrintCategory(map<string, int>& M)
{
	vector<pair<string, int> > A;

	for (auto& it : M) {
		A.push_back(it);
	}

	sort(A.begin(), A.end(), Comp);

	fout.open(path, ofstream::app);

	for (int i = A.size(); i > A.size() - 3; i--)
	{
		cout << A[i - 1].first << " " << A[i - 1].second << endl;
		if (fout.is_open())
			fout << A[i - 1].first << " " << A[i - 1].second << endl;
	}
	fout.close();
}

void SystemFinance::ReportTOPCategoryForWeek()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report TOP Catgory Week\n";
	fout.close();

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	int dayOfWeek;

	for (auto& cost : myCost)
	{
		int dayOfWeek = now->tm_wday;
		while (dayOfWeek >= 0)
		{
			if (now->tm_mday - dayOfWeek > 0 && cost.time.month == now->tm_mon + 1 && cost.time.year == now->tm_year + 1900)
			{
				if (cost.time.day == now->tm_mday - dayOfWeek)
					SumOfCategory(cost);
			}
			if (now->tm_mday - dayOfWeek <= 0)
			{
				if (now->tm_mon + 1 == 2 || now->tm_mon + 1 == 4 || now->tm_mon + 1 == 6 || now->tm_mon + 1 == 8 || now->tm_mon + 1 == 9
					|| now->tm_mon + 1 == 11)
				{
					if (cost.time.day == 31 + now->tm_mday - dayOfWeek && cost.time.month == now->tm_mon && cost.time.year == now->tm_year + 1900)
						SumOfCategory(cost);
				}
				if (now->tm_mon + 1 == 5 || now->tm_mon + 1 == 7 || now->tm_mon + 1 == 10 || now->tm_mon + 1 == 12)
				{
					if (cost.time.day == 30 + now->tm_mday - dayOfWeek && cost.time.month == now->tm_mon && cost.time.year == now->tm_year + 1900)
						SumOfCategory(cost);
				}
				if (now->tm_mon + 1 == 1 && cost.time.day == 31 + now->tm_mday - dayOfWeek && cost.time.month == 12 && cost.time.year == now->tm_year + 1900 - 1)
					SumOfCategory(cost);

				if (now->tm_mon + 1 == 3 && cost.time.day == 28 + now->tm_mday - dayOfWeek && cost.time.month == 12 && cost.time.year == now->tm_year + 1900)
					SumOfCategory(cost);
			}
			dayOfWeek--;
		}
	}
	SortAndPrintCategory(Category);
	for (auto it : Category)
		it.second = 0;
}

void SystemFinance::ReportTOPCategoryForMonth()
{
	fout.open(path, ofstream::app);
	if (fout.is_open())
		fout << "Report TOP Catgory Month\n";
	fout.close();

	time_t t = time(nullptr);
	tm* now = localtime(&t);

	for (auto& cost : myCost)
	{
		if (cost.time.month == now->tm_mon + 1 && cost.time.year == now->tm_year + 1900)
			SumOfCategory(cost);
	}
	SortAndPrintCategory(Category);
	for (auto it : Category)
		it.second = 0;
}
