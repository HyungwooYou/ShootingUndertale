#pragma once
#include "gameNode.h"
#include <vector>

struct tagbird
{
	image* image1;
	image* image2;
	RECT hpbar;			//새의 체력바
	RECT rc;			//새의렉트
	float birdx, birdy;	//새의현재좌표
	float speed;		//새의스피드
	float angle;		//새의각도
	bool isDead;		//새가뒤졌는지
	int size;			//새크기
	
	int hp; // 몬스터체력

	int birdstate;//개상태

	int imagecount;
	int imageindex;

	float playerDistance;
	float playerangle;

	float rndNumber;

	//새는 총알발사하고 그동안 총을쏠수없다.
	int birdshotcount;

	//총알의텀을주는 불값
	bool shotplayer;

	//확인용 LR
	int LR;

};

class bird : public gameNode
{
private:

	bool checkrect2;
	
	//테스트용 치트키
	char str[128];
	//받아오는 아이들
	int _birdMax;
	int _goLR;
	float _playerx;
	float _playery;

	//새들 공간
	vector<tagbird>				_vbird;
	vector<tagbird>::iterator	_vibird;

	//wave1 시작하기전
	bool wave1on;
	//wave1
	bool wave1;


public:
	
	int getwave1on(){return wave1on;}
	void setwave1on(int v){wave1on = v;}

	void setwave1(bool v){wave1 = v;}

	//새들 공간
	vector<tagbird>*			 getVbird() { return &_vbird; }
	vector<tagbird>::iterator    getVIbird() { return _vibird; }
	bird();
	~bird();

	virtual HRESULT init(int birdMax);
	virtual void release();
	virtual void update(float playerx, float playery, int goLR);
	virtual void render(float playerx);

	//새들 출격
	void birdcreate1();

	//새 카메라
	void birdcamera();
	
	//새움직임
	void birdMove();
};

