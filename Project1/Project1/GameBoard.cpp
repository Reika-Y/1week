#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"
#include "KeyboardCtl.h"
#include "Card.h"

const VECTOR2 CARD_SIZE = VECTOR2(60, 80);
const int T_LIMIT= 180;
const int D_LIMIT = 30;

GameBoard::GameBoard()
{
	ReSize(VECTOR2(8, 7));
	ScrCnt = 0;
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
	if (LineCheck())
	{
		JudgeRole();
		LineDelete();
		drawScr += role->RoleCntSum();
		role->ReSetJudge();
	}
}

//描画
void GameBoard::Draw(void)
{
	DrawScore();
	DrawFormatString(560, 10, 0xffffff,"残り時間%d", e_time - n_time);
	DrawBox(boardLT, boardLT + boardSize, 0x109910, true);
	if (nowCard)
	{
		nowCard->Draw();
	}
	for (int y = 0; y < GetBoardSize().y / CARD_SIZE.y; y++)
	{
		for (int x = 0; x < GetBoardSize().x / CARD_SIZE.x; x++)
		{
			if (!data[y][x].expired())
			{
				data[y][x].lock()->Draw();
			}
		}
	}
}

auto GameBoard::AddCardList(std::shared_ptr<Card>&& cardPtr)
{
	cardlist.push_back(cardPtr);
	auto itr = cardlist.end();
	itr--;
	return itr;
}


//盤面サイズ
const VECTOR2 GameBoard::GetBoardSize(void)
{
	return VECTOR2((baseData.size() / data.size())*CARD_SIZE.x, data.size()*CARD_SIZE.y);
}

bool GameBoard::GameOver(void)
{
	for (int x = 0; x < GetBoardSize().x / CARD_SIZE.x; x++)
	{
		if (!data[0][x].expired())
		{
			return true;
		}
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
		nowCard->SetPos(VECTOR2(tmpPos.x, tmpPos.y + 2));
	}
	else
	{
		VECTOR2 stop = tmpPos / CARD_SIZE;
		auto tmp = AddCardList(std::make_shared<Card>(tmpPos, boardLT, nowCard->GetCardInfo().hundle, nowCard->GetCardInfo().num));
		data[stop.y][stop.x] = (*tmp);
		nowCard.reset();
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

bool GameBoard::LineCheck(void)
{
	bool rtnFlag = true;
	for (int x = 0; x < GetBoardSize().x / CARD_SIZE.x; x++)
	{
		if (data[6][x].expired())
		{
			rtnFlag = false;
		}
	}
	return rtnFlag;
}

bool GameBoard::LineDelete(void)
{
	for (int x = 0; x < GetBoardSize().x / CARD_SIZE.x; x++)
	{
		if (!data[6][x].expired())
		{
			data[6][x].reset();
		}
	}
	for (int y = (GetBoardSize().y / CARD_SIZE.y) - 2; y >=0 ; y--)
	{
		for (int x = 0; x < GetBoardSize().x / CARD_SIZE.x; x++)
		{
			if (!data[y][x].expired())
			{
				auto tmp = data[y][x].lock()->GetPos();
				data[y][x].lock()->SetPos(VECTOR2(tmp.x, tmp.y + CARD_SIZE.y));
				data[y + 1][x] = std::move(data[y][x]);
			}
		}
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
		nowCard = std::make_shared<Card>(VECTOR2(boardSize.x/2, 0), boardLT, hundle, num);
	}
	return true;
}


//カードの判定
void GameBoard::JudgeRole(void)
{
	role->ReSetJudge();
	VECTOR2 cardMax = (GetBoardSize() / CARD_SIZE);

	CardInfo judge[8];
	
	for (int x = 0; x < cardMax.x; x++)
	{
		judge[x] = data[6][x].lock()->GetCardInfo();
	}

	role->PairJudge(judge);
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

void GameBoard::DrawScore(void)
{
	int drawLength;
	int textColor = GetColor(255, 255, 255);

	ChangeFont("HG創英角ﾎﾟｯﾌﾟ体");
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);

	DrawString(boardSize.x + 90, 50, "SCORE", textColor);
	DrawString(boardSize.x + 180, 150, "配点", textColor);

	DrawString(boardSize.x + 100, 205, "1ペア", textColor);
	DrawString(boardSize.x + 250, 205, "1pt", textColor);

	DrawString(boardSize.x + 100, 260, "2ペア", textColor);
	DrawString(boardSize.x + 250, 260, "2pt", textColor);

	DrawString(boardSize.x + 100, 315, "3カード", textColor);
	DrawString(boardSize.x + 250, 315, "3pt", textColor);

	DrawString(boardSize.x + 100, 370, "4カード", textColor);
	DrawString(boardSize.x + 250, 370, "4pt", textColor);

	DrawString(boardSize.x + 100, 425, "フラッシュ", textColor);
	DrawString(boardSize.x + 250, 425, "5pt", textColor);

	DrawString(boardSize.x + 100, 480, "ストレート", textColor);
	DrawString(boardSize.x + 250, 480, "6pt", textColor);

	DrawString(boardSize.x + 100, 535, "ストレート", textColor);
	DrawString(boardSize.x + 100, 550, "フラッシュ", textColor);
	DrawString(boardSize.x + 250, 540, "7pt", textColor);


	drawScr += ScrCnt;

	if (drawScr >= 10000)
	{
		drawScr = 9999;
	}

	drawLength = GetDrawFormatStringWidth("%d", drawScr);
	DrawFormatString(boardSize.x + 280 - drawLength, 70, textColor, "%d", drawScr);
	DrawString(boardSize.x + 290, 70, "pt", textColor);
	ScrCnt = 0;
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
	role = std::make_unique<Role>();
	return true;
}

int DrawBox(const VECTOR2 &vec1, const VECTOR2 &vec2, unsigned int color, int FillFlag)
{
	return DrawBox(vec1.x, vec1.y, vec2.x, vec2.y, color, FillFlag);
}
