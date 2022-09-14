#pragma once
#include "DebetCard.h"
class CreditCard : public DebetCard
{
	unsigned int debt = 0;

	int TakeCredit(int creditSum)
	{
		debt += creditSum;
		return debt;
	}

	int RepayCredit(int creditSum)
	{
		debt -= creditSum;
	}
};

