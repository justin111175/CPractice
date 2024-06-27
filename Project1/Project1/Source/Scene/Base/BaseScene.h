#pragma once
#include <memory>
#include <string>
#include "DxLib.h"
#include <map>


#include "../../common/LoadManager.h"
#include "../../Common/Input/MouseCtl.h"
#include "../../Common/EventDelegateManager.h"

class BaseScene;
using namespace std;
using unique_Base = unique_ptr<BaseScene>;							

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base own) = 0;	

	virtual void Draw();
	virtual void DrawOwn() = 0;
	bool isTranUpdate = false;

protected:
	EventDelegateManager delegateMng;
	shared_ptr<MouseCtl> mouseCtl;

	int screenID_;
private:

};

