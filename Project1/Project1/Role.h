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


class Role
{
public:
	Role();
	~Role();

	void ReSetJudge(void);
	void PairJudge(CardInfo card[7]);//�y�A����
	int RoleCntSum(void);

private:
	HAND hand;
	int point[HAND_MAX];//���������̐��𐔂���
	int rolePoint;
};

