#pragma once
#include <vector>
#include <list>
#include <memory>
#include <time.h>
#include "VECTOR2.h"
#include "Role.h"

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
	bool GameOver(void);
	bool CardFall(void);
	bool CardMove(const KeyboardCtl& key);
	bool LineCheck(void);
	bool LineDelete(void);
	void SetTime(void);
private:
	bool ReSize(VECTOR2 vec);
	auto AddCardList(std::shared_ptr<Card>&& cardPtr);
	bool CardCreate(void);
	void JudgeRole(void);
	bool MoveLimitR(VECTOR2 nowPos);
	bool MoveLimitL(VECTOR2 nowPos);
	bool MoveLimitY(VECTOR2 nowPos);
	void DrawScore(void);
	int ScrCnt;
	int drawScr = 0;
	std::shared_ptr<Card> nowCard;
	std::vector<std::weak_ptr<Card>*> data;
	std::vector<std::weak_ptr<Card>> baseData;
	time_t s_time, e_time,n_time;
	card_List cardlist;
	VECTOR2 boardLT;
	VECTOR2 screenSize;
	VECTOR2 boardSize;
	std::unique_ptr<Role> role;
};

int DrawBox(const VECTOR2& vec1, const VECTOR2& vec2, unsigned int color, int FillFlag);

