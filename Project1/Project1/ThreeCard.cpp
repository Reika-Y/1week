#include "ThreeCard.h"



ThreeCard::ThreeCard()
{
	cnt = 0;
}


ThreeCard::~ThreeCard()
{
}

HAND ThreeCard::GetHand(void)
{
	return HAND_THREECARD;
}

int ThreeCard::GetPoint(void)
{
	return 3;
}

//bool ThreeCard::RoleJuge(/*HUNDLE hd1, int num1, HUNDLE hd2, int num2*/)
//{
//	if (num1 == num2)
//	{
//		cnt++;
//	}
//	if (cnt == 2)
//	{
//		cnt= 0;
//		return true;
//	}
//	return false;
//}
