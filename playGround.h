#pragma once
#include "gameNode.h"
#include "stageManager.h"

class playGround : public gameNode
{
private:
	stageManager* _stageManager; // ���������Ŵ��� ���


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();
};

