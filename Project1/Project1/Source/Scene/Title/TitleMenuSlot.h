#pragma once
#include "../Base/Slot.h"

class TitleMenuSlot:public Slot
{
public:
	TitleMenuSlot() {}
	~TitleMenuSlot() {}

	void Init(const SlotData* tmpData)override;
	void UpdateDraw()override;
	void Draw()override;

	//CollisionBox collision;

};

