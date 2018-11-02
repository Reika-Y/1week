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
	Card();
	~Card();
	void Draw(void);	// �`��֐�
	bool Update(void);		// �X�V�֐�
private:
	VECTOR2 pos;		// ���W
	VECTOR2 offSet;		// �̾�č��W
	int speed;			// ����
};

