#pragma once
#include "Hand.h"
class Onepair :
	public Hand
{
public:
	Onepair();
	~Onepair();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

