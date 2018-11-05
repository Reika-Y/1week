#pragma once
#include <array>
#include "VECTOR2.h"

enum Key_ST 
{
	ST_NOW,
	ST_OLD,
	ST_MAX
};

using KEY_INT = std::array<int, ST_MAX>;

class KeyboardCtl
{
public:
	KeyboardCtl();
	~KeyboardCtl();
	VECTOR2 GetPoint(void)const;
	KEY_INT GetBtn(void)const;
	void UpDate(void);

private:
	char key[256];
	KEY_INT keyBtn;
	VECTOR2 pos;
};

