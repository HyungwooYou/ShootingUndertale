#include "stdafx.h"
#include "bird.h"


bird::bird()
{
}


bird::~bird()
{
}

HRESULT bird::init(int birdMax)
{
	//�̸� ������ ���� �ִ��
	_birdMax = birdMax;
	wave1 = false;
	return S_OK;
}

void bird::release()
{

}

void bird::update(float playerx, float playery, int goLR)
{
	//�޾ƿ��� ���̵�
	_goLR = goLR;
	_playerx = playerx;
	_playery = playery;

	//���� ��Ʈ ����
	if (_vbird.size() > 0)
	{
		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			_vibird->rc = RectMakeCenter(_vibird->birdx, _vibird->birdy, _vibird->size, _vibird->size);

			if (_vibird->birdx < _playerx)
			{
				_vibird->LR = 2;
			}

			if (_vibird->birdx > _playerx)
			{
				_vibird->LR = 1;
			}
		}
	}

		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			_vibird->imagecount++;

			if (_vibird->LR == 2)
			{
				if (_vibird->imagecount % 10 == 0)
				{
					if (_vibird->imageindex > 4)
					{
						_vibird->imageindex = 0;
					}
					_vibird->image1->SetFrameX(_vibird->imageindex);

					_vibird->imageindex++;
				}
			}

			if (_vibird->LR == 1)
			{
				if (_vibird->imagecount % 10 == 0)
				{
					if (_vibird->imageindex > 3)
					{
						_vibird->imageindex = 0;
					}
					_vibird->image2->SetFrameX(_vibird->imageindex);

					_vibird->imageindex++;
				}
			}
		}


	//wave1 �����ϱ���
	if (wave1on == true)
	{
		//wave1
		birdcreate1();
	}

	//�� ī�޶�
	birdcamera();

	//��������
	birdMove();

	//�� ü�¹�
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		_vibird->hpbar = RectMakeCenter(_vibird->birdx,_vibird->birdy - 40, 50, 10);
	}
}

void bird::render(float playerx)
{
	//���� ��Ʈ ����
	if (_vbird.size() > 0)
	{
		for(_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			if (_vibird->LR == 2)
			{
				IMAGEMANAGER->findImage("�����̴»�1")->frameRender(getMemDC(), _vibird->rc.left, _vibird->rc.top);
			}
			if (_vibird->LR == 1)
			{
				IMAGEMANAGER->findImage("�����̴»�2")->frameRender(getMemDC(), _vibird->rc.left, _vibird->rc.top);
			}
			
			// �� ü�¹�
			Rectangle(getMemDC(),_vibird->hpbar);
			IMAGEMANAGER->findImage("������")->render(getMemDC(),_vibird->hpbar.left,_vibird->hpbar.top,0,0,50,10);
			IMAGEMANAGER->findImage("�ʷϹ�")->render(getMemDC(), _vibird->hpbar.left, _vibird->hpbar.top,0,0,_vibird->hp*2.5,10);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5))
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
		for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
		{
			Rectangle(getMemDC(),_vibird->rc);
		}
	}

	//�׽�Ʈ�� ġƮŰ
	//int e = 0;
	//for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	//{
	//	e++;
	//	sprintf_s(str, "%d", _vibird->LR);
	//	TextOut(getMemDC(), 50, 50 + e * 50, str, strlen(str));
	//}
}

//wave1
void bird::birdcreate1()
{
	float angle;

	if (wave1 == false)
	{
		angle = PI/8;
		//�׽�Ʈ�� 5����
		for (int i = 0; i < 50; i++)
		{
			tagbird monsterbird;
			ZeroMemory(&monsterbird, sizeof(monsterbird));
			monsterbird.image1 = IMAGEMANAGER->addFrameImage("�����̴»�1", "birdfly1.bmp", 200, 50,4,1,true, RGB(255, 0, 255));
			monsterbird.image2 = IMAGEMANAGER->addFrameImage("�����̴»�2", "birdfly2.bmp", 200, 50, 4, 1, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("������", "frontbar.bmp", 50, 10, true, RGB(255, 0, 255));
			IMAGEMANAGER->addImage("�ʷϹ�", "bottombar.bmp", 50, 10, true, RGB(255, 0, 255));

			monsterbird.hp = 20;
			monsterbird.imagecount = 0;
			monsterbird.imageindex = 0;
			monsterbird.size = 50;
			monsterbird.speed = 3.0f;
			monsterbird.angle = 0;
			monsterbird.birdx = _playerx + cosf(angle)*1300;
			monsterbird.birdy = _playery - sinf(angle)*1300;
			monsterbird.isDead = false;

			_vbird.push_back(monsterbird);
			wave1 = true;

			angle += PI/20;
		}
	}
}

//�� ī�޶�
void bird::birdcamera()
{
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		if (_goLR == 2)
		{
			_vibird->birdx -= 3;
		}
		if (_goLR == 3)
		{
			_vibird->birdx += 3;
		}
	}
}

//��������
void bird::birdMove()
{
	for (_vibird = _vbird.begin(); _vibird != _vbird.end(); ++_vibird)
	{
		_vibird->playerDistance = getDistance(_vibird->birdx, _vibird->birdy, _playerx, _playery);
		if (_vibird->playerDistance > 300)
		{
			_vibird->birdstate = 0;
			_vibird->rndNumber = RND->getFromFloatTo(-PI / 1.5, PI / 1.5);
			_vibird->playerangle = getAngle(_vibird->birdx, _vibird->birdy, _playerx, _playery);
			_vibird->birdx = _vibird->birdx + cosf(_vibird->playerangle + _vibird->rndNumber)*_vibird->speed;
			_vibird->birdy = _vibird->birdy - sinf(_vibird->playerangle + _vibird->rndNumber)*_vibird->speed;
		}
		else
		{
			//�Ѿ˽����ιٲ�
			_vibird->birdstate = 1;
		}

	}
}
