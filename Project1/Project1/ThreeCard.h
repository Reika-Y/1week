#pragma once
#include "Hand.h"
class ThreeCard :
	public Hand
{
public:
	ThreeCard();
	~ThreeCard();

	HAND GetHand(void);		//役を返す
	int GetPoint(void);		//得点を返す
	//bool RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2);	//役判定
	int cnt;
};

