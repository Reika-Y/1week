#pragma once
#include "Hand.h"
class ThreeCard :
	public Hand
{
public:
	ThreeCard();
	~ThreeCard();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

