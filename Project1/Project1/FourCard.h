#pragma once
#include "Hand.h"
class FourCard :
	public Hand
{
public:
	FourCard();
	~FourCard();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

