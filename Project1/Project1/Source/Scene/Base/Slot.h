#pragma once

#include <iostream>
#include <functional>
#include "../../Common/Vector2.h"
#include"DxLib.h"
#include "../Base/CollisionBox.h"
#include "../../Common/EventDelegateManager.h"

typedef std::function<void(Vector2 pos)> Action;

struct SlotData
{
	int no = 0;
	Vector2 panel_Size;
	Vector2 screenSize;
	Vector2 offSetPos;
	std::string Naem = "";
};

class Slot
{
public:
	Slot();
	~Slot();
	virtual void Init(const SlotData* tmpData)=0;

	virtual void UpdateDraw(int screen)=0;

	Action ButtonAction;
	void BindDeleaget();
protected:
	SlotData slotData;

};

