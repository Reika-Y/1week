#include "Straight.h"



Straight::Straight()
{
}


Straight::~Straight()
{
}

HAND Straight::GetHand(void)
{
	return HAND_STRAIGHT;
}

int Straight::GetPoint(void)
{
	return 4;
}

//bool ThreeCard::RoleJuge(/*HUNDLE hd1, int num1, HUNDLE hd2, int num2*/)
//{
//	if (num2 == (num1 + 1))
//	{
//		icnt++;
//	}
//  else if(num2 == (num1 - 1))
//	{
//		dcnt++;
//	}
//	if ((icnt == 4) || (dcnt == 4))
//	{
//		icnt = 0;dcnt = 0;
//		return true;
//	}
//	return false;
//}

