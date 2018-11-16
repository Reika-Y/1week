#include "DxLib.h"
#include "Card.h"
#include "Role.h"


Role::Role()
{
	pairCnt = 0;
}


Role::~Role()
{
}

int Role::PairJudge(int num1, int num2)
{
	if (num1 == num2)
	{
		pairCnt++;
		return true;
	}
	return pairCnt;
}

void Role::CntClear(void)
{
	pairCnt = 0;
}
