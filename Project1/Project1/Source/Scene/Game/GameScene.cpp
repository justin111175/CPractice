#include "GameScene.h"
#include"../SceneManager.h"
#include "../CrossOver.h"

GameScene::GameScene()
{

	printf("\n進入GameScene");
	isTranUpdate = false;
	LoadMng.GetID("Test_BG", "Resources/image/G_BG.png", { 900,720 }, { 1,1 });
	GetDrawScreenSize(&screen_Size.x, &screen_Size.y);

	screenID_ = MakeScreen(screen_Size.x, screen_Size.y);
	mouseCtl = make_shared<MouseCtl>();
	SceneManager::GetInstance().SetTranUpdate(false);

}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{

	DrawOwn();

	mouseCtl->Update();



	if (isTranUpdate)
	{
		return std::make_unique<CrossOver>(std::move(own), std::make_unique<GameScene>());
	}
	return std::move(own);
}



void GameScene::Draw()
{
	DrawGraph(0, 0, screenID_, true);

	//滑鼠位置渲染
	Vector2 mouseVec;
	GetMousePoint(&mouseVec.x, &mouseVec.y);
	SetFontSize(20);
	DrawFormatString(mouseVec.x, mouseVec.y, 0xff0000, _T("Ｘ:%d　,Ｙ:%d"), mouseVec.x, mouseVec.y);

	
}

void GameScene::DrawOwn()
{

	SetDrawScreen(screenID_);
	ClearDrawScreen();

	//DrawRectExtendGraph(
	//	0, 0, screen_Size.x, screen_Size.y,
	//	0, 0, 900, 720,
	//	LoadMng.GetID("Test_BG")[0],
	//	TRUE
	//);
	SetFontSize(50);
}
