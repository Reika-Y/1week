#pragma once
#include "Hand.h"
class Flush :
	public Hand
{
public:
	Flush();
	~Flush();

	HAND GetHand(void);		//����Ԃ�
	int GetPoint(void);		//���_��Ԃ�
};

