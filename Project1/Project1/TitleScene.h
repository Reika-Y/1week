#pragma once
#include "VECTOR2.h"
#include "BaseScene.h"

#define GET_DEF_RNG 30
#define MOVE_CURSOR_TIME 5

struct TitleScene : BaseScene
{
	TitleScene();
	~TitleScene();
	int Init(void);
	baseScene Updata(baseScene own, const KeyboardCtl&key);
private:
	VECTOR2 pos;
	int keyGetRng;
	int flam;
};

