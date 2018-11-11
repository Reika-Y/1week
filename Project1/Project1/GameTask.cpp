#include "Dxlib.h"	
#include "KeyboardCtl.h"
#include "VECTOR2.h"
#include "GameTask.h"
#include "TitleScene.h"

using std::move;

// ここで実体を作る（ｺﾝﾄﾛｰﾙされたくない）
unique_ptr<GameTask,GameTask::GameTaskDeleter> GameTask::s_instance(new GameTask());		

// 画面ｻｲｽﾞ
const int screen_size_x = 800;
const int screen_size_y = 600;


// ｽｸﾘｰﾝｻｲｽﾞ取得用
const VECTOR2 GameTask::GetScreenSize(void)
{
	return VECTOR2(screen_size_x,screen_size_y);
}

// ｺﾝｽﾄﾗｸﾀ
GameTask::GameTask()
{
	SysInit();
}

// ﾃﾞｽﾄﾗｸﾀ
GameTask::~GameTask()
{
	// DXﾗｲﾌﾞﾗﾘの終了処理
	DxLib_End();
}

// 初期化関数
int GameTask::SysInit(void) 
{
	// ｼｽﾃﾑ処理
	SetGraphMode(screen_size_x, screen_size_y, 16);	// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);							// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("FallPoker");
	if (DxLib_Init() == -1) return false;			// DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);					// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	key = std::make_unique<KeyboardCtl>();
	return true;
}

// ｹﾞｰﾑﾙｰﾌﾟ
void GameTask::Run(void)
{
	nowScene = make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		(*key).UpDate();
		nowScene = (*nowScene).Updata(move(nowScene), *key);
	}
}
