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
	bool RoleJuge(/*���g�̃J�[�h�̏��A�P�ׂ̃J�[�h�̏��*/);	//�𔻒�
	//bool RoleJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2);	//�𔻒�
};

