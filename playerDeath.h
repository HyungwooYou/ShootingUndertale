#pragma once
#include "gameNode.h"
class playerDeath : public gameNode
{
private:
	//������ �����¹��
	image* backgroundDeath;
	//�÷��̾� ������ġ
	image* _playerheart;
	RECT playerheart;

	//��������ΰ�
	image* _crackheart1;
	image* _crackheart2;
	RECT crackheart1;
	RECT crackheart2;
	//��ǥ
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
	//�̹��� �����ӿ�

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
	RECT pressEnter; //enter�����ּ��� RECTȮ�ο�
	float pressEnterAlpha; // �ΰ���İ�

	bool checkrect;
public:
	int getsaveScene(){return _saveScene;}
	//����
	int getgameoverend(){return gameoverend2;}
	void setgameoverend(int v){ gameoverend2 = v;}


	playerDeath();
	~playerDeath();

	virtual HRESULT init();
	virtual void release();
	virtual void update(float playerx,float playery, int Scene);
	virtual void render();
};

