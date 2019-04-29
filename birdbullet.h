#pragma once
#include "gameNode.h"

struct tagbirdBullet
{
	image* image100;//미사일이미지
	RECT rc;		//총아렉트
	float x, y;		//총알좌표
	float angle;	//총알각도
	float speed;	//총알스피드
	bool fire;		//쐇는지
	int imagecount2;
	int imageindex2;
	int bulletcount;
	int bulletsize;
	//사거리
	int rangecount;
	bool bird;
};
class birdbullet : public gameNode
{
private:
	bool checkrect3;

	char str[128];

	vector<tagbirdBullet>				_vbirdBullet;
	vector<tagbirdBullet>::iterator		_vibirdBullet;

	float _birdx;
	float _birdy;
	int _birdstate;

public:
	birdbullet();
	~birdbullet();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int goLR);
	virtual void render();

	vector<tagbirdBullet>*			getvbirdBullet() { return &_vbirdBullet; }
	vector<tagbirdBullet>::iterator	getvibirdBullet() { return _vibirdBullet; }

	void fire(float birdx, float birdy, float playerx, float playery, float speed, int bulletsize, bool bird);

	void deletebullet();
};

