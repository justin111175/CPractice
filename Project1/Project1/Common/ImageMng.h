#pragma once
#include <memory>
#include <map>
#include <vector>
#include "Vector2.h"
using VecInt = std::vector<int>;

#define IpImageMng ImageMng::GetInstance()

#define IMAGE_ID(KEY)(ImageMng::GetInstance().GetID(KEY))
#define IMAGE_SOUND(KEY)(ImageMng::GetInstance().GetSound(KEY))


class ImageMng
{
public:
	static ImageMng &GetInstance(void)
	{
		return *sInstance;
	}
	
	const VecInt& GetID(const std::string&key);
	const VecInt& GetID(const std::string&key, const std::string & fileName);
	const VecInt& GetID(const std::string&key, const std::string & fileName, const Vector2 & divSize, const Vector2 & divCnt);

	const VecInt& GetSound(const std::string&key);
	const VecInt& GetSound(const std::string&key, const std::string & fileName);


private:
	struct ImageMngDeleter
	{
		void operator()(ImageMng* imageMng)const
		{
			delete imageMng;
		}
	};
	
	ImageMng();
	~ImageMng();
	
	static std::unique_ptr <ImageMng,ImageMngDeleter> sInstance;
	
	std::map<std::string, VecInt> imgMap;
	std::map<std::string, VecInt> soundMng;


};


