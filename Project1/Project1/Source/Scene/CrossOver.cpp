#include "CrossOver.h"

CrossOver::CrossOver(unique_Base oldScene, unique_Base nextScene)
{
	oldScene_ = std::move(oldScene);
	nextScene_ = std::move(nextScene);
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
