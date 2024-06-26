#include "TranScene.h"

TranScene::TranScene()
{
}
TranScene::~TranScene()
{
}

unique_Base TranScene::Update(unique_Base scene)
{
	if (!TransUpdate())
	{
		return std::move(nextScene_);
	}
	return scene;
}

void TranScene::Draw()
{
}

void TranScene::DrawOwn()
{
}
