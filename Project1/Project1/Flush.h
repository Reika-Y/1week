#pragma once
#include "Hand.h"
class Flush :
	public Hand
{
public:
	Flush();
	~Flush();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
};

