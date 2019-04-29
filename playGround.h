#pragma once
#include "gameNode.h"
#include "stageManager.h"

class playGround : public gameNode
{
private:
	stageManager* _stageManager; // 스테이지매니저 사용


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();
};

