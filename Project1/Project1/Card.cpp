#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"

// ‰æ‘œŠÖ˜A
const string fileName = "image/trump.png";
const VECTOR2 cardDiv = { 8,8 };
const VECTOR2 cardSize = { 60,90 };

/*
* ºİ½Ä×¸À
* @param (HUNDLE hundle) Ä×İÌß‚Ì•¿
* @param (int num) Ä×İÌß‚Ì”š
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

// •`‰æŠÖ”
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*‰æ‘œ‚ÌÊİÄŞÙ*/0);
}

// XVŠÖ”
bool Card::Update(void)
{

}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	return DrawGraph(pos.x, pos.y, GrHundle, true);
}