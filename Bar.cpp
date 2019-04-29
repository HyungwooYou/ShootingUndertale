#include "stdafx.h"
#include "Bar.h"


Bar::Bar()
{
}


Bar::~Bar()
{
}

HRESULT Bar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	{
		string imgName = AppendInt("frontBar", width); //가로크기 대입값만큼 이미지 크기 가로크기만큼 늘어남.
		string fileName = MakeImageName("hpBarTop"); //파일명 추가
		_topImgName = imgName;
		_progressBarTop = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));
	}

	{
		string imgName = AppendInt("backBar", width);
		string fileName = MakeImageName("hpBarBottom");
		_backImgName = imgName;
		_progressBarBottom = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));
	}


	/*_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));*/

	//프로그래스바 이미지의 크기가 가로크기가 된다.
	_width = _progressBarBottom->GetWidth();

	return S_OK;
}

HRESULT Bar::init(const char * backImgName, const char * frontImgName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	{
		string imgName = AppendInt("frontBar", width);
		string fileName = MakeImageName("hpBarTop");
		_topImgName = imgName; //이미지 이름 키값을 저장하기 위함.
		_progressBarTop = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));
	}

	{
		string imgName = AppendInt("backBar", width);
		string fileName = MakeImageName("hpBarBottom");
		_backImgName = imgName; //이미지 이름 키값을 저장하기 위함.
		_progressBarBottom = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));

	}

	//프로그레스 바 이미지의 크기가 가로크기가 된다.
	_width = _progressBarBottom->GetWidth();

	return S_OK;
}

void Bar::release()
{
}

void Bar::update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->GetWidth(), _progressBarTop->GetHeight());
}


void Bar::render()
{
	//렌더는 그려주는 순서 영향을 받는다. 그려지는 순서대로 앞으로 나온다.
	IMAGEMANAGER->render(_backImgName, getMemDC(),
		_rcProgress.left + _progressBarBottom->GetWidth() / 2,
		_y + _progressBarBottom->GetHeight() / 2,
		0, 0,
		_progressBarBottom->GetWidth(),
		_progressBarBottom->GetHeight());

	//앞에 그려지는 게이지의 가로크기를 조절한다.
	IMAGEMANAGER->render(_topImgName, getMemDC(),
		_rcProgress.left + _progressBarBottom->GetWidth() / 2,
		_y + _progressBarBottom->GetHeight() / 2,
		0, 0,
		_width, _progressBarBottom->GetHeight());
}

void Bar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->GetWidth();
}
