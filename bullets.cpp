#include "stdafx.h"
#include "bullets.h"


bullets::bullets()
{
}


bullets::~bullets()
{
}

HRESULT bullets::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;


	return S_OK;
}

void bullets::release()
{
}

void bullets::update()
{
	bulletMove();
}

void bullets::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void bullets::bulletFire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.radius = bullet.bulletImage->GetWidth() / 2;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.bulletImage->GetWidth(), bullet.bulletImage->GetHeight());

	_vBullet.push_back(bullet);

}

void bullets::bulletMove()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->bulletImage->GetWidth(), _viBullet->bulletImage->GetHeight());

		if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			++_viBullet;
		}
	}
}

void bullets::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
