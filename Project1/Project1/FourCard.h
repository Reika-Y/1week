#pragma once
#include "Hand.h"
class FourCard :
	public Hand
{
public:
	FourCard();
	~FourCard();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

