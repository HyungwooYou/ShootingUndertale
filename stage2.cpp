#include "stdafx.h"
#include "stage2.h"


stage2::stage2()
{
}


stage2::~stage2()
{
}

HRESULT stage2::init()
{
	IMAGEMANAGER->addImage("��������2", "stage2.bmp", 2777, 768 , true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������2��", "stage2back.bmp", 2777, 768, true, RGB(255, 0, 255));
	//��������2�� ���� ī�޶�
	map1x = 0;
	

	return S_OK;
}

void stage2::release()
{
}

void stage2::update(int cleardogboss)
{
	_stage3go = cleardogboss;

	//���ʸ���
	hill1 = RectMake(map1x, 0, 220, 160);
	hill2 = RectMake(hill1.right-60, hill1.bottom, 50, 60);
	hill3 = RectMake(hill2.left+10,hill2.bottom,2160,15);
	hill4 = RectMake(hill3.right,hill3.top-40,10,40);
	hill5 = RectMake(hill4.right, hill4.top-30, 500, 10);

	//�Ʒ�����
	hill6 = RectMake(hill1.left, hill1.bottom+250, 220, 160);
	hill7 = RectMake(hill6.right-80, hill6.top-10, 10, 10);
	hill8 = RectMake(hill7.right, hill7.top-10, 10, 10);
	hill9 = RectMake(hill8.right, hill8.top - 42, 10, 42);
	hill10 = RectMake(hill9.right, hill9.top - 10, 2140, 10);

	//�Ʒ�����2
	hill11 = RectMake(hill10.right, hill10.top + 10, 10, 40);
	hill12 = RectMake(hill11.right, hill11.bottom, 10, 10);
	hill13 = RectMake(hill12.right, hill12.bottom, 10, 10);
	hill14 = RectMake(hill13.right, hill13.bottom, 10, 10);
	hill15 = RectMake(hill14.right, hill14.bottom, 500, 10);

	//���ʸ���
	hill16 = RectMake(hill1.left-10, hill1.top, 10, WINSIZEY);
	
	//����������Ȳ
	stage3go = RectMake(hill5.right-100,hill5.bottom,200,300);

	if (KEYMANAGER->isOnceKeyDown(VK_F5))
	{
		if (f5on == false)
		{
			f5on = true;
		}
		else if (f5on == true)
		{
			f5on = false;
		}
	}
}

void stage2::render()
{
	//Ȯ�ο� f5
	//��������2�� ���� ī�޶�
	IMAGEMANAGER->findImage("��������2��")->render(getMemDC(), map1x/2, 0); // ������ȭ��
	IMAGEMANAGER->findImage("��������2")->render(getMemDC(), map1x, 0); // ������ȭ��

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
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
		//���ʸ���
		Rectangle(getMemDC(), hill1);
		Rectangle(getMemDC(), hill2);
		Rectangle(getMemDC(), hill3);
		Rectangle(getMemDC(), hill4);
		Rectangle(getMemDC(), hill5);

		//�Ʒ�����
		Rectangle(getMemDC(), hill6);
		Rectangle(getMemDC(), hill7);
		Rectangle(getMemDC(), hill8);
		Rectangle(getMemDC(), hill9);
		Rectangle(getMemDC(), hill10);

		//�Ʒ�����2
		Rectangle(getMemDC(), hill11);
		Rectangle(getMemDC(), hill12);
		Rectangle(getMemDC(), hill13);
		Rectangle(getMemDC(), hill14);
		Rectangle(getMemDC(), hill15);

		//���ʸ���
		Rectangle(getMemDC(), hill16);

		//����������Ȳ
		Rectangle(getMemDC(), stage3go);
	}
	//Ȯ�ο� ġƮŰ
	//sprintf_s(str,"%d",map1x);
	//TextOut(getMemDC(),WINSIZEX/2,100,str,strlen(str));

}
