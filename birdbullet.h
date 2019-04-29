#pragma once
#include "gameNode.h"

struct tagbirdBullet
{
	image* image100;//�̻����̹���
	RECT rc;		//�ѾƷ�Ʈ
	float x, y;		//�Ѿ���ǥ
	float angle;	//�Ѿ˰���
	float speed;	//�Ѿ˽��ǵ�
	bool fire;		//�i����
	int imagecount2;
	int imageindex2;
	int bulletcount;
	int bulletsize;
	//��Ÿ�
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

