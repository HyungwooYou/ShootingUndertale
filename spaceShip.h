#pragma once
#include "gameNode.h"



class spaceShip : public gameNode
{
private:
	image* _ship;
	image* _mon;
	int _alpha;
	int _alphamon;
	bool _alphabool;

public:
	spaceShip();
	~spaceShip();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

