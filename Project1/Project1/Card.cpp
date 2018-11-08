#include "DxLib.h"
#include "Card.h"
#include "ImageMng.h"

// �摜�֘A
const string fileName = "image/trump.png";
const VECTOR2 cardDiv = { 13,4 };
const VECTOR2 cardSize = { 60,90 };

/*
* �ݽ�׸�
* @param (VECTOR2 pos) ���W
* @param (VECTOR2 offSet)�@�`�掞�̵̾�č��W
* @param (HUNDLE hundle) ����߂̕�
* @param (int num) ����߂̐���
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

// �`��֐�
void Card::Draw(void)
{
	int id = 0;
	DrawGraph(pos + offSet, fileName[0]);
}

// �X�V�֐�
bool Card::Update(void)
{
	return false;
}

// ���ޏ��擾�p
const CardInfo Card::GetCardInfo(void)
{
	return Card::cardInfo;
}

// ���W�擾�p
const VECTOR2 Card::GetPos(void)
{
	return pos;
}

/*
*�@���W��������
* @param (VECTOR2 pos) ���������������W
*/
bool Card::SetPos(VECTOR2 pos)
{
	Card::pos = pos;
	return true;
}
/*
* �̾�č��W��������
* @param (VECTOR2 offSet)	�������������̾�č��W
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