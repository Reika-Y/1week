#include "Twopair.h"



Twopair::Twopair()
{
}


Twopair::~Twopair()
{
}

HAND Twopair::GetHand(void)
{
	return HAND_TWOPAIR;
}

int Twopair::GetPoint(void)
{
	return 2;
}
