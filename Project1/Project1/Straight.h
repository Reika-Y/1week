#pragma once
#include "Hand.h"
class Straight :
	public Hand
{
public:
	Straight();
	~Straight();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

