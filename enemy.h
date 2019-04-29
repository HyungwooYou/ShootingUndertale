#pragma once
#include "gameNode.h"


class enemy : public gameNode
{
protected:

	image* _imageName;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;

	int _count;
	int _fireCount;
	int _rndFireCount;

	float _moveAngle;

	int _moveType;




public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position, int moveType);
	void release();
	void update();
	void render();

	void move(int count);
	void draw();

	bool bulletCountFire();
};

