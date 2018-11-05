#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"
#include "GameBoard.h"

// —‚¿‚é‘¬‚³
const int def_speed = 5;

const VECTOR2 cardDiv = VECTOR2(8, 8);
/*
* ºİ½Ä×¸À
* @param (HUNDLE hundle) Ä×İÌß‚Ì•¿
* @param (int num) Ä×İÌß‚Ì”š
* @param (VECTOR2 cardSize) Ä×İÌß‚Ì»²½Ş
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

// •`‰æŠÖ”
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*‰æ‘œ‚ÌÊİÄŞÙ*/0);
}

// XVŠÖ”
bool Card::Update(void)
{
	if (nowFlag)
	{
		
	}
	nowFlag = false;
	return true;
}

// ‹­§—‰º—p
bool Card::SetDown(bool flag)
{
	return downFlag = flag;
}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	DrawGraph(pos.x, pos.y, GrHundle, true);
}