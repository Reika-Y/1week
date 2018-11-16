#pragma once
#include "Card.h"
#include "Role.h"


class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//����Ԃ�
	virtual int GetPoint(void) = 0;		//���_��Ԃ�
	virtual bool RolrJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2) = 0;	//�𔻒�
};

