#include "SceneManager.h"
#include "Title/TitleScene.h"
#include "../Common/Debug/_DebugConOut.h"
#include "../Common/Debug/_DebugDispOut.h"
void SceneManager::Run()
{
	if (!SysInit())
	{
		TRACE("系統初始化失敗");
		//AST();
	}

	SetUseZBufferFlag(TRUE);
	SetWriteZBufferFlag(TRUE);
	SetMouseDispFlag(TRUE);

	activeScene = std::make_unique<TitleScene>();
	//SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_dbgStartDraw();

		activeScene = (*activeScene).Update(std::move(activeScene));


		activeScene->Draw();
		_dbgAddDraw();


		frames++;
	}

}
SceneManager::SceneManager():
	screenSize{1280,720}
{

	frames = 0;
}

SceneManager::~SceneManager()
{
}

bool SceneManager::SysInit()
{

	SetWindowText(_T("測試C++"));
	SetGraphMode(screenSize.x, screenSize.y, 16);
	
	_dbgSetup(screenSize.x, screenSize.y, 16);
	ChangeWindowMode(true);												

	if (DxLib_Init() == -1)												
	{
		return false;
	}
	return true;

}
