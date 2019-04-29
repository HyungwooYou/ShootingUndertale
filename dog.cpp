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
	
	//�ʱ�ȭ ���̿��� ���������ּ��� 2018/12/27

	_dogMax = dogMax;

	//�����Ǽ���γ������� ������
	ZeroMemory(&monsterDog, sizeof(monsterDog));

	IMAGEMANAGER->addImage("���ִ°�", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����̴°�", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
	monsterDog.rc = RectMakeCenter(9999,9999, 50, 80);
	//�ʱ��ġ
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

		IMAGEMANAGER->addImage("���ִ°�", "dogstand.bmp", 160,80,true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("�����̴°�", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("������", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
		monsterDog.rc = RectMakeCenter(1000 + i*80, 430,80, 80);
		//�ʱ��ġ
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
	
		IMAGEMANAGER->addImage("���ִ°�", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("�����̴°�", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("������", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
		monsterDog.rc = RectMakeCenter(2400, 200+i * 80, 80, 80);
		//�ʱ��ġ
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

		//���� ������ �ִ»���
		
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

		//�Ÿ��ȿ������� ����´�.
		if (_viDog->playerDistance < DOG_PLAYER_DISTANCE)
		{
			//�̹��� ī���õȴ�.
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

		//�⺻ ��ũ��
			_viDog->rc = RectMakeCenter(_viDog->dogx, _viDog->dogy, 80, 80);
			_viDog->hpbar = RectMakeCenter(_viDog->dogx + 10, _viDog->dogy, 80, 10);
		
	}
	//ī�޶󿡵��� ���͵��̵�
	
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
	//������ ���� �����������Ѵ�.
	dogpig();
}

void dog::render(float playerx)
{
	//��� ���������� �÷��̾������ ����.
	for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	{
		if (_viDog->dogstate == DOG_IDLE_L)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("���ִ°�")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, 0, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_IDLE_R)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("���ִ°�")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, 80, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_MOVE_L)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("�����̴°�")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, _viDog->imageindex, 0, 80, 80);
		}
		if (_viDog->dogstate == DOG_MOVE_R)
		{
			//Rectangle(getMemDC(), _viDog->rc);
			IMAGEMANAGER->findImage("�����̴°�")->render(getMemDC(), _viDog->rc.left, _viDog->rc.top, _viDog->imageindex, 0, 80, 80);
		}

		//ü�¹ٻ���
		IMAGEMANAGER->findImage("������")->render(getMemDC(), _viDog->hpbar.left+ DOG_HP_LEFT, _viDog->hpbar.top + DOG_HP_TOP);
		//ü�¹��ʷ�
		IMAGEMANAGER->findImage("�ʷϹ�")->render(getMemDC(), _viDog->hpbar.left+ DOG_HP_LEFT, _viDog->hpbar.top + DOG_HP_TOP,0,0, _viDog->hp,10);
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
	//Ȯ�ο�
	//int k = 0;
	//for (_viDog = _vDog.begin(); _viDog != _vDog.end(); _viDog++)
	//{
	//	sprintf_s(str, "%d", _viDog->isDead);
	//	TextOut(getMemDC(), WINSIZEX/2, k * 20, str, strlen(str));
	//	k++;
	//}
	//sprintf_s(str, "�۸��̼� : %d", _vDog.size());
	//TextOut(getMemDC(), WINSIZEX / 2,  20, str, strlen(str));

}

//���� �������°���
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

//��������2 wave2���� ������ ����
void dog::stage2dogcreate(float mapx , float playerx)
{
	//if (mapx <= -800)
	//{
		for (int i = 0; i < 5; i++)
		{
			ZeroMemory(&monsterDog, sizeof(monsterDog));

			IMAGEMANAGER->addImage("���ִ°�", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("�����̴°�", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("������", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
			monsterDog.rc = RectMakeCenter(playerx-1000-i*50, WINSIZEY/2, 80, 80);
			//�ʱ��ġ
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
	//		IMAGEMANAGER->addImage("���ִ°�", "dogstand.bmp", 160, 80, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("�����̴°�", "dogwalk.bmp", 320, 80, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("������", "frontbar.bmp", 80, 10, true, RGB(255, 0, 255));
	//		IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 80, 10, true, RGB(255, 0, 255));
	//		monsterDog.rc = RectMakeCenter(playerx+1200 + i*50, WINSIZEY / 2, 80, 80);
	//		//�ʱ��ġ
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

