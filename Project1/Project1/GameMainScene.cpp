#include "DxLib.h"
#include "GameMainScene.h"
#include "KeyboardCtl.h"
#include "GameBoard.h"
#include "Player.h"
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

void GameMainScene::MakePlayer(void)
{
	player = std::make_unique<Player>();
}

int GameMainScene::Init(void)
{
	gboard = std::make_shared<GameBoard>();
	MakePlayer();
	return 0;
}

baseScene GameMainScene::Updata(baseScene own, const KeyboardCtl&key)
{		
	ClsDrawScreen();
	DrawString(0,0,"GameScene",0xffffff);
	gboard->Update(key);
	gboard->Draw();
	player->Update();
	ScreenFlip();
	if (key.CheckKey(KEY_INPUT_RETURN))
	{
		return make_unique<ResultScene>();
	}
	return move(own);
}
