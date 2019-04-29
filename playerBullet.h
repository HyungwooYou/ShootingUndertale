#pragma once
#include "gameNode.h"
#define PI 3.141592f
struct tagplayerBullet
{
	image* image100;//�̻����̹���
	RECT rc;		//�ѾƷ�Ʈ
	float x,y;		//�Ѿ���ǥ
	float angle;	//�Ѿ˰���
	float speed;	//�Ѿ˽��ǵ�
	bool fire;		//�i����
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

	//�Ѿ� ������(������)
	void _setplayerBullet(vector<tagplayerBullet> *v){ _vplayerBullet = *v ;}

	void fire(float x, float y, int playerlook , int bulletrange);

	void DeleteDogBullet();
};

