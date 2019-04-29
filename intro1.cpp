#include "stdafx.h"
#include "intro1.h"


intro1::intro1()
{
}


intro1::~intro1()
{
}

HRESULT intro1::init()
{
	//==================================== 기본배경 ===================================
	//기본 배경화면 생성
	IMAGEMANAGER->addImage("백그라운드", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));


	//==================================== undertaleLogo ===================================
	//언더테일 기본로고
	undertaleLoge = IMAGEMANAGER->addImage("언더테일로고", "undertaleLogo.bmp", 902, 61, true, RGB(255, 0, 255));
	undertaleLoge->setAlpahBlend(true, 255);
	//로고위치 보기 임시RECT
	undertaleLogoRECT = RectMakeCenter(WINSIZEX / 2, LOGO_LOCATION_Y, 902, 61);

	undertaleLogoAlpha = 0; // 로고 처음알파값

	//==================================== pressEnter ===================================
	_pressEnter = IMAGEMANAGER->addImage("pressEnter", "pressEnter.bmp", 344, 16, true, RGB(255, 0, 255));
	_pressEnter->setAlpahBlend(true,255);
	//pressEnter 임시RECT
	pressEnter = RectMakeCenter(WINSIZEX / 2, PRESS_LOCATION_Y, 344, 16);
	pressEnterAlpha = 0; // pressEnter 처음알파값
	return S_OK;
}

void intro1::release()
{
}

void intro1::update()
{
	Logo(); // 로고 알파값을 변화해서 보여줘요
	pressEnterG(); // pressEnter는 지속적으로 깜박거려요
}

void intro1::render()
{
	//==================================== 기본배경 ===================================
	//기본 배경이미지 랜더
	IMAGEMANAGER->findImage("백그라운드")->render(getMemDC()); // 검은색화면 

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
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
		Rectangle(getMemDC(), undertaleLogoRECT);
		Rectangle(getMemDC(), pressEnter);
	}

	//==================================== undertaleLogo ===================================
	//언더테일 로고
	IMAGEMANAGER->findImage("언더테일로고")->alphaRender(getMemDC(), undertaleLogoRECT.left, undertaleLogoRECT.top, undertaleLogoAlpha);
	//Rectangle(getMemDC(),undertaleLogoRECT); //로고랙터 잡는 임시RECT

	//==================================== pressEnter ===================================
	//Rectangle(getMemDC(),pressEnter); //pressEnter확인용
	IMAGEMANAGER->findImage("pressEnter")->alphaRender(getMemDC(), pressEnter.left, pressEnter.top, pressEnterAlpha);
	//sprintf_s(str, "%f", undertaleLogoAlpha);
	//TextOut(getMemDC(), 100, 100, str, strlen(str));
}

void intro1::Logo()
{
	//처음에 안보였다가 게임을 키면 로고 알파랜더값이 점점늘어남
	if (undertaleLogoAlpha < 255)
	{
		undertaleLogoAlpha++;
	}
}

void intro1::pressEnterG()
{
	//pressEnter 그림은 계속 깜박거림
	pressEnterAlpha += PRESS_ENTER_BLINK_SPEED;
}
