#pragma once

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

	int PairJudge(int num,int num2);//�y�A����
	void CntClear(void);

private:
	int pairCnt;
};

