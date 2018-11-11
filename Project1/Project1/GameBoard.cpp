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
		nowCard->SetPos(VECTOR2(tmpPos.x, tmpPos.y + 2));
	}
	else
	{
		cnt++;
		VECTOR2 stop = tmpPos / CARD_SIZE;
		data[stop.y][stop.x] = nowCard;
		oldCard = std::move(nowCard);
		cardlist.push_back(oldCard);
		CheckRole(cnt);
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

bool GameBoard::CheckRole(int ucnt)
{
	VECTOR2 vec[4] = { VECTOR2(1,0),VECTOR2(0,-1),VECTOR2(-1,0),VECTOR2(0,1) };
	for (auto vector : vec)
	{
		if (JudgeRole(vector, ucnt))
		{
			return true;
		}
	}
	return false;
}

bool GameBoard::JudgeRole(const VECTOR2 vec, int ucnt)
{
	bool rtnFlag = false;
	int numCnt = 0; //ペアカウント
	int icnt = 0;	//ストレート用カウント
	int dcnt = 0;
	int markCnt = 0;//マークカウント
	int cnt = 0;

	VECTOR2 cardMax = (GetBoardSize() / CARD_SIZE);
	for (int y = (cardMax.y - 1); y >= 0; y--)
	{
		cnt = 0;
		for (int x = 0; x < cardMax.x - 1; x++)
		{
			if ((!data[y][x].expired()))
			{
				if (y >= 6 && vec.y != 0)
				{
					return false;
				}
				if ((!data[y + vec.y][x + vec.x].expired()))//データあり
				{
					auto hundle1 = data[y][x].lock()->GetCardInfo().hundle;//1枚目
					auto hundle2 = data[y + vec.y][x + vec.x].lock()->GetCardInfo().hundle;//2枚目
					auto num1 = data[y][x].lock()->GetCardInfo().num;//1枚目
					auto num2 = data[y + vec.y][x + vec.x].lock()->GetCardInfo().num;//2枚目

					cnt++;
					if (num1 == num2)
					{
						numCnt++;
					}

					if (numCnt == 3)
					{
						//フォーカード
						rtnFlag = true;
					}
					//else if ((numCnt == 2))
					//{
					//	//スリーカード
					//	rtnFlag = true;
					//}
					else if (numCnt == 2)
					{
						//ツーペア
						rtnFlag = true;
					}
					else if (numCnt == 1)
					{
						//ワンペア
						rtnFlag = true;
						/*auto itr = cardlist.begin();
						for (int j = 0; j < ucnt + 5; j++)
						{
							itr++;
						}
						for (auto itr = cardlist.begin(); itr != cardlist.end(); itr++)
						{
							
							if (data[y][x].expired())
							{
								cardlist.erase(itr);
							}
						}*/
						
					}


					//if (num2 == (num1 + 1))
					//{
					//	icnt++;
					//}
					//else if(num2 == (num1 - 1))
					//{
					//	dcnt++;
					//}
					//if ((icnt == 4) || (dcnt == 4))
					//{
					//	//ストレート
					//	return true;
					//}


					if (hundle1 == hundle2)
					{
						markCnt++;
					}
					if (markCnt == 4)
					{
						//フラッシュ
						return true;
					}
				}
			}
		}
	}
	return rtnFlag;
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
