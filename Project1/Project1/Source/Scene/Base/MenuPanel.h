#pragma once
#include "../Base/BasePanel.h"


class MenuPanel:public BasePanel
{
public:
	virtual void Init(Vector2 panelSize);

	void Draw() override;
	void UpdateDraw() override;

protected:
	Vector2 screenSize;
	Vector2 offSetPos;
private:


};

