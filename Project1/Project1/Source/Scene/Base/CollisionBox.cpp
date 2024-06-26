#include "CollisionBox.h"

CollisionBox::CollisionBox()
{
}

CollisionBox::~CollisionBox()
{
}

void CollisionBox::Init(Vector2 tmpPos, Vector2 tmpSize)
{
    
    pos = tmpPos;
    size = tmpSize;
    
}

bool CollisionBox::isPointInside(Vector2 mousePos)
{
    
    return mousePos.x >= pos.x && mousePos.x <= (pos.x + size.x) && mousePos.y >= pos.y && mousePos.y <= (pos.y + size.y);
    
}
