#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, WINSIZEY);

	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(_bullet);
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	_bullet->update();
	minionBulletFire();
	collision();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}

void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("enemy", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}
}

void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			/*
			_bullet->bulletFire(rc.left + (rc.right - rc.left) / 2, //x ��ǥ
								rc.bottom + 5,						//y ��ǥ
								-(PI / 2),							//����
								7.0f);								//�Ѿ˼ӵ�

			*/

			_bullet->bulletFire(rc.left + (rc.right - rc.left) / 2, //x ��ǥ
				rc.bottom + 5,						//y ��ǥ
				getAngle(rc.left + (rc.right - rc.left) / 2, rc.bottom,
					_ship->getShipImage()->GetCenterX(), 
					_ship->getShipImage()->GetCenterY()),//����
				12.0f);								//�Ѿ˼ӵ�
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	_vMinion.erase(_vMinion.begin() + arrNum);

}

void enemyManager::collision()
{
	RECT temp;
	RECT shipRc = RectMake(_ship->getShipImage()->GetX(),
		_ship->getShipImage()->GetY(),
		_ship->getShipImage()->GetWidth(),
		_ship->getShipImage()->GetHeight());

	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		if (IntersectRect(&temp, &shipRc, &_bullet->getVBullet()[i].rc))
		{
			//_ship->�÷��̾� ��ü ��ȯ�� ���� �ϴ���... ������ �����...
			_ship->hitDamage(10);
			_bullet->removeBullet(i);
			break;
		}
	}

}
