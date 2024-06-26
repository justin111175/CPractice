#pragma once
#include "../Base/Slot.h"

class TitleMenuSlot:public Slot
{
public:
	TitleMenuSlot() {}
	~TitleMenuSlot() {}

	void Init(const SlotData* tmpData)override;
	void UpdateDraw(int screen)override;

	//CollisionBox collision;
	CollisionBox collision;

};

