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
	IMAGEMANAGER->addImage("출발전배경", "stage1.bmp", 2777, WINSIZEY - 200, true, RGB(255, 0, 255));
	stageclearcamera = false;
	//모든렉트들이 같이 움직여야한다 satge1x는 기준점
	stage1x = 0;

	return S_OK;
}

void stage1::release()
{
}

void stage1::update(int dogdie)
{
	//개들이죽음
	_dogdie = dogdie;

	//기준보라색문 처음위치
	object2 = RectMake(stage1x, 0, 250, 360);
	//보라색문 바로아래(아래나무숲이랑 이어져있음)
	object3 = RectMake(stage1x, object2.bottom, 80, 168);
	//아래쪽나무들
	objectDOWN = RectMake(stage1x, object3.bottom, 2777, 100);

	//기준보라색문 오른쪽작은숲
	object4 = RectMake(object2.right, 0, 270, 270);
	//위쪽나무 왼쪽벽
	object11 = RectMake(object4.right, 0, 10, 300);
	//위쪽나무들
	objectUP = RectMake(object11.right, 0, 1500, 310);
	//보라색문 오른쪽 작은실드
	object5 = RectMake(object2.right, object4.bottom, 10, 80);

	//사다리 아래
	object6 = RectMake(objectUP.right - 600, objectDOWN.top - 50, 110, 50);

	//사다리 왼쪽실드
	object7 = RectMake(object6.left - 10, objectDOWN.top - 40, 10, 50);

	//사다리 왼쪽실드
	object8 = RectMake(object6.right, objectDOWN.top - 40, 15, 50);


	//사다리 위쪽
	object9 = RectMake(objectUP.right - 600, objectDOWN.top - 220, 110, 50);

	//사다리 위쪽 왼쪽실드
	object10 = RectMake(object9.left - 10, objectUP.bottom - 10, 10, 50);

	//사다리 위쪽 왼쪽실드
	object12 = RectMake(object9.right, objectUP.bottom - 10, 10, 50);

	//위쪽숲 오른쪽실드
	object13 = RectMake(objectUP.right, 0, 17, 300);

	//위쪽2번째 
	object14 = RectMake(object13.right, 0, 800, 120);
	//위쪽2번째 
	object15 = RectMake(object13.right + 660, 120, 10, 200);

	//위쪽2번째 
	object16 = RectMake(object15.right, object15.top, 100, 210);

	//스테이지 클리어되면 렉트
	clearlocation = RectMake(50+object15.right, object15.bottom, 100,300);

}

void stage1::render()
{
	IMAGEMANAGER->findImage("출발전배경")->render(getMemDC(), stage1x, 0); // 검은색화면

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
