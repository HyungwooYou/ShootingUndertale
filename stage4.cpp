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
	//배경화면
	IMAGEMANAGER->addImage("블랙아웃", "background.bmp", 1280, 768, true, RGB(255, 0, 255));
	
	//언다인 좌표와 움직이는 각도
	x = WINSIZEX / 2;
	y = 200;
	angle = 0;

	//언다인 렉트 초기화
	undynerc = RectMakeCenter(x, y, 190, 280);
	undyneImagerc = RectMakeCenter(x + 15, y - 10, 730 , 300);

	//언다인 프레임
	undyneImage = IMAGEMANAGER->addFrameImage("보통언다인", "undyne.bmp", 27010, 600, 37, 2, true, RGB(255, 0, 255));
	undyneImage->SetFrameX(0);
	undyneImage->SetFrameY(0);

	//언다인 상태
	undyneState = 1;

	//영웅이 등장했다.
	Startpont = RectMakeCenter(WINSIZEX/2, 400, 560, 80);
	IMAGEMANAGER->addImage("영웅이등장했다", "herobegin.bmp", 560, 80, true, RGB(255, 0, 255));
	StartpontX = 0;

	//방금보다힘좀써야될거다
	Startpont2 = RectMakeCenter(WINSIZEX / 2, 30, 600, 50);
	IMAGEMANAGER->addImage("방금보다힘좀써야될거다", "herobegin2.bmp", 600, 50, true, RGB(255, 0, 255));
	StartpontX2 = 0;

	//언다인 체력바
	IMAGEMANAGER->addImage("언다인초록바", "undynehptop.bmp", 1280, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("언다인빨간바", "undynehpbottom.bmp", 1280, 50, true, RGB(255, 0, 255));

	hpbar = RectMake(0,0,WINSIZEX,50);

	//총알패턴
	undyneStatebullet = 1;

	//초기화를 하즈아
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
	//이미지와 언다인 렉트 갱신
	undynerc = RectMakeCenter(x, y, 190, 280);
	undyneImagerc = RectMakeCenter(x + 15, y - 10, 730, 300);


	//플레이어 시작지점
	if (playerStart1 == false)
	{
		PlayerStart();
	}

	//언다인프레임
	undyneFrame();

	//언다인 움직임
	undyneMove();

	//영웅이 등장했다.
	herobegin();

	//방금보다힘좀써야될거다
	herobegin2();

	//hp체력바생겨남
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
	//배경화면
	IMAGEMANAGER->findImage("블랙아웃")->render(getMemDC(), 0, 0);

	//언다인 프레임
	if (undyneState == 1) //상태이면
	{
		IMAGEMANAGER->findImage("보통언다인")->frameRender(getMemDC(), undyneImagerc.left, undyneImagerc.top);
	}

	//영웅이 등장했다.
	IMAGEMANAGER->findImage("영웅이등장했다")->render(getMemDC(), Startpont.left, Startpont.top,0,0, StartpontX,80);

	//영웅이 등장했다.
	IMAGEMANAGER->findImage("방금보다힘좀써야될거다")->render(getMemDC(), Startpont.left, Startpont.top, 0, 0, StartpontX2, 50);

	//체력바
	IMAGEMANAGER->findImage("언다인빨간바")->render(getMemDC(), hpbar.left, hpbar.top, 0, 0, hpbarx, 30);
	IMAGEMANAGER->findImage("언다인초록바")->render(getMemDC(), hpbar.left, hpbar.top, 0, 0, hp, 30);

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

//플레이어 시작지점(한번만)
void stage4::PlayerStart()
{
	//스테이지4 시작되면 한번만 실행됨
	playerStart1 = true;
}

//언다인프레임
void stage4::undyneFrame()
{
	imagecount++;

	if (imagecount % 2 == 0) // 10초마다
	{
		if (undyneState == 1) //상태이면
		{
			if (undyneImage->getFrameY() == 0)
			{
				if (imageindex > 36) // index 3보다 크면
				{
					undyneImage->SetFrameY(1);
					imageindex = 0; // 일단 이미지 0으로만들고
				}
			}
			else if (undyneImage->getFrameY() == 1)
			{
				if (imageindex > 34) // index 3보다 크면
				{
					undyneImage->SetFrameY(0);
					imageindex = 0; // 일단 이미지 0으로만들고
				}
			}
			undyneImage->SetFrameX(imageindex); //이미지입히고

			imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		}
	}

}

//언다인 움직임
void stage4::undyneMove()
{
	angle += 0.07;
	x = WINSIZEX / 2 + cosf(angle) * 10;
	y = 200 - sinf(angle) * 10;
}

//영웅이 등장했다.
void stage4::herobegin()
{
	if (GameStart == false)
	{
		//이미지카운트 재탕 ㅇㅅㅇ
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

//방금보다힘좀써야될거다
void stage4::herobegin2()
{
	if (GameStart == false)
	{
		//다음대사 출력이 온되면
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

//hp체력바생겨남
void stage4::hpbarbegin()
{
	//게임시작전일때
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
