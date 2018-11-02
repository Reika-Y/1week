#include "DxLib.h"
#include "TitleScene.h"
#include "MouseCtrl.h"
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

baseScene TitleScene::Updata(baseScene own, const MouseCtrl&mouseCtrl)
{
	ClsDrawScreen();
	DrawString(0, 0, "TitleScene", 0xffffff);
	ScreenFlip();
	if ((mouseCtrl.GetBtn()[ST_NOW] & (~mouseCtrl.GetBtn()[ST_OLD]) & MOUSE_INPUT_LEFT) != 0)
	{
		return make_unique<GameMainScene>();
	}
	return move(own);
}
