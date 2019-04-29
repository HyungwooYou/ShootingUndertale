#pragma once
#include "gameNode.h"
#include "intro1.h"
#include "intro2.h"
#include "stage1.h"
#include "player.h"
#include "dog.h"
#include "playerDeath.h"
#include "stage2.h"
#include "bird.h"
#include "birdbullet.h"
#include "item.h"
#include "dogboss.h"
#include "stage3boss.h"
#include "stage4.h"

enum tagScean
{
	INTRO1 = 1, // 1����� ��Ʈ��1
	INTRO2 = 2, // 2������
	STAGE1 = 3, // ��������1
	STAGE2 = 4, // ��������2
	STAGE3 = 5, // ��������3������
	STAGE4 = 6,
};

class stageManager : public gameNode
{
private:


	// ����ȣ
	int scean;
	//============= 1���� ===========
	intro1* _intro1;
	//============= 2���� ===========
	intro2* _intro2;
	//============= 3�� - ��������1 ========
	stage1* _stage1;
	dog* _dog; //���������
	player* _player;//�÷��̾� �������
	//============= 4�� - ��������2 ========
	stage2* _stage2;
	bool stage1skip;
	bird* _bird;
	birdbullet* _birdbullet;
	//wave1����ų
	int stageWave1birdkill;
	bool stage2wave2on;
	//============= 5�� - ��������3������ ==========
	//Ȥ�ø��� ��ױ�
	bool stage2ok;
	bool stage2ok2;
	stage3boss* _stage3boss;
	//============= 6�� - ��������4
	stage4* _stage4;


	//======= ������ =========
	item* _item;



	//=============�÷��̾� ����==========
	playerDeath* _playerDeath;

	float angledog;
	//2������ �ٳ����� ������
	bool intro2Change;

	char str[128];

	//�����ʿ�������
	int goLR;

	bool crashDog;//���ε���
	int crashDogcount;

	//���� ��� ������ ī�޶��̵��ϰ� ����ȿ��
	int stage1Clear;
	int dogdie;
	int stage1Clearcount;
	bool stage2on;

	//������ �ڽ��� ����߸�
	int randBox;

	//������
	dogboss* _dogboss;
	int stage2dogkill;
	bool stage2dogkillon;
	bool cleardogboss;
	float bossattack;

	bool stage2clear;
	int countfontman;
	bool sibar;

	//ȭ�� ��ȯ ȿ��
	bool whiteouton;

	//����� �ѽ��
	int undynecount;
	bool undyneshot;
	int undynerandNum;


	
	image* whiteout3;
	int whiteoutalpha3;

	image* whiteout4;
	int whiteoutalpha4;


public:
	stageManager();
	~stageManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�÷��̾�1 ������Ʈ �浹
	void stage1objectCrash();
	void stage1camera();

	//���� �÷��̾� �Ѿ˿� ����
	void DogCrashplayerBullet();

	//���� �÷��̾� �Ѿ˿� ����
	void birdCrashplayerBullet();

	//���� ����̶� �浹�ϸ�(������)
	void playercrashDog();

	//���Ѿ˰� ����̶� �浹�ϸ� ������(������)
	void playercrashbirdBullet();

	//���� ��� ������ ī�޶��̵��ϰ� ����ȿ��
	void Dogstage1Maplive();
	
	//stage1��
	void stage1end();

	//�÷��̾� ��������2 ������Ʈ �浹
	void stage2objectCrash();
	
	//��������2 wave1 ����
	void stage2wave1();

	//���� ��� �Ѿ�����
	void birdshotbullet();

	//��������2���� �÷��̾� ������ ���µ�
	void playerDeadstage2();

	//�� �������� stage2 - wave2����
	void stage2wave2();

	//�������� ������
	void playeritemcrash();

	//���غ���
	void bossdogopen();

	//��������3�� �Ѿ��
	void gostage3();

	//��������3������ �浹ó��
	void stage3mapcrash();
	bool stage3mapcrashbool;

	//======================= ���� �۾� ================
	//�������Ͱ� �Ѿ˸���
	void babymonstercrashbullet();
	bool stage2scene1on;

	//�������Ͱ� �Ѿ˸����� ������� �پ
	void undynego();

	//��������4 �����Լ�����
	void stage4function();

	//������� ���Ѿ��� ������
	void undynebirdbullet();

	//�÷��̾� �Ѿ˰� ����ΰ� ������(�÷��̾����)
	void undyneDead();

	//��
	void end();

	//����ΰ� �÷��̾� �浹
	void undyneCrashplayer();
};

