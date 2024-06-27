#include "TitleScene.h"
#include "../../Common/Debug/_DebugDispOut.h"
#include "../../Common/Debug/_DebugConOut.h"
#include"../../Common/Function.h"
#include "../../Common/LoadManager.h"
#include "../../Common/EventDelegateManager.h"
#include "../Game/GameScene.h"
#include "../CrossOver.h"
TitleScene::TitleScene()
{
	TRACE("\n%s", "初始化登入頁面");
	LoadMng.GetID("Test_BG", "Resources/image/G_BG.png", { 900,720 }, { 1,1 });
	GetDrawScreenSize(&screen_Size.x, &screen_Size.y);
	menuPanel.Init({ 200, 150 });

	screenID_ = MakeScreen(screen_Size.x, screen_Size.y);
	mouseCtl = make_shared<MouseCtl>();
	isChangeScene = false;

}

TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	menuPanel.UpdateDraw();
	DrawOwn();
	mouseCtl->Update();

	if (mouseCtl->GetClickTrigger() & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<CrossOver>(std::move(own),std::make_unique<GameScene>());
		//for (auto& slot : menuPanel.slotMap)
		//{
		//	if (slot.second.collision.isPointInside(mouseCtl->Pos()))
		//	{
		//		slot.second.ButtonAction();
		//		break;
		//	}
		//}
	}


	return std::move(own);
}



void TitleScene::Draw()
{


	DrawGraph(0, 0, screenID_, true);
	
	//滑鼠位置渲染
	Vector2 mouseVec;
	GetMousePoint(&mouseVec.x, &mouseVec.y);
	SetFontSize(20);
	DrawFormatString(mouseVec.x, mouseVec.y, 0xff0000, _T("Ｘ:%d　,Ｙ:%d"), mouseVec.x, mouseVec.y);

}

void TitleScene::DrawOwn()
{
	SetDrawScreen(screenID_);
	ClearDrawScreen();

	DrawRectExtendGraph(
		0, 0, screen_Size.x, screen_Size.y,  
		0, 0, 900, 720,                   
		LoadMng.GetID("Test_BG")[0],                      
		TRUE                              
	);
	SetFontSize(50);
	menuPanel.Draw();
	//SetDrawScreen(DX_SCREEN_FRONT);

}




