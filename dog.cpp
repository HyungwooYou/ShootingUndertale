#include "stdafx.h"
#include "dog.h"


dog::dog()
{
}


dog::~dog()
{
}

HRESULT dog::init(int dogMax , int stageScene)
{
	
	//초기화 중이엿음 잊지말아주세요 2018/12/27

	_dogMax = dogMax;

	//미지의세계로날려버릴 강아지
	ZeroMemory(&monsterDog, sizeof(monsterDog));

	IMAGEMANAGER->addImage("서있는개", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("움직이는개", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
	monsterDog.rc = RectMakeCenter(9999,9999, 50, 80);
	//초기배치
	monsterDog.dogx = monsterDog.rc.left;
	monsterDog.dogy = monsterDog.rc.top;
	monsterDog.speed = 1.0f;
	monsterDog.hp = 80;
	monsterDog.imagecount = 0;
	monsterDog.imageindex = 0;

	_vDog.push_back(monsterDog);
	
	for (int i = 0; i < _dogMax; i++)
	{
		ZeroMemory(&monsterDog, sizeof(monsterDog));

		IMAGEMANAGER->addImage("서있는개", "dogstand.bmp", 160,80,true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("움직이는개", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
		monsterDog.rc = RectMakeCenter(1000 + i*80, 430,80, 80);
		//초기배치
		monsterDog.dogx = monsterDog.rc.left;
		monsterDog.dogy = monsterDog.rc.top;
		monsterDog.speed = 1.0f;
		monsterDog.hp = 80;
		monsterDog.imagecount = 0;
		monsterDog.imageindex = 0;

		_vDog.push_back(monsterDog);		
	}

	for (int i = 0; i < _dogMax; i++)
	{
		ZeroMemory(&monsterDog, sizeof(monsterDog));
	
		IMAGEMANAGER->addImage("서있는개", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("움직이는개", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
		monsterDog.rc = RectMakeCenter(2400, 200+i * 80, 80, 80);
		//초기배치
		monsterDog.dogx = monsterDog.rc.left;
		monsterDog.dogy = monsterDog.rc.top;
		monsterDog.speed = 1.0f;
		monsterDog.hp = 80;
		monsterDog.imagecount = 0;
		monsterDog.imageindex = 0;
	
		_vDog.push_back(monsterDog);
	}

	return S_OK;
}

void dog::release()
{
}

void dog::update(float playerx,float playery,int goLR)
{
	dogsize = _vDog.size();
	
	for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	{
		_viDog->playerDistance = getDistance(playerx,playery,_viDog->dogx,_viDog->dogy);

		//개의 가만히 있는상태
		
		if (_viDog->playerDistance > DOG_PLAYER_DISTANCE)
		{
			if (playerx < _viDog->dogx)
			{
				_viDog->dogstate = DOG_IDLE_L;
			}
			if (playerx > _viDog->dogx)
			{
				_viDog->dogstate = DOG_IDLE_R;
			}
		}

		//거리안에있을때 따라온다.
		if (_viDog->playerDistance < DOG_PLAYER_DISTANCE)
		{
			//이미지 카운팅된다.
			_viDog->imagecount++;
			_viDog->playerangle = getAngle(_viDog->dogx, _viDog->dogy, playerx, playery);

			_viDog->dogx = _viDog->dogx + cosf(_viDog->playerangle)*_viDog->speed;
			_viDog->dogy = _viDog->dogy - sinf(_viDog->playerangle)*_viDog->speed;

			if (playerx < _viDog->dogx)
			{
				_viDog->dogstate = DOG_MOVE_L;
				if (_viDog->imagecount % 10 == 0)
				{
					if (_viDog->imageindex != 80)
					{
						_viDog->imageindex = 80;
						break;
					}
					if (_viDog->imageindex == 80)
					{
						_viDog->imageindex = 0;
						break;
					}
				}
			}
			if (playerx > _viDog->dogx)
			{
				_viDog->dogstate = DOG_MOVE_R;
				if (_viDog->imagecount % 10 == 0)
				{
					if (_viDog->imageindex != 160)
					{
						_viDog->imageindex = 160;
						break;
					}
					if (_viDog->imageindex == 160)
					{
						_viDog->imageindex = 240;
						break;
					}
				}
			}
		}

		//기본 개크기
			_viDog->rc = RectMakeCenter(_viDog->dogx, _viDog->dogy, 80, 80);
			_viDog->hpbar = RectMakeCenter(_viDog->dogx + 10, _viDog->dogy, 80, 10);
		
	}
	//카메라에따라 몬스터도이동
	
	for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	{
		if (goLR == 2)
		{
			_viDog->dogx-=3;
		}
		if (goLR == 3)
		{
			_viDog->dogx+=3;
		}
	}
	//개들은 서로 떨어질려고한다.
	dogpig();
}

void dog::render(float playerx)
{
	//모든 개새끼들은 플레이어반향을 본다.
	for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	{
		if (_viDog->dogstate == DOG_IDLE_L)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("서있는개")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, 0, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_IDLE_R)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("서있는개")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, 80, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_MOVE_L)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("움직이는개")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, _viDog->imageindex, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_MOVE_R)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("움직이는개")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, _viDog->imageindex, 0, 80, 80);
		}

		//체력바빨강
		IMAGEMANAGER->findImage("빨간바")->render(getMemDC(), _viDog->hpbar.left+ DOG_HP_LEFT, _viDog->hpbar.top + DOG_HP_TOP);
		//체력바초록
		IMAGEMANAGER->findImage("초록바")->render(getMemDC(), _viDog->hpbar.left+ DOG_HP_LEFT, _viDog->hpbar.top + DOG_HP_TOP,0,0, _viDog->hp,10);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4))
	{
		if (checkrect2 == true)
		{
			checkrect2 = false;
		}
		else if (checkrect2 == false)
		{
			checkrect2 = true;
		}
	}
	if (checkrect2 == true)
	{
		for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
		{
			Rectangle(getMemDC(), _viDog->rc);
		}
	}
	//확인용
	//int k = 0;
	//for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	//{
	//	sprintf_s(str, "%d", _viDog->isDead);
	//	TextOut(getMemDC(), WINSIZEX/2, k * 20, str, strlen(str));
	//	k++;
	//}
	//sprintf_s(str, "멍멍이수 : %d", _vDog.size());
	//TextOut(getMemDC(), WINSIZEX / 2,  20, str, strlen(str));

}

//서로 떨어지는개들
void dog::dogpig()
{
	RECT temp;
	for (int i = 0; i < _vDog.size()-1; i++)
	{
		if (IntersectRect(&temp, &_vDog[i].rc, &_vDog[i+1].rc))
		{
			_vDog[i].dogx+=0.3;
			_vDog[i+1].dogx -= 0.3;
		}
	}
	
}

//스테이지2 wave2에서 나오는 개들
void dog::stage2dogcreate(float mapx , float playerx)
{
	//if (mapx <= -800)
	//{
		for (int i = 0; i < 5; i++)
		{
			ZeroMemory(&monsterDog, sizeof(monsterDog));

			IMAGEMANAGER->addImage("서있는개", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("움직이는개", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
			monsterDog.rc = RectMakeCenter(playerx-1000-i*50, WINSIZEY/2, 80, 80);
			//초기배치
			monsterDog.dogx = monsterDog.rc.left;
			monsterDog.dogy = monsterDog.rc.top;
			monsterDog.speed = 3.0f;
			monsterDog.hp = 80;
			monsterDog.imagecount = 0;
			monsterDog.imageindex = 0;

			_vDog.push_back(monsterDog);
		}
	//}
	//else if (mapx > -800)
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		ZeroMemory(&monsterDog, sizeof(monsterDog));
	//
	//		IMAGEMANAGER->addImage("서있는개", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("움직이는개", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("빨간바", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("초록바", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
	//		monsterDog.rc = RectMakeCenter(playerx+1200 + i*50, WINSIZEY / 2, 80, 80);
	//		//초기배치
	//		monsterDog.dogx = monsterDog.rc.left;
	//		monsterDog.dogy = monsterDog.rc.top;
	//		monsterDog.speed = 2.0f;
	//		monsterDog.hp = 80;
	//		monsterDog.imagecount = 0;
	//		monsterDog.imageindex = 0;
	//
	//		_vDog.push_back(monsterDog);
	//	}
	//}
}

