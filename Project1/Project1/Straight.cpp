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
