#include "DxLib.h"
#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::Update(void)
{
	Draw();
}

void Player::Draw(void)
{
	DrawString(0, 100, "�Ղꂢ��[", 0xffffff);
}
