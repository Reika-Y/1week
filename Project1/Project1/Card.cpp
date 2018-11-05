#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"
#include "GameBoard.h"

// 落ちる速さ
const int def_speed = 5;

const VECTOR2 cardDiv = VECTOR2(8, 8);
/*
* ｺﾝｽﾄﾗｸﾀ
* @param (HUNDLE hundle) ﾄﾗﾝﾌﾟの柄
* @param (int num) ﾄﾗﾝﾌﾟの数字
* @param (VECTOR2 cardSize) ﾄﾗﾝﾌﾟのｻｲｽﾞ
*/
Card::Card(HUNDLE hundle, int num, VECTOR2 cardSize)
{
	//ImageMng::GetID("f_name", cardSize, cardDiv, VECTOR2(0, 0));
	cardInfo.hundle = hundle;
	cardInfo.num	= num;
	this->cardSize = cardSize;
	speed = 0;
	nowFlag = true;
	downFlag = false;
}


Card::~Card()
{
	downFlag = false;
}

// 描画関数
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*画像のﾊﾝﾄﾞﾙ*/0);
}

// 更新関数
bool Card::Update(void)
{
	if (nowFlag)
	{
		
	}
	nowFlag = false;
	return true;
}

// 強制落下用
bool Card::SetDown(bool flag)
{
	return downFlag = flag;
}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	DrawGraph(pos.x, pos.y, GrHundle, true);
}