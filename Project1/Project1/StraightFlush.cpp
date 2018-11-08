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
