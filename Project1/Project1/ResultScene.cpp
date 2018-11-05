#include "DxLib.h"
#include "ResultScene.h"
#include "KeyboardCtl.h"
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

baseScene ResultScene::Updata(baseScene own, const KeyboardCtl&key)
{
	if ((key.GetBtn()[ST_NOW] & (~key.GetBtn()[ST_OLD]) & KEY_INPUT_RETURN) != 0)
	{
		return make_unique<TitleScene>();
	}
	ClsDrawScreen();
	DrawString(0, 0, "ResultScene", 0xffffff);
	ScreenFlip();
	return move(own);
}
