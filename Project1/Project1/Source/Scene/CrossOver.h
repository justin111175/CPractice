#pragma once
#include "Base/TranScene.h"


class CrossOver:public TranScene
{
public:
	CrossOver(unique_Base oldScene, unique_Base nextScene);
	~CrossOver();

	bool TransUpdate() override;

private:
	int count_;
	void Draw();
	void DrawOwn() override;
};

