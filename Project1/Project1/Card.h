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
	Card(HUNDLE hundle,int num, VECTOR2 cardSize);
	~Card();
	void Draw(void);		// �`��֐�
	bool Update(void);		// �X�V�֐�
	bool SetDown(bool flag);		// ���������p
private:
	VECTOR2 pos;		// ���W
	VECTOR2 offSet;		// �̾�č��W
	VECTOR2 cardSize;	// ����
	int speed;			// ����
	bool nowFlag;		// ���݂̏��
	bool downFlag;		// ���������p
};

int DrawGraph(VECTOR2 pos, int GrHundle);
