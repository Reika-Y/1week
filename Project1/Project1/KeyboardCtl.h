#pragma once
#include <array>
#include "VECTOR2.h"

enum Key_ST 
{
	ST_NOW,
	ST_OLD,
	ST_MAX
};

//using KEY_INT = std::array<int, 256/*ST_MAX*/>;

class KeyboardCtl
{
public:
	KeyboardCtl();
	~KeyboardCtl();
	char GetBtn(int key)const;
	bool CheckKey(int key)const;
	void UpDate(void);

private:
	char keyData[256];
	char keyDataOld[256];
};

