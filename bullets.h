#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;
	RECT rc;
	float fireX, fireY;
	float x, y;
	float speed;
	float angle;
	float gravity;
	float radius;
	bool isFire;
	int count;
};

class bullets : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char*					_imageName;
	float						_range;
	int							_bulletMax;

public:
	bullets();
	~bullets();

	HRESULT init(const char* imageName , int bulletMax, float range);
	void release();
	void update();
	void render();

	void bulletFire(float x,float y,float angle, float speed);

	void bulletMove();

	void removeBullet(int arrNum);

	
};

