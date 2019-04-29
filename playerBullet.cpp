#include "stdafx.h"
#include "playerBullet.h"


playerBullet::playerBullet()
{
}


playerBullet::~playerBullet()
{
}

HRESULT playerBullet::init(int MaxBullet)
{
	

	return S_OK;
}

void playerBullet::release()
{
}

void playerBullet::update(int goLR)
{
	_goLR = goLR;

	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		_viplayerBullet->bulletcount++;
		_viplayerBullet->x = _viplayerBullet->x + cosf(_viplayerBullet->angle)*_viplayerBullet->speed;
		_viplayerBullet->y = _viplayerBullet->y - sinf(_viplayerBullet->angle)*_viplayerBullet->speed;
		_viplayerBullet->rc = RectMakeCenter(_viplayerBullet->x,_viplayerBullet->y,30,30);
		if (_goLR == 2)
		{
			_viplayerBullet->x-=3;
		}
		if (_goLR == 3)
		{
			_viplayerBullet->x+=3;
		}
	}
	//================================���������ʿ� ����=================================
	//for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	//{
	//	_viplayerBullet->imagecount2++;
	//	if (_viplayerBullet->imagecount2 % 20 == 0) // 10�ʸ���
	//	{
	//		if (_viplayerBullet->imageindex2 > 1) // index 3���� ũ��
	//		{
	//			_viplayerBullet->imageindex2 = 0; // �ϴ� �̹��� 0���θ����
	//		}
	//		//������X�̵��ϸ� ����
	//		//_viplayerBullet->image100->SetFrameX(_viplayerBullet->imageindex2);
	//
	//		_viplayerBullet->imageindex2++; //���� �̹������������� �ε����� �ø���.
	//	}
	//}

	DeleteDogBullet();

}

void playerBullet::render()
{
	//�̹��� ������ ������ ����ٸ� ���� ���� ������� ��������
	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		_viplayerBullet->imagecount2++; // �̹��� ī���Ͱ�� ����
		if (_viplayerBullet->imagecount2 % 10 == 0)
		{
			if (_viplayerBullet->imageindex2 == 0)
			{
				_viplayerBullet->imageindex2 = 30;
				break;
			}
			if (_viplayerBullet->imageindex2 == 30)
			{
				_viplayerBullet->imageindex2 = 0;
				break;
			}
		}
	}


	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	{
		//Rectangle(getMemDC(),_viplayerBullet->rc);

		IMAGEMANAGER->findImage("�÷��̾�̻���")->render(getMemDC(), _viplayerBullet->rc.left, _viplayerBullet->rc.top, _viplayerBullet->imageindex2, 0, 30, 30);

	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))
	{
		if (checkrect4 == true)
		{
			checkrect4 = false;
		}
		else if (checkrect4 == false)
		{
			checkrect4 = true;
		}
	}
	if (checkrect4 == true)
	{
		for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
		{
			Rectangle(getMemDC(), _viplayerBullet->rc);
		}
	}

	//int k = 0;
	//for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end(); _viplayerBullet++)
	//{
	//	sprintf_s(str, "%d   ", _viplayerBullet->bulletcount);
	//	TextOut(getMemDC(), WINSIZEX / 2, k * 20, str, strlen(str));
	//	k++;
	//}
}

void playerBullet::fire(float playerx, float playery ,int playerlook, int bulletrange)
{

	ZeroMemory(&playerBullet1, sizeof(playerBullet1));
	//�̻���ũ������
	
	playerBullet1.image100 = IMAGEMANAGER->addImage("�÷��̾�̻���", "playerbullet.bmp", 60, 30, true, RGB(255, 0, 255));
	playerBullet1.rc = RectMakeCenter(playerx, playery, 30, 30);
	playerBullet1.x = playerx;
	playerBullet1.y = playery;
	playerBullet1.speed = 5.0f;
	playerBullet1.imagecount2 = 0;
	playerBullet1.imageindex2 = 0;
	



	if (playerlook == 1 || playerlook == 5)
	{
		playerBullet1.angle = 0;
	}
	if (playerlook == 2 || playerlook == 6)
	{
		playerBullet1.angle = PI;
	}
	if (playerlook == 3 || playerlook == 7)
	{
		playerBullet1.angle = PI/2;
	}
	if (playerlook == 4 || playerlook == 8)
	{
		playerBullet1.angle = PI+PI / 2;
	}

	

	_vplayerBullet.push_back(playerBullet1);
}

//�Ѿ��� �����ݽô�.
void playerBullet::DeleteDogBullet()
{
	bool god;

	for (_viplayerBullet = _vplayerBullet.begin(); _viplayerBullet != _vplayerBullet.end();)
	{
		god = false;

		//�Ѿ�ī��Ʈ
		if (_viplayerBullet->bulletcount > 100)
		{
			god = true;
			_vplayerBullet.erase(_viplayerBullet);
			break;
		}
		else _viplayerBullet++;
	}
}
