#pragma once
#include "gameNode.h"
#define PI 3.141592f
struct tagplayerBullet
{
	image* image100;//미사일이미지
	RECT rc;		//총아렉트
	float x,y;		//총알좌표
	float angle;	//총알각도
	float speed;	//총알스피드
	bool fire;		//쐇는지
	int imagecount2;
	int imageindex2;
	int bulletcount;
};
class playerBullet : public gameNode
{
private:
	bool checkrect4;
	
	tagplayerBullet playerBullet1;

	vector<tagplayerBullet>			_vplayerBullet;
	vector<tagplayerBullet>::iterator	_viplayerBullet;


	int _goLR;
	char str[128];


public:
	playerBullet();
	~playerBullet();

	virtual HRESULT init(int MaxBullet);
	virtual void release();
	virtual void update(int goLR);
	virtual void render();

	vector<tagplayerBullet>*			getvBullet() { return &_vplayerBullet; }
	vector<tagplayerBullet>::iterator	getviBullet() { return _viplayerBullet; }

	//총알 지우기용(정리용)
	void _setplayerBullet(vector<tagplayerBullet> *v){ _vplayerBullet = *v ;}

	void fire(float x, float y, int playerlook , int bulletrange);

	void DeleteDogBullet();
};

