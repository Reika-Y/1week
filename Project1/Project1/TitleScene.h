#pragma once
#include "BaseScene.h"

struct TitleScene : BaseScene
{
	TitleScene();
	~TitleScene();
	int Init(void);
	baseScene Updata(baseScene own, const KeyboardCtl&key);
};

