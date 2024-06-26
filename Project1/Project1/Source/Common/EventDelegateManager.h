#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "Singleton.h"
#include "map"
#include "string"
#include"Vector2.h"
#include "../Scene/Base/CollisionBox.h"

using namespace std;
using EventDelegate = function<void(Vector2)>;


class EventDelegateManager:public Singleton<EventDelegateManager>
{
public:

    // 執行delegate
    void ExecuteButtonDelegate(Vector2 pos) {
        
		for (auto& component : OnButtonDelegates) 
		{
            component(pos);
		}
    }

    vector<EventDelegate>  OnButtonDelegates;

};

