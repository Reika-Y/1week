#pragma once
#include "VECTOR2.h"

// ��
enum HUNDLE
{
	HEART,		// ʰ�
	DIA,		// �޲�
	CLUB,		// ����
	SPADE,		// ��߰��
	HUNDLE_MAX
};

// ���ޏ��
struct CardInfo {
	HUNDLE hundle;		// ��
	int num;			// �ԍ�
};


class Card
{
public:
	Card(VECTOR2 pos, VECTOR2 offSet, HUNDLE hundle,int num);
	~Card();
	void Draw(void);		// �`��֐�
	bool Update(void);		// �X�V�֐�
	const VECTOR2 GetPos(void);				// ���W�擾�p
	bool SetPos(VECTOR2 pos);				// ���W��������
	bool SetOffSet(VECTOR2 offSet); 		// �̾�č��W��������
private:
	VECTOR2 pos;		// ���W
	VECTOR2 offSet;		// �̾�č��W
	CardInfo cardInfo;
};

int DrawGraph(VECTOR2 pos, int GrHundle);
