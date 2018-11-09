#pragma once
#include "Hand.h"
class Straight :
	public Hand
{
public:
	Straight();
	~Straight();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

