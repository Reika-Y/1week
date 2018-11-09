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
	//bool RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2);	//–ð”»’è
	int cnt;
};

