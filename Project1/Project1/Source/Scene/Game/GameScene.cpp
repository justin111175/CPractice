#include "GameScene.h"

GameScene::GameScene()
{

	printf("進入GameScene");
	LoadMng.GetID("Test_BG", "Resources/image/G_BG.png", { 900,720 }, { 1,1 });
	GetDrawScreenSize(&screen_Size.x, &screen_Size.y);

	screenID_ = MakeScreen(screen_Size.x, screen_Size.y);
	mouseCtl = make_shared<MouseCtl>();
	delegateMng = EventDelegateManager::GetInstance();
}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	DrawOwn();

	mouseCtl->Update();

	if (mouseCtl->GetClickTrigger() & MOUSE_INPUT_LEFT)
	{

		if (mouseCtl->GetClickTrigger() & MOUSE_INPUT_LEFT)
		{
			//delegateMng.ExecuteButtonDelegate(mouseCtl->Pos());
		}

	}

	return std::move(own);
}

void GameScene::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();  // 清空主画面
	//menuPanel.Draw();

	DrawGraph(0, 0, screenID_, true);

	//滑鼠位置渲染
	Vector2 mouseVec;
	GetMousePoint(&mouseVec.x, &mouseVec.y);
	SetFontSize(20);
	DrawFormatString(mouseVec.x, mouseVec.y, 0xff0000, _T("Ｘ:%d　,Ｙ:%d"), mouseVec.x, mouseVec.y);

	ScreenFlip();

}

void GameScene::DrawOwn()
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
}
