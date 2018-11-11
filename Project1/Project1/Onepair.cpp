#include "Onepair.h"

Onepair::Onepair()
{
}


Onepair::~Onepair()
{
}

HAND Onepair::GetHand(void)
{
	return HAND_ONEPAIR;
}

int Onepair::GetPoint(void)
{
	return 1;
}

bool Onepair::RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2)
{
	if (num1 == num2)
	{
		return true;
	}
	return false;
}
