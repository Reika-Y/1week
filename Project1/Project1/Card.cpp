#include "VECTOR2.h"
#include "Card.h"

// 落ちる速さ
const int def_speed = 5;

Card::Card()
{
	speed = 0;
}


Card::~Card()
{
}

// 描画関数
void Card::Draw(void)
{
}

// 更新関数
bool Card::Update(void)
{
	return true;
}
