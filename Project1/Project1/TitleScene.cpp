#include "DxLib.h"
#include "TitleScene.h"
#include "MouseCtrl.h"
#include "KeyboardCtl.h"
#include "GameMainScene.h"
#include "ImageMng.h"

using std::move;
using std::make_unique;

// 描画関連
const string fileName = "image/title.png";
const VECTOR2 stringPos = { 300,370 };
static int flamCnt = 0;

TitleScene::TitleScene()
{
	keyGetRng = GET_DEF_RNG;
	flam = GET_DEF_RNG;
	Init();
}

TitleScene::~TitleScene()
{
	flamCnt = 0;
}

int TitleScene::Init(void)
{
	pos = VECTOR2(0, 0);
	fontHandle = CreateFontToHandle("メイリオ", 30, 9);
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
	//if (tmpPos != pos)	// 変化している場合に動く
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
	flamCnt++;
	ClsDrawScreen();
	DrawGraph(0, 0, IMAGE_ID(fileName)[0], true);
	// 点滅表示
	if (flamCnt / 30 % 2 == 0)
	{
		DrawStringToHandle(stringPos.x, stringPos.y, "Push_Enter", 0x000000, fontHandle);
	}
	ScreenFlip();
	if (key.CheckKey(KEY_INPUT_RETURN))
	{
		return make_unique<GameMainScene>();
	}
	return move(own);
}
