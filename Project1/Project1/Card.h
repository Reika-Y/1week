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
	Card();
	~Card();
	void Draw(void);	// 描画関数
	bool Update(void);		// 更新関数
private:
	VECTOR2 pos;		// 座標
	VECTOR2 offSet;		// ｵﾌｾｯﾄ座標
	int speed;			// 速さ
};

