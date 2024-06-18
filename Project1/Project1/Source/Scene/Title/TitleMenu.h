#pragma once
#include"../Base/MenuPanel.h"
#include <iostream>
#include <map>
#include "TitleMenuSlot.h"


class TitleMenu : public MenuPanel
{
	enum MenuType
	{
		StartGame,
		Editor,
		Quit,
		Max
	};


public:
	void Init(Vector2 panelSize)override;

	void Draw() override;
	void UpdateDraw() override;

	std::map<MenuType, TitleMenuSlot> slotMap;

};

