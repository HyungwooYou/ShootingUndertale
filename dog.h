#pragma once
#include "gameNode.h"
#include <vector>

enum statedog
{
	//개와 사람거리
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
	RECT hpbar;			//개의 체력바
	RECT rc;			//개의렉트
	float dogx, dogy;	//개의현재좌표
	float speed;		//개의스피드
	float angle;		//개의각도
	bool isDead;		//개가뒤졌는지

	int hp; // 몬스터체력

	int dogstate;//개상태

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


	//개 수량 올림
	int getdogsize(){return dogsize;}
	void setdogsize(int v){ dogsize = v;}
	//포인터로 직접 받습니다.(민노스)
	vector<tagDog>*			 getVdog()			{return &_vDog;}
	vector<tagDog>::iterator getVIdog()			{return _viDog;}

	void _settagDog(vector<tagDog> *v) { _vDog = *v; }

	dog();
	~dog();

	virtual HRESULT init(int dogMax, int stageScene);
	virtual void release();
	virtual void update(float playerx, float playery, int goLR);
	virtual void render(float playerx);

	//개들은 서로 떨어질려그래용
	void dogpig();

	//스테이지2 wave2에서 나오는 개들
	void stage2dogcreate(float mapx, float playerx);
};

