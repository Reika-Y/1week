#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"

// 画像関連
const string fileName = "image/trump.png";
const VECTOR2 cardDiv = { 8,8 };
const VECTOR2 cardSize = { 60,90 };

/*
* ｺﾝｽﾄﾗｸﾀ
* @param (HUNDLE hundle) ﾄﾗﾝﾌﾟの柄
* @param (int num) ﾄﾗﾝﾌﾟの数字
*/
Card::Card(HUNDLE hundle, int num)
{
	ImageMng::GetInstance().GetID(fileName,cardSize,cardDiv);
	cardInfo.hundle = hundle;
	cardInfo.num	= num;
}


Card::~Card()
{
}

// 描画関数
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*画像のﾊﾝﾄﾞﾙ*/0);
}

// 更新関数
bool Card::Update(void)
{

}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	return DrawGraph(pos.x, pos.y, GrHundle, true);
}