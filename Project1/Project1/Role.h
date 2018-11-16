#pragma once

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

	int PairJudge(int num,int num2);//ペア判定
	void CntClear(void);

private:
	int pairCnt;
};

