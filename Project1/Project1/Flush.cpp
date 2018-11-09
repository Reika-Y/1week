#include "Flush.h"



Flush::Flush()
{
}


Flush::~Flush()
{
}

HAND Flush::GetHand(void)
{
	return HAND_FLUSH;
}

int Flush::GetPoint(void)
{
	return 5;
}

//bool ThreeCard::RoleJuge(/*HUNDLE hd1, int num1, HUNDLE hd2, int num2*/)
//{
//	if (hd1 == hd2)
//	{
//		cnt++;
//	}
//	if (cnt == 4)
//	{
//		cnt = 0;
//		return true;
//	}
//	return false;
//}

