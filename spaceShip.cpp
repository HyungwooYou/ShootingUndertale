#include "stdafx.h"
#include "spaceShip.h"


spaceShip::spaceShip()
{
}

spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("플레이어", MakeImageName("rocket", "image").c_str(), 52, 64, true, RGB(255, 0, 255));
	_mon = IMAGEMANAGER->addImage("몬스터", MakeImageName("missile1","image").c_str(), 26, 124, true, RGB(255, 0, 255));

	_ship->SetX(WINSIZEX / 2);
	_ship->SetY(WINSIZEY / 2 + 200);

	_mon->SetX(WINSIZEX / 2 + 10);
	_mon->SetY(WINSIZEY / 2 + 200 - 30);

	_alpha = 255;
	_alphamon = 0;

	_alphabool = false;

	

	return S_OK;
}

void spaceShip::release()
{
}

void spaceShip::update()
{
	if (KEYMANAGER->isStayKeyDown('W') && _ship->GetY() > 0)
	{
		_ship->SetY(_ship->GetY() - 8);
		_mon->SetY(_mon->GetY() - 8);
	}
	if (KEYMANAGER->isStayKeyDown('S') && _ship->GetY() + _ship->GetHeight() < WINSIZEY)
	{
		_ship->SetY(_ship->GetY() + 8);
		_mon->SetY(_mon->GetY() + 8);
	}
	if (KEYMANAGER->isStayKeyDown('A') && _ship->GetX() > 0)
	{
		_ship->SetX(_ship->GetX() - 8);
		_mon->SetX(_mon->GetX() - 8);
	}
	if (KEYMANAGER->isStayKeyDown('D') && _ship->GetX() + _ship->GetWidth() < WINSIZEX)
	{
		_ship->SetX(_ship->GetX() + 8);
		_mon->SetX(_mon->GetX() + 8);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if(!_alphabool)
			_alphabool = true;
		else if(_alphabool)
			_alphabool = false;

	}
	if (_alphabool)
	{
		_alpha--;
		_alphamon++;
		if (_alpha <= 0) _alpha = 0;
		if (_alphamon >= 255) _alphamon = 255;
	}
	else if (!_alphabool)
	{
		_alphamon--;
		_alpha++;
		if (_alphamon <= 0) _alphamon = 0;
		if (_alpha >= 255) _alpha = 255;
	}

	

}

void spaceShip::render()
{
	//_ship->render(getMemDC(), _ship->GetX(), _ship->GetY());
	_ship->alphaRender(getMemDC(), _ship->GetX(), _ship->GetY(), _alpha);
	_mon->alphaRender(getMemDC(), _mon->GetX(), _mon->GetY(), _alphamon);
}
