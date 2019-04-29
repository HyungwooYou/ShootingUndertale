#include "stdafx.h"
#include "bird.h"


bird::bird()
{
}


bird::~bird()
{
}

HRESULT bird::init(int birdMax)
{
	//미리 만들어둘 새의 최대수
	_birdMax = birdMax;
	wave1 = false;
	return S_OK;
}

void bird::release()
{

}

void bird::update(float playerx, float playery, int goLR)
{
	//받아오는 아이들
	_goLR = goLR;
	_playerx = playerx;
	_playery = playery;

	//버드 렉트 갱신
	if (_vbird.size() > 0)
	{
		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			_vibird->rc = RectMakeCenter(_vibird->birdx, _vibird->birdy, _vibird->size, _vibird->size);

			if (_vibird->birdx < _playerx)
			{
				_vibird->LR = 2;
			}

			if (_vibird->birdx > _playerx)
			{
				_vibird->LR = 1;
			}
		}
	}

		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			_vibird->imagecount++;

			if (_vibird->LR == 2)
			{
				if (_vibird->imagecount % 10 == 0)
				{
					if (_vibird->imageindex > 4)
					{
						_vibird->imageindex = 0;
					}
					_vibird->image1->SetFrameX(_vibird->imageindex);

					_vibird->imageindex++;
				}
			}

			if (_vibird->LR == 1)
			{
				if (_vibird->imagecount % 10 == 0)
				{
					if (_vibird->imageindex > 3)
					{
						_vibird->imageindex = 0;
					}
					_vibird->image2->SetFrameX(_vibird->imageindex);

					_vibird->imageindex++;
				}
			}
		}


	//wave1 시작하기전
	if (wave1on == true)
	{
		//wave1
		birdcreate1();
	}

	//새 카메라
	birdcamera();

	//새움직임
	birdMove();

	//새 체력바
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		_vibird->hpbar = RectMakeCenter(_vibird->birdx,_vibird->birdy - 40, 50, 10);
	}
}

void bird::render(float playerx)
{
	//버드 렉트 갱신
	if (_vbird.size() > 0)
	{
		for(_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			if (_vibird->LR == 2)
			{
				IMAGEMANAGER->findImage("움직이는새1")->frameRender(getMemDC(), _vibird->rc.left, _vibird->rc.top);
			}
			if (_vibird->LR == 1)
			{
				IMAGEMANAGER->findImage("움직이는새2")->frameRender(getMemDC(), _vibird->rc.left, _vibird->rc.top);
			}
			
			// 새 체력바
			Rectangle(getMemDC(),_vibird->hpbar);
			IMAGEMANAGER->findImage("빨간바")->render(getMemDC(),_vibird->hpbar.left,_vibird->hpbar.top,0,0,50,10);
			IMAGEMANAGER->findImage("초록바")->render(getMemDC(), _vibird->hpbar.left, _vibird->hpbar.top,0,0,_vibird->hp*2.5,10);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5))
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
		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			Rectangle(getMemDC(),_vibird->rc);
		}
	}

	//테스트용 치트키
	//int e = 0;
	//for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	//{
	//	e++;
	//	sprintf_s(str, "%d", _vibird->LR);
	//	TextOut(getMemDC(), 50, 50 + e * 50, str, strlen(str));
	//}
}

//wave1
void bird::birdcreate1()
{
	float angle;

	if (wave1 == false)
	{
		angle = PI/8;
		//테스트용 5마리
		for (int i = 0; i < 50; i++)
		{
			tagbird monsterbird;
			ZeroMemory(&monsterbird, sizeof(monsterbird));
			monsterbird.image1 = IMAGEMANAGER->addFrameImage("움직이는새1", "birdfly1.bmp", 200, 50,4,1,true, RGB(255, 0, 255));
			monsterbird.image2 = IMAGEMANAGER->addFrameImage("움직이는새2", "birdfly2.bmp", 200, 50, 4, 1, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 50, 10, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 50, 10, true, RGB(255, 0, 255));

			monsterbird.hp = 20;
			monsterbird.imagecount = 0;
			monsterbird.imageindex = 0;
			monsterbird.size = 50;
			monsterbird.speed = 3.0f;
			monsterbird.angle = 0;
			monsterbird.birdx = _playerx + cosf(angle)*1300;
			monsterbird.birdy = _playery - sinf(angle)*1300;
			monsterbird.isDead = false;

			_vbird.push_back(monsterbird);
			wave1 = true;

			angle += PI/20;
		}
	}
}

//새 카메라
void bird::birdcamera()
{
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		if (_goLR == 2)
		{
			_vibird->birdx -= 3;
		}
		if (_goLR == 3)
		{
			_vibird->birdx += 3;
		}
	}
}

//새움직임
void bird::birdMove()
{
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		_vibird->playerDistance = getDistance(_vibird->birdx, _vibird->birdy, _playerx, _playery);
		if (_vibird->playerDistance > 300)
		{
			_vibird->birdstate = 0;
			_vibird->rndNumber = RND->getFromFloatTo(-PI / 1.5, PI / 1.5);
			_vibird->playerangle = getAngle(_vibird->birdx, _vibird->birdy, _playerx, _playery);
			_vibird->birdx = _vibird->birdx + cosf(_vibird->playerangle + _vibird->rndNumber)*_vibird->speed;
			_vibird->birdy = _vibird->birdy - sinf(_vibird->playerangle + _vibird->rndNumber)*_vibird->speed;
		}
		else
		{
			//총알쏨으로바꿈
			_vibird->birdstate = 1;
		}

	}
}
