#pragma once

#include "../Base/BaseScene.h"
class GameScene :public BaseScene
{

public:
	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own) override;

	Vector2 screen_Size;
private:
	void Draw() override;
	void DrawOwn() override;
};

