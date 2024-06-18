#pragma once
#include "../Vector2.h"

class MouseCtl
{
public:

	bool GetClickTrigger();					
	bool GetClicking();					
	const Vector2& Pos();			
	void Update();					

private:
	Vector2 pos;							
	char mouseData=0;							
	char mouseDataOld=0;						
};

