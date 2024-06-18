#include "TitleScene.h"
#include "../../Common/Debug/_DebugDispOut.h"
#include "../../Common/Debug/_DebugConOut.h"
#include"../../Common/Function.h"
#include "../../Common/LoadManager.h"

TitleScene::TitleScene()
{
	TRACE("\n%s", "初始化登入頁面");
	LoadMng.GetID("Test_BG", "Resources/image/G_BG.png", { 900,720 }, { 1,1 });
	GetDrawScreenSize(&screen_Size.x, &screen_Size.y);
	menuPanel.Init({ 200, 150 });

	screenID_ = MakeScreen(screen_Size.x, screen_Size.y);
	mouseCtl = std::make_shared<MouseCtl>();
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
		for (auto& component : menuPanel.slotMap) {
			if (component.second.collision.isPointInside(mouseCtl->Pos())) {
				TRACE("成功");
				break;
			}
		}
	}

	return std::move(own);
}



void TitleScene::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();  // 清空主画面
	//menuPanel.Draw();

	DrawGraph(0, 0, screenID_, true);
	
	menuPanel.Draw();

	Vector2 mouseVec;
	GetMousePoint(&mouseVec.x, &mouseVec.y);
	SetFontSize(20);
	DrawFormatString(mouseVec.x, mouseVec.y, 0xff0000, _T("Ｘ:%d　,Ｙ:%d"), mouseVec.x, mouseVec.y);

	ScreenFlip();
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

	//SetDrawScreen(DX_SCREEN_FRONT);

}




