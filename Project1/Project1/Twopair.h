#pragma once
#include "Hand.h"
class Twopair :
	public Hand
{
public:
	Twopair();
	~Twopair();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

