#pragma once
#include "gameNode.h"
#include <vector>

struct tagbird
{
	image* image1;
	image* image2;
	RECT hpbar;			//���� ü�¹�
	RECT rc;			//���Ƿ�Ʈ
	float birdx, birdy;	//����������ǥ
	float speed;		//���ǽ��ǵ�
	float angle;		//���ǰ���
	bool isDead;		//������������
	int size;			//��ũ��
	
	int hp; // ����ü��

	int birdstate;//������

	int imagecount;
	int imageindex;

	float playerDistance;
	float playerangle;

	float rndNumber;

	//���� �Ѿ˹߻��ϰ� �׵��� �����������.
	int birdshotcount;

	//�Ѿ��������ִ� �Ұ�
	bool shotplayer;

	//Ȯ�ο� LR
	int LR;

};

class bird : public gameNode
{
private:

	bool checkrect2;
	
	//�׽�Ʈ�� ġƮŰ
	char str[128];
	//�޾ƿ��� ���̵�
	int _birdMax;
	int _goLR;
	float _playerx;
	float _playery;

	//���� ����
	vector<tagbird>				_vbird;
	vector<tagbird>::iterator	_vibird;

	//wave1 �����ϱ���
	bool wave1on;
	//wave1
	bool wave1;


public:
	
	int getwave1on(){return wave1on;}
	void setwave1on(int v){wave1on = v;}

	void setwave1(bool v){wave1 = v;}

	//���� ����
	vector<tagbird>*			 getVbird() { return &_vbird; }
	vector<tagbird>::iterator    getVIbird() { return _vibird; }
	bird();
	~bird();

	virtual HRESULT init(int birdMax);
	virtual void release();
	virtual void update(float playerx, float playery, int goLR);
	virtual void render(float playerx);

	//���� ���
	void birdcreate1();

	//�� ī�޶�
	void birdcamera();
	
	//��������
	void birdMove();
};

