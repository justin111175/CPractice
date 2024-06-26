#include "Slot.h"
Slot::Slot()
{
}
Slot::~Slot()
{
}
void Slot::Init(const SlotData* tmpData)
{
	//panel_Size = tmpPanelSize;
	//GetDrawScreenSize(&screenSize.x, &screenSize.y);

}

void Slot::UpdateDraw(int screen)
{
	//SetDrawScreen(screen);
	//DrawBox(0, 0, panel_Size.x, panel_Size.y, 0xffff00, true);
}

void Slot::BindDeleaget()
{
	EventDelegateManager::GetInstance().OnButtonDelegates.push_back(ButtonAction);

}

