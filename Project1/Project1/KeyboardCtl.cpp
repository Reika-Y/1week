#include "DxLib.h"
#include "KeyboardCtl.h"



KeyboardCtl::KeyboardCtl()
{
}


KeyboardCtl::~KeyboardCtl()
{
}

char KeyboardCtl::GetBtn(int key) const
{
	return keyData[key];
}

bool KeyboardCtl::CheckKey(int key) const
{
	if (keyData[key] && !keyDataOld[key])
	{
		return true;
	}
	return false;
}

void KeyboardCtl::UpDate(void)
{
	memcpy(keyDataOld, keyData, sizeof(keyDataOld));
	GetHitKeyStateAll(keyData);
}
