#pragma once
#include "../Base/Slot.h"
#include "../Base/CollisionBox.h"

class TitleMenuSlot:public Slot
{
public:
	void Init(const SlotData* tmpData)override;
	void UpdateDraw(int screen)override;


	CollisionBox collision;
};

