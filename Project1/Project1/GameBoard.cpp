#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"
#include "KeyboardCtl.h"
#include "Card.h"

const VECTOR2 CARD_SIZE = VECTOR2(60, 80);
const int T_LIMIT= 180;

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
	CardCreate();
	if (CardFall())
	{
		CardMove(key);
	}
}

//描画
void GameBoard::Draw(void)
{
	DrawFormatString(560, 10, 0xffffff,"残り時間%d", e_time - n_time);
	DrawBox(boardLT, boardLT + boardSize, 0x109910, true);
	if (nowCard)
	{
		nowCard->Draw();
	}
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
	return VECTOR2((baseData.size() / data.size())*CARD_SIZE.x, data.size()*CARD_SIZE.y);
}

bool GameBoard::GameOver(void)
{
	if (!data[0][0].expired())
	{
		return true;
	}
	time(&n_time);
	if (e_time <= n_time)
	{
		return true;
	}

	return false;
}

//落下処理
bool GameBoard::CardFall(void)
{
	if (!nowCard)
	{
		return false;
	}
	VECTOR2 tmpPos = nowCard->GetPos();
	if (MoveLimitY(tmpPos))
	{
		nowCard->SetPos(VECTOR2(tmpPos.x, tmpPos.y + 1));
	}
	else
	{
		VECTOR2 stop = tmpPos / CARD_SIZE;
		data[stop.y][stop.x] = nowCard;
		oldCard = std::move(nowCard);
		cardlist.push_back(oldCard);
		if (CardCreate())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//左右移動
bool GameBoard::CardMove(const KeyboardCtl& key)
{
	VECTOR2 tmpPos = nowCard->GetPos();
	if (key.CheckKey(KEY_INPUT_RIGHT) && MoveLimitR(tmpPos))
	{
		nowCard->SetPos(VECTOR2(tmpPos.x + CARD_SIZE.x, tmpPos.y));
	}
	if (key.CheckKey(KEY_INPUT_LEFT) && MoveLimitL(tmpPos))
	{
		nowCard->SetPos(VECTOR2(tmpPos.x - CARD_SIZE.x, tmpPos.y));
	}
	return false;
}

void GameBoard::SetTime(void)
{
	time(&s_time);
	e_time = s_time + T_LIMIT;
	time(&n_time);
}

//カード生成
bool GameBoard::CardCreate(void)
{
	if (!nowCard)
	{
		HUNDLE hundle = (HUNDLE)GetRand(3);
		int num = GetRand(12)+1;
		for (auto itr : cardlist)
		{
			if (itr->GetCardInfo().hundle == hundle && itr->GetCardInfo().num == num)
			{
				return false;
			}
		}
		nowCard = std::make_shared<Card>(VECTOR2(0, 0), boardLT, hundle, num);
	}
	return true;
}

//移動限界
bool GameBoard::MoveLimitR(VECTOR2 nowPos)
{
	VECTOR2 nextPos = nowPos / CARD_SIZE;

	if (boardSize.x - CARD_SIZE.x < nowPos.x + CARD_SIZE.x)
	{
		return false;
	}
	if (data[nextPos.y][nextPos.x + 1].expired())
	{
		if (nextPos.y == 6)
		{
			return true;
		}
		if (!data[nextPos.y + 1][nextPos.x + 1].expired())
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool GameBoard::MoveLimitL(VECTOR2 nowPos)
{
	VECTOR2 nextPos = nowPos / CARD_SIZE;

	if (nowPos.x - CARD_SIZE.x < 0)
	{
		return false;
	}
	if (data[nextPos.y][nextPos.x-1].expired())
	{
		if (nextPos.y == 6)
		{
			return true;
		}
		if (!data[nextPos.y + 1][nextPos.x - 1].expired())
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool GameBoard::MoveLimitY(VECTOR2 nowPos)
{
	VECTOR2 nextPos = nowPos  / CARD_SIZE;

	if (boardSize.y - CARD_SIZE.y < nowPos.y )
	{
		return false;
	}
	if (!data[6][nextPos.x].expired())
	{
		if (!data[nextPos.y+1][nextPos.x].expired())
		{
			return false;
		}
	}
	return true;
}

//初期化
bool GameBoard::ReSize(VECTOR2 vec)
{
	baseData.resize(vec.y*vec.x);
	data.resize(vec.y);

	for (unsigned int j = 0; j < data.size(); j++)
	{
		data[j] = &baseData[j*vec.x];
	}
	screenSize = lpGameTask.GetScreenSize();
	boardSize = GetBoardSize();
	boardLT = VECTOR2((screenSize.x - boardSize.x)/4, (screenSize.y - boardSize.y)/2);
	return true;
}

int DrawBox(const VECTOR2 &vec1, const VECTOR2 &vec2, unsigned int color, int FillFlag)
{
	return DrawBox(vec1.x, vec1.y, vec2.x, vec2.y, color, FillFlag);
}
