#include "DxLib.h"
#include "ImageMng.h"


unique_ptr<ImageMng, ImageMng::ImageMngDeleter>ImageMng::s_Instance(new ImageMng());

// �����Ȃ�
const VEC_INT & ImageMng::GetID(string f_name)
{
	if (imgMap.find(f_name) == imgMap.end())				// f_name�̉摜ID�����������
	{
		imgMap[f_name].resize(1);							// f_name�̉摜ID��ǂݍ��݁A����ق��쐬
		imgMap[f_name][0] = LoadGraph(f_name.c_str());		
	}
	return imgMap[f_name];									// f_name�̉摜ID��Ԃ�
}

 // �����t��
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
