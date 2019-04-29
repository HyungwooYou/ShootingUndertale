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
	INTRO1 = 1, // 1번장면 인트로1
	INTRO2 = 2, // 2번영상
	STAGE1 = 3, // 스테이지1
	STAGE2 = 4, // 스테이지2
	STAGE3 = 5, // 스테이지3보스전
	STAGE4 = 6,
};

class stageManager : public gameNode
{
private:


	// 씬번호
	int scean;
	//============= 1번씬 ===========
	intro1* _intro1;
	//============= 2번씬 ===========
	intro2* _intro2;
	//============= 3번 - 스테이지1 ========
	stage1* _stage1;
	dog* _dog; //개만들어줌
	player* _player;//플레이어 만들어줌
	//============= 4번 - 스테이지2 ========
	stage2* _stage2;
	bool stage1skip;
	bird* _bird;
	birdbullet* _birdbullet;
	//wave1버드킬
	int stageWave1birdkill;
	bool stage2wave2on;
	//============= 5번 - 스테이지3보스전 ==========
	//혹시몰라서 잠그기
	bool stage2ok;
	bool stage2ok2;
	stage3boss* _stage3boss;
	//============= 6번 - 스테이지4
	stage4* _stage4;


	//======= 아이템 =========
	item* _item;



	//=============플레이어 죽음==========
	playerDeath* _playerDeath;

	float angledog;
	//2번씬이 다끝나면 봐꿔줌
	bool intro2Change;

	char str[128];

	//오른쪽왼쪽인지
	int goLR;

	bool crashDog;//개부딪힘
	int crashDogcount;

	//개가 모두 죽으면 카메라이동하고 연출효과
	int stage1Clear;
	int dogdie;
	int stage1Clearcount;
	bool stage2on;

	//아이템 박스를 떨어뜨림
	int randBox;

	//개보스
	dogboss* _dogboss;
	int stage2dogkill;
	bool stage2dogkillon;
	bool cleardogboss;
	float bossattack;

	bool stage2clear;
	int countfontman;
	bool sibar;

	//화면 전환 효과
	bool whiteouton;

	//언다인 총쏜다
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

	//플레이어1 오브젝트 충돌
	void stage1objectCrash();
	void stage1camera();

	//개가 플레이어 총알에 맞음
	void DogCrashplayerBullet();

	//새도 플레이어 총알에 맞음
	void birdCrashplayerBullet();

	//개가 사람이랑 충돌하면(개공격)
	void playercrashDog();

	//새총알과 사람이랑 충돌하면 데미지(새공격)
	void playercrashbirdBullet();

	//개가 모두 죽으면 카메라이동하고 연출효과
	void Dogstage1Maplive();
	
	//stage1끝
	void stage1end();

	//플레이어 스테이지2 오브젝트 충돌
	void stage2objectCrash();
	
	//스테이지2 wave1 시작
	void stage2wave1();

	//새가 쏘는 총알페턴
	void birdshotbullet();

	//스테이지2에서 플레이어 죽으면 리셋됨
	void playerDeadstage2();

	//새 다죽으면 stage2 - wave2시작
	void stage2wave2();

	//아이템을 먹으면
	void playeritemcrash();

	//개준보스
	void bossdogopen();

	//스테이지3로 넘어가자
	void gostage3();

	//스테이지3보스전 충돌처리
	void stage3mapcrash();
	bool stage3mapcrashbool;

	//======================= 영상 작업 ================
	//작은몬스터가 총알맞음
	void babymonstercrashbullet();
	bool stage2scene1on;

	//작은몬스터가 총알맞으면 언다인이 뛰어감
	void undynego();

	//스테이지4 관련함수모음
	void stage4function();

	//언다인은 새총알을 재탕함
	void undynebirdbullet();

	//플레이어 총알과 언다인과 만나면(플레이어공격)
	void undyneDead();

	//끗
	void end();

	//언다인과 플레이어 충돌
	void undyneCrashplayer();
};

