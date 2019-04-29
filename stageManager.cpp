#include "stdafx.h"
#include "stageManager.h"


stageManager::stageManager()
{
}


stageManager::~stageManager()
{
}

HRESULT stageManager::init()
{

	scean = 1; //처음씬은 intro1 이다.

	//intro1 1번씬일때
	_intro1 = new intro1;
	_intro1->init();

	//intro2 2번씬일때
	_intro2 = new intro2;
	_intro2->init();
	
	//stage1 3번씬일때
	_stage1 = new stage1;
	_stage1->init();

	//stage2 4번씬일때
	_stage2 = new stage2;
	_stage2->init();

	//플레이어 만들어줌
	_player = new player;
	_player->init();

	//개 3마리 만들어줌
	_dog = new dog;
	_dog->init(5,scean);

	//플레이어가 죽음
	_playerDeath = new playerDeath;
	_playerDeath->init();

	//새 공간 100마리 만들어둠
	_bird = new bird;
	_bird->init(100);

	//새총알
	_birdbullet = new birdbullet;
	_birdbullet->init();

	//아이템
	_item = new item;
	_item->init();

	//개보스
	_dogboss = new dogboss;
	_dogboss->init();

	//개보스
	_stage3boss = new stage3boss;
	_stage3boss->init();

	//언다인
	_stage4 = new stage4;
	_stage4->init();

	whiteout3 = IMAGEMANAGER->addImage("화이트아웃", "whiteout.bmp", 1280, 768, true, RGB(255, 0, 255));

	whiteoutalpha3 = 0;
	whiteout3->setAlpahBlend(true, whiteoutalpha3);

	whiteout4 = IMAGEMANAGER->addImage("끗", "endend.bmp", 1280, 768, true, RGB(255, 0, 255));

	whiteoutalpha4 = 0;
	whiteout4->setAlpahBlend(true, whiteoutalpha4);

	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	end();

	//끝내기연출
	if (_stage4->getend() == false)
	{
		//아이템
		_item->update(goLR);

		//개보스
		_dogboss->update(_player->getplayerx(), _player->getplayery(), goLR, _stage2->getmap1x());


		//intro1 1번씬일때
		if (scean == 1)
		{
			_intro1->update();
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				scean = 2; // 화면이 2번으로 넘어간다.
			}
		}
		//intro2 2번씬일때
		if (scean == 2)
		{
			_intro2->update();
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				scean = 3; // 화면이 2번으로 넘어간다.
			}
		}

		//stage1 3번씬일때
		if (scean == 3)
		{
			_stage1->update(dogdie);
			//stage1에 물체들은 플레이어와 충돌한다.
			stage1objectCrash();
			//멍멍이들
			_dog->update(_player->getplayerx(), _player->getplayery(), goLR);

			_player->update(goLR);
			stage1camera(); // 스테이지1의 카메라사용임.

			DogCrashplayerBullet();
			playercrashDog();
		}

		//stage2 4번씬일때
		if (scean == 4)
		{
			DogCrashplayerBullet();
			playercrashDog();
			_dog->update(_player->getplayerx(), _player->getplayery(), goLR);
			_stage2->update(cleardogboss);
			_player->update(goLR);
			stage1camera();
			if (stage1skip == false)
			{
				_player->setplayerx(50);
				_player->setplayery(300);
				stage1skip = true;
			}
			stage2objectCrash();
			//새들
			_bird->update(_player->getplayerx(), _player->getplayery(), goLR);
			stage2wave1();

			_birdbullet->update(goLR);
			birdshotbullet();
			//새도총알에 맞음
			birdCrashplayerBullet();
			//새총알과 사람이랑 충돌하면 데미지(새공격)
			playercrashbirdBullet();
			//새총알에도 반짝거릴거임
			playercrashDog();

			stage2wave2();



		}

		//2번씬이 다끝나면 바꿔줌
		if (intro2Change == false)
		{
			if (_intro2->getsceneChange() == 12) // 아랫놈스테이지가 12면 씬을 3으로바꾼다.
			{
				scean = 3;
				intro2Change = true;
			}
		}


		//플레이어 체력이 0이되면 업데이트시작한다.
		if (_player->getplayerhp() == 0)
		{
			_playerDeath->update(_player->getplayerx(), _player->getplayery(), scean);
			_player->setplayerlive(0);
		}

		//플레이어가 씬에서 죽고나면 초기화부분
		if (_playerDeath->getgameoverend() == 1)
		{
			if (scean == 3)
			{
				_playerDeath->init();
				_stage1->init();
				_player->init();
				_dog->init(5, scean);
				_playerDeath->setgameoverend(0);
			}
			if (scean == 4)
			{
				//스테이지2에서 플레이어 죽으면 리셋됨
				playerDeadstage2();
				_playerDeath->init();
				_stage2->init();
				_player->init();
				_playerDeath->setgameoverend(0);
				_bird->setwave1on(false);
				_bird->setwave1(false);
				stageWave1birdkill = 0;
				stage2wave2on = false;

			}
			if (scean == 6)
			{
				//스테이지2에서 플레이어 죽으면 리셋됨
				_playerDeath->init();
				_stage4->init();
				_player->init();
				_playerDeath->setgameoverend(0);
				_birdbullet->getvbirdBullet()->clear();
				_player->setplayerx(WINSIZEX / 2);
				_player->setplayery(WINSIZEY - 250);
				_player->setplayerstop(true);

			}

		}

		//stage1기준 개가 몇마리 살아있는지
		Dogstage1Maplive();

		//stage1끝
		stage1end();

		//아이템을 먹으면
		playeritemcrash();

		//============= 5번 - 스테이지3보스전 ==========
		if (scean == 5)
		{
			_stage3boss->update(whiteouton);
			_player->update(goLR);
			//언다인은 새총알을 재탕함
		}

		//스테이지3로 넘어가자
		gostage3();

		if (KEYMANAGER->isOnceKeyDown(VK_F10))
		{
			_player->setplayerx(50);
			_player->setplayery(WINSIZEY / 2 - 50);
		}

		if (scean == 5)
		{
			//스테이지3보스전 충돌처리
			stage3mapcrash();
			babymonstercrashbullet();
			undynego();
		}

		//개보스
		bossdogopen();

		//스테이지4 관련함수모음
		if (scean == 6)
		{
			_birdbullet->update(goLR);
			stage4function();
			undynebirdbullet();
			undyneDead();
			playercrashbirdBullet();
			playercrashDog();
			undyneCrashplayer();
		}
	}
}

void stageManager::render()
{

	//intro1 1번씬일때
	if (scean == 1)
	{
		_intro1->render();
	}
	//intro2 2번씬일때
	if (scean == 2)
	{
		_intro2->render();
	}
	if (scean == 3)
	{
		_stage1->render();
		_player->render();
		_dog->render(_player->getplayerx());
	}
	//stage2 4번씬일때
	if (scean == 4)
	{
		_stage2->render();
		_player->render();
		_bird->render(_player->getplayerx());
		_dog->render(_player->getplayerx());
		_birdbullet->render();
	}

	//===================죽으면 초기화 스테이지 부분=================
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	vector<tagbird>*				_vbird = _bird->getVbird();
	vector<tagbird>::iterator	    _vibird = _bird->getVIbird();

	
	//================================== 요단강 건던 코딩이니 보지마시오 =================================
	//스테이지3일때 플레이어 체력이 0되면

	if (scean == 3)
	{
		for (_vidog = _vdog->begin(); _vidog != _vdog->end();)
		{
			if (_vdog->size() > 11)
			{
				_vdog->erase(_vidog);
				break;
			}
			else
			{
				_vidog++;
			}
		}
	}

	//개죽으면 지움
	for (_vidog = _vdog->begin(); _vidog != _vdog->end();)
	{
		if (_vidog->isDead == true)
		{
			dogdie++;
			_vdog->erase(_vidog);
			break;
		}
		else
		{
			_vidog++;
		}
	}

	//=================================== 요단강 건던 코딩이니 보지마시오 =================================
	//아이템박스
	_item->render();

	

	//============= 5번 - 스테이지3보스전 ==========
	if (scean == 5)
	{
		_stage3boss->render();
		_player->render();
		_dog->render(_player->getplayerx());
	}

	_dogboss->render(_player->getplayerx());

	//만약 스테이지3의 끝이면, 스테이지4를 랜더해라.

	if (_stage3boss->getstage3bossend() == true)
	{
		scean = 6;
	}

	if (scean == 6)
	{
		_stage4->render();
		_player->render();
		_birdbullet->render();
	}

	if (_player->getplayerhp() == 0)
	{
		if (scean == 4)
		{
			_item->getVitem()->clear();
			stage2dogkillon = false;
			stage2dogkill = 0;
			_dogboss->getVbossdog()->clear();
		}
		dogdie = 0;

		_playerDeath->render();
	}

	//치트키
	//sprintf_s(str, "패턴상태 :  %d   카운트상태 : %d  언다인체력 : %d", undynerandNum, undynecount , _stage4->getundynehp());
	//TextOut(getMemDC(), 100, 100, str, strlen(str));

	if (_stage4->getend() == true)
	{
		IMAGEMANAGER->findImage("화이트아웃")->alphaRender(getMemDC(), 0, 0, whiteoutalpha3);

		IMAGEMANAGER->findImage("끗")->alphaRender(getMemDC(), 0, 0, whiteoutalpha4);
	}
}


//stage1에 물체들은 플레이어와 충돌한다.
void stageManager::stage1objectCrash()
{
		RECT temp; // 오브젝트랑 부딪히면?

	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobjectUP()))
	{
		_player->setplayery(_player->getplayery()+PLAYER_SPEED);
	}
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobjectDOWN()))
	{
		_player->setplayery(_player->getplayery()-PLAYER_SPEED);
	}

	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject11()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	//보라색 문이랑 부딪히면 플레이어 내려감
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject2()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	//보라색 문아래랑 부딪히면 오른쪽으로 밀려남
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject3()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	//작은숲풀이랑 부딪히면 아래으로 밀려남
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject4()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	//보라색문오른쪽작은실드
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject5()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	//사다리 아래쪽
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject6()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}
	//사다리 왼쪽실드
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject7()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}

	//사다리 오른쪽실드
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject8()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	//사다리 아래쪽
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject9()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}

	//사다리 아래쪽
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject10()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	//사다리 아래쪽
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject12()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	//
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject13()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	//
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject14()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	//
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject15()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	//마지막 나무두자루
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject16()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}


	//==================================================================
	//포인터로 직접 받습니다.(민노스)
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	for (_vidog = _vdog->begin(); _vidog != _vdog->end(); _vidog++)
	{
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobjectUP()))
		{
			_vidog->dogy += _vidog->speed;
		}
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobjectDOWN()))
		{
			_vidog->dogy -= _vidog->speed;
			//_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject11()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		//보라색 문이랑 부딪히면 플레이어 내려감
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject2()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		//보라색 문아래랑 부딪히면 오른쪽으로 밀려남
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject3()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
		//작은숲풀이랑 부딪히면 아래으로 밀려남
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject4()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		//보라색문오른쪽작은실드
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject5()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}

		//사다리 아래쪽
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject6()))
		{
			_vidog->dogy -= _vidog->speed;
			//_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		//사다리 왼쪽실드
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject7()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}

		//사다리 오른쪽실드
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject8()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}

		//사다리 아래쪽
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject9()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}

		//사다리 아래쪽
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject10()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		//사다리 아래쪽
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject12()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}

		//
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject13()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
		//
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject14()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		//
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject15()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		//마지막 나무두자루
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject16()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
	}
	
}

//플레이어와 스테이지카메라 연동 //적의 총알과 몬스터는 스스로 가지고있음 // 하트는아직안함
void stageManager::stage1camera()
{
	//개가 모두 죽으면 카메라이동하고 연출효과
	if (_stage1->getstageclearcamera() == false)

		//카메라 연출
		//플레이어 카메라 왼쪽부분보다 플레이어 플레이어 왼쪽보다크면
	{
		if (scean == 3) // 씬3
		{
			if (_player->getcamerarect().left > _player->getplayerrect().left)
			{
				if (_stage1->getstage1x() > -1)
				{
					goLR = 1;
				}
				else
				{
					goLR = 3;
					_stage1->setstage1x(_stage1->getstage1x() + PLAYER_SPEED);
					_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
				}
			}
			if (_player->getcamerarect().right < _player->getplayerrect().right)
			{
				//if (_stage1->getstage1x() < -1495)
				if (_stage1->getstage1x() < -1495)
				{
					goLR = 1;
				}
				else
				{
					goLR = 2;
					_stage1->setstage1x(_stage1->getstage1x() - PLAYER_SPEED);
					_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
				}
			}
			if (_player->getcamerarect().right > _player->getplayerrect().right && _player->getcamerarect().left <= _player->getplayerrect().left)
			{
				goLR = 1;
			}
		}
		// =============================================================씬 4일때
		if (scean == 4)
		{
			if (_player->getcamerarect().left > _player->getplayerrect().left)
			{
				if (_stage2->getmap1x() > -1)
				{
					goLR = 1;
				}
				else
				{
					goLR = 3;
					_stage2->setmap1x(_stage2->getmap1x() + PLAYER_SPEED);
					_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
				}
			}
			if (_player->getcamerarect().right < _player->getplayerrect().right)
			{
				//if (_stage1->getstage1x() < -1495)
				if (_stage2->getmap1x() < -1495)
				{
					goLR = 1;
				}
				else
				{
					goLR = 2;
					_stage2->setmap1x(_stage2->getmap1x() - PLAYER_SPEED);
					_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
				}
			}
			if (_player->getcamerarect().right > _player->getplayerrect().right && _player->getcamerarect().left <= _player->getplayerrect().left)
			{
				goLR = 1;
			}
		}
	}

}

//개는 총알에 맞음
void stageManager::DogCrashplayerBullet()
{
	RECT temp2;
	//포인터로 직접 받습니다.(민노스)
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	vector<tagplayerBullet>*			_vplayerBullet1 = _player->getplayerBullet()->getvBullet();
	vector<tagplayerBullet>::iterator	_viplayerBullet1 = _player->getplayerBullet()->getviBullet();

	bool shit2;

		for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end() ;)
		{
			shit2 = false;
			for (_vidog = _vdog->begin(); _vidog != _vdog->end();)
			{
				if (IntersectRect(&temp2, &_vidog->rc, &_viplayerBullet1->rc))
				{
					shit2 = true;
					_viplayerBullet1 = _vplayerBullet1->erase(_viplayerBullet1);
					//_player->getplayerBullet()->_setplayerBullet(_vplayerBullet1);

					if (_vidog->hp == 0)
					{
						_vidog->isDead = true;
						if (scean == 4)
						{
							stage2dogkill++;
						}
						//아이템 박스를 떨어뜨림
						randBox = RND->getFromIntTo(1,3);
						if (randBox == 1)
						{
							_item->itemDrop(0, _vidog->dogx, _vidog->dogy);
						}
					}
					else if(_vidog->hp > 0) //체력이깍임
					{
							_vidog->hp -= 10;
					}
					break;
				}
				else _vidog++;
			}
			if (!shit2) { _viplayerBullet1++; }
		}

	
}

//새도 총알에 맞음
void stageManager::birdCrashplayerBullet()
{
	RECT temp2;
	//포인터로 직접 받습니다.(민노스)
	vector<tagbird>*				_vbird = _bird->getVbird();
	vector<tagbird>::iterator		_vibird = _bird->getVIbird();

	vector<tagplayerBullet>*			_vplayerBullet1 = _player->getplayerBullet()->getvBullet();
	vector<tagplayerBullet>::iterator	_viplayerBullet1 = _player->getplayerBullet()->getviBullet();

	bool shit5;

	for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end();)
	{
		shit5 = false;
		for (_vibird = _vbird->begin(); _vibird != _vbird->end();)
		{
			if (IntersectRect(&temp2, &_vibird->rc, &_viplayerBullet1->rc))
			{
				shit5 = true;
				
				if (_vibird->hp > 0)
				{
					_vibird->hp -= 10;
				}
				if (_vibird->hp == 0)
				{
					randBox = RND->getFromIntTo(1,2);
					stageWave1birdkill++;
					_vbird->erase(_vibird);
				}
				_vplayerBullet1->erase(_viplayerBullet1);

				break;
			}
			else
			{
				_vibird++;
			}
		}
		if(shit5 == true){break;}
		else if (shit5 == false) { _viplayerBullet1++; }
	}
}

//플레이어와 개의 충돌(개공격)
void stageManager::playercrashDog()
{

	RECT temp3;
	//포인터로 직접 받습니다.(민노스)
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	float temp1;
	
	//부딪혓을떄
	if(crashDog == false)
	{
		for (_vidog = _vdog->begin(); _vidog != _vdog->end();)
		{
			if (IntersectRect(&temp3, &_player->getplayerrect(), &_vidog->rc))
			{
				//플레이어 체력깍음
				if (_player->getplayerhp() > 0)
				{
					//개공격력
					if (_player->getshildcount() <= 0)
					{
						_player->setplayerhp(_player->getplayerhp() - 20);
					}
					else if (_player->getshildcount() > 0)
					{
						_player->setshildcount(_player->getshildcount() - 1);
					}
				}
				crashDog = true;
				break;
			}
			_vidog++;
		}
	}
	//부딪힌상태
	if (crashDog == true)
	{
		if (scean == 3)
		{
			crashDogcount++;
			_player->setplayeralpha(_player->getplayeralpha() + 30);

			if (crashDogcount > 100)
			{
				_player->setplayeralpha(255);
				crashDogcount = 0;
				crashDog = false;
			}
		}

		if (scean == 4)
		{
			crashDogcount++;
			_player->setplayeralpha(_player->getplayeralpha() + 30);

			if (crashDogcount > 200)
			{
				_player->setplayeralpha(255);
				crashDogcount = 0;
				crashDog = false;
			}
		}

		if (scean == 6)
		{
			crashDogcount++;
			_player->setplayeralpha(_player->getplayeralpha() + 30);

			if (crashDogcount > 200)
			{
				_player->setplayeralpha(255);
				crashDogcount = 0;
				crashDog = false;
			}
		}
	}
}

//새총알과 사람이랑 충돌하면 데미지(새공격)
void stageManager::playercrashbirdBullet()
{
	vector<tagbirdBullet>*				_vbirdBullet = _birdbullet->getvbirdBullet();
	vector<tagbirdBullet>::iterator		_vibirdBullet = _birdbullet->getvibirdBullet();

	RECT temp9;
	//부딪혓을떄
	if (crashDog == false)
	{
		for (_vibirdBullet = _vbirdBullet->begin(); _vibirdBullet != _vbirdBullet->end();)
		{
			if (IntersectRect(&temp9, &_player->getplayerrect(), &_vibirdBullet->rc))
			{
				//개공격력
				if (_player->getshildcount() <= 0)
				{
					//플레이어 체력깍음
					if (_player->getplayerhp() > 0)
					{
						//개공격력
						_player->setplayerhp(_player->getplayerhp() - 10);
						_vbirdBullet->erase(_vibirdBullet);
					}
				}
				else if (_player->getshildcount() > 0)
				{
					_player->setshildcount(_player->getshildcount() - 1);
				}
				////플레이어 체력깍음
				//if (_player->getplayerhp() > 0)
				//{
				//	//개공격력
				//	_player->setplayerhp(_player->getplayerhp() - 10);
				//	_vbirdBullet->erase(_vibirdBullet);
				//}
				//개가 사람이랑충돌했을때 반짝거리는효과
				crashDog = true;
				break;
			}
			else { _vibirdBullet++; }
		}
	}
}

//스테이지 클리어하면 카메라이동하고 연출효과
void stageManager::Dogstage1Maplive()
{
	vector<tagitem>*				_vitem = _item->getVitem();
	vector<tagitem>::iterator	    _viitem = _item->getVIitem();

	if (scean == 3)
	{
		if (dogdie == 10)
		{
			_player->pontclear();
			_player->setplayerstop(true);
			_player->setclearfonton(true);
			_stage1->setstageclearcamera(true);
			if (_stage1->getstage1x() > -1490)
			{
				for (_viitem = _vitem->begin(); _viitem != _vitem->end();_viitem++)
				{
					_viitem->x -= 2;
				}
				_player->setplayerx(_player->getplayerx() - 2);
				_stage1->setstage1x(_stage1->getstage1x() - 2);
			}
			if (_stage1->getstage1x() <= -1490)
			{
				_player->setplayerstop(false);
				stage1Clear = 1;
				stage1Clearcount++;
				dogdie = 0;
				_stage1->setstageclearcamera(false);
				_stage1->setstage1x(_stage1->getstage1x() - 2);
			}
		}
	}

	if (scean == 4)
	{
		if (cleardogboss == true)
		{
			_player->pontclear();
			_player->setclearfonton(true);
			_player->setplayerstop(true);
			_stage1->setstageclearcamera(true);
			sibar = true;
			if (_stage2->getmap1x() > -1490)
			{
				for (_viitem = _vitem->begin(); _viitem != _vitem->end(); _viitem++)
				{
					_viitem->x -= 2;
				}
				_player->setplayerx(_player->getplayerx() - 2);
				_stage2->setmap1x(_stage2->getmap1x() - 2);
			}
			if (_stage2->getmap1x() <= -1490)
			{
				_player->setplayerstop(false);
				_stage1->setstageclearcamera(false);
				_stage2->setmap1x(_stage2->getmap1x() - 2);
				stage2clear = true;
				cleardogboss = false;
			}
		}

		if (sibar == true)
		{
			if (_player->get_imageindex2() == 385)
			{
				countfontman++;
				if (countfontman > 100)
				{
					_player->set_imageindex2(440);
				}
			}
		}
	}
}

//stage1끝z
void stageManager::stage1end()
{
	RECT temp5;
	//만약 stage1클리어시
	if (!stage2on)
	{
		if (stage1Clear == 1)
		{
			if (IntersectRect(&temp5, &_player->getplayerrect(), &_stage1->getclearlocation()))
			{
				scean = 4;
				_player->setplayerx(200);
				_player->setplayery(200);
				stage2on = true;
			}
		}
	}
}

//플레이어 스테이지2 오브젝트 충돌
void stageManager::stage2objectCrash()
{
	RECT temp6; // 오브젝트랑 부딪히면?

	//위쪽막기
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill1()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill2()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill3()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill4()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill5()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}

	//아래막기
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill6()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill7()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill8()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill9()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill10()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}

	//아래막기2
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill11()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill12()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill13()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill14()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill15()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}

	//왼쪽막기
	if (IntersectRect(&temp6, &_player->getplayerrect(), &_stage2->gethill16()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	RECT temp9;

	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	
	for (_vidog = _vdog->begin(); _vidog != _vdog->end(); _vidog++)
	{
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill1()))
		{
			_vidog->dogy += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill2()))
		{
			_vidog->dogx -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill3()))
		{
			_vidog->dogy += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill4()))
		{
			_vidog->dogx += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill5()))
		{
			_vidog->dogy += _vidog->speed;
		}

		//아래막기
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill6()))
		{
			_vidog->dogy -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill7()))
		{
			_vidog->dogx -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill8()))
		{
			_vidog->dogy -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill9()))
		{
			_vidog->dogx -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill10()))
		{
			_vidog->dogy -= _vidog->speed;
		}

		//아래막기2
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill11()))
		{
			_vidog->dogx += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill12()))
		{
			_vidog->dogx += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill13()))
		{
			_vidog->dogy -= _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill14()))
		{
			_vidog->dogx += _vidog->speed;
		}
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill15()))
		{
			_vidog->dogy -= _vidog->speed;
		}

		//왼쪽막기
		if (IntersectRect(&temp6, &_vidog->rc, &_stage2->gethill16()))
		{
			_vidog->dogx += _vidog->speed;
		}
	}

	vector<tagdogboss>*				_vbossdog = _dogboss->getVbossdog();
	vector<tagdogboss>::iterator	_vibossdog = _dogboss->getVIbossdog();
	
	for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
	{
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill1()))
		{
			_vibossdog->y += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill2()))
		{
			_vibossdog->x -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill3()))
		{
			_vibossdog->y += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill4()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill5()))
		{
			_vibossdog->y += _vibossdog->speed;
		}

		//아래막기
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill6()))
		{
			_vibossdog->y -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill7()))
		{
			_vibossdog->x -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill8()))
		{
			_vibossdog->y -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill9()))
		{
			_vibossdog->x -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill10()))
		{
			_vibossdog->y -= _vibossdog->speed;
		}

		//아래막기2
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill11()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill12()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill13()))
		{
			_vibossdog->y -= _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill14()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill15()))
		{
			_vibossdog->y -= _vibossdog->speed;
		}

		//왼쪽막기
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill16()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
	}
}

//스테이지2 wave1 시작
void stageManager::stage2wave1()
{
	if (_stage2->getmap1x() < -400)
	{
		//stage2 wave1새출격
		_bird->setwave1on(true);
	}
}

//새가 총쏨
void stageManager::birdshotbullet()
{
	vector<tagbird>*				_vbird = _bird->getVbird();
	vector<tagbird>::iterator	    _vibird = _bird->getVIbird();

	for (_vibird = _vbird->begin(); _vibird != _vbird->end(); _vibird++)
	{
		if (_vibird->birdstate == 1)
		{
			if (_vibird->birdshotcount == 0)
			{
				_birdbullet->fire(_vibird->birdx, _vibird->birdy, _player->getplayerx(), _player->getplayery(),3.0f,10 , true);
			}
			_vibird->birdshotcount++;
			if (_vibird->birdshotcount == 200)
			{
				_vibird->birdshotcount = 0;
			}
		}
	}
}

//스테이지2에서 플레이어 죽으면 리셋됨
void stageManager::playerDeadstage2()
{
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	vector<tagbird>*				_vbird = _bird->getVbird();
	vector<tagbird>::iterator	    _vibird = _bird->getVIbird();


	if (scean == 4)
	{
		if (_player->getplayerhp() == 0)
		{
			_vbird->clear();
			_birdbullet->getvbirdBullet()->clear();

			

			for (_vidog = _vdog->begin() + 1; _vidog != _vdog->end(); _vidog++)
			{
				_vidog->isDead = true;
			}
		}
	}
	
}

//스테이지2 wave2 시작
void stageManager::stage2wave2()
{
	//새 다죽으면 stage2 - wave2시작
	if (stageWave1birdkill == 50)
	{
		if (stage2wave2on == false)
		{
			_dog->stage2dogcreate(_stage2->getmap1x(),_player->getplayerx());
			stage2wave2on = true;
		}
	}
}

//아이템을 먹으면
void stageManager::playeritemcrash()
{
	RECT temp12;
	vector<tagitem>*				_vitem = _item->getVitem();
	vector<tagitem>::iterator	    _viitem = _item->getVIitem();

	for (_viitem = _vitem->begin(); _viitem != _vitem->end();)
	{
		if (IntersectRect(&temp12, &_viitem->rc, &_player->getplayerrect()))
		{
			if (_viitem->itemNum == 1)
			{
				if (_player->getplayer1item() < 3)
				{
					_player->setplayer1item(_player->getplayer1item() + 1);
				}
				_vitem->erase(_viitem);
				break;
			}
			if (_viitem->itemNum == 2)
			{
				_player->setshildcount(3);
				_vitem->erase(_viitem);
				break;
			}
			if (_viitem->itemNum == 3)
			{
				_player->setplayerhp(100);
				_vitem->erase(_viitem);
				break;
			}
		}
		else{ _viitem++; }
	}

}

//개보스
void stageManager::bossdogopen()
{
	vector<tagdogboss>*				_vbossdog = _dogboss->getVbossdog();
	vector<tagdogboss>::iterator	_vibossdog = _dogboss->getVIbossdog();

	vector<tagplayerBullet>*			_vplayerBullet1 = _player->getplayerBullet()->getvBullet();
	vector<tagplayerBullet>::iterator	_viplayerBullet1 = _player->getplayerBullet()->getviBullet();

	if (stage2dogkill > 4)
	{
		if (stage2dogkillon == false)
		{
			_dogboss->bossdogCreate();
			stage2dogkillon = true;
		}
	}

	RECT temp;

	//준보스 공격
	if (crashDog == false)
	{
		for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
		{
			if (IntersectRect(&temp, &_vibossdog->imagerc, &_player->getplayerrect()))
			{
				//준보스는 실드를 바로 박살냄
				if (_player->getshildcount() > 0)
				{
					_player->setshildcount(0);
					crashDog = true;
				}
				else if (_player->getshildcount() == 0)
				{
					_player->setplayerhp(0);
				}
			}
		}
	}

	//플레이어 총알
	
	for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
	{
		for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end();)
		{
			if (IntersectRect(&temp, &_vibossdog->imagerc, &_viplayerBullet1->rc))
			{
				//보스밀려나면서 체력깍임
				bossattack = getAngle(_viplayerBullet1->x, _viplayerBullet1->y, _vibossdog->x, _vibossdog->y);

				_vibossdog->x = _vibossdog->x + cosf(bossattack)*8;
				_vibossdog->y = _vibossdog->y - sinf(bossattack)*8;

				_vibossdog->hp -= 1;
				_vplayerBullet1->erase(_viplayerBullet1);
				break;
			}
			else
			{
				_viplayerBullet1++;
			}
		}
	}

	for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
	{
		if (_vibossdog->hp == 0)
		{
			cleardogboss = true;
			stage2ok2 = true;
		}
	}

	if (cleardogboss == true)
	{
		_vbossdog->clear();
	}
}

//스테이지3 넘어가는작업
void stageManager::gostage3()
{
	RECT temp;
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	if (stage2ok2 == true)
	{
		if(stage2ok == false)
		{
			if (IntersectRect(&temp, &_player->getplayerrect(),&_stage2->getstage3go()))
			{
				//씬옮기고
				scean = 5;
				//혹시모를 새 지움
				_bird->getVbird()->clear();
				//혹시모를 개새끼들 지움
				for (_vidog = _vdog->begin() + 1; _vidog != _vdog->end(); _vidog++)
				{
					_vidog->isDead = true;
				}
				//혹시모를 아이템들 지움
				_item->getVitem()->clear();

				//위치조정
				_player->setplayerx(50);
				_player->setplayery(WINSIZEY / 2 - 50);
				
				stage2ok = true;
				//===========================안정장치 초기화 작업중 =====================
			}

		}
	}
}

//스테이지3보스전 충돌처리
void stageManager::stage3mapcrash()
{
	RECT temp;
	if (stage3mapcrashbool == false)
	{
		//위쪽
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill1()))
		{
			_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill2()))
		{
			_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill3()))
		{
			_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill4()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill5()))
		{
			_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill6()))
		{
			_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}

		//아래쪽
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill7()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill8()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill9()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill10()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill11()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill12()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill13()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill14()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill15()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill16()))
		{
			_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill17()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}

		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill18()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill19()))
		{
			_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill20()))
		{
			_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}

		if (IntersectRect(&temp, &_player->getplayerrect(), &_stage3boss->getstage3hill21()))
		{
			_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
	}
}

//작은몬스터가 총알맞음 // 이벤트씬 발생하고 플레이어 묶임
void stageManager::babymonstercrashbullet()
{
	RECT temp;
	vector<tagplayerBullet>*			_vplayerBullet1 = _player->getplayerBullet()->getvBullet();
	vector<tagplayerBullet>::iterator	_viplayerBullet1 = _player->getplayerBullet()->getviBullet();

	for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end();)
	{
		if (IntersectRect(&temp, &_stage3boss->getbabymonster(), &_viplayerBullet1->rc))
		{
			stage2scene1on = true;
			_vplayerBullet1->erase(_viplayerBullet1);
			_player->setplayerx(WINSIZEX/2);
			_player->setplayery(WINSIZEY - 250);
			break;
		}
		else{_viplayerBullet1++;}
	}
}

//작은몬스터가 총알맞으면 언다인이 뛰어감
void stageManager::undynego()
{
	if (stage2scene1on == true)
	{
		if (_stage3boss->get_undyne1x() > WINSIZEX / 2 - 10)
		{
			_player->setplayerstop(true);
			stage3mapcrashbool = true;
			_stage3boss->set_undyne1x(_stage3boss->get_undyne1x() - 50);
		}
		else if (_stage3boss->get_undyne1x() <= WINSIZEX / 2 - 10)
		{
			whiteouton = true;
		}
	}
}

//스테이지4 관련함수모음
void stageManager::stage4function()
{

	//만약 스테이지3 끝을 알린다면, 스테이지4 업데이트를 해라.
	if (_stage3boss->getstage3bossend() == true)
	{
		scean = 6;
	}
	//처음시작하면 플레이어 위치 조정해줌
	if (_stage4->getplayerStart1() == false)
	{
		_player->setplayerx(WINSIZEX / 2);
		_player->setplayery(WINSIZEY - 250);
		_player->setplayerstop(true);
	}
	//스테이지4
	if (scean == 6)
	{
		_stage4->update();
		_player->update(goLR);
	}
	//만약 플레이어움직임이 허락되면 플레이어가 움직여짐
	if (_stage4->getplayerMove() == true)
	{
		_player->setplayerstop(false);
	}

}

//언다인은 새총알을 재탕함 ( 공격패턴 )
void stageManager::undynebirdbullet()
{
	undynecount++;
	if (_stage4->getGameStart() == true)
	{
		if (_stage4->getundyneStatebullet() == 1)
		{
			if (undynecount > 500)
			{
				undynerandNum = RND->getFromIntTo(1, 6);//1~3패턴중한개
				undynecount = 0;
			}

			//패턴1 - 채찍?
			if(undynerandNum == 1)
			{
				if (undynecount % 70 == 0 && undynecount < 400)
				{
					for (int i = 0; i < 64; i++)
					{
						_birdbullet->fire(i * 20, 0, _player->getplayerx(), _player->getplayery(), 5.0f, 20, false);
					}
				}
			}

			//패턴2 - 원형분사
			if (undynerandNum == 2)
			{
				if (undynecount % 20 == 0 && undynecount < 400)
				{
					for (int i = 0; i < 20; i++)
					{
						_birdbullet->fire(_stage4->getundynex(), _stage4->getundyney(), _stage4->getundynex() + cosf(PI/(3.14f/i)), _stage4->getundyney() - sinf(PI / (3.14f / i)), 4.0f, 20, false);
					}
				}
			}

			//패턴3 - 유도 랜덤 속도
			if (undynerandNum == 3)
			{
				if (undynecount % 5 == 0 && undynecount < 350)
				{
					_birdbullet->fire(_stage4->getundynex()-100, _stage4->getundyney()+100, _player->getplayerx(), _player->getplayery(), RND->getFromFloatTo(4,8), 20, false);
				}
			}

			//패턴4 - 체크무늬 패턴
			if (undynerandNum == 4)
			{
				if (undynecount % 80 == 0 && undynecount < 350)
				{
					for (int i = 0; i < 10; i++)
					{
						_birdbullet->fire(0, i*150,  cosf(0) , i*150 -sinf(0), 7.0f, 20, false);
					}
				}
				if (undynecount % 80 == 40 && undynecount < 350)
				{
					for (int i = 0; i < 10; i++)
					{
						_birdbullet->fire(0, i*150 + 75, cosf(0), i*150 - sinf(0) + 75, 7.0f, 20, false);
					}
				}
			}

			//패턴4 - 체크무늬 패턴
			if (undynerandNum == 5)
			{
				if (undynecount % 80 == 0 && undynecount < 350)
				{
					for (int i = 0; i < 10; i++)
					{
						_birdbullet->fire(WINSIZEX, i * 150, cosf(PI), i * 150 - sinf(PI), 7.0f, 20, false);
					}
				}
				if (undynecount % 80 == 40 && undynecount < 350)
				{
					for (int i = 0; i < 10; i++)
					{
						_birdbullet->fire(WINSIZEX, i * 150 + 75, cosf(PI), i * 150 - sinf(PI) + 75, 7.0f, 20, false);
					}
				}
			}




		}
	}
}

//언다인 대미지(플레이어공격)
void stageManager::undyneDead()
{

	RECT temp77;
	vector<tagplayerBullet>*			_vplayerBullet1 = _player->getplayerBullet()->getvBullet();
	vector<tagplayerBullet>::iterator	_viplayerBullet1 = _player->getplayerBullet()->getviBullet();

	for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end();)
	{
		if (IntersectRect(&temp77, &_stage4->getundynerc(), &_viplayerBullet1->rc))
		{
			_vplayerBullet1->erase(_viplayerBullet1);
			_stage4->setundynehp(_stage4->getundynehp() - 1.28);
			break;
		}
		else
		{
			_viplayerBullet1++;
		}
	}

}

//끗
void stageManager::end()
{
	if (_stage4->getend() == true)
	{
		if (whiteoutalpha3 < 255)
		{
			whiteoutalpha3++;
		}

		if (whiteoutalpha3 >= 255)
		{
			if (whiteoutalpha4 < 255)
			{
				whiteoutalpha4++;
			}
		}
	}
}

//언다인과 플레이어 충돌
void stageManager::undyneCrashplayer()
{
	RECT temp777;
	if (crashDog == false)
	{
		if (_player->getplayerhp() > 0)
		{
			if (IntersectRect(&temp777, &_player->getplayerrect(), &_stage4->getundynerc()))
			{
				_player->setplayerhp(_player->getplayerhp() - 10);
				crashDog = true;
			}
		}
	}
}


