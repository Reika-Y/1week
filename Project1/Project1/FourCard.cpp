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
