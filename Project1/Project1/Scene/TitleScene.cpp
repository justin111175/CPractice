#include "TitleScene.h"
#include "../Common/Debug/_DebugDispOut.h"
#include "../Common/Debug/_DebugConOut.h"
#include"../Common/Function.h"
TitleScene::TitleScene()
{
	TRACE("%s", "初始化登入頁面");
}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{

	DrawOwn();
	//if (!FadeUpdate())
	//{

	//	for (auto&& state : playerState_)
	//	{

	//		state->Run();

	//	}
	//}

	return std::move(own);
}

void TitleScene::Init(void)
{
	GetDrawScreenSize(&screen_size_.x, &screen_size_.y);
}

void TitleScene::DrawOwn()
{
	//DrawGraph(0,0, IpImageMng.GetID("0")[0], true);
	SetDrawScreen(screenID_);
	SetFontSize(50);
	DrawString(0, 0, ConvertToTCHAR("TTT"), 0xf0f8ff, 0xFFFFFF);

}

void TitleScene::Ctl(conType input)
{
}


