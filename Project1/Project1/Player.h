#pragma once
#include "GameBoard.h"
#include "KeyboardCtl.h"
class Player
{
public:
	Player();
	~Player();

	void Update(void); 
	void Draw(void);
	bool move(KeyboardCtl&key);

private:

};