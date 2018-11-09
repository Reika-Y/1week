#include "FourCard.h"



FourCard::FourCard()
{
}


FourCard::~FourCard()
{
}

HAND FourCard::GetHand(void)
{
	return HAND_FOURCARD;
}

int FourCard::GetPoint(void)
{
	return 6;
}

//bool FourCard::RoleJuge(/*HUNDLE hd1, int num1, HUNDLE hd2, int num2*/)
//{
//	if (num1 == num2)
//	{
//		cnt++;
//	}
//	if (cnt == 3)
//	{
//		return true;
//	}
//	return false;
//}

