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
		string imgName = AppendInt("frontBar", width); //����ũ�� ���԰���ŭ �̹��� ũ�� ����ũ�⸸ŭ �þ.
		string fileName = MakeImageName("hpBarTop"); //���ϸ� �߰�
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

	//���α׷����� �̹����� ũ�Ⱑ ����ũ�Ⱑ �ȴ�.
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
		_topImgName = imgName; //�̹��� �̸� Ű���� �����ϱ� ����.
		_progressBarTop = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));
	}

	{
		string imgName = AppendInt("backBar", width);
		string fileName = MakeImageName("hpBarBottom");
		_backImgName = imgName; //�̹��� �̸� Ű���� �����ϱ� ����.
		_progressBarBottom = IMAGEMANAGER->addImage(imgName, fileName.c_str(), x, y, width, height, true, RGB(255, 0, 255));

	}

	//���α׷��� �� �̹����� ũ�Ⱑ ����ũ�Ⱑ �ȴ�.
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
	//������ �׷��ִ� ���� ������ �޴´�. �׷����� ������� ������ ���´�.
	IMAGEMANAGER->render(_backImgName, getMemDC(),
		_rcProgress.left + _progressBarBottom->GetWidth() / 2,
		_y + _progressBarBottom->GetHeight() / 2,
		0, 0,
		_progressBarBottom->GetWidth(),
		_progressBarBottom->GetHeight());

	//�տ� �׷����� �������� ����ũ�⸦ �����Ѵ�.
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
