#pragma once
#include <memory>
#include <string>
#include "DxLib.h"
#include <map>

#include "../common/Input/Controller.h"
#include "../common/ImageMng.h"
class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;							

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base own) = 0;					
	virtual void Draw();
	virtual void DrawOwn() = 0;
protected:

	
	std::map<conType, std::unique_ptr<Controller>> controller;
	int screenID_;
											
private:

};

