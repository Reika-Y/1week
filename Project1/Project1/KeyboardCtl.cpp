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
		// �����ꂽ
		return true;
	}
	// ������ĂȂ�
	return false;
}

bool KeyboardCtl::TriggerBtn(int key) const
{
	if (keyData[key])
	{
		// �����Ă���
		return true;
	}
	return false;
}

void KeyboardCtl::UpDate(void)
{
	memcpy(keyDataOld, keyData, sizeof(keyDataOld));
	GetHitKeyStateAll(keyData);
}
