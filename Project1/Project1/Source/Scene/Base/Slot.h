#pragma once

#include <iostream>
#include <functional>
#include "../../Common/Vector2.h"
#include"DxLib.h"
typedef std::function<void()> Action;

struct SlotData
{
	Vector2 panel_Size;
	Vector2 screenSize;
	Vector2 offSetPos;
	std::string Naem = "";
};

class Slot
{
public:

	virtual void Init(const SlotData* tmpData)=0;

	virtual void UpdateDraw(int screen)=0;
	Action ButtonAction;

protected:
	SlotData slotData;

};

