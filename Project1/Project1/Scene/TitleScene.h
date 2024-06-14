#pragma once
#include "BaseScene.h"
class TitleScene:public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own) override;					// XV
	void BaseDraw(void) override;									// •`‰æ

private:
	void Draw(void);
};

