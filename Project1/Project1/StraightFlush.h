#pragma once
#include "Hand.h"
class StraightFlush :
	public Hand
{
public:
	StraightFlush();
	~StraightFlush();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

