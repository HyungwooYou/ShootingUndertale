#include "stdafx.h"
#include "stage1.h"


stage1::stage1()
{
}


stage1::~stage1()
{
}

HRESULT stage1::init()
{
	IMAGEMANAGER->addImage("��������", "stage1.bmp", 2777, WINSIZEY - 200, true, RGB(255, 0, 255));
	stageclearcamera = false;
	//��緺Ʈ���� ���� ���������Ѵ� satge1x�� ������
	stage1x = 0;

	return S_OK;
}

void stage1::release()
{
}

void stage1::update(int dogdie)
{
	//����������
	_dogdie = dogdie;

	//���غ������ ó����ġ
	object2 = RectMake(stage1x, 0, 250, 360);
	//������� �ٷξƷ�(�Ʒ��������̶� �̾�������)
	object3 = RectMake(stage1x, object2.bottom, 80, 168);
	//�Ʒ��ʳ�����
	objectDOWN = RectMake(stage1x, object3.bottom, 2777, 100);

	//���غ������ ������������
	object4 = RectMake(object2.right, 0, 270, 270);
	//���ʳ��� ���ʺ�
	object11 = RectMake(object4.right, 0, 10, 300);
	//���ʳ�����
	objectUP = RectMake(object11.right, 0, 1500, 310);
	//������� ������ �����ǵ�
	object5 = RectMake(object2.right, object4.bottom, 10, 80);

	//��ٸ� �Ʒ�
	object6 = RectMake(objectUP.right - 600, objectDOWN.top - 50, 110, 50);

	//��ٸ� ���ʽǵ�
	object7 = RectMake(object6.left - 10, objectDOWN.top - 40, 10, 50);

	//��ٸ� ���ʽǵ�
	object8 = RectMake(object6.right, objectDOWN.top - 40, 15, 50);


	//��ٸ� ����
	object9 = RectMake(objectUP.right - 600, objectDOWN.top - 220, 110, 50);

	//��ٸ� ���� ���ʽǵ�
	object10 = RectMake(object9.left - 10, objectUP.bottom - 10, 10, 50);

	//��ٸ� ���� ���ʽǵ�
	object12 = RectMake(object9.right, objectUP.bottom - 10, 10, 50);

	//���ʽ� �����ʽǵ�
	object13 = RectMake(objectUP.right, 0, 17, 300);

	//����2��° 
	object14 = RectMake(object13.right, 0, 800, 120);
	//����2��° 
	object15 = RectMake(object13.right + 660, 120, 10, 200);

	//����2��° 
	object16 = RectMake(object15.right, object15.top, 100, 210);

	//�������� Ŭ����Ǹ� ��Ʈ
	clearlocation = RectMake(50+object15.right, object15.bottom, 100,300);

}

void stage1::render()
{
	IMAGEMANAGER->findImage("��������")->render(getMemDC(), stage1x, 0); // ������ȭ��

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
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
		Rectangle(getMemDC(), object11);
		Rectangle(getMemDC(), objectUP);
		Rectangle(getMemDC(), objectDOWN);
		Rectangle(getMemDC(), object2);
		Rectangle(getMemDC(), object3);
		Rectangle(getMemDC(), object4);
		Rectangle(getMemDC(), object5);
		Rectangle(getMemDC(), object6);
		Rectangle(getMemDC(), object7);
		Rectangle(getMemDC(), object8);
		Rectangle(getMemDC(), object9);
		Rectangle(getMemDC(), object10);
		Rectangle(getMemDC(), object12);
		Rectangle(getMemDC(), object13);
		Rectangle(getMemDC(), object14);
		Rectangle(getMemDC(), object15);
		Rectangle(getMemDC(), object16);

		Rectangle(getMemDC(), clearlocation);
	}
}
