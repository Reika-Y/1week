#pragma once
#include "Hand.h"
class Twopair :
	public Hand
{
public:
	Twopair();
	~Twopair();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

