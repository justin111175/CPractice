#pragma once
#include "BaseScene.h"
class TitleScene:public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own) override;					
	
	void Init(void);
	Vector2 screen_size_;
private:
	void DrawOwn() override;
	void Ctl(conType input);

};

