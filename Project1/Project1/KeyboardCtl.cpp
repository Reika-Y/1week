#include "DxLib.h"
#include "KeyboardCtl.h"



KeyboardCtl::KeyboardCtl()
{
}


KeyboardCtl::~KeyboardCtl()
{
}

bool KeyboardCtl::CheckKey(int key) const
{
	if (keyData[key] && !keyDataOld[key])
	{
		// 押された
		return true;
	}
	// 押されてない
	return false;
}

bool KeyboardCtl::TriggerBtn(int key) const
{
	if (keyData[key])
	{
		// 押してる状態
		return true;
	}
	return false;
}

void KeyboardCtl::UpDate(void)
{
	memcpy(keyDataOld, keyData, sizeof(keyDataOld));
	GetHitKeyStateAll(keyData);
}
