﻿#include "DxLib.h"
#include "Source/Scene/SceneManager.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SceneManager::Create();
	SceneManager::Destroy();
	SceneManager::GetInstance().Run();

	return 0;															// ブログラムの終了
}

