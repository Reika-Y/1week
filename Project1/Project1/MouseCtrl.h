#pragma once
#include <array>
#include "VECTOR2.h"

// œ≥ΩÇÃƒÿ∂ﬁ∞ä«óùóp
enum MOUSE_ST
{
	ST_NOW,
	ST_OLD,
	ST_MAX
};

using MOUSE_INT = std::array<int, ST_MAX>;

class MouseCtrl
{
public:
	MouseCtrl();
	~MouseCtrl();
	VECTOR2 GetPoint(void)const;
	MOUSE_INT GetBtn(void)const;
	void UpDate(void);
private:
	MOUSE_INT mouseBtn;
	VECTOR2 pos;
};

