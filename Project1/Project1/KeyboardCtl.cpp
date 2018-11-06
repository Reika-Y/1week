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
		// ‰Ÿ‚³‚ê‚½
		return true;
	}
	// ‰Ÿ‚³‚ê‚Ä‚È‚¢
	return false;
}

bool KeyboardCtl::TriggerBtn(int key) const
{
	if (keyData[key])
	{
		// ‰Ÿ‚µ‚Ä‚éó‘Ô
		return true;
	}
	return false;
}

void KeyboardCtl::UpDate(void)
{
	memcpy(keyDataOld, keyData, sizeof(keyDataOld));
	GetHitKeyStateAll(keyData);
}
