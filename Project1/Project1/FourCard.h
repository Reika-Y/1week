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
	//bool RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2);	//�𔻒�

};

