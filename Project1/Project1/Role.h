#pragma once
#include "Card.h"


enum HAND {
	HAND_ONEPAIR,		//ワンペア
	HAND_TWOPAIR,		//ツーペア
	HAND_THREECARD,		//スリーカード
	HAND_FOURCARD,		//フォーカード
	HAND_FLUSH,			//フラッシュ
	HAND_STRAIGHT,		//ストレート
	HAND_STRAIGHTFLUSH, //ストレートフラッシュ
	HAND_MAX
};


class Role
{
public:
	Role();
	~Role();

	void ReSetJudge(void);
	void PairJudge(CardInfo card[7]);//ペア判定
	int RoleCntSum(void);

private:
	HAND hand;
	int point[HAND_MAX];//揃った役の数を数える
	int rolePoint;
};

