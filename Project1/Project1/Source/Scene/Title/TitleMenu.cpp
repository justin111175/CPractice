#include "TitleMenu.h"

void TitleMenu::Init(Vector2 panelSize)
{
	panel_Size = panelSize;
	screenID_ = MakeScreen(panel_Size.x, panel_Size.y);
	GetDrawScreenSize(&screenSize.x, &screenSize.y);
	
	offSetPos = Vector2{ (screenSize.x - panel_Size.x) /2, 430 };


	SlotData data;
	data.Naem = "Quit";
	data.panel_Size = { panel_Size.x, panel_Size.y / MenuType::Max };
	data.offSetPos = offSetPos;
	data.screenSize = screenSize;

	TitleMenuSlot quitSlot;
	quitSlot.Init(&data);
	quitSlot.ButtonAction = []() {	
		DxLib_End();
	};

	slotMap.try_emplace(MenuType::Quit, quitSlot);
}

void TitleMenu::Draw()
{
	DrawGraph(offSetPos.x, offSetPos.y, screenID_, true);

}

void TitleMenu::UpdateDraw()
{
	
	SetDrawScreen(screenID_);
	ClearDrawScreen();
	DrawBox(0, 0, panel_Size.x, panel_Size.y, GetColor(0, 0, 0), true);
	DrawBox(0, 0, panel_Size.x, panel_Size.y, GetColor(255, 255, 255), false);
	
	slotMap[MenuType::Quit].UpdateDraw(screenID_);

}
