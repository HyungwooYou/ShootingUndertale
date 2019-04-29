#include "stdafx.h"
#include "stage4.h"

stage4::stage4()
{
}


stage4::~stage4()
{
}

HRESULT stage4::init()
{
	//���ȭ��
	IMAGEMANAGER->addImage("���ƿ�", "background.bmp", 1280, 768, true, RGB(255, 0, 255));
	
	//����� ��ǥ�� �����̴� ����
	x = WINSIZEX / 2;
	y = 200;
	angle = 0;

	//����� ��Ʈ �ʱ�ȭ
	undynerc = RectMakeCenter(x, y, 190, 280);
	undyneImagerc = RectMakeCenter(x + 15, y - 10, 730 , 300);

	//����� ������
	undyneImage = IMAGEMANAGER->addFrameImage("��������", "undyne.bmp", 27010, 600, 37, 2, true, RGB(255, 0, 255));
	undyneImage->SetFrameX(0);
	undyneImage->SetFrameY(0);

	//����� ����
	undyneState = 1;

	//������ �����ߴ�.
	Startpont = RectMakeCenter(WINSIZEX/2, 400, 560, 80);
	IMAGEMANAGER->addImage("�����̵����ߴ�", "herobegin.bmp", 560, 80, true, RGB(255, 0, 255));
	StartpontX = 0;

	//��ݺ���������ߵɰŴ�
	Startpont2 = RectMakeCenter(WINSIZEX / 2, 30, 600, 50);
	IMAGEMANAGER->addImage("��ݺ���������ߵɰŴ�", "herobegin2.bmp", 600, 50, true, RGB(255, 0, 255));
	StartpontX2 = 0;

	//����� ü�¹�
	IMAGEMANAGER->addImage("������ʷϹ�", "undynehptop.bmp", 1280, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����λ�����", "undynehpbottom.bmp", 1280, 50, true, RGB(255, 0, 255));

	hpbar = RectMake(0,0,WINSIZEX,50);

	//�Ѿ�����
	undyneStatebullet = 1;

	//�ʱ�ȭ�� �����
	GameStart = false;
	Startpontbool2 = false;
	StartpontCount = 0;
	StartpontCount2 = 0;
	playerMove = false;
	hp = 0;
	hpbarx = 0;
	

	return S_OK;
}

void stage4::release()
{

}

void stage4::update()
{
	//�̹����� ����� ��Ʈ ����
	undynerc = RectMakeCenter(x, y, 190, 280);
	undyneImagerc = RectMakeCenter(x + 15, y - 10, 730, 300);


	//�÷��̾� ��������
	if (playerStart1 == false)
	{
		PlayerStart();
	}

	//�����������
	undyneFrame();

	//����� ������
	undyneMove();

	//������ �����ߴ�.
	herobegin();

	//��ݺ���������ߵɰŴ�
	herobegin2();

	//hpü�¹ٻ��ܳ�
	hpbarbegin();

	if (GameStart == true)
	{
		if (hp <= 0)
		{
			 end = true;
		}
	}
}

void stage4::render()
{
	//���ȭ��
	IMAGEMANAGER->findImage("���ƿ�")->render(getMemDC(), 0, 0);

	//����� ������
	if (undyneState == 1) //�����̸�
	{
		IMAGEMANAGER->findImage("��������")->frameRender(getMemDC(), undyneImagerc.left, undyneImagerc.top);
	}

	//������ �����ߴ�.
	IMAGEMANAGER->findImage("�����̵����ߴ�")->render(getMemDC(), Startpont.left, Startpont.top,0,0, StartpontX,80);

	//������ �����ߴ�.
	IMAGEMANAGER->findImage("��ݺ���������ߵɰŴ�")->render(getMemDC(), Startpont.left, Startpont.top, 0, 0, StartpontX2, 50);

	//ü�¹�
	IMAGEMANAGER->findImage("����λ�����")->render(getMemDC(), hpbar.left, hpbar.top, 0, 0, hpbarx, 30);
	IMAGEMANAGER->findImage("������ʷϹ�")->render(getMemDC(), hpbar.left, hpbar.top, 0, 0, hp, 30);

	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		if (checkrect == true)
		{
			checkrect = false;
		}
		else if (checkrect == false)
		{
			checkrect = true;
		}
	}
	if (checkrect == true)
	{
		Rectangle(getMemDC(), undyneImagerc);
		Rectangle(getMemDC(), undynerc);
		Rectangle(getMemDC(), hpbar);
		Rectangle(getMemDC(), Startpont);
		Rectangle(getMemDC(), Startpont2);
	}

	//Rectangle(getMemDC(), undyneImagerc);
	//Rectangle(getMemDC(), hpbarbar);
}

//�÷��̾� ��������(�ѹ���)
void stage4::PlayerStart()
{
	//��������4 ���۵Ǹ� �ѹ��� �����
	playerStart1 = true;
}

//�����������
void stage4::undyneFrame()
{
	imagecount++;

	if (imagecount % 2 == 0) // 10�ʸ���
	{
		if (undyneState == 1) //�����̸�
		{
			if (undyneImage->getFrameY() == 0)
			{
				if (imageindex > 36) // index 3���� ũ��
				{
					undyneImage->SetFrameY(1);
					imageindex = 0; // �ϴ� �̹��� 0���θ����
				}
			}
			else if (undyneImage->getFrameY() == 1)
			{
				if (imageindex > 34) // index 3���� ũ��
				{
					undyneImage->SetFrameY(0);
					imageindex = 0; // �ϴ� �̹��� 0���θ����
				}
			}
			undyneImage->SetFrameX(imageindex); //�̹���������

			imageindex++; //���� �̹������������� �ε����� �ø���.
		}
	}

}

//����� ������
void stage4::undyneMove()
{
	angle += 0.07;
	x = WINSIZEX / 2 + cosf(angle) * 10;
	y = 200 - sinf(angle) * 10;
}

//������ �����ߴ�.
void stage4::herobegin()
{
	if (GameStart == false)
	{
		//�̹���ī��Ʈ ���� ������
		if (imagecount % 20 == 0)
		{
			if (StartpontX < 560)
			{
				StartpontX = StartpontX + 80;
			}

		}
		if (StartpontX >= 560)
		{
			StartpontCount++;
			if (StartpontCount > 100)
			{
				StartpontX = StartpontX + 80;
				Startpontbool2 = true;
			}
		}
	}
}

//��ݺ���������ߵɰŴ�
void stage4::herobegin2()
{
	if (GameStart == false)
	{
		//������� ����� �µǸ�
		if (Startpontbool2 == true)
		{
			if (imagecount % 10 == 0)
			{
				if (StartpontX2 < 600)
				{
					StartpontX2 = StartpontX2 + 50;
				}
			}
			if (StartpontX2 >= 600)
			{
				StartpontCount2++;
				if (StartpontCount2 > 100)
				{
					StartpontX2 = StartpontX2 + 50;
					playerMove = true;
					GameStart = true;
				}
			}
		}
	}
}

//hpü�¹ٻ��ܳ�
void stage4::hpbarbegin()
{
	//���ӽ������϶�
	if (GameStart == false)
	{
		if (imagecount % 2 == 0)
		{
			if (hpbarx < 1280)
			{
				hp = hp + 10;
				hpbarx = hpbarx + 10;
			}
		}
	}
}
