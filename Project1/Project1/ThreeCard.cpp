#include "ThreeCard.h"



ThreeCard::ThreeCard()
{
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
