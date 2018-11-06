#pragma once

class VECTOR2;

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
CardInfo cardInfo;

class Card
{
public:
	Card(VECTOR2 pos, VECTOR2 offSet, HUNDLE hundle,int num);
	~Card();
	void Draw(void);		// �`��֐�
	bool Update(void);		// �X�V�֐�
	bool SetPos(VECTOR2 pos);				// ���W��������
	bool SetOffSet(VECTOR2 offSet); 		// �̾�č��W��������
private:
	VECTOR2 pos;		// ���W
	VECTOR2 offSet;		// �̾�č��W
};

int DrawGraph(VECTOR2 pos, int GrHundle);
