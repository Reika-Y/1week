#pragma once
#include <array>
#include "VECTOR2.h"



class KeyboardCtl
{
public:
	KeyboardCtl();
	~KeyboardCtl();
	bool CheckKey(int key)const; // �L�[���͏�ԃ`�F�b�N
	bool TriggerBtn(int key)const;
	void UpDate(void);

private:
	char keyData[256];
	char keyDataOld[256];
};

