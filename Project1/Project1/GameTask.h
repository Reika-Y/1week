#pragma once
#include <memory>
#include <list>
#include "BaseScene.h"

class VECTOR2;
class KeyboardCtl;

#define lpGameTask		(GameTask::GetInstance())

using std::unique_ptr;
using std::make_unique;
using std::list;

class GameTask 
{
public:
	static GameTask& GetInstance(void) {
		return *s_instance;
	}
	void Run(void);
	const VECTOR2 GetScreenSize(void);
private:
	struct GameTaskDeleter		// ŠÖ”µÌŞ¼Şª¸Ä
	{
		void operator()(GameTask* gameTask) const 
		{
			// ‚±‚±‚Ådelete‚·‚é
			delete gameTask;						
		}
	};

	GameTask();
	~GameTask();

	int SysInit(void);

	int (GameTask::*TaskPtr)(void);
	static unique_ptr<GameTask,GameTaskDeleter>s_instance;
	unique_ptr<KeyboardCtl>key;
	baseScene nowScene;
};
