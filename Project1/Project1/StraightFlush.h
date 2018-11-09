#pragma once
#include "Hand.h"
class StraightFlush :
	public Hand
{
public:
	StraightFlush();
	~StraightFlush();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

