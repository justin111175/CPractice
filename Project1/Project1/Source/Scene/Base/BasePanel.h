#pragma once
#include "DxLib.h"
#include "../../Common/Vector2.h"


class BasePanel
{
public:
	virtual void Draw();

	virtual void UpdateDraw() = 0;


protected:
	Vector2 panel_Size;

	int screenID_;
};

