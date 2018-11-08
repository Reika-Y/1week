#pragma once
#include "Hand.h"
class Flush :
	public Hand
{
public:
	Flush();
	~Flush();

	HAND GetHand(void);		//–ð‚ð•Ô‚·
	int GetPoint(void);		//“¾“_‚ð•Ô‚·
};

