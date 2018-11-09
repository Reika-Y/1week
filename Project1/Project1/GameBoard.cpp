#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"
#include "KeyboardCtl.h"
#include "Card.h"

const VECTOR2 CARD_SIZE = VECTOR2(60, 80);
const VECTOR2 BOARD_SIZE = VECTOR2(CARD_SIZE.x * 8, CARD_SIZE.y * 7);


GameBoard::GameBoard()
{
	ReSize(VECTOR2(8, 7));
}

GameBoard::~GameBoard()
{
}

//更新処理
void GameBoard::Update(const KeyboardCtl& key)
{
	if (!nowCard)
	{
		CardCreate();
	}
	CardFall();
	CardMove(key);
}

//描画
void GameBoard::Draw(void)
{
	DrawBox(boardLT, boardLT + BOARD_SIZE, 0x109910, true);
	nowCard->Draw();
	if (cardlist.size() > 0)
	{
		for (auto itr : cardlist)
		{
			itr->Draw();
		}
	}
}

//盤面サイズ
const VECTOR2 GameBoard::GetBoardSize(void)
{
	return BOARD_SIZE;
}

//落下処理
bool GameBoard::CardFall(void)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (MoveLimitY())
	{
		nowCard->SetPos(VECTOR2(tmpPos.x, tmpPos.y + 1));
	}
	else
	{
		oldCard = std::move(nowCard);
		cardlist.push_back(oldCard);
		CardCreate();
	}
	return false;
}

//左右移動
bool GameBoard::CardMove(const KeyboardCtl& key)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (key.CheckKey(KEY_INPUT_RIGHT) && !(BOARD_SIZE.x - CARD_SIZE.x < tmpPos.x + CARD_SIZE.x))
	{
		nowCard->SetPos(VECTOR2(tmpPos.x + CARD_SIZE.x, tmpPos.y));
	}
	if (key.CheckKey(KEY_INPUT_LEFT) && !(tmpPos.x - CARD_SIZE.x < 0))
	{
		nowCard->SetPos(VECTOR2(tmpPos.x - CARD_SIZE.x, tmpPos.y));
	}
	return false;
}

//カード生成
bool GameBoard::CardCreate(void)
{
	nowCard = std::make_shared<Card>(VECTOR2(0,0),boardLT,SPADE,11);
	return false;
}

//移動限界
bool GameBoard::MoveLimitX(void)
{
	VECTOR2 tmpPos = nowCard->GetPos();

	if (BOARD_SIZE.x - CARD_SIZE.x < tmpPos.x + CARD_SIZE.x)
	{
		return false;
	}
	if (tmpPos.x - CARD_SIZE.x < 0)
	{
		return true;
	}
	return true;
}

bool GameBoard::MoveLimitY(void)
{
	VECTOR2 tmpPos = nowCard->GetPos();

	if (BOARD_SIZE.y - CARD_SIZE.y < tmpPos.y + 10)
	{
		return false;
	}
	return true;
}

//初期化
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
