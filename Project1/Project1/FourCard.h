#pragma once
#include "Hand.h"
class FourCard :
	public Hand
{
public:
	FourCard();
	~FourCard();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

