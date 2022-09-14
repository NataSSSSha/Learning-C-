#pragma once
#include <iostream>

using namespace std; 

class Wallet
{
public:
	int cash;
	string name;

	int Add(int addSum)
	{
		cash += addSum;
		return cash;
	}

	int  WriteOff(int cost)
	{
		if (cost <= cash)
		{
			cash -= cost;
		}
		else
		{
			throw new exception("The ammount is greater than the balance");
		}
		return cash;
	}
};

