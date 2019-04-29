#include "stdafx.h"
#include "birdbullet.h"


birdbullet::birdbullet()
{
}


birdbullet::~birdbullet()
{
}

HRESULT birdbullet::init()
{

	return S_OK;
}

void birdbullet::release()
{

}

void birdbullet::update(int goLR)
{
	for (_vibirdBullet = _vbirdBullet.begin(); _vibirdBullet != _vbirdBullet.end(); _vibirdBullet++)
	{
		_vibirdBullet->rc = RectMakeCenter(_vibirdBullet->x,_vibirdBullet->y,_vibirdBullet->bulletsize, _vibirdBullet->bulletsize);
		_vibirdBullet->x = _vibirdBullet->x + cosf(_vibirdBullet->angle)*_vibirdBullet->speed;
		_vibirdBullet->y = _vibirdBullet->y - sinf(_vibirdBullet->angle)*_vibirdBullet->speed;
		_vibirdBullet->rangecount++;

		if (goLR == 3)
		{
			_vibirdBullet->x += 3;
		}
		if (goLR == 2)
		{
			_vibirdBullet->x -= 3;
		}
	}
	//총알지움
	deletebullet();
}

void birdbullet::render()
{
	for (_vibirdBullet = _vbirdBullet.begin(); _vibirdBullet != _vbirdBullet.end(); _vibirdBullet++)
	{
		if (_vibirdBullet->bird == true)
		{
			IMAGEMANAGER->findImage("버드미사일")->render(getMemDC(), _vibirdBullet->rc.left, _vibirdBullet->rc.top);
		}
		if (_vibirdBullet->bird == false)
		{
			IMAGEMANAGER->findImage("버드미사일2")->render(getMemDC(), _vibirdBullet->rc.left, _vibirdBullet->rc.top);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD7))
	{
		if (checkrect3 == true)
		{
			checkrect3 = false;
		}
		else if (checkrect3 == false)
		{
			checkrect3 = true;
		}
	}
	if (checkrect3 == true)
	{
		for (_vibirdBullet = _vbirdBullet.begin(); _vibirdBullet != _vbirdBullet.end(); _vibirdBullet++)
		{
			Rectangle(getMemDC(), _vibirdBullet->rc);
		}
	}

	//sprintf_s(str,"%d",_vbirdBullet.size());
	//TextOut(getMemDC(),100,100,str,strlen(str));
}

void birdbullet::fire(float birdx, float birdy, float playerx, float playery ,float speed,int bulletsize , bool bird)
{
	tagbirdBullet birdbullet;
	ZeroMemory(&birdbullet, sizeof(birdbullet));
	birdbullet.bird = bird;
	if (birdbullet.bird == true)
	{
		IMAGEMANAGER->addImage("버드미사일", "birdbulletgo.bmp", bulletsize, bulletsize, true, RGB(255, 0, 255));
	}
	if (birdbullet.bird == false)
	{
		IMAGEMANAGER->addImage("버드미사일2", "undynebullet.bmp", bulletsize, bulletsize, true, RGB(255, 0, 255));
	}
	birdbullet.fire = 1;
	birdbullet.x = birdx;
	birdbullet.y = birdy;
	birdbullet.angle = getAngle(birdx,birdy,playerx,playery);
	birdbullet.speed = speed;
	birdbullet.bulletsize = bulletsize;

	_vbirdBullet.push_back(birdbullet);
}

void birdbullet::deletebullet()
{
	for (_vibirdBullet = _vbirdBullet.begin(); _vibirdBullet != _vbirdBullet.end();)
	{
		if (_vibirdBullet->rangecount > 500)
		{
			_vbirdBullet.erase(_vibirdBullet);
			break;
		}
		else 
		{
			_vibirdBullet++;
		}
	}
	
}
