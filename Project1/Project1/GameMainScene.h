#pragma once
#include <list>
#include "BaseScene.h"

class VECTOR2;
class Player;
class GameBoard;

using std::shared_ptr;
using std::list;

typedef shared_ptr<Player>player_ptr;
typedef list<player_ptr>Player_List;

struct GameMainScene : BaseScene
{
	GameMainScene();
	~GameMainScene();
	int Init(void);
	baseScene Updata(baseScene own, const KeyboardCtl&key);

private:
	void MakePlayer(void);
	bool ResultCheck(void);
	shared_ptr<GameBoard>gboard;
	Player_List PlayerList;
};

