#pragma once
#include "Hand.h"
class Onepair :
	public Hand
{
public:
	Onepair();
	~Onepair();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

