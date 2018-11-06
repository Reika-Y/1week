#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"
#include "KeyboardCtl.h"
#include "Card.h"

const VECTOR2 BOARD_SIZE = VECTOR2(60 * 8, 80 * 7);

GameBoard::GameBoard()
{
	ReSize(VECTOR2(8, 7));
}

GameBoard::~GameBoard()
{
}

//�X�V����
void GameBoard::Update(void)
{
}

//�`��
void GameBoard::Draw(void)
{
	DrawBox(boardLT, boardLT + BOARD_SIZE, 0x109910, true);
}

//�ՖʃT�C�Y
const VECTOR2 GameBoard::GetBoardSize(void)
{
	return BOARD_SIZE;
}

//��������
bool GameBoard::CardFall(void)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (MoveLimit())
	{
		nowCard->SetPos(VECTOR2(tmpPos.x, tmpPos.y + 10));
	}
	else
	{
		oldCard = std::move(nowCard);
		cardlist.push_back(oldCard);
	}
	return false;
}

//���E�ړ�
bool GameBoard::CardMove(const KeyboardCtl& key)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (key.CheckKey(KEY_INPUT_RIGHT) && MoveLimit())
	{
		nowCard->SetPos(VECTOR2(tmpPos.x + 60, tmpPos.y));
	}
	if (key.CheckKey(KEY_INPUT_LEFT) && MoveLimit())
	{
		nowCard->SetPos(VECTOR2(tmpPos.x - 60, tmpPos.y));
	}
	return false;
}

//�J�[�h����
bool GameBoard::CardCreate(void)
{
	nowCard = std::make_shared<Card>(VECTOR2(0,0),boardLT,HEART,1);
	return false;
}

//�ړ����E
bool GameBoard::MoveLimit(void)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (boardLT.x + BOARD_SIZE.x - 60 <= tmpPos.x || tmpPos.x <= boardLT.x ||
		boardLT.y + BOARD_SIZE.y - 80 <= tmpPos.y)
	{
		return false;
	}
	return true;
}

//������
bool GameBoard::ReSize(VECTOR2 vec)
{
	screenSize = lpGameTask.GetScreenSize();
	boardLT = VECTOR2((screenSize.x - BOARD_SIZE.x)/4, (screenSize.y - BOARD_SIZE.y)/2);
	return true;
}

int DrawBox(const VECTOR2 &vec1, const VECTOR2 &vec2, unsigned int color, int FillFlag)
{
	return DrawBox(vec1.x, vec1.y, vec2.x, vec2.y, color, FillFlag);
}
