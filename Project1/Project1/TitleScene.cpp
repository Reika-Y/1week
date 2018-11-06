#include "DxLib.h"
#include "TitleScene.h"
#include "MouseCtrl.h"
#include "KeyboardCtl.h"
#include "GameMainScene.h"

using std::move;
using std::make_unique;

TitleScene::TitleScene()
{
	keyGetRng = GET_DEF_RNG;
	flam = GET_DEF_RNG;
}

TitleScene::~TitleScene()
{
}

int TitleScene::Init(void)
{
	pos = VECTOR2(0, 0);
	return 0;
}

baseScene TitleScene::Updata(baseScene own, const KeyboardCtl&key)
{
	//VECTOR2 tmpPos(pos);
	//if (key.TriggerBtn(KEY_INPUT_LEFT))
	//{
	//	tmpPos.x -= 10;
	//}
	//if (key.TriggerBtn(KEY_INPUT_RIGHT))
	//{
	//	tmpPos.x += 10;
	//}
	//if (tmpPos != pos)	// •Ï‰»‚µ‚Ä‚¢‚éê‡‚É“®‚­
	//{
	//	flam++;
	//	if (flam >= keyGetRng)
	//	{
	//		pos = tmpPos;
	//		flam = 0;
	//		if (keyGetRng > MOVE_CURSOR_TIME)
	//		{
	//			keyGetRng = keyGetRng / 2;
	//		}
	//	}
	//}
	//else
	//{
	//	keyGetRng = GET_DEF_RNG;
	//	flam = GET_DEF_RNG;
	//}
	if (key.CheckKey(KEY_INPUT_RIGHT))
	{
		pos.x += 10;
	}

	ClsDrawScreen();
	DrawString(pos.x, pos.y, "TitleScene", 0xffffff);
	ScreenFlip();
	if (key.CheckKey(KEY_INPUT_RETURN))
	{
		return make_unique<GameMainScene>();
	}
	return move(own);
}
