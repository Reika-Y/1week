#include "DxLib.h"
#include "KeyboardCtl.h"



KeyboardCtl::KeyboardCtl()
{
}


KeyboardCtl::~KeyboardCtl()
{
}

VECTOR2 KeyboardCtl::GetPoint(void) const
{
	return pos;
}

KEY_INT KeyboardCtl::GetBtn(void) const
{
	return keyBtn;
}

void KeyboardCtl::UpDate(void)
{
	keyBtn[ST_OLD] = keyBtn[ST_NOW];
	keyBtn[ST_NOW] = GetHitKeyStateAll(key);
}
