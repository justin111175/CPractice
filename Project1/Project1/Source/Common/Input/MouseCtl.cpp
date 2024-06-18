#include "MouseCtl.h"
#include <Dxlib.h>
#include "MouseCtl.h"


bool MouseCtl::GetClickTrigger()
{
	return (((mouseData & (~mouseDataOld)) & MOUSE_INPUT_LEFT) != 0);
}

bool MouseCtl::GetClicking()
{
	return (((mouseData & (mouseDataOld)) & MOUSE_INPUT_LEFT) != 0);
}

const Vector2& MouseCtl::Pos()
{
	return pos;
}

void MouseCtl::Update()
{

	GetMousePoint(&pos.x, &pos.y);

	mouseDataOld = mouseData;
	mouseData = GetMouseInput();

}
