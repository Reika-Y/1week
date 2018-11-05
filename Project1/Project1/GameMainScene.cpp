#include "DxLib.h"
#include "GameMainScene.h"
#include "KeyboardCtl.h"
#include "VECTOR2.h"
#include "ResultScene.h"

using std::make_shared;
using std::make_unique;
using std::move;

Player_List::iterator player_itr;

GameMainScene::GameMainScene()
{
	Init();
}


GameMainScene::~GameMainScene()
{
}

int GameMainScene::Init(void)
{
	return 0;
}

baseScene GameMainScene::Updata(baseScene own, const KeyboardCtl&key)
{		
	ClsDrawScreen();
	DrawString(0,0,"GameScene",0xffffff);
	ScreenFlip();
	if ((key.GetBtn()[ST_NOW] & (~key.GetBtn()[ST_OLD]) & KEY_INPUT_RETURN) != 0)
	{
		return make_unique<ResultScene>();
	}
	return move(own);
}
