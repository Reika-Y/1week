#include "Dxlib.h"	
#include "KeyboardCtl.h"
#include "VECTOR2.h"
#include "GameTask.h"
#include "TitleScene.h"

using std::move;

// �����Ŏ��̂����i���۰ق��ꂽ���Ȃ��j
unique_ptr<GameTask,GameTask::GameTaskDeleter> GameTask::s_instance(new GameTask());		

// ��ʻ���
const int screen_size_x = 800;
const int screen_size_y = 600;


// ��ذݻ��ގ擾�p
const VECTOR2 GameTask::GetScreenSize(void)
{
	return VECTOR2(screen_size_x,screen_size_y);
}

// �ݽ�׸�
GameTask::GameTask()
{
	SysInit();
}

// �޽�׸�
GameTask::~GameTask()
{
	// DXײ���؂̏I������
	DxLib_End();
}

// �������֐�
int GameTask::SysInit(void) 
{
	// ���я���
	SetGraphMode(screen_size_x, screen_size_y, 16);	// 65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);							// true:window�@false:�ٽ�ذ�
	SetWindowText("FallPoker");
	if (DxLib_Init() == -1) return false;			// DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);					// �ЂƂ܂��ޯ��ޯ̧�ɕ`��
	key = std::make_unique<KeyboardCtl>();
	return true;
}

// �ް�ٰ��
void GameTask::Run(void)
{
	nowScene = make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		(*key).UpDate();
		nowScene = (*nowScene).Updata(move(nowScene), *key);
	}
}
