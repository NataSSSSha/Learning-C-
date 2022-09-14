#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Cost.h"
#include "CreditCard.h"
#include "DebetCard.h"
#include "Wallet.h"
#include "SystemFinance.h"
#include "Menu.h"


using namespace std;

int main()
{
	auto MyFinance = SystemFinance::getInstance();
	int choose;
	do
	{
		Menu::ShowMenu();
		std::cin >> choose;
		switch (choose)
		{
		case(1):
		{
			Menu::AddCard();
			int choose1;
			std::cin >> choose1;
			switch (choose1)
			{
			case(1):
			{
				auto debetCard = new DebetCard();
				std::cout << "Enter card number:\n";
				std::cin >> debetCard->numberCard;
				std::cout << "Enter the amountof money on the card:\n";
				std::cin >> debetCard->sum;
				std::cout << "Give some name of your card:\n";
				std::cin >> debetCard->myName;

				MyFinance->myDebetCards.push_back(*debetCard);
				break;
			}
			case(2):
			{
				auto creditCard = new CreditCard();

				std::cout << "Enter card number:\n";
				std::cin >> creditCard->numberCard;
				std::cout << "Enter the amount of money on the card:\n";
				std::cin >> creditCard->sum;
				std::cout << "Give some name of your card:\n";
				std::cin >> creditCard->myName;

				MyFinance->myCreditCards.push_back(*creditCard);
				break;
			}
			case(3):
			{
				auto myWallet = new Wallet();

				std::cout << "Enter amount of cash in your wallet:\n";
				std::cin >> myWallet->cash;
				std::cout << "Give some name of your wallet:\n";
				std::cin >> myWallet->name;

				MyFinance->myWallets.push_back(*myWallet);
				break;
			}
			}
			break;
		}
		case (2):
		{
			std::cout << "Enter type:\n"
				<< "1 - debet card\n"
				<< "2 - credit card\n"
				<< "3 - wallet\n";
			int choose2;
			std::cin >> choose2;
			std::cout << "Enter the sum of money:\n";
			int sum;
			std::cin >> sum;
			std::cout << "Enter the name of card:\n";
			string name;
			std::cin >> name;
			switch (choose2)
			{
			case(1):
			{
				auto card = MyFinance->FindCardByName(name);
				card.Add(sum);
				break;
			}
			case(2):
			{
				auto card = MyFinance->FindCreditCardByName(name);
				card.Add(sum);
				break;
			}
			case (3):
			{
				auto wallet = MyFinance->FindWalletByName(name);
				wallet.Add(sum);
				break;
			}
			default:
				break;
			}
			break;
		}
		case (3):
		{
			auto cost = new Cost();
			Menu::ShowCategory();
			std::cin >> cost->numberOfCategory;
			std::cout << "Choose the date of cost:\n"
				<< "1 - today,\n"
				<< "2 - another day.\n";
			int chooseDate;
			std::cin >> chooseDate;
			switch (chooseDate)
			{
			case(1):
			{
				time_t t = time(nullptr);
				tm* now = localtime(&t);
				cost->time.year = now->tm_year + 1900;
				cost->time.month = now->tm_mon + 1;
				cost->time.day = now->tm_mday;
				break;
			}
			case(2):
			{
				std::cout << "Enter year:\n";
				std::cin >> cost->time.year;
				std::cout << "Enter month:\n";
				std::cin >> cost->time.month;
				std::cout << "Enter day:\n";
				std::cin >> cost->time.day;
				break;
			}
			default:
				break;
			}
			std::cout << "Enter the sum:\n";
			cin >> cost->sum;

			MyFinance->myCost.push_back(*cost);
			MyFinance->isSortCosts = false;
			break;
		}
		case (4):
		{
			Menu::ShowReportInfo();
			int chooseReport;
			std::cin >> chooseReport;
			switch (chooseReport)
			{
			case (1):
			{
				MyFinance->ReportCostsDay();
				break;
			}
			case (2):
			{
				MyFinance->ReportCostsWeek();
				break;
			}
			case (3):
			{
				MyFinance->ReportCostsMonth();
				break;
			}
			case (4):
			{
				MyFinance->ReportTOPCostsForWeek();
				break;
			}
			case (5):
			{
				MyFinance->ReportTOPCostsForMonth();
				break;
			}
			case (6):
			{
				MyFinance->ReportTOPCategoryForWeek();
				break;
			}
			case (7):
			{
				MyFinance->ReportTOPCategoryForMonth();
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
	while (choose != 5);

}
