#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{


	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT position, int moveType)
{
	_currentFrameX = _currentFrameY = 0;

	_count = _fireCount = 0;

	_imageName = IMAGEMANAGER->findImage(imageName);

	_moveType = moveType;

	_rndFireCount = RND->getFromIntTo(1, 300);


	_rc = RectMakeCenter(position.x, position.y, _imageName->getFrameWidth(), _imageName->getFrameHeight());


	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	_count++;

	if (_count % 5 == 0)
	{
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0;
		_imageName->SetFrameX(_currentFrameX);
		_currentFrameX++;



		_count = 0;
	}

}

void enemy::render()
{
}

void enemy::move(int count)
{
}

void enemy::draw()
{
}

bool enemy::bulletCountFire()
{
	return false;
}
