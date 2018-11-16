#pragma once
#include "Card.h"
#include "Role.h"


class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//–ð‚ð•Ô‚·
	virtual int GetPoint(void) = 0;		//“¾“_‚ð•Ô‚·
	virtual bool RolrJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2) = 0;	//–ð”»’è
};

