#include "DxLib.h"
#include "GameMainScene.h"
#include "MouseCtrl.h"
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

baseScene GameMainScene::Updata(baseScene own, const MouseCtrl&mouseCtrl)
{		
	ClsDrawScreen();
	DrawString(0,0,"GameScene",0xffffff);
	ScreenFlip();
	if ((mouseCtrl.GetBtn()[ST_NOW] & (~mouseCtrl.GetBtn()[ST_OLD]) & MOUSE_INPUT_LEFT) != 0)
	{
		return make_unique<ResultScene>();
	}
	return move(own);
}
