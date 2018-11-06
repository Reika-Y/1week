#pragma once
#include <map>
#include <memory>
#include <vector>
#include "VECTOR2.h"

#define IMAGE_ID (ImageMng::GetInstance().GetID)

using namespace std;
using VEC_INT = vector<int>;

class ImageMng
{
public:
	static ImageMng &GetInstance()		
	{
		return *s_Instance;
	}	

	const VEC_INT&GetID(string f_name);
	const VEC_INT&GetID(string f_name, VECTOR2 divSize, VECTOR2 divCnt);	
private:
	struct ImageMngDeleter
	{
		void operator()(ImageMng*imageMng)const
		{
			delete imageMng;
		}
	};

	ImageMng();
	~ImageMng();

	static unique_ptr<ImageMng, ImageMngDeleter>s_Instance;
	map<string, VEC_INT>imgMap;
};

