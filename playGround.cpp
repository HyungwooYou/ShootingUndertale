#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);

	//스테이지 매니저만듬
	_stageManager = new stageManager();
	_stageManager->init();

	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();

	_stageManager->update();

}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//============================================================
	_stageManager->render();
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
