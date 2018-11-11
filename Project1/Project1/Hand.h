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

class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//役を返す
	virtual int GetPoint(void) = 0;		//得点を返す
	virtual bool RolrJuge(HUNDLE hd1, int num1, HUNDLE hd2, int num2) = 0;	//役判定
};

