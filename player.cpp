#include "stdafx.h"
#include "player.h"
#include "Stage1.h" // ��ȣ�����ҳ༮
#include "stageManager.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	
	playerstop = false;
	//�÷��̾� �������
	playerlive = 1;
	//�÷��̾� �⺻ ���İ�
	playeralpha = 255;
	//�÷��̾� ü��
	hp = 100;

	IMAGEMANAGER->addImage("�÷��̾����", "frontbar.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾��ʷϹ�", "bottombar.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hp��Ʈ", "hp.bmp", 60, 28, true, RGB(255, 0, 255));
	//�÷��̾� �⺻��ġ
	x = WINSIZEX / 2 - 500;
	y = WINSIZEY / 2;

	//�÷��̾��
	playerbar = RectMake(0, WINSIZEY - 200, WINSIZEX, 200);
	IMAGEMANAGER->addImage("�÷��̾��", "playerbar.bmp", WINSIZEX, 200, true, RGB(255, 0, 255));

	camerax = WINSIZEX / 2;
	cameray = WINSIZEY / 2;

	//�÷��̾� �������̵���
	playerstate = PLAYER_STATE_IDLE_RIGHT;

	//�÷��̾� �̹��� ����
	image0 = IMAGEMANAGER->addFrameImage("�÷��̾������", "playeridle.bmp", 240, 80,4,1, true, RGB(255, 0, 255));
	image0->setAlpahBlend(true,255);
	
	//������ �̹���
	image1 = IMAGEMANAGER->addFrameImage("�Ʒ��ο�����", "movedown.bmp", 240, 80, 4, 1, true, RGB(255, 0, 255));
	image1->setAlpahBlend(true, 255);
	image1->SetFrameX(0);
	image1->SetFrameY(0);

	image2 = IMAGEMANAGER->addFrameImage("���ο�����", "moveup.bmp", 240, 80, 4, 1, true, RGB(255, 0, 255));
	image2->setAlpahBlend(true, 255);
	image2->SetFrameX(0);
	image2->SetFrameY(0);

	image3 = IMAGEMANAGER->addFrameImage("�������ο�����", "moveleft.bmp", 120, 80, 2, 1, true, RGB(255, 0, 255));
	image3->setAlpahBlend(true, 255);
	image3->SetFrameX(0);
	image3->SetFrameY(0);

	image4 = IMAGEMANAGER->addFrameImage("���������ο�����", "moveright.bmp", 120, 80, 2, 1, true, RGB(255, 0, 255));
	image4->setAlpahBlend(true, 255);
	image4->SetFrameX(0);
	image4->SetFrameY(0);

	_playerBullet = new playerBullet;
	_playerBullet->init(50);


	//��������1Ŭ�����ϸ� ��縦 ��´�.
	clearfontimage = IMAGEMANAGER->addImage("�÷��̾�stage1Ŭ����","playerstage1clear.bmp",385,55,true,RGB(255,0,255));
	clearfont = RectMake(500, 600, 385, 55);
	_imageindex2 = 0;
	clearfonton = false;
	imageend = false;

	//�Ŀ�������
	item1x = x;
	item1y = y;
	item2x = x;
	item2y = y;
	item3x = x;
	item3y = y;

	item1angle = PI2/3;
	item2angle = (PI2/3)*2;
	item3angle = (PI2/3)*3;

	item1distance = 100;
	item2distance = 100;
	item3distance = 100;

	IMAGEMANAGER->addImage("������1", "item1.bmp", 50, 50, true, RGB(255, 0, 255));
	
	//�ǵ������
	shildcount = 0;
	_imageshild = IMAGEMANAGER->addFrameImage("����", "shildsprite.bmp", 500, 100, 5, 1, true, RGB(255, 0, 255));
	_imageshild->SetFrameX(0);
	_imageshild->SetFrameY(0);
	_imageshildindex = 0;
	_imageshildcount = 0;

	//����������
	IMAGEMANAGER->addImage("�������ִ¾�����1", "haveitem1.bmp", 240, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������ִ¾�����2", "haveitem2.bmp", 240, 80, true, RGB(255, 0, 255));

	return S_OK;
}

void player::release()
{
}

void player::update(int goLR)
{
	//�÷��̾� ��������� �����ϼ�����.
	if (playerlive == 1)
	{
		playerMove(); // �÷��̾� ������
	}

	_imagecount++;
	_imageshildcount++;

	if (_imageshildcount % 10 == 0) // 10�ʸ���
	{
		if (_imageshildindex > 4) // index 3���� ũ��
		{
			_imageshildindex = 0; // �ϴ� �̹��� 0���θ����
		}
		_imageshild->SetFrameX(_imageshildindex); //�̹���������

		_imageshildindex++; //���� �̹������������� �ε����� �ø���.
		
	}


	//�Ʒ��� ������
	if (_imagecount % 10 == 0) // 10�ʸ���
	{
		if (playerstate == PLAYER_STATE_MOVE_DOWN) //�����̸�
		{
			if (_imageindex > 3) // index 3���� ũ��
			{
				_imageindex = 0; // �ϴ� �̹��� 0���θ����
			}
			image1->SetFrameX(_imageindex); //�̹���������

			_imageindex++; //���� �̹������������� �ε����� �ø���.
		}
	}

	//�Ʒ��� ������
	if (_imagecount % 10 == 0) // 10�ʸ���
	{
		if (playerstate == PLAYER_STATE_MOVE_UP) //�����̸�
		{
			if (_imageindex > 3) // index 3���� ũ��
			{
				_imageindex = 0; // �ϴ� �̹��� 0���θ����
			}
			image2->SetFrameX(_imageindex); //�̹���������

			_imageindex++; //���� �̹������������� �ε����� �ø���.
		}
	}

	//�������� ������
	if (_imagecount % 10 == 0) // 10�ʸ���
	{
		if (playerstate == PLAYER_STATE_MOVE_LEFT) //�����̸�
		{
			if (_imageindex > 1) // index 3���� ũ��
			{
				_imageindex = 0; // �ϴ� �̹��� 0���θ����
			}
			image3->SetFrameX(_imageindex); //�̹���������

			_imageindex++; //���� �̹������������� �ε����� �ø���.
		}
	}

	//���������� ������
	if (_imagecount % 10 == 0) // 10�ʸ���
	{
		if (playerstate == PLAYER_STATE_MOVE_RIGHT) //�����̸�
		{
			if (_imageindex > 1) // index 3���� ũ��
			{
				_imageindex = 0; // �ϴ� �̹��� 0���θ����
			}
			image4->SetFrameX(_imageindex); //�̹���������

			_imageindex++; //���� �̹������������� �ε����� �ø���.
		}
	}

	

	//�÷��̾� �Ѿ�
	_playerBullet->update(goLR);

	//��������1Ŭ�����ϸ� ��縦 ��´�.
	stage1cleartalk();

	//�Ŀ�������
	playeritem1();

	//�ǵ������
	player2item2();

	if (hp < 0)
	{
		hp++;
	}

}

void player::render()
{
	//�÷��̾� �� �̹���
	IMAGEMANAGER->findImage("�÷��̾��")->render(getMemDC(), playerbar.left, playerbar.top);
	
	//Rectangle(getMemDC(), camera);
	//Rectangle(getMemDC(), rc);
	//Rectangle(getMemDC(), playerbar);
	//sprintf_s(str, "�ǵ�Ƚ�� :%d",shildcount);
	//TextOut(getMemDC(), WINSIZEX/2, 100, str, strlen(str));
	


	// ======================= �÷��̾� ���¿����� �̹��� ==============


	if (playerstate == PLAYER_STATE_IDLE_RIGHT)
	{
		IMAGEMANAGER->findImage("�÷��̾������")->alphaFrameRender(getMemDC(),rc.left,rc.top,0,0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_LEFT)
	{
		IMAGEMANAGER->findImage("�÷��̾������")->alphaFrameRender(getMemDC(), rc.left, rc.top, 1, 0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_UP)
	{
		IMAGEMANAGER->findImage("�÷��̾������")->alphaFrameRender(getMemDC(), rc.left, rc.top, 2, 0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_DOWN)
	{
		IMAGEMANAGER->findImage("�÷��̾������")->alphaFrameRender(getMemDC(), rc.left, rc.top, 3, 0, playeralpha);
	}


	if (playerstate == PLAYER_STATE_MOVE_DOWN)
	{
		IMAGEMANAGER->findImage("�Ʒ��ο�����")->alphaFrameRender(getMemDC(),rc.left,rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_UP)
	{
		IMAGEMANAGER->findImage("���ο�����")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_LEFT)
	{
		IMAGEMANAGER->findImage("�������ο�����")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_RIGHT)
	{
		IMAGEMANAGER->findImage("���������ο�����")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}


	//�÷��̾� ü�¹�
	playerHPbar1 = RectMake(PLAYER_HP_BAR_X, PLAYER_HP_BAR_Y, 200, 50);
	playerHPbar2 = RectMake(PLAYER_HP_BAR_X, PLAYER_HP_BAR_Y, 200, 50);
	hpfont = RectMake(playerHPbar1.left - 80,playerHPbar1.top+12,60,28);

	IMAGEMANAGER->findImage("�÷��̾����")->render(getMemDC(), playerHPbar1.left, playerHPbar1.top);
	IMAGEMANAGER->findImage("�÷��̾��ʷϹ�")->render(getMemDC(), playerHPbar2.left, playerHPbar2.top,0,0,hp*2,50);
	IMAGEMANAGER->findImage("hp��Ʈ")->render(getMemDC(), hpfont.left, hpfont.top);
	//Rectangle(getMemDC(), hpfont);
	//�÷��̾� �Ѿ�
	_playerBullet->render();

	//�������� Ŭ���� ī�޶�
	//Rectangle(getMemDC(), clearfont);

	//��������1Ŭ�����ϸ� ��縦 ��´�.
	IMAGEMANAGER->findImage("�÷��̾�stage1Ŭ����")->render(getMemDC(), clearfont.left, clearfont.top,0,0, _imageindex2,55);

	//�Ŀ�������
	if (player1item == 1)
	{
		//�������ִ¾�����1
		//�������ִ¾�����2
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item1.left, item1.top);
		//Rectangle(getMemDC(), item1);
		IMAGEMANAGER->findImage("�������ִ¾�����1")->render(getMemDC(), haveitem1.left, haveitem1.top,0,0,80,80);
	}
	else if (player1item == 2)
	{
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item1.left, item1.top);
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item2.left, item2.top);
		IMAGEMANAGER->findImage("�������ִ¾�����1")->render(getMemDC(), haveitem1.left, haveitem1.top, 0, 0, 160, 80);
		//Rectangle(getMemDC(), item1);
		//Rectangle(getMemDC(), item2);
	}
	else if (player1item == 3)
	{
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item1.left, item1.top);
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item2.left, item2.top);
		IMAGEMANAGER->findImage("������1")->render(getMemDC(), item3.left, item3.top);
		IMAGEMANAGER->findImage("�������ִ¾�����1")->render(getMemDC(), haveitem1.left, haveitem1.top, 0, 0, 240, 80);
		//Rectangle(getMemDC(), item1);
		//Rectangle(getMemDC(), item2);
		//Rectangle(getMemDC(), item3);
	}

	if (shildcount > 0)
	{
		if (shildcount == 1)
		{
			IMAGEMANAGER->findImage("�������ִ¾�����2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 80, 80);
		}
		else if (shildcount == 2)
		{
			IMAGEMANAGER->findImage("�������ִ¾�����2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 160, 80);
		}
		else if (shildcount == 3)
		{
			IMAGEMANAGER->findImage("�������ִ¾�����2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 240, 80);
		}
		IMAGEMANAGER->findImage("����")->frameRender(getMemDC(), shild.left, shild.top);
	}

	haveitem1 = RectMake(WINSIZEX-300,WINSIZEY-185,240,80);
	haveitem2 = RectMake(WINSIZEX-300,WINSIZEY-95,240,80);
	//Rectangle(getMemDC(), haveitem1);
	//Rectangle(getMemDC(), haveitem2);

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))
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
		Rectangle(getMemDC(), hpfont);
		Rectangle(getMemDC(), camera);
		Rectangle(getMemDC(), rc);
		Rectangle(getMemDC(), playerbar);
		Rectangle(getMemDC(), hpfont);
		Rectangle(getMemDC(), clearfont);
		Rectangle(getMemDC(), item1);
		Rectangle(getMemDC(), item2);
		Rectangle(getMemDC(), item3);
		Rectangle(getMemDC(), haveitem1);
		Rectangle(getMemDC(), haveitem2);
	}
}


//============================== ���� �Լ��� ==============================
//�÷��̾� Ű�Է°���
void player::playerMove()
{
		rc = RectMakeCenter(x, y, PLAYER_SIZE_X, PLAYER_SIZE_Y);
		camera = RectMakeCenter(camerax, cameray, 400, 768);

		if (playerstop == false)
		{
			//����
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				if (y > PLAYER_SIZE_Y/2)
				{
					playerstate = PLAYER_STATE_MOVE_UP; //�������մ´�
					y -= PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				playerstate = PLAYER_STATE_IDLE_UP; //�����δ�.
			}

			//�Ʒ���
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				if (y < WINSIZEY/2+143)
				{
					playerstate = PLAYER_STATE_MOVE_DOWN; //�������մ´�
					y += PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				playerstate = PLAYER_STATE_IDLE_DOWN; //�����δ�.
			}

			//����
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				if (x > PLAYER_SIZE_X/2)
				{
					playerstate = PLAYER_STATE_MOVE_LEFT; //�������մ´�
					x -= PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				playerstate = PLAYER_STATE_IDLE_LEFT; //�����δ�.
			}


			//������ (��������2�϶� �����ʿ�)!!!!!!!!!!!!!!!
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				//stage1 1�϶�
				if (x < WINSIZEX - PLAYER_SIZE_X / 2)
				{
					if (x < 1250)
					{
						playerstate = PLAYER_STATE_MOVE_RIGHT; //�������մ´�
						x += PLAYER_SPEED;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				playerstate = PLAYER_STATE_IDLE_RIGHT; //�����δ�.
			}



			//�Ѿ˴���� �Ѿ˳���
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				_playerBullet->fire(x, y, playerstate, 500);

				if (player1item == 1)
				{
					_playerBullet->fire(item1x, item1y, playerstate, 500);
				}
				else if (player1item == 2)
				{
					_playerBullet->fire(item1x, item1y, playerstate, 500);
					_playerBullet->fire(item2x, item2y, playerstate, 500);
				}
				else if (player1item == 3)
				{
					_playerBullet->fire(item1x, item1y, playerstate, 500);
					_playerBullet->fire(item3x, item3y, playerstate, 500);
					_playerBullet->fire(item2x, item2y, playerstate, 500);
				}
			}

			//�Ŀ�������
			if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
			{
				if (item1distance > 50)
				{
					item1distance -= 2;
				}
				if (item2distance > 50)
				{
					item2distance -= 2;
				}
				if (item3distance > 50)
				{
					item3distance -= 2;
				}
			}
			if (item1distance < 100)
			{
				item1distance += 1;
			}
			if (item2distance < 100)
			{
				item2distance += 1;
			}
			if (item3distance < 100)
			{
				item3distance += 1;
			}



			//�Ŀ������� ����� 
			if (KEYMANAGER->isOnceKeyDown(VK_F8))
			{
				player1item = 3;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_F9))
			{
				shildcount = 3;
			}
		}
}

//��������1Ŭ�����ϸ� ��縦 ��´�.
void player::stage1cleartalk()
{
	if (clearfonton == true)
	{
		if (_imagecount % 15 == 0)
		{
			if (_imageindex2 < 385)
			{
				_imageindex2 += 55;
			}
			else
			{
				_imagecount2++;
				if (_imagecount2 == 5)
				{
					if (imageend == false)
					{
						_imageindex2 += 55;
						imageend = true;
					}
				}
			}
		}
	}
}

//�Ŀ�������
void player::playeritem1()
{
	item1 = RectMakeCenter(item1x, item1y, 50, 50);
	item2 = RectMakeCenter(item2x, item2y, 50, 50);
	item3 = RectMakeCenter(item3x, item3y, 50, 50);

	item1x = x + cosf(item1angle) * item1distance;
	item1y = y + -sinf(item1angle) * item1distance;
	item2x = x + cosf(item2angle) * item2distance;
	item2y = y + -sinf(item2angle) * item2distance;
	item3x = x + cosf(item3angle) * item3distance;
	item3y = y+ -sinf(item3angle) * item3distance;

	item1angle+= 0.05f;
	item2angle+= 0.05f;
	item3angle+= 0.05f;
}

void player::player2item2()
{
	shild = RectMakeCenter(x,y,100,100);
}

void player::pontclear()
{
	_imageindex2 = 0;
	imageend = false;
}

