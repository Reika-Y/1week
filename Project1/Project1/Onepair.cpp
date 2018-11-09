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
