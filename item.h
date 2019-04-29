#pragma once
#include "gameNode.h"

struct tagitem
{
	image* _image;
	RECT rc;
	int itemNum;
	float x,y;
	bool itemmove;
	int itemcount;
};
class item : public gameNode
{
private:
	bool checkrect;

	vector<tagitem>				_vitem;
	vector<tagitem>::iterator	_viitem;



public:
	vector<tagitem>*			 getVitem() { return &_vitem; }
	vector<tagitem>::iterator    getVIitem() { return _viitem; }

	item();
	~item();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int goLR);
	virtual void render();

	void itemDrop(int rndNumber, float x, float y);
};

