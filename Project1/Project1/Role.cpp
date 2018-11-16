#include "DxLib.h"
#include "Role.h"


Role::Role()
{
}


Role::~Role()
{
}

void Role::ReSetJudge(void)
{
	hand = HAND_MAX;
	rolePoint = 0;
	for (int j = 0; j < HAND_MAX; j++)
	{
		point[j] = 0;
	}
}

void Role::PairJudge(CardInfo card[7])
{
	for (int x = 0; x < 7; x++)
	{
		if (card[x].num == card[x + 1].num)//ワンペア
		{
			hand = HAND_ONEPAIR;
			if (card[x].num == card[x + 2].num)//スリーカード
			{
				hand = HAND_THREECARD;
				if (card[x].num == card[x + 3].num)//フォーカード
				{
					hand = HAND_FOURCARD;
				}
			}
		}
		else
		{
			hand = HAND_MAX;
		}

		switch (hand)
		{
		case HAND_ONEPAIR:
			point[HAND_ONEPAIR]++;
			break;
		case HAND_THREECARD:
			point[HAND_THREECARD]++;
			x += 2;
			break;
		case HAND_FOURCARD:
			point[HAND_FOURCARD]++;
			x += 3;
			break;
		}

		hand = HAND_MAX;
	}
}

int Role::RoleCntSum(void)
{
	if (rolePoint < 0)
	{
		rolePoint = 0;
	}
	for (int p = 0; p < HAND_MAX; p++)
	{
		rolePoint += (point[p] * (p + 1));
	}
	return rolePoint;
}
