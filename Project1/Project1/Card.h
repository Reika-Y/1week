#pragma once

class VECTOR2;

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
CardInfo cardInfo;

class Card
{
public:
	Card(VECTOR2 pos, VECTOR2 offSet, HUNDLE hundle,int num);
	~Card();
	void Draw(void);		// 描画関数
	bool Update(void);		// 更新関数
	bool SetPos(VECTOR2 pos);				// 座標書き換え
	bool SetOffSet(VECTOR2 offSet); 		// ｵﾌｾｯﾄ座標書き換え
private:
	VECTOR2 pos;		// 座標
	VECTOR2 offSet;		// ｵﾌｾｯﾄ座標
};

int DrawGraph(VECTOR2 pos, int GrHundle);
