#pragma once
#include "gameNode.h"
class playerDeath : public gameNode
{
private:
	//죽으면 나오는배경
	image* backgroundDeath;
	//플레이어 심장위치
	image* _playerheart;
	RECT playerheart;

	//깨진심장두개
	image* _crackheart1;
	image* _crackheart2;
	RECT crackheart1;
	RECT crackheart2;
	//좌표
	float h1x, h1y;
	float h2x, h2y;

	float angle1;
	float angle2;
	float speed;
	float gravity;

	int count;

	bool Scene1;

	int _imagecount;
	int _imageindex;
	//이미지 프레임용

	float _playerx, _playery;
	bool savexy;

	image* _gameover;
	RECT gameover;
	float gameoveralpha;

	int gameoverend2;

	char str[128];

	RECT backgroundd;
	
	int _saveScene;

	bool gameoverEnter;

	image* _pressEnter;
	RECT pressEnter; //enter눌러주세요 RECT확인용
	float pressEnterAlpha; // 로고알파값

	bool checkrect;
public:
	int getsaveScene(){return _saveScene;}
	//쓰셈
	int getgameoverend(){return gameoverend2;}
	void setgameoverend(int v){ gameoverend2 = v;}


	playerDeath();
	~playerDeath();

	virtual HRESULT init();
	virtual void release();
	virtual void update(float playerx,float playery, int Scene);
	virtual void render();
};

