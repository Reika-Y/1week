#pragma once
#include <vector>
#include <memory>
#include "VECTOR2.h"

class Card;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void Update(void);
	void Draw(void);
	const VECTOR2 GetBoardSize(void);
	bool CardFall(void);
	bool CardMove(void);
	bool HandCheck(void);

private:
	bool ReSize(VECTOR2 vec);
	std::vector<std::weak_ptr<Card>*> data;
	std::vector<std::weak_ptr<Card>> baseData;
	VECTOR2 boardLT;
	VECTOR2 screenSize;
	VECTOR2 boardSize;
};

int DrawBox(const VECTOR2& vec1, const VECTOR2& vec2, unsigned int color, int FillFlag);

