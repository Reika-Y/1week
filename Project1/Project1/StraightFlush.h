#pragma once
#include "Hand.h"
class StraightFlush :
	public Hand
{
public:
	StraightFlush();
	~StraightFlush();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

