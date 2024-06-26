#pragma once
#include "../Common/Singleton.h"
#include "../Common/Vector2.h"
#include "Base/BaseScene.h"
#include "DxLib.h"


class SceneManager:public Singleton<SceneManager>
{
public:
    void Run();
    const int Frames() const { return frames; }
    int blendCnt;
    const Vector2 screenSize;
    
    void SetTranUpdate(bool flag);

private:
    bool isTranUpdate = false;

    friend class Singleton<SceneManager>;
    
    SceneManager();
    ~SceneManager();

    bool SysInit();
    unique_Base activeScene;  
    int frames;                


};

