#pragma once
#include "Hand.h"
class Straight :
	public Hand
{
public:
	Straight();
	~Straight();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

