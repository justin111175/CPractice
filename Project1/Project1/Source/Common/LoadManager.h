#pragma once
#include <memory>
#include <map>
#include <vector>
#include "Vector2.h"

using VecInt = std::vector<int>;

#define LoadMng LoadManager::GetInstance()
#define IMAGE_ID(KEY)(LoadManager::GetInstance().GetID(KEY))
#define SOUND_ID(KEY)(LoadManager::GetInstance().GetSound(KEY))


class LoadManager
{
public:
	static LoadManager &GetInstance(void)
	{
		return *sInstance;
	}
	
	const VecInt& GetID(const std::string&key);
	const VecInt& GetID(const std::string&key, const std::string & fileName);
	const VecInt& GetID(const std::string&key, const std::string & fileName, const Vector2 & divSize, const Vector2 & divCnt);

	const VecInt& GetSound(const std::string&key);
	const VecInt& GetSound(const std::string&key, const std::string & fileName);


private:
	struct LoadMngDeleter
	{
		void operator()(LoadManager* imageMng)const
		{
			delete imageMng;
		}
	};
	
	LoadManager();
	~LoadManager();
	
	static std::unique_ptr <LoadManager,LoadMngDeleter> sInstance;
	
	std::map<std::string, VecInt> imgMap;
	std::map<std::string, VecInt> soundMng;


};


