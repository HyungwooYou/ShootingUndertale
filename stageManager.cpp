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

	scean = 1; //ó������ intro1 �̴�.

	//intro1 1�����϶�
	_intro1 = new intro1;
	_intro1->init();

	//intro2 2�����϶�
	_intro2 = new intro2;
	_intro2->init();
	
	//stage1 3�����϶�
	_stage1 = new stage1;
	_stage1->init();

	//stage2 4�����϶�
	_stage2 = new stage2;
	_stage2->init();

	//�÷��̾� �������
	_player = new player;
	_player->init();

	//�� 3���� �������
	_dog = new dog;
	_dog->init(5,scean);

	//�÷��̾ ����
	_playerDeath = new playerDeath;
	_playerDeath->init();

	//�� ���� 100���� ������
	_bird = new bird;
	_bird->init(100);

	//���Ѿ�
	_birdbullet = new birdbullet;
	_birdbullet->init();

	//������
	_item = new item;
	_item->init();

	//������
	_dogboss = new dogboss;
	_dogboss->init();

	//������
	_stage3boss = new stage3boss;
	_stage3boss->init();

	//�����
	_stage4 = new stage4;
	_stage4->init();

	whiteout3 = IMAGEMANAGER->addImage("ȭ��Ʈ�ƿ�", "whiteout.bmp", 1280, 768, true, RGB(255, 0, 255));

	whiteoutalpha3 = 0;
	whiteout3->setAlpahBlend(true, whiteoutalpha3);

	whiteout4 = IMAGEMANAGER->addImage("��", "endend.bmp", 1280, 768, true, RGB(255, 0, 255));

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

	//�����⿬��
	if (_stage4->getend() == false)
	{
		//������
		_item->update(goLR);

		//������
		_dogboss->update(_player->getplayerx(), _player->getplayery(), goLR, _stage2->getmap1x());


		//intro1 1�����϶�
		if (scean == 1)
		{
			_intro1->update();
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				scean = 2; // ȭ���� 2������ �Ѿ��.
			}
		}
		//intro2 2�����϶�
		if (scean == 2)
		{
			_intro2->update();
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				scean = 3; // ȭ���� 2������ �Ѿ��.
			}
		}

		//stage1 3�����϶�
		if (scean == 3)
		{
			_stage1->update(dogdie);
			//stage1�� ��ü���� �÷��̾�� �浹�Ѵ�.
			stage1objectCrash();
			//�۸��̵�
			_dog->update(_player->getplayerx(), _player->getplayery(), goLR);

			_player->update(goLR);
			stage1camera(); // ��������1�� ī�޶�����.

			DogCrashplayerBullet();
			playercrashDog();
		}

		//stage2 4�����϶�
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
			//����
			_bird->update(_player->getplayerx(), _player->getplayery(), goLR);
			stage2wave1();

			_birdbullet->update(goLR);
			birdshotbullet();
			//�����Ѿ˿� ����
			birdCrashplayerBullet();
			//���Ѿ˰� ����̶� �浹�ϸ� ������(������)
			playercrashbirdBullet();
			//���Ѿ˿��� ��¦�Ÿ�����
			playercrashDog();

			stage2wave2();



		}

		//2������ �ٳ����� �ٲ���
		if (intro2Change == false)
		{
			if (_intro2->getsceneChange() == 12) // �Ʒ����������� 12�� ���� 3���ιٲ۴�.
			{
				scean = 3;
				intro2Change = true;
			}
		}


		//�÷��̾� ü���� 0�̵Ǹ� ������Ʈ�����Ѵ�.
		if (_player->getplayerhp() == 0)
		{
			_playerDeath->update(_player->getplayerx(), _player->getplayery(), scean);
			_player->setplayerlive(0);
		}

		//�÷��̾ ������ �װ��� �ʱ�ȭ�κ�
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
				//��������2���� �÷��̾� ������ ���µ�
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
				//��������2���� �÷��̾� ������ ���µ�
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

		//stage1���� ���� ��� ����ִ���
		Dogstage1Maplive();

		//stage1��
		stage1end();

		//�������� ������
		playeritemcrash();

		//============= 5�� - ��������3������ ==========
		if (scean == 5)
		{
			_stage3boss->update(whiteouton);
			_player->update(goLR);
			//������� ���Ѿ��� ������
		}

		//��������3�� �Ѿ��
		gostage3();

		if (KEYMANAGER->isOnceKeyDown(VK_F10))
		{
			_player->setplayerx(50);
			_player->setplayery(WINSIZEY / 2 - 50);
		}

		if (scean == 5)
		{
			//��������3������ �浹ó��
			stage3mapcrash();
			babymonstercrashbullet();
			undynego();
		}

		//������
		bossdogopen();

		//��������4 �����Լ�����
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

	//intro1 1�����϶�
	if (scean == 1)
	{
		_intro1->render();
	}
	//intro2 2�����϶�
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
	//stage2 4�����϶�
	if (scean == 4)
	{
		_stage2->render();
		_player->render();
		_bird->render(_player->getplayerx());
		_dog->render(_player->getplayerx());
		_birdbullet->render();
	}

	//===================������ �ʱ�ȭ �������� �κ�=================
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	vector<tagbird>*				_vbird = _bird->getVbird();
	vector<tagbird>::iterator	    _vibird = _bird->getVIbird();

	
	//================================== ��ܰ� �Ǵ� �ڵ��̴� �������ÿ� =================================
	//��������3�϶� �÷��̾� ü���� 0�Ǹ�

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

	//�������� ����
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

	//=================================== ��ܰ� �Ǵ� �ڵ��̴� �������ÿ� =================================
	//�����۹ڽ�
	_item->render();

	

	//============= 5�� - ��������3������ ==========
	if (scean == 5)
	{
		_stage3boss->render();
		_player->render();
		_dog->render(_player->getplayerx());
	}

	_dogboss->render(_player->getplayerx());

	//���� ��������3�� ���̸�, ��������4�� �����ض�.

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

	//ġƮŰ
	//sprintf_s(str, "���ϻ��� :  %d   ī��Ʈ���� : %d  �����ü�� : %d", undynerandNum, undynecount , _stage4->getundynehp());
	//TextOut(getMemDC(), 100, 100, str, strlen(str));

	if (_stage4->getend() == true)
	{
		IMAGEMANAGER->findImage("ȭ��Ʈ�ƿ�")->alphaRender(getMemDC(), 0, 0, whiteoutalpha3);

		IMAGEMANAGER->findImage("��")->alphaRender(getMemDC(), 0, 0, whiteoutalpha4);
	}
}


//stage1�� ��ü���� �÷��̾�� �浹�Ѵ�.
void stageManager::stage1objectCrash()
{
		RECT temp; // ������Ʈ�� �ε�����?

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
	//����� ���̶� �ε����� �÷��̾� ������
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject2()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	//����� ���Ʒ��� �ε����� ���������� �з���
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject3()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}
	//������Ǯ�̶� �ε����� �Ʒ����� �з���
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject4()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}
	//������������������ǵ�
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject5()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	//��ٸ� �Ʒ���
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject6()))
	{
		_player->setplayery(_player->getplayery() - PLAYER_SPEED);
	}
	//��ٸ� ���ʽǵ�
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject7()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}

	//��ٸ� �����ʽǵ�
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject8()))
	{
		_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
	}

	//��ٸ� �Ʒ���
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject9()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}

	//��ٸ� �Ʒ���
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject10()))
	{
		_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
	}
	//��ٸ� �Ʒ���
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
	//������ �������ڷ�
	if (IntersectRect(&temp, &_player->getplayerrect(), &_stage1->getobject16()))
	{
		_player->setplayery(_player->getplayery() + PLAYER_SPEED);
	}


	//==================================================================
	//�����ͷ� ���� �޽��ϴ�.(�γ뽺)
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
		//����� ���̶� �ε����� �÷��̾� ������
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject2()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		//����� ���Ʒ��� �ε����� ���������� �з���
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject3()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}
		//������Ǯ�̶� �ε����� �Ʒ����� �з���
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject4()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
		//������������������ǵ�
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject5()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}

		//��ٸ� �Ʒ���
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject6()))
		{
			_vidog->dogy -= _vidog->speed;
			//_player->setplayery(_player->getplayery() - PLAYER_SPEED);
		}
		//��ٸ� ���ʽǵ�
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject7()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}

		//��ٸ� �����ʽǵ�
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject8()))
		{
			_vidog->dogx += _vidog->speed;
			//_player->setplayerx(_player->getplayerx() + PLAYER_SPEED);
		}

		//��ٸ� �Ʒ���
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject9()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}

		//��ٸ� �Ʒ���
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject10()))
		{
			_vidog->dogx -= _vidog->speed;
			//_player->setplayerx(_player->getplayerx() - PLAYER_SPEED);
		}
		//��ٸ� �Ʒ���
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
		//������ �������ڷ�
		if (IntersectRect(&temp, &_vidog->rc, &_stage1->getobject16()))
		{
			_vidog->dogy += _vidog->speed;
			//_player->setplayery(_player->getplayery() + PLAYER_SPEED);
		}
	}
	
}

//�÷��̾�� ��������ī�޶� ���� //���� �Ѿ˰� ���ʹ� ������ ���������� // ��Ʈ�¾�������
void stageManager::stage1camera()
{
	//���� ��� ������ ī�޶��̵��ϰ� ����ȿ��
	if (_stage1->getstageclearcamera() == false)

		//ī�޶� ����
		//�÷��̾� ī�޶� ���ʺκк��� �÷��̾� �÷��̾� ���ʺ���ũ��
	{
		if (scean == 3) // ��3
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
		// =============================================================�� 4�϶�
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

//���� �Ѿ˿� ����
void stageManager::DogCrashplayerBullet()
{
	RECT temp2;
	//�����ͷ� ���� �޽��ϴ�.(�γ뽺)
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
						//������ �ڽ��� ����߸�
						randBox = RND->getFromIntTo(1,3);
						if (randBox == 1)
						{
							_item->itemDrop(0, _vidog->dogx, _vidog->dogy);
						}
					}
					else if(_vidog->hp > 0) //ü���̱���
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

//���� �Ѿ˿� ����
void stageManager::birdCrashplayerBullet()
{
	RECT temp2;
	//�����ͷ� ���� �޽��ϴ�.(�γ뽺)
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

//�÷��̾�� ���� �浹(������)
void stageManager::playercrashDog()
{

	RECT temp3;
	//�����ͷ� ���� �޽��ϴ�.(�γ뽺)
	vector<tagDog>*				_vdog = _dog->getVdog();
	vector<tagDog>::iterator	_vidog;

	float temp1;
	
	//�ε�������
	if(crashDog == false)
	{
		for (_vidog = _vdog->begin(); _vidog != _vdog->end();)
		{
			if (IntersectRect(&temp3, &_player->getplayerrect(), &_vidog->rc))
			{
				//�÷��̾� ü�±���
				if (_player->getplayerhp() > 0)
				{
					//�����ݷ�
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
	//�ε�������
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

//���Ѿ˰� ����̶� �浹�ϸ� ������(������)
void stageManager::playercrashbirdBullet()
{
	vector<tagbirdBullet>*				_vbirdBullet = _birdbullet->getvbirdBullet();
	vector<tagbirdBullet>::iterator		_vibirdBullet = _birdbullet->getvibirdBullet();

	RECT temp9;
	//�ε�������
	if (crashDog == false)
	{
		for (_vibirdBullet = _vbirdBullet->begin(); _vibirdBullet != _vbirdBullet->end();)
		{
			if (IntersectRect(&temp9, &_player->getplayerrect(), &_vibirdBullet->rc))
			{
				//�����ݷ�
				if (_player->getshildcount() <= 0)
				{
					//�÷��̾� ü�±���
					if (_player->getplayerhp() > 0)
					{
						//�����ݷ�
						_player->setplayerhp(_player->getplayerhp() - 10);
						_vbirdBullet->erase(_vibirdBullet);
					}
				}
				else if (_player->getshildcount() > 0)
				{
					_player->setshildcount(_player->getshildcount() - 1);
				}
				////�÷��̾� ü�±���
				//if (_player->getplayerhp() > 0)
				//{
				//	//�����ݷ�
				//	_player->setplayerhp(_player->getplayerhp() - 10);
				//	_vbirdBullet->erase(_vibirdBullet);
				//}
				//���� ����̶��浹������ ��¦�Ÿ���ȿ��
				crashDog = true;
				break;
			}
			else { _vibirdBullet++; }
		}
	}
}

//�������� Ŭ�����ϸ� ī�޶��̵��ϰ� ����ȿ��
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

//stage1��z
void stageManager::stage1end()
{
	RECT temp5;
	//���� stage1Ŭ�����
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

//�÷��̾� ��������2 ������Ʈ �浹
void stageManager::stage2objectCrash()
{
	RECT temp6; // ������Ʈ�� �ε�����?

	//���ʸ���
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

	//�Ʒ�����
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

	//�Ʒ�����2
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

	//���ʸ���
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

		//�Ʒ�����
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

		//�Ʒ�����2
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

		//���ʸ���
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

		//�Ʒ�����
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

		//�Ʒ�����2
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

		//���ʸ���
		if (IntersectRect(&temp6, &_vibossdog->rc, &_stage2->gethill16()))
		{
			_vibossdog->x += _vibossdog->speed;
		}
	}
}

//��������2 wave1 ����
void stageManager::stage2wave1()
{
	if (_stage2->getmap1x() < -400)
	{
		//stage2 wave1�����
		_bird->setwave1on(true);
	}
}

//���� �ѽ�
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

//��������2���� �÷��̾� ������ ���µ�
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

//��������2 wave2 ����
void stageManager::stage2wave2()
{
	//�� �������� stage2 - wave2����
	if (stageWave1birdkill == 50)
	{
		if (stage2wave2on == false)
		{
			_dog->stage2dogcreate(_stage2->getmap1x(),_player->getplayerx());
			stage2wave2on = true;
		}
	}
}

//�������� ������
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

//������
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

	//�غ��� ����
	if (crashDog == false)
	{
		for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
		{
			if (IntersectRect(&temp, &_vibossdog->imagerc, &_player->getplayerrect()))
			{
				//�غ����� �ǵ带 �ٷ� �ڻ쳿
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

	//�÷��̾� �Ѿ�
	
	for (_vibossdog = _vbossdog->begin(); _vibossdog != _vbossdog->end(); _vibossdog++)
	{
		for (_viplayerBullet1 = _vplayerBullet1->begin(); _viplayerBullet1 != _vplayerBullet1->end();)
		{
			if (IntersectRect(&temp, &_vibossdog->imagerc, &_viplayerBullet1->rc))
			{
				//�����з����鼭 ü�±���
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

//��������3 �Ѿ���۾�
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
				//���ű��
				scean = 5;
				//Ȥ�ø� �� ����
				_bird->getVbird()->clear();
				//Ȥ�ø� �������� ����
				for (_vidog = _vdog->begin() + 1; _vidog != _vdog->end(); _vidog++)
				{
					_vidog->isDead = true;
				}
				//Ȥ�ø� �����۵� ����
				_item->getVitem()->clear();

				//��ġ����
				_player->setplayerx(50);
				_player->setplayery(WINSIZEY / 2 - 50);
				
				stage2ok = true;
				//===========================������ġ �ʱ�ȭ �۾��� =====================
			}

		}
	}
}

//��������3������ �浹ó��
void stageManager::stage3mapcrash()
{
	RECT temp;
	if (stage3mapcrashbool == false)
	{
		//����
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

		//�Ʒ���
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

//�������Ͱ� �Ѿ˸��� // �̺�Ʈ�� �߻��ϰ� �÷��̾� ����
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

//�������Ͱ� �Ѿ˸����� ������� �پ
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

//��������4 �����Լ�����
void stageManager::stage4function()
{

	//���� ��������3 ���� �˸��ٸ�, ��������4 ������Ʈ�� �ض�.
	if (_stage3boss->getstage3bossend() == true)
	{
		scean = 6;
	}
	//ó�������ϸ� �÷��̾� ��ġ ��������
	if (_stage4->getplayerStart1() == false)
	{
		_player->setplayerx(WINSIZEX / 2);
		_player->setplayery(WINSIZEY - 250);
		_player->setplayerstop(true);
	}
	//��������4
	if (scean == 6)
	{
		_stage4->update();
		_player->update(goLR);
	}
	//���� �÷��̾�������� ����Ǹ� �÷��̾ ��������
	if (_stage4->getplayerMove() == true)
	{
		_player->setplayerstop(false);
	}

}

//������� ���Ѿ��� ������ ( �������� )
void stageManager::undynebirdbullet()
{
	undynecount++;
	if (_stage4->getGameStart() == true)
	{
		if (_stage4->getundyneStatebullet() == 1)
		{
			if (undynecount > 500)
			{
				undynerandNum = RND->getFromIntTo(1, 6);//1~3�������Ѱ�
				undynecount = 0;
			}

			//����1 - ä��?
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

			//����2 - �����л�
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

			//����3 - ���� ���� �ӵ�
			if (undynerandNum == 3)
			{
				if (undynecount % 5 == 0 && undynecount < 350)
				{
					_birdbullet->fire(_stage4->getundynex()-100, _stage4->getundyney()+100, _player->getplayerx(), _player->getplayery(), RND->getFromFloatTo(4,8), 20, false);
				}
			}

			//����4 - üũ���� ����
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

			//����4 - üũ���� ����
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

//����� �����(�÷��̾����)
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

//��
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

//����ΰ� �÷��̾� �浹
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


