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
	bool RoleJuge(/*自身のカードの情報、１つ隣のカードの情報*/);	//役判定
	//bool RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2);	//役判定
};

