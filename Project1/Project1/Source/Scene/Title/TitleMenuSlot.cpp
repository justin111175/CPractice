#include "TitleMenuSlot.h"
#include"../../Common/Debug/_DebugDispOut.h"
#include "../../Common/Function.h"

void TitleMenuSlot::Init(const SlotData* tmpData)
{

	slotData = *tmpData;

	collision.Init(slotData.offSetPos, slotData.panel_Size);
	BindDeleaget();
}

void TitleMenuSlot::UpdateDraw(int screen)
{

	SetDrawScreen(screen);
	DrawBox(0, 0, slotData.panel_Size.x, slotData.panel_Size.y, 0xffff00, true);
	SetFontSize(30);
	DrawString(65, 10, ConvertToTCHAR(slotData.Naem), 0x000000);
	//DrawBox(0, 0, panel_Size.x, panel_Size.y, 0xffff00, true);

}
