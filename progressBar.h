#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;		//프로그레스 바 렉트
	float _x, _y;			//프로그레스 바 좌표
	float _maxWidth;
	float _width;			//가로크기
	float _height;
	bool _useBottom;
	image* _progressBarTop;
	image* _progressBarBottom;
	string _top;
	string _bottom;


public:
	progressBar();
	~progressBar();

	HRESULT init(string top, string bottom, float x, float y, int width, int height, bool useBottom);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

};

