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
	Card(HUNDLE hundle,int num, VECTOR2 cardSize);
	~Card();
	void Draw(void);		// 描画関数
	bool Update(void);		// 更新関数
	bool SetDown(bool flag);		// 強制落下用
private:
	VECTOR2 pos;		// 座標
	VECTOR2 offSet;		// ｵﾌｾｯﾄ座標
	VECTOR2 cardSize;	// ｻｲｽﾞ
	int speed;			// 速さ
	bool nowFlag;		// 現在の情報
	bool downFlag;		// 強制落下用
};

int DrawGraph(VECTOR2 pos, int GrHundle);
