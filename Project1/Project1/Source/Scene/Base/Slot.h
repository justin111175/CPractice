#pragma once

#include <iostream>
#include <functional>
#include "../../Common/Vector2.h"
#include"DxLib.h"
#include "../Base/CollisionBox.h"
#include "../../Common/EventDelegateManager.h"

typedef std::function<void()> Action;

struct SlotData
{
	int no = 0;
	Vector2 panel_Size;
	Vector2 screenSize;
	Vector2 offSetPos;
	Vector2 localPos;
	std::string Naem = "";
};

class Slot
{
public:
	Slot();
	~Slot();
	virtual void Init(const SlotData* tmpData)=0;
	virtual void Draw();
	virtual void UpdateDraw()=0;

	Action ButtonAction;

	CollisionBox collision;

protected:
	SlotData slotData;
	int screenID_;

};

