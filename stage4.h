#pragma once
#include "gameNode.h"



class stage4 : public gameNode
{
private:
	bool checkrect;

	bool playerStart1;
	bool playerStart2;
	bool playerStart3;

	//언다인프레임
	RECT undyneImagerc;
	image* undyneImage;
	int imagecount;
	int imageindex;

	// ====== 언다인 ======
	int undyneState;
	RECT undynerc;
	float x;
	float y;
	float angle;
	float hp;

	//언다인이 총알쏨
	int undyneStatebullet;

	// ====== 언다인 체력바 =====
	RECT hpbar;
	float hpbarx;


	//영웅이 등장했따.
	RECT Startpont;
	int StartpontX;
	int StartpontCount;

	//방금보다힘좀써야될거다
	bool Startpontbool2;
	RECT Startpont2;
	int StartpontX2;
	int StartpontCount2;

	//폰트끝냄
	bool GameStart;
	


	bool playerMove;

	//게임끗
	bool end;
public:
	bool getend() { return end; }

	//언다인렉트
	RECT getundynerc(){return undynerc;}
	//언다인체력
	int getundynehp() { return hp; }
	void setundynehp(int v){hp = v;}

	bool getGameStart() { return GameStart; }

	int getundynex() { return x; }
	int getundyney() { return y; }


	int getundyneStatebullet() {return undyneStatebullet;}

	bool getplayerStart1() {return playerStart1;}
	bool getplayerMove() {return playerMove;}

	stage4();
	~stage4();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//플레이어 시작지점
	void PlayerStart();

	//언다인프레임
	void undyneFrame();

	//언다인 움직임
	void undyneMove();

	//영웅이 등장했다.
	void herobegin();

	//방금보다힘좀써야될거다
	void herobegin2();

	//hp체력바생겨남
	void hpbarbegin();
};

