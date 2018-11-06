#include "DxLib.h"
#include "VECTOR2.h"
#include "Card.h"
#include "ImageMng.h"

// �摜�֘A
const string fileName = "image/trump.png";
const VECTOR2 cardDiv = { 8,8 };
const VECTOR2 cardSize = { 60,90 };

/*
* �ݽ�׸�
* @param (HUNDLE hundle) ����߂̕�
* @param (int num) ����߂̐���
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

// �`��֐�
void Card::Draw(void)
{
	DrawGraph(pos + offSet, /*�摜�������*/0);
}

// �X�V�֐�
bool Card::Update(void)
{

}

int DrawGraph(VECTOR2 pos, int GrHundle)
{
	return DrawGraph(pos.x, pos.y, GrHundle, true);
}