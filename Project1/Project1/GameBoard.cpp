#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"

const VECTOR2 BOARD_SIZE = VECTOR2(60 * 8, 80 * 7);

GameBoard::GameBoard()
{
	ReSize(VECTOR2(8, 7));
}


GameBoard::~GameBoard()
{
}

void GameBoard::Update(void)
{
}

void GameBoard::Draw(void)
{
	DrawBox(boardLT, screenSize - boardLT, 0x109910, true);
}

const VECTOR2 GameBoard::GetBoardSize(void)
{
	return VECTOR2();
}

bool GameBoard::CardFall(void)
{
	return false;
}

bool GameBoard::CardMove(void)
{
	return false;
}

bool GameBoard::HandCheck(void)
{
	return false;
}

bool GameBoard::ReSize(VECTOR2 vec)
{
	baseData.resize(vec.y*vec.x);
	data.resize(vec.y);
	for (unsigned int j = 0; j < data.size(); j++)
	{
		data[j] = &baseData[j*vec.x];
	}
	screenSize = lpGameTask.GetScreenSize();
	boardLT = VECTOR2((screenSize.x - BOARD_SIZE.x) / 2, (screenSize.y - BOARD_SIZE.y) / 2);
	return true;
}

int DrawBox(const VECTOR2 &vec1, const VECTOR2 &vec2, unsigned int color, int FillFlag)
{
	return DrawBox(vec1.x, vec1.y, vec2.x, vec2.y, color, FillFlag);
}
