#include "BaseScene.h"

BaseScene::BaseScene()
{
    
}

BaseScene::~BaseScene()
{
}

void BaseScene::Draw()
{

    DrawGraph(0, 0, screenID_, true);

}


