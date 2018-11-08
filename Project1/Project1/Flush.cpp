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
