#include "Number.h"
#include "ImageMng.h"
#include <Dxlib.h>

void Number::Init(void)
{
	IpImageMng.GetID("����1", "image/Number/Number3.png", { 45,50 }, { 10,1 });
	numLen = 1;
}

void Number::Draw(Vector2 pos,Vector2Dbl exrate, int score)
{
	// �����l1����
	numLen = 1;

	//�����`�F�b�N
	for (int i = 10; score >= i; i *= 10)
	{
		numLen++;
	}

	//�����`��
	for (int i = 0; i < numLen; i++)
	{
		//IpSceneMng.AddDrawQue({ IMAGE_ID("����1")[score % 10], {pos.x - 90 * exrate.x * i,pos.y} ,{0,0},{exrate.x,exrate.y},0,false,0,LAYER::NUMBER });
		DrawRotaGraph3(pos.x - 45 * exrate.x * i, pos.y, 0, 0, exrate.x, exrate.y, 0, IMAGE_ID("����1")[score % 10], true, false);
		score /= 10;
	}

	// score�̒l�Ŏ��O�`�F�b�N
	if (score <= 0)
	{
		return;
	}

}