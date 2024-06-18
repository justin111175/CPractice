#pragma once
#include "../Base/BaseScene.h"
#include "TitleMenu.h"
class TitleScene:public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own) override;					

	Vector2 screen_Size;
private:
	void Draw() override;
	void DrawOwn() override;
	TitleMenu menuPanel;
};

