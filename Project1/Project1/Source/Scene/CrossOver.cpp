#include "CrossOver.h"

CrossOver::CrossOver(unique_Base oldScene, unique_Base nextScene)
{
	oldScene_ = std::move(oldScene);
	nextScene_ = std::move(nextScene);
	GetDrawScreenSize(&screenSize.x, &screenSize.y);
	screenID_ = MakeScreen(screenSize.x, screenSize.y);

	count_ = 0;
}

CrossOver::~CrossOver()
{


}

bool CrossOver::TransUpdate()
{
	DrawOwn();
	count_ += 5;
	return (count_ < 255);
}

void CrossOver::Draw()
{


	DrawGraph(0, 0, screenID_, true);

}

void CrossOver::DrawOwn()
{
	SetDrawScreen(screenID_);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - count_);
	oldScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
	nextScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
