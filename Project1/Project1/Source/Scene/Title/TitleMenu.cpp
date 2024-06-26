#include "TitleMenu.h"

void TitleMenu::Init(Vector2 panelSize)
{
	panel_Size = panelSize;
	screenID_ = MakeScreen(panel_Size.x, panel_Size.y);
	GetDrawScreenSize(&screenSize.x, &screenSize.y);
	
	offSetPos = Vector2{ (screenSize.x - panel_Size.x) /2, 430 };


	SlotData QuitData;
	QuitData.no = 0;
	QuitData.Naem = "Quit";
	QuitData.panel_Size = { panel_Size.x, panel_Size.y / MenuType::Max };
	QuitData.offSetPos = offSetPos;
	QuitData.screenSize = screenSize;

	TitleMenuSlot quitSlot;
	quitSlot.ButtonAction = [&](Vector2 pos) {
		if (quitSlot.collision.isPointInside(pos))
		{
			DxLib_End();
		}
		};
	quitSlot.Init(&QuitData);
	slotMap.try_emplace(MenuType::Quit, quitSlot);


	TitleMenuSlot startSlot;
	startSlot.ButtonAction = [&](Vector2 pos) {
		if (startSlot.collision.isPointInside(pos))
		{
			DxLib_End();
		}
	};

	SlotData StartData;
	QuitData.no = 1;
	StartData.Naem = "Start";
	StartData.panel_Size = { panel_Size.x, panel_Size.y / MenuType::Max };
	StartData.offSetPos = offSetPos;
	StartData.screenSize = screenSize;
	startSlot.Init(&StartData);

	slotMap.try_emplace(MenuType::StartGame, startSlot);




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
	slotMap[MenuType::StartGame].UpdateDraw(screenID_);

}

