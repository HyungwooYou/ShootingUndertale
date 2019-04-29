#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(string top, string bottom, float x, float y, int width, int height, bool useBottom)
{
	_x = x;
	_y = y;
	_useBottom = useBottom;
	_rcProgress = RectMake(_x, _y, width, height);
	_top = top;
	_bottom = bottom;
	_progressBarTop = IMAGEMANAGER->addImage(top, "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	if (_useBottom)
	{
		_progressBarBottom = IMAGEMANAGER->addImage(bottom, "hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));
		//프로그레스 바 이미지의 크기가 가로크기가 된다.
		_width = _progressBarBottom->GetWidth();
	}
	_maxWidth = width;
	_height = height;



	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->GetWidth(), _progressBarTop->GetHeight());
}

void progressBar::render()
{
	if (_useBottom)
	{
		//렌더는 그려주는 순서 영향을 받는다. 그려지는 순서대로 앞으로 나온다
		IMAGEMANAGER->render(_bottom, getMemDC(),
			_rcProgress.left + _progressBarTop->GetWidth() / 2,
			_y + _progressBarBottom->GetHeight() / 2, 0, 0,
			_progressBarBottom->GetWidth(), _progressBarBottom->GetHeight());
	}
	//앞에 그려지는 게이지의 가로크기를 조절한다.
	IMAGEMANAGER->render(_top, getMemDC(), _rcProgress.left + _maxWidth / 2, _y + _height / 2, 0, 0, _width, _height);
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//수치가 들어오면 계산해준다.
	_width = (currentGauge / maxGauge) * _maxWidth;
}
