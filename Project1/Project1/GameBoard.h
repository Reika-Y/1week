#pragma once
#include "VECTOR2.h"
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void Update(void);
	void Draw(void);
	const VECTOR2 GetBoardSize(void);
	bool HandCheck(void);

private:
	bool fallFlag;
	VECTOR2 pos;
};

