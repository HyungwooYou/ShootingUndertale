#pragma once
#include "gameNode.h"
class Bar : public gameNode
{
private:
	RECT _rcProgress; // 프로그레스바렉트
	float _x, _y; //프로그레스바 좌표
	float _width; //프로그레스바 가로크기

	//키값으로 설정하기위해 문자열 공간을 만들어줌
	string _topImgName;	//상단 이미지 문자열
	string _backImgName; //하단 이미지 문자열

	image* _progressBarTop; //상단 체력바 이미지
	image* _progressBarBottom; //하단 체력바 이미지

public:
	Bar();
	~Bar();

	HRESULT init(int x, int y, int width, int height);
	HRESULT init(const char* backImgName, const char* frontImgName, int x, int y,int width, int height);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);
	
	void setX(int x){_x = x;}
	void setY(int y){_y = y;}
};

