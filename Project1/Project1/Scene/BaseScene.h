#pragma once
#include <memory>
#include <string>
#include "DxLib.h"
class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;							

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base own) = 0;					
	virtual void BaseDraw(void) = 0;
protected:
	void FadeInit(std::string fadeType);								
	bool FadeUpdate(void);												
	std::string _fadeType;												
private:
	int _fadeScrID;														

};

