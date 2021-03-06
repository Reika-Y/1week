#include "DxLib.h"
#include "ImageMng.h"


unique_ptr<ImageMng, ImageMng::ImageMngDeleter>ImageMng::s_Instance(new ImageMng());

// 引数なし
const VEC_INT & ImageMng::GetID(string f_name)
{
	if (imgMap.find(f_name) == imgMap.end())				// f_nameの画像IDのﾊﾝﾄﾞﾙﾁｪｯｸ
	{
		imgMap[f_name].resize(1);							// f_nameの画像IDを読み込み、ﾊﾝﾄﾞﾙを作成
		imgMap[f_name][0] = LoadGraph(f_name.c_str());		
	}
	return imgMap[f_name];									// f_nameの画像IDを返す
}

 // 引数付き
const VEC_INT & ImageMng::GetID(string f_name, VECTOR2 divSize, VECTOR2 divCnt)
{
	if (imgMap.find(f_name) == imgMap.end())
	{
		imgMap[f_name].resize(divCnt.x * divCnt.y);
		LoadDivGraph(f_name.c_str(), (divCnt.x * divCnt.y),
			divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap[f_name][0], true);
	}
	return imgMap[f_name];
}

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}
