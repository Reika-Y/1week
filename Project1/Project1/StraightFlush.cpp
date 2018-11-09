#include "StraightFlush.h"



StraightFlush::StraightFlush()
{
}


StraightFlush::~StraightFlush()
{
}

HAND StraightFlush::GetHand(void)
{
	return HAND_STRAIGHTFLUSH;
}

int StraightFlush::GetPoint(void)
{
	return 7;
}

//bool ThreeCard::RoleJuge(/*HUNDLE hd1, int num1, HUNDLE hd2, int num2*/)
//{
//	if(Straught(hd1, num1, hd2, num2)&&Flush(hd1, num1, hd2, num2))true
//	return false;
//}

