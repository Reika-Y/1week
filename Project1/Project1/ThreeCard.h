#pragma once
#include "Hand.h"
class ThreeCard :
	public Hand
{
public:
	ThreeCard();
	~ThreeCard();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

