#include "MouseCtrl.h"
#include "DxLib.h"

MouseCtrl::MouseCtrl()
{
}


MouseCtrl::~MouseCtrl()
{
}

VECTOR2 MouseCtrl::GetPoint(void)const
{
	return pos;
}

MOUSE_INT MouseCtrl::GetBtn(void)const
{
	return mouseBtn;
}

void MouseCtrl::UpDate(void)
{
	mouseBtn[ST_OLD] = mouseBtn[ST_NOW];
	mouseBtn[ST_NOW] = (MOUSE_ST)GetMouseInput();
	GetMousePoint(&pos.x,&pos.y);
}
