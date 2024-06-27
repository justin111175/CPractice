#include "TitleMenu.h"
#include "../SceneManager.h"
#include "../Game/GameScene.h"

void TitleMenu::Init(Vector2 panelSize)
{
	panel_Size = panelSize;
	screenID_ = MakeScreen(panel_Size.x, panel_Size.y);
	GetDrawScreenSize(&screenSize.x, &screenSize.y);
	
	// 偏移位置
	offSetPos = Vector2{ (screenSize.x - panel_Size.x) /2, 430 };


	TitleMenuSlot tmpSlot;
	SlotData tmpData;

	tmpSlot.ButtonAction = [&]() {
		DxLib_End();
		};
	tmpData = InitSlotData(MenuType::Quit);
	tmpSlot.Init(&tmpData);
	slotMap.try_emplace(MenuType::Quit, tmpSlot);


	tmpSlot.ButtonAction = [&]() {
		//SceneManager::GetInstance().SceneMovement(std::make_unique<GameScene>());
		};
	tmpData = InitSlotData(MenuType::StartGame);
	tmpSlot.Init(&tmpData);
	slotMap.try_emplace(MenuType::StartGame, tmpSlot);





}

void TitleMenu::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(offSetPos.x, offSetPos.y, screenID_, true);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	for (auto& slot : slotMap)
	{
		slot.second.Draw();
	}
}

void TitleMenu::UpdateDraw()
{
	
	SetDrawScreen(screenID_);
	ClearDrawScreen();

	DrawBox(0, 0, panel_Size.x, panel_Size.y, 0x000000, true);

	for (auto& slot : slotMap)
	{
		slot.second.UpdateDraw();
	}

}

SlotData TitleMenu::InitSlotData(MenuType type)
{
	SlotData data;

	switch (type)
	{
	case TitleMenu::StartGame:
		data.Naem = "Start";
		break;
	case TitleMenu::Editor:
		break;
	case TitleMenu::Quit:
		data.Naem = "Quit";
		break;
	case TitleMenu::Max:
		break;
	default:
		break;
	}

	data.panel_Size = { panel_Size.x, panel_Size.y / MenuType::Max };
	data.localPos = Vector2{ 0,20+30* type };
	data.offSetPos = offSetPos + data.localPos;
	data.screenSize = screenSize;

	return data;

}

