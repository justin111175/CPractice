#include "TitleMenuSlot.h"
#include"../../Common/Debug/_DebugDispOut.h"
#include "../../Common/Function.h"
#include "../../Common/LoadManager.h"

void TitleMenuSlot::Init(const SlotData* tmpData)
{

	slotData = *tmpData;

	collision.Init(slotData.offSetPos, slotData.panel_Size);
	LoadMng.GetID("txtBG", "Resources/image/txtBG.png", { 310,330 }, { 1,1 });
	screenID_ = MakeScreen(slotData.panel_Size.x, slotData.panel_Size.y);

}

void TitleMenuSlot::Draw()
{
	DrawGraph(slotData.offSetPos.x, slotData.offSetPos.y, screenID_, true);


}

void TitleMenuSlot::UpdateDraw()
{

	SetDrawScreen(screenID_);
	ClearDrawScreen();

	//DrawRectExtendGraph(
	//	slotData.pos.x,                             // x1: 左上角 x 坐標
	//	slotData.pos.y,                             // y1: 左上角 y 坐標
	//	slotData.pos.x + slotData.panel_Size.x,     // x2: 右下角 x 坐標
	//	slotData.pos.y + slotData.panel_Size.y,     // y2: 右下角 y 坐標
	//	0,                                          // SrcX1: 圖像源矩形的左上角 x 坐標
	//	0,                                          // SrcY1: 圖像源矩形的左上角 y 坐標
	//	slotData.pos.x + slotData.panel_Size.x, slotData.pos.y + slotData.panel_Size.y,
	//	LoadMng.GetID("txtBG")[0],                                    // 使用的圖像 ID
	//	TRUE                                        // TRUE 表示啟用透明度
	//);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawBox(0, 0, slotData.panel_Size.x,slotData.panel_Size.y, 0xffffff, true);
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	SetFontSize(30);
	DrawString(65,10, ConvertToTCHAR(slotData.Naem), 0x000000);
	//DrawBox(0, 0, panel_Size.x, panel_Size.y, 0xffff00, true);

}
