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
	DrawBox(boardLT, boardLT + BOARD_SIZE, 0x109910, true);
}

const VECTOR2 GameBoard::GetBoardSize(void)
{
	return BOARD_SIZE;
}

bool GameBoard::CardFall(void)
{

	return false;
}

bool GameBoard::CardMove(void)
{
	cardlist.push_back(nowCard);

	return false;
}

bool GameBoard::HandCheck(void)
{
	return false;
}

bool GameBoard::CardCreate(void)
{
	nowCard = std::make_shared<Card>();
	return false;
}

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
