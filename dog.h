#pragma once
#include "gameNode.h"
#include <vector>

enum statedog
{
	//���� ����Ÿ�
	DOG_PLAYER_DISTANCE = 1500,

	DOG_IDLE_L = 1,
	DOG_IDLE_R = 2,
	DOG_MOVE_L = 3,
	DOG_MOVE_R = 4,

	DOG_HP_LEFT = -10,
	DOG_HP_TOP = -50,
};
struct tagDog
{
	//image* imagedog;
	RECT hpbar;			//���� ü�¹�
	RECT rc;			//���Ƿ�Ʈ
	float dogx, dogy;	//����������ǥ
	float speed;		//���ǽ��ǵ�
	float angle;		//���ǰ���
	bool isDead;		//������������

	int hp; // ����ü��

	int dogstate;//������

	int imagecount;
	int imageindex;

	float playerDistance;
	float playerangle;
};

class dog : public gameNode
{
private:
	bool checkrect2;

	tagDog monsterDog;

	vector<tagDog>				_vDog;
	vector<tagDog>::iterator	_viDog;

	int _dogMax;

	char str[128];

	int dogsize;

public:


	//�� ���� �ø�
	int getdogsize(){return dogsize;}
	void setdogsize(int v){ dogsize = v;}
	//�����ͷ� ���� �޽��ϴ�.(�γ뽺)
	vector<tagDog>*			 getVdog()			{return &_vDog;}
	vector<tagDog>::iterator getVIdog()			{return _viDog;}

	void _settagDog(vector<tagDog> *v) { _vDog = *v; }

	dog();
	~dog();

	virtual HRESULT init(int dogMax, int stageScene);
	virtual void release();
	virtual void update(float playerx, float playery, int goLR);
	virtual void render(float playerx);

	//������ ���� ���������׷���
	void dogpig();

	//��������2 wave2���� ������ ����
	void stage2dogcreate(float mapx, float playerx);
};

