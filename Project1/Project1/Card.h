#pragma once
#include "VECTOR2.h"

// 柄
enum HUNDLE
{
	HEART,		// ﾊｰﾄ
	DIA,		// ﾀﾞｲｱ
	CLUB,		// ｸﾗﾌﾞ
	SPADE,		// ｽﾍﾟｰﾄﾞ
	HUNDLE_MAX
};

// ｶｰﾄﾞ情報
struct CardInfo {
	HUNDLE hundle;		// 柄
	int num;			// 番号
};


class Card
{
public:
	Card(VECTOR2 pos, VECTOR2 offSet, HUNDLE hundle,int num);
	~Card();
	void Draw(void);		// 描画関数
	bool Update(void);		// 更新関数
	const VECTOR2 GetPos(void);				// 座標取得用
	bool SetPos(VECTOR2 pos);				// 座標書き換え
	bool SetOffSet(VECTOR2 offSet); 		// ｵﾌｾｯﾄ座標書き換え
private:
	VECTOR2 pos;		// 座標
	VECTOR2 offSet;		// ｵﾌｾｯﾄ座標
	CardInfo cardInfo;
};

int DrawGraph(VECTOR2 pos, int GrHundle);
