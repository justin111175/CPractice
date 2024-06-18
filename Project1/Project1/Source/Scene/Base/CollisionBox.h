#pragma once


class CollisionBox
{
public:
    Vector2 pos;
    Vector2 size;
    bool isPointInside(Vector2 mousePos) {
        return mousePos.x >= pos.x && mousePos.x <= (pos.x + size.x) && mousePos.y >= pos.y && mousePos.y <= (pos.y + size.y);
    }
};