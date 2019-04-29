#pragma once
#include "gameNode.h"

struct tagdogboss
{
	RECT rc;
	RECT imagerc;
	image* image;
	RECT hpbar;
	float x,y;
	float speed;
	int hp;
	float angle;

	int imagecount;
	int imageindex;
};
class dogboss : public gameNode
{
private:
	bool checkrect2;

	float _mapx;
	float _playerx;
	float _playery;
	int _goLR;

	vector<tagdogboss>				_vbossdog;
	vector<tagdogboss>::iterator	_vibossdog;

public:

	//새들 공간
	vector<tagdogboss>*				getVbossdog() { return &_vbossdog; }
	vector<tagdogboss>::iterator    getVIbossdog() { return _vibossdog; }

	dogboss();
	~dogboss();

	virtual HRESULT init();
	virtual void release();
	virtual void update(float playerx, float playery, int goLR,  float mapx);
	virtual void render(float playerx);

	void bossdogCreate();
};

