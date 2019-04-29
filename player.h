#pragma once
#include "gameNode.h"
#include "playerBullet.h"

enum tagPlayer
{
	//�÷��̾� ũ��
	PLAYER_SIZE_X = 60,
	PLAYER_SIZE_Y = 80,

	PLAYER_SPEED = 3,
	//PLAYER_SPEED = 10,

	//�÷��̾� ����ǥ��
	PLAYER_STATE_IDLE_RIGHT = 1,
	PLAYER_STATE_IDLE_LEFT = 2,
	PLAYER_STATE_IDLE_UP = 3,
	PLAYER_STATE_IDLE_DOWN = 4,

	PLAYER_STATE_MOVE_RIGHT = 5,
	PLAYER_STATE_MOVE_LEFT = 6,
	PLAYER_STATE_MOVE_UP = 7,
	PLAYER_STATE_MOVE_DOWN = 8,

	PLAYER_HP_BAR_X = 150,
	PLAYER_HP_BAR_Y = 600,

};

class player : public gameNode
{
private:
	bool checkrect2;

	image* image0;
	image* image1;	//�÷��̾����ΰȴ��̹���
	image* image2;	//�÷��̾�Ʒ���
	image* image3;	//�÷��̾������
	image* image4;	//�÷��̾����

	RECT rc;		//�÷��̾Ʈ
	float x, y;		//�÷��̾���ǥ
	float speed;	//�÷��̾�ǵ�
	int hp;		//�÷��̾�ü��
	float atk;		//�÷��̾���ݷ�
	RECT playerbar; //�÷��̾�� ��ġǥ��

	//�÷��̾� ü�¹� �̹�����
	image* _playerHPbar;
	RECT playerHPbar1;
	RECT playerHPbar2;
	RECT hpfont;

	int playerlive; //�÷��̾� ��Ҵ��� �׾�����

	int playerstate; //�÷��̾����


	//�̹��� �����ӿ�
	int _imagecount;
	int _imageindex;

	RECT camera; // �÷��̾� ī�޶�
	float camerax, cameray; //ī�޶�x,y

	char str[128]; // ������¿�

	bool Scean3on; // ���������ʱ�ȭ

	playerBullet* _playerBullet; // �÷��̾��Ѿ�

	//�÷��̾� ���ķ���
	float playeralpha;

	//��������1Ŭ�����ϸ� ��縦 ��´�.
	image* clearfontimage;
	RECT clearfont;
	bool clearfonton;
	int _imageindex2;
	int _imagecount2;
	bool imageend;

	//�Ŀ�������
	int player1item;

	RECT item1;
	float item1x;
	float item1y;
	float item1angle;
	float item1distance;
	RECT item2;
	float item2x;
	float item2y;
	float item2angle;
	float item2distance;
	RECT item3;
	float item3x;
	float item3y;
	float item3angle;
	float item3distance;

	bool item1on;
	bool item2on;
	bool item3on;

	//�ǵ������
	int player2item;
	RECT shild;
	int shildcount;
	image* _imageshild;
	int _imageshildindex;
	int _imageshildcount;


	//�÷��̾� ��ž
	bool playerstop;

	//������ ǥ��
	RECT haveitem1;
	RECT haveitem2;
	
public:

	int get_imageindex2() { return _imageindex2; }
	void set_imageindex2(int v) { _imageindex2 = v; }

	//�ǵ������
	int getshildcount() { return shildcount; }
	void setshildcount(int v) { shildcount = v; }

	//�÷��̾� ��ž
	bool getplayerstop() { return playerstop; }
	void setplayerstop(bool v) { playerstop = v; }

	//�Ŀ������� ����� 
	int getplayer1item() { return player1item; }
	void setplayer1item(int v) { player1item = v; }

	//��������1Ŭ�����ϸ� ��縦 ��´�.
	bool getclearfonton() { return clearfonton; }
	void setclearfonton(bool v) { clearfonton = v; }

	//��Ҵ��� �׾���������
	float getplayerlive() { return playerlive; }
	void setplayerlive(float v) { playerlive = v; }
	
	//���ķ���������
	float getplayeralpha(){return playeralpha;}
	void setplayeralpha(float v){ playeralpha = v;}

	playerBullet* getplayerBullet(){return _playerBullet;}

	//�÷��̾�hp����
	float getplayerhp(){return hp;}
	void setplayerhp(int v){hp = v;}

	//�Ŵ�������ī�޶� ��Ʈ������
	RECT getcamerarect() { return camera; }
	//stage1���� �÷��̾� ��Ʈ��������
	RECT getplayerrect() { return rc; }

	//stage1������ �÷��̾� x,y������ ��
	float getplayerx() { return x; }
	float getplayery() { return y; }
	//stage1���� �÷��̾� ��ǥ�� ����
	void setplayerx(float _x) { x = _x; }
	void setplayery(float _y) { y = _y; }

	//ī�޶� ��� �����÷��̾� x��ǥ
	float getcamerax() { return camerax; }


	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int goLR);
	virtual void render();

	void playerMove();

	//��������1Ŭ�����ϸ� ��縦 ��´�.
	void stage1cleartalk();

	//�Ŀ�������
	void playeritem1();

	//�ǵ������
	void player2item2();

	//��Ʈ�ʱ�ȭ
	void pontclear();
};

