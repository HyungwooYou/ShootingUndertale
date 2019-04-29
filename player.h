#pragma once
#include "gameNode.h"
#include "playerBullet.h"

enum tagPlayer
{
	//플레이어 크기
	PLAYER_SIZE_X = 60,
	PLAYER_SIZE_Y = 80,

	PLAYER_SPEED = 3,
	//PLAYER_SPEED = 10,

	//플레이어 상태표시
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
	image* image1;	//플레이어위로걷는이미지
	image* image2;	//플레이어아래로
	image* image3;	//플레이어오른쪽
	image* image4;	//플레이어왼쪽

	RECT rc;		//플레이어렉트
	float x, y;		//플레이어좌표
	float speed;	//플레이어스피드
	int hp;		//플레이어체력
	float atk;		//플레이어공격력
	RECT playerbar; //플레이어바 위치표시

	//플레이어 체력바 이미지들
	image* _playerHPbar;
	RECT playerHPbar1;
	RECT playerHPbar2;
	RECT hpfont;

	int playerlive; //플레이어 살았는지 죽엇는지

	int playerstate; //플레이어상태


	//이미지 프레임용
	int _imagecount;
	int _imageindex;

	RECT camera; // 플레이어 카메라
	float camerax, cameray; //카메라x,y

	char str[128]; // 문자출력용

	bool Scean3on; // 스테이지초기화

	playerBullet* _playerBullet; // 플레이어총알

	//플레이어 알파랜더
	float playeralpha;

	//스테이지1클리어하면 대사를 뱉는다.
	image* clearfontimage;
	RECT clearfont;
	bool clearfonton;
	int _imageindex2;
	int _imagecount2;
	bool imageend;

	//파워아이템
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

	//실드아이템
	int player2item;
	RECT shild;
	int shildcount;
	image* _imageshild;
	int _imageshildindex;
	int _imageshildcount;


	//플레이어 스탑
	bool playerstop;

	//아이템 표시
	RECT haveitem1;
	RECT haveitem2;
	
public:

	int get_imageindex2() { return _imageindex2; }
	void set_imageindex2(int v) { _imageindex2 = v; }

	//실드아이템
	int getshildcount() { return shildcount; }
	void setshildcount(int v) { shildcount = v; }

	//플레이어 스탑
	bool getplayerstop() { return playerstop; }
	void setplayerstop(bool v) { playerstop = v; }

	//파워아이템 실험용 
	int getplayer1item() { return player1item; }
	void setplayer1item(int v) { player1item = v; }

	//스테이지1클리어하면 대사를 뱉는다.
	bool getclearfonton() { return clearfonton; }
	void setclearfonton(bool v) { clearfonton = v; }

	//살았는지 죽었는지보냄
	float getplayerlive() { return playerlive; }
	void setplayerlive(float v) { playerlive = v; }
	
	//알파랜더값보냄
	float getplayeralpha(){return playeralpha;}
	void setplayeralpha(float v){ playeralpha = v;}

	playerBullet* getplayerBullet(){return _playerBullet;}

	//플레이어hp보냄
	float getplayerhp(){return hp;}
	void setplayerhp(int v){hp = v;}

	//매니저한테카메라 렉트보내줌
	RECT getcamerarect() { return camera; }
	//stage1에게 플레이어 렉트정보를줌
	RECT getplayerrect() { return rc; }

	//stage1에에게 플레이어 x,y정보를 줌
	float getplayerx() { return x; }
	float getplayery() { return y; }
	//stage1에서 플레이어 좌표를 제어
	void setplayerx(float _x) { x = _x; }
	void setplayery(float _y) { y = _y; }

	//카메라 제어를 위한플레이어 x좌표
	float getcamerax() { return camerax; }


	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int goLR);
	virtual void render();

	void playerMove();

	//스테이지1클리어하면 대사를 뱉는다.
	void stage1cleartalk();

	//파워아이템
	void playeritem1();

	//실드아이템
	void player2item2();

	//폰트초기화
	void pontclear();
};

