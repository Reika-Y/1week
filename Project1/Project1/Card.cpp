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
* @param (VECTOR2 pos) 座標
* @param (VECTOR2 offSet)　描画時のｵﾌｾｯﾄ座標
* @param (HUNDLE hundle) ﾄﾗﾝﾌﾟの柄
* @param (int num) ﾄﾗﾝﾌﾟの数字
*/
Card::Card(VECTOR2 pos, VECTOR2 offSet, HUNDLE hundle, int num)
{
	ImageMng::GetInstance().GetID(fileName,cardSize,cardDiv);
	cardInfo.hundle = hundle;
	cardInfo.num	= num;
	Card::pos       = pos;
	Card::offSet    = offSet;
}


Card::~Card()
{
}

// 描画関数
void Card::Draw(void)
{
	int id = 0;
	DrawGraph(pos + offSet, fileName[id]);
}

// 更新関数
bool Card::Update(void)
{
}

/*
*　座標書き換え
* @param (VECTOR2 pos) 書き換えたい座標
*/
bool Card::SetPos(VECTOR2 pos)
{
	Card::pos = pos;
	return true;
}
/*
* ｵﾌｾｯﾄ座標書き換え
* @param (VECTOR2 offSet)	書き換えたいｵﾌｾｯﾄ座標
*/
bool Card::SetOffSet(VECTOR2 offSet)
{
	Card::offSet = offSet;
	return true;
}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	return DrawGraph(pos.x, pos.y, GrHundle, true);
}