#include "stdafx.h"
#include "dogboss.h"


dogboss::dogboss()
{
}


dogboss::~dogboss()
{
}

HRESULT dogboss::init()
{



	return S_OK;
}

void dogboss::release()
{
}

void dogboss::update(float playerx, float playery, int goLR, float mapx)
{
	_playerx = playerx;
	_playery = playery;
	_goLR = goLR;
	_mapx = mapx;

	
	for (_vibossdog = _vbossdog.begin(); _vibossdog != _vbossdog.end(); _vibossdog++)
	{
		_vibossdog->imagecount++;

		_vibossdog->rc = RectMakeCenter(_vibossdog->x,_vibossdog->y,80,80);
		_vibossdog->imagerc = RectMake(_vibossdog->x-100, _vibossdog->y-160,200,200);
		_vibossdog->hpbar = RectMake(_vibossdog->imagerc.left, _vibossdog->imagerc.top - 40, 200, 30);

		_vibossdog->angle = getAngle(_vibossdog->x,_vibossdog->y,_playerx,_playery);

		_vibossdog->x = _vibossdog->x + cosf(_vibossdog->angle)*_vibossdog->speed;
		_vibossdog->y = _vibossdog->y - sinf(_vibossdog->angle)*_vibossdog->speed;

		if (goLR == 2)
		{
			_vibossdog->x -= 3;
		}
		if (goLR == 3)
		{
			_vibossdog->x += 3;
		}


		if (_vibossdog->imagecount % 10 == 0) // 10초마다
		{
			if (_vibossdog->x < _playerx) //플레이어 오른쪽에서옴
			{
				if (_vibossdog->imageindex > 3) // index 3보다 크면
				{
					_vibossdog->imageindex = 0; // 일단 이미지 0으로만들고
				}
				_vibossdog->image->SetFrameX(_vibossdog->imageindex); //이미지입히고

				_vibossdog->imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
			}
			else if (_vibossdog->x > _playerx) //플레이어 왼쪽에서옴
			{
				if (_vibossdog->imageindex < 4) // index 3보다 크면
				{
					_vibossdog->imageindex = 7; // 일단 이미지 0으로만들고
				}
				_vibossdog->image->SetFrameX(_vibossdog->imageindex); //이미지입히고

				_vibossdog->imageindex--; //다음 이미지를쓰기위해 인덱스를 늘린다.
			}
		}
	}
}

void dogboss::render(float playerx)
{
	for (_vibossdog = _vbossdog.begin(); _vibossdog != _vbossdog.end(); _vibossdog++)
	{
		//Rectangle(getMemDC(), _vibossdog->imagerc);
		//Rectangle(getMemDC(), _vibossdog->rc);
		//Rectangle(getMemDC(), _vibossdog->hpbar);

		IMAGEMANAGER->findImage("빨간바1")->render(getMemDC(),_vibossdog->hpbar.left,_vibossdog->hpbar.top);
		IMAGEMANAGER->findImage("초록바1")->render(getMemDC(), _vibossdog->hpbar.left,_vibossdog->hpbar.top,0,0,_vibossdog->hp,30);
		IMAGEMANAGER->findImage("준보스")->frameRender(getMemDC(),_vibossdog->imagerc.left,_vibossdog->imagerc.top);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6))
	{
		if (checkrect2 == true)
		{
			checkrect2 = false;
		}
		else if (checkrect2 == false)
		{
			checkrect2 = true;
		}
	}
	if (checkrect2 == true)
	{
		for (_vibossdog = _vbossdog.begin(); _vibossdog != _vbossdog.end(); _vibossdog++)
		{
			Rectangle(getMemDC(), _vibossdog->rc);
		}
	}
}

void dogboss::bossdogCreate()
{
	if (_mapx > -800)
	{
		tagdogboss dogboss1;
		ZeroMemory(&dogboss1, sizeof(dogboss1));
		dogboss1.image = IMAGEMANAGER->addFrameImage("준보스", "dogboss.bmp", 1600, 200, 8, 1, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("빨간바1", "frontbar2.bmp", 200, 30, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("초록바1", "bottombar1.bmp", 200, 30, true, RGB(255, 0, 255));

		dogboss1.hp = 200;
		dogboss1.imagecount = 0;
		dogboss1.imageindex = 0;
		dogboss1.speed = 2.0f;
		dogboss1.angle = 0;
		dogboss1.x = _playerx + 1000;
		dogboss1.y = _playery;

		_vbossdog.push_back(dogboss1);
	}
	else if (_mapx <= -800)
	{
		tagdogboss dogboss1;
		ZeroMemory(&dogboss1, sizeof(dogboss1));
		dogboss1.image = IMAGEMANAGER->addFrameImage("준보스", "dogboss.bmp", 1600, 200, 8, 1, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("빨간바1", "frontbar2.bmp", 200, 30, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("초록바1", "bottombar1.bmp", 200, 30, true, RGB(255, 0, 255));

		dogboss1.hp = 200;
		dogboss1.imagecount = 0;
		dogboss1.imageindex = 0;
		dogboss1.speed = 2.0f;
		dogboss1.angle = 0;
		dogboss1.x = _playerx - 1000;
		dogboss1.y = _playery;

		_vbossdog.push_back(dogboss1);
	}
}
