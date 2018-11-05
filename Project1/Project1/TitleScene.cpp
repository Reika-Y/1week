#include "DxLib.h"
#include "TitleScene.h"
#include "MouseCtrl.h"
#include "KeyboardCtl.h"
#include "GameMainScene.h"

using std::move;
using std::make_unique;

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

int TitleScene::Init(void)
{
	return 0;
}

baseScene TitleScene::Updata(baseScene own, const KeyboardCtl&key)
{
	ClsDrawScreen();
	DrawString(0, 0, "TitleScene", 0xffffff);
	ScreenFlip();
	if (key.CheckKey(KEY_INPUT_RETURN))
	{
		return make_unique<GameMainScene>();
	}
	return move(own);
}
