#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"
#include "GameBoard.h"

// �����鑬��
const int def_speed = 5;

const VECTOR2 cardDiv = VECTOR2(8, 8);
/*
* �ݽ�׸�
* @param (HUNDLE hundle) ����߂̕�
* @param (int num) ����߂̐���
* @param (VECTOR2 cardSize) ����߂̻���
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

// �`��֐�
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*�摜�������*/0);
}

// �X�V�֐�
bool Card::Update(void)
{
	if (nowFlag)
	{
		
	}
	nowFlag = false;
	return true;
}

// ���������p
bool Card::SetDown(bool flag)
{
	return downFlag = flag;
}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	DrawGraph(pos.x, pos.y, GrHundle, true);
}