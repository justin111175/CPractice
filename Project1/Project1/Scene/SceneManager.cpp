#include "SceneManager.h"
#include "TitleScene.h"
#include "../Common/Debug/_DebugConOut.h"
#include "../Common/Debug/_DebugDispOut.h"
void SceneManager::Run()
{
	if (!SysInit())
	{
		TRACE("系統初始化失敗");
		//AST();
	}

	activeScene = std::make_unique<TitleScene>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_dbgStartDraw();

		activeScene = (*activeScene).Update(std::move(activeScene));

		frames++;
	}

}
SceneManager::SceneManager():
	screenSize{1280,720}
{


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
