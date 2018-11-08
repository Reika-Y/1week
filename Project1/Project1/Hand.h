#pragma once

enum HAND {
	HAND_ONEPAIR,
	HAND_TWOPAIR,
	HAND_THREECARD,
	HAND_FOURCARD,
	HAND_FLUSH,
	HAND_STRAIGHT,
	HAND_STRAIGHTFLUSH,
	HAND_MAX
};

class Hand
{
public:
	virtual ~Hand();

	virtual HAND GetHand(void) = 0;		//–ð‚ð•Ô‚·
	virtual int GetPoint(void) = 0;		//“¾“_‚ð•Ô‚·
};

