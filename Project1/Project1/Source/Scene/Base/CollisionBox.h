#pragma once

#include "../../Common/Vector2.h"
class CollisionBox
{
public:
    CollisionBox();
    ~CollisionBox();
    Vector2 pos = {0,0};
    Vector2 size = {0,0};

    void Init(Vector2 tmpPos, Vector2 tmpSize);

    bool isPointInside(Vector2 mousePos);
};