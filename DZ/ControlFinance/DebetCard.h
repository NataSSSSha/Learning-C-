#pragma once
#include <iostream>

using namespace std;

class DebetCard
{
public:
	string numberCard;
	int sum = 0;
	string myName;

	DebetCard() {}

	DebetCard(string numberCard, int sum, string myName)
	{
		this->numberCard = numberCard;
		this->sum = sum;
		this->myName = myName;
	}

	int ShowBalance()
	{
		return sum;
	}

	int Add(int addSum)
	{
		sum += addSum;
		return sum;
	}

	int  WriteOff(int cost)
	{
		if (cost <= sum)
		{
			sum -= cost;
		}
		else
		{
			throw new exception("The ammount is greater than the balance");
		}
		return sum;
	}
};

