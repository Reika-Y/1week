#pragma once
#include "Card.h"
#include "Role.h"


class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//役を返す
	virtual int GetPoint(void) = 0;		//得点を返す
	virtual bool RolrJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2) = 0;	//役判定
};

