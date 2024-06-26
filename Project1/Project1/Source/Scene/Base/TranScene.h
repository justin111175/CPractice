#pragma once

#include "BaseScene.h"
class TranScene : public BaseScene
{
public:
	TranScene();
	~TranScene();

	unique_Base Update(unique_Base scene) override;

	void Draw();
	void DrawOwn() override;

	virtual bool TransUpdate() = 0;			
protected:
	unique_Base oldScene_;			
	unique_Base nextScene_;			

};

