#include "DxLib.h"
#include "ResultScene.h"
#include "MouseCtrl.h"
#include "TitleScene.h"

using std::make_unique;

ResultScene::ResultScene()
{
	Init();
}


ResultScene::~ResultScene()
{
}

int ResultScene::Init(void)
{
	return 0;
}

baseScene ResultScene::Updata(baseScene own, const MouseCtrl&mouseCtrl)
{
	if ((mouseCtrl.GetBtn()[ST_NOW] & (~mouseCtrl.GetBtn()[ST_OLD]) & MOUSE_INPUT_LEFT) != 0)
	{
		return make_unique<TitleScene>();
	}
	ClsDrawScreen();
	DrawString(0, 0, "ResultScene", 0xffffff);
	ScreenFlip();
	return move(own);
}
