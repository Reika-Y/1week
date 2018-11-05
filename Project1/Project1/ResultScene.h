#pragma once
#include "BaseScene.h"
 
using std::shared_ptr;

struct ResultScene : BaseScene
{
	ResultScene();
	~ResultScene();
	int Init(void);
	baseScene Updata(baseScene own, const KeyboardCtl&key);
private:
};

