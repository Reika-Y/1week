#pragma once
#include <vector>
#include "list"
#include <memory>
#include "VECTOR2.h"

class Card;
class KeyboardCtl;
using card_List = std::list<std::shared_ptr<Card>>;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void Update(const KeyboardCtl& key);
	void Draw(void);
	const VECTOR2 GetBoardSize(void);
	bool CardFall(void);
	bool CardMove(const KeyboardCtl& key);
private:
	bool ReSize(VECTOR2 vec);
	bool CardCreate(void);
	bool MoveLimitX(void);
	bool MoveLimitY(void);
	std::shared_ptr<Card> nowCard;
	std::shared_ptr<Card> oldCard;
	card_List cardlist;
	VECTOR2 boardLT;
	VECTOR2 screenSize;
	VECTOR2 boardSize;
};

int DrawBox(const VECTOR2& vec1, const VECTOR2& vec2, unsigned int color, int FillFlag);

