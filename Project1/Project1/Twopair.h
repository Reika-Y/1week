#pragma once
#include "Hand.h"
class Twopair :
	public Hand
{
public:
	Twopair();
	~Twopair();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

