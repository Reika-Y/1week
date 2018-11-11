#pragma once
#include "Card.h"

enum HAND {
	HAND_ONEPAIR,		//�����y�A
	HAND_TWOPAIR,		//�c�[�y�A
	HAND_THREECARD,		//�X���[�J�[�h
	HAND_FOURCARD,		//�t�H�[�J�[�h
	HAND_FLUSH,			//�t���b�V��
	HAND_STRAIGHT,		//�X�g���[�g
	HAND_STRAIGHTFLUSH, //�X�g���[�g�t���b�V��
	HAND_MAX
};

class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//����Ԃ�
	virtual int GetPoint(void) = 0;		//���_��Ԃ�
	virtual bool RolrJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2) = 0;	//�𔻒�
};

