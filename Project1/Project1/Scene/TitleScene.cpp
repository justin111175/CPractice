#include "TitleScene.h"
#include "../Common/Debug/_DebugDispOut.h"
#include "../Common/Debug/_DebugConOut.h"
TitleScene::TitleScene()
{
	TRACE("%s", "初始化登入頁面");
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	Draw();

	//if (!FadeUpdate())
	//{

	//	for (auto&& state : playerState_)
	//	{

	//		state->Run();

	//	}
	//}

	return std::move(own);
}

void TitleScene::BaseDraw()
{

	SetDrawScreen(DX_SCREEN_BACK);


}

void TitleScene::Draw()
{
	ClsDrawScreen();
	BaseDraw();

	ScreenFlip();

}
