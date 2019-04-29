#include "stdafx.h"
#include "playerBullet.h"


playerBullet::playerBullet()
{
}


playerBullet::~playerBullet()
{
}

HRESULT playerBullet::init(int MaxBullet)
{
	

	return S_OK;
}

void playerBullet::release()
{
}

void playerBullet::update(int goLR)
{
	_goLR = goLR;

	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		_viplayerBullet->bulletcount++;
		_viplayerBullet->x = _viplayerBullet->x + cosf(_viplayerBullet->angle)*_viplayerBullet->speed;
		_viplayerBullet->y = _viplayerBullet->y - sinf(_viplayerBullet->angle)*_viplayerBullet->speed;
		_viplayerBullet->rc = RectMakeCenter(_viplayerBullet->x,_viplayerBullet->y,30,30);
		if (_goLR == 2)
		{
			_viplayerBullet->x-=3;
		}
		if (_goLR == 3)
		{
			_viplayerBullet->x+=3;
		}
	}
	//================================유지보수필요 터짐=================================
	//for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	//{
	//	_viplayerBullet->imagecount2++;
	//	if (_viplayerBullet->imagecount2 % 20 == 0) // 10초마다
	//	{
	//		if (_viplayerBullet->imageindex2 > 1) // index 3보다 크면
	//		{
	//			_viplayerBullet->imageindex2 = 0; // 일단 이미지 0으로만들고
	//		}
	//		//프레임X이동하면 터짐
	//		//_viplayerBullet->image100->SetFrameX(_viplayerBullet->imageindex2);
	//
	//		_viplayerBullet->imageindex2++; //다음 이미지를쓰기위해 인덱스를 늘린다.
	//	}
	//}

	DeleteDogBullet();

}

void playerBullet::render()
{
	//이미지 랜더가 오류가 생긴다면 내가 직접 만들엇다 우함하하
	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		_viplayerBullet->imagecount2++; // 이미지 카운터계속 증감
		if (_viplayerBullet->imagecount2 % 10 == 0)
		{
			if (_viplayerBullet->imageindex2 == 0)
			{
				_viplayerBullet->imageindex2 = 30;
				break;
			}
			if (_viplayerBullet->imageindex2 == 30)
			{
				_viplayerBullet->imageindex2 = 0;
				break;
			}
		}
	}


	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		//Rectangle(getMemDC(),_viplayerBullet->rc);

		IMAGEMANAGER->findImage("플레이어미사일")->render(getMemDC(), _viplayerBullet->rc.left, _viplayerBullet->rc.top, _viplayerBullet->imageindex2, 0, 30, 30);

	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))
	{
		if (checkrect4 == true)
		{
			checkrect4 = false;
		}
		else if (checkrect4 == false)
		{
			checkrect4 = true;
		}
	}
	if (checkrect4 == true)
	{
		for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
		{
			Rectangle(getMemDC(), _viplayerBullet->rc);
		}
	}

	//int k = 0;
	//for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	//{
	//	sprintf_s(str, "%d   ", _viplayerBullet->bulletcount);
	//	TextOut(getMemDC(), WINSIZEX / 2, k * 20, str, strlen(str));
	//	k++;
	//}
}

void playerBullet::fire(float playerx, float playery ,int playerlook, int bulletrange)
{

	ZeroMemory(&playerBullet1, sizeof(playerBullet1));
	//미사일크기조정
	
	playerBullet1.image100 = IMAGEMANAGER->addImage("플레이어미사일", "playerbullet.bmp", 60, 30, true, RGB(255, 0, 255));
	playerBullet1.rc = RectMakeCenter(playerx, playery, 30, 30);
	playerBullet1.x = playerx;
	playerBullet1.y = playery;
	playerBullet1.speed = 5.0f;
	playerBullet1.imagecount2 = 0;
	playerBullet1.imageindex2 = 0;
	



	if (playerlook == 1 || playerlook == 5)
	{
		playerBullet1.angle = 0;
	}
	if (playerlook == 2 || playerlook == 6)
	{
		playerBullet1.angle = PI;
	}
	if (playerlook == 3 || playerlook == 7)
	{
		playerBullet1.angle = PI/2;
	}
	if (playerlook == 4 || playerlook == 8)
	{
		playerBullet1.angle = PI+PI / 2;
	}

	

	_vplayerBullet.push_back(playerBullet1);
}

//총알을 지워줍시다.
void playerBullet::DeleteDogBullet()
{
	bool god;

	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end();)
	{
		god = false;

		//총알카운트
		if (_viplayerBullet->bulletcount > 100)
		{
			god = true;
			_vplayerBullet.erase(_viplayerBullet);
			break;
		}
		else _viplayerBullet++;
	}
}
