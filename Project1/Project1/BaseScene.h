#pragma once
#include <memory>

class MouseCtrl;
class KeyboardCtl;
class VECTOR2;
struct BaseScene;

using std::unique_ptr;

using  baseScene = unique_ptr<BaseScene>;

struct BaseScene
{
	~BaseScene();
	virtual int Init(void) = 0;
	virtual baseScene Updata(baseScene own, const KeyboardCtl&key) = 0;
};

