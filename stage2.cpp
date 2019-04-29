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
	IMAGEMANAGER->addImage("스테이지2", "stage2.bmp", 2777, 768 , true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지2뒤", "stage2back.bmp", 2777, 768, true, RGB(255, 0, 255));
	//스테이지2맵 메인 카메라
	map1x = 0;
	

	return S_OK;
}

void stage2::release()
{
}

void stage2::update(int cleardogboss)
{
	_stage3go = cleardogboss;

	//위쪽막기
	hill1 = RectMake(map1x, 0, 220, 160);
	hill2 = RectMake(hill1.right-60, hill1.bottom, 50, 60);
	hill3 = RectMake(hill2.left+10,hill2.bottom,2160,15);
	hill4 = RectMake(hill3.right,hill3.top-40,10,40);
	hill5 = RectMake(hill4.right, hill4.top-30, 500, 10);

	//아래막기
	hill6 = RectMake(hill1.left, hill1.bottom+250, 220, 160);
	hill7 = RectMake(hill6.right-80, hill6.top-10, 10, 10);
	hill8 = RectMake(hill7.right, hill7.top-10, 10, 10);
	hill9 = RectMake(hill8.right, hill8.top - 42, 10, 42);
	hill10 = RectMake(hill9.right, hill9.top - 10, 2140, 10);

	//아래막기2
	hill11 = RectMake(hill10.right, hill10.top + 10, 10, 40);
	hill12 = RectMake(hill11.right, hill11.bottom, 10, 10);
	hill13 = RectMake(hill12.right, hill12.bottom, 10, 10);
	hill14 = RectMake(hill13.right, hill13.bottom, 10, 10);
	hill15 = RectMake(hill14.right, hill14.bottom, 500, 10);

	//왼쪽막기
	hill16 = RectMake(hill1.left-10, hill1.top, 10, WINSIZEY);
	
	//스테이지상황
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
	//확인용 f5
	//스테이지2맵 메인 카메라
	IMAGEMANAGER->findImage("스테이지2뒤")->render(getMemDC(), map1x/2, 0); // 검은색화면
	IMAGEMANAGER->findImage("스테이지2")->render(getMemDC(), map1x, 0); // 검은색화면

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
		//위쪽막기
		Rectangle(getMemDC(), hill1);
		Rectangle(getMemDC(), hill2);
		Rectangle(getMemDC(), hill3);
		Rectangle(getMemDC(), hill4);
		Rectangle(getMemDC(), hill5);

		//아래막기
		Rectangle(getMemDC(), hill6);
		Rectangle(getMemDC(), hill7);
		Rectangle(getMemDC(), hill8);
		Rectangle(getMemDC(), hill9);
		Rectangle(getMemDC(), hill10);

		//아래막기2
		Rectangle(getMemDC(), hill11);
		Rectangle(getMemDC(), hill12);
		Rectangle(getMemDC(), hill13);
		Rectangle(getMemDC(), hill14);
		Rectangle(getMemDC(), hill15);

		//왼쪽막기
		Rectangle(getMemDC(), hill16);

		//스테이지상황
		Rectangle(getMemDC(), stage3go);
	}
	//확인용 치트키
	//sprintf_s(str,"%d",map1x);
	//TextOut(getMemDC(),WINSIZEX/2,100,str,strlen(str));

}
