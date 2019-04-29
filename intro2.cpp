#include "stdafx.h"
#include "intro2.h"


intro2::intro2()
{
}


intro2::~intro2()
{

}

HRESULT intro2::init()
{
	//==================================== 기본배경 ===================================
	//기본 배경화면 생성
	IMAGEMANAGER->addImage("백그라운드", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//첫씬 상태
	sceneChange = STATR_SCENE;
	//==================================== 화면1 ===================================
	//그림
	image1 = IMAGEMANAGER->addImage("화면1", "image1.bmp", 600, 300, true, RGB(255, 0, 255));
	image1->setAlpahBlend(true, 255);
	image1RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image1Alpha = 0;
	//글자
	image1font1 = IMAGEMANAGER->addImage("화면1폰트", "image1font.bmp", 600, 150, true, RGB(255, 0, 255));
	image1font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image1font1->setAlpahBlend(true, 255);
	image1fontAlpha = 0;

	count1 = 0;

	//==================================== 화면2 ===================================
	//그림
	image2 = IMAGEMANAGER->addImage("화면2", "image2.bmp", 600, 300, true, RGB(255, 0, 255));
	image2RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image2->setAlpahBlend(true, 255);
	image2Alpha = 0;
	//글자
	image2font1 = IMAGEMANAGER->addImage("화면2폰트", "image2font.bmp", 600, 150, true, RGB(255, 0, 255));
	image2font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image2font1->setAlpahBlend(true, 255);
	image2fontAlpha = 0;

	count2 = 0;

	//==================================== 화면3 ===================================
	//그림
	image3 = IMAGEMANAGER->addImage("화면3", "image3.bmp", 600, 300, true, RGB(255, 0, 255));
	image3RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image3->setAlpahBlend(true, 255);
	image3Alpha = 0;
	//글자
	image3font1 = IMAGEMANAGER->addImage("화면3폰트", "image3font.bmp", 600, 150, true, RGB(255, 0, 255));
	image3font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image3font1->setAlpahBlend(true, 255);
	image3fontAlpha = 0;

	count3 = 0;

	//==================================== 화면4 ===================================
	//글자
	image4font1 = IMAGEMANAGER->addImage("화면4폰트", "image4font.bmp", 600, 225, true, RGB(255, 0, 255));
	image4font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 600, 225);
	image4font1->setAlpahBlend(true, 255);
	image4fontAlpha = 0;

	count4 = 0;

	//==================================== 화면5 ===================================
	//글자
	image5font1 = IMAGEMANAGER->addImage("화면5폰트", "image5font.bmp", 600, 150, true, RGB(255, 0, 255));
	image5font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image5font1->setAlpahBlend(true, 255);
	image5fontAlpha = 0;

	image5font2 = IMAGEMANAGER->addImage("화면5폰트2", "image5font2.bmp", 100, 150, true, RGB(255, 0, 255));
	image5font3 = RectMakeCenter(image5font.right - 200, WINSIZEY - 200, 100, 150);

	count5 = 0;

	countIndex = 0;
	//==================================== 화면6 ===================================
	//그림
	image6 = IMAGEMANAGER->addImage("화면6", "image6.bmp", 600, 300, true, RGB(255, 0, 255));
	image6RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image6->setAlpahBlend(true, 255);
	image6Alpha = 0;
	//글자
	image6font1 = IMAGEMANAGER->addImage("화면6폰트", "image6font.bmp", 600, 150, true, RGB(255, 0, 255));
	image6font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image6font1->setAlpahBlend(true, 255);
	image6fontAlpha = 0;

	count6 = 0;

	//==================================== 화면7 ===================================
	//그림
	image7 = IMAGEMANAGER->addImage("화면7", "image7.bmp", 600, 300, true, RGB(255, 0, 255));
	image7RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image7->setAlpahBlend(true, 255);
	image7Alpha = 0;
	//글자
	image7font1 = IMAGEMANAGER->addImage("화면7폰트", "image7font.bmp", 600, 225, true, RGB(255, 0, 255));
	image7font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 600, 255);
	image7font1->setAlpahBlend(true, 255);
	image7fontAlpha = 0;

	count7 = 0;

	//==================================== 화면8 ===================================
	//그림
	image8 = IMAGEMANAGER->addImage("화면8", "image8.bmp", 600, 300, true, RGB(255, 0, 255));
	image8RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image8->setAlpahBlend(true, 255);
	image8Alpha = 0;

	count8 = 0;

	//==================================== 화면9 ===================================
	//그림
	image9 = IMAGEMANAGER->addImage("화면9", "image9.bmp", 600, 300, true, RGB(255, 0, 255));
	image9RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image9->setAlpahBlend(true, 255);
	image9Alpha = 0;

	count9 = 0;

	//==================================== 화면10 ===================================
	//그림
	image10 = IMAGEMANAGER->addImage("화면10", "image10.bmp", 600, 300, true, RGB(255, 0, 255));
	image10RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image10->setAlpahBlend(true, 255);
	image10Alpha = 0;

	count10 = 0;

	//==================================== 화면11 ===================================
	//그림
	image11 = IMAGEMANAGER->addImage("화면11", "image11.bmp", 600, 900, true, RGB(255, 0, 255));
	image11RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image11->setAlpahBlend(true, 255);
	image11Alpha = 0;

	count11 = 0;
	imageindex11 = 0;

	//==================================== pressEnter ===================================
	IMAGEMANAGER->addImage("pressEnter", "pressEnter.bmp", 344, 16, true, RGB(255, 0, 255));
	//pressEnter 임시RECT
	pressEnter = RectMakeCenter(PRESS_LOCATION_X2, PRESS_LOCATION_Y2, 344, 16);
	pressEnterAlpha = 0; // pressEnter 처음알파값


	return S_OK;
}

void intro2::release()
{
}

void intro2::update()
{
	//씬출력
	imageAtoZ();
	pressEnterG2();

}

void intro2::render()
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
		Rectangle(getMemDC(), image1RECT);
		Rectangle(getMemDC(), image1font);
		Rectangle(getMemDC(), pressEnter);
	}

	//=================================== 이미지1과 글 ================================
	if (sceneChange == SCENE1)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면1")->alphaRender(getMemDC(), image1RECT.left, image1RECT.top, image1Alpha);

		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면1폰트")->alphaRender(getMemDC(), image1font.left, image1font.top, image1fontAlpha);
	}

	//=================================== 이미지2과 글 ================================
	if (sceneChange == SCENE2)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면2")->alphaRender(getMemDC(), image2RECT.left, image2RECT.top, image2Alpha);

		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면2폰트")->alphaRender(getMemDC(), image2font.left, image2font.top, image2fontAlpha);
	}

	//=================================== 이미지3과 글 ================================
	if (sceneChange == SCENE3 || sceneChange == SCENE4)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면3")->alphaRender(getMemDC(), image3RECT.left, image3RECT.top, image3Alpha);
	}
	if (sceneChange == SCENE3)
	{
		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면3폰트")->alphaRender(getMemDC(), image3font.left, image3font.top, image3fontAlpha);
	}

	//=================================== 이미지4과 글 ================================
	if (sceneChange == SCENE4)
	{
		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면4폰트")->alphaRender(getMemDC(), image4font.left, image4font.top, image4fontAlpha);
	}

	//=================================== 이미지5과 글 ================================
	if (sceneChange == SCENE5)
	{
		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면5폰트")->alphaRender(getMemDC(), image5font.left, image5font.top, image5fontAlpha);


		if (count5point > SCENE_POINT)
		{
			count5point = 0;
			if (countIndex < 4)
			{
				countIndex++;
			}
			if (countIndex >= 4)
			{
				sceneChange = SCENE6;
			}
		}
		IMAGEMANAGER->findImage("화면5폰트2")->render(getMemDC(), image5font3.left, image5font3.top, 0, 0, 30 * countIndex, 150);
		//Rectangle(getMemDC(),image5font3);
	}

	//=================================== 이미지6과 글 ================================
	if (sceneChange == SCENE6)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면6")->alphaRender(getMemDC(), image6RECT.left, image6RECT.top, image6Alpha);

		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면6폰트")->alphaRender(getMemDC(), image6font.left, image6font.top, image6fontAlpha);
	}

	//=================================== 이미지7과 글 ================================
	if (sceneChange == SCENE7)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면7")->alphaRender(getMemDC(), image7RECT.left, image7RECT.top, image7Alpha);

		//글자
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("화면7폰트")->alphaRender(getMemDC(), image7font.left, image7font.top, image7fontAlpha);
	}

	//=================================== 이미지8과 글 ================================
	if (sceneChange == SCENE8)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면8")->alphaRender(getMemDC(), image8RECT.left, image8RECT.top, image8Alpha);
	}

	//=================================== 이미지9과 글 ================================
	if (sceneChange == SCENE9)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면9")->alphaRender(getMemDC(), image9RECT.left, image9RECT.top, image9Alpha);
	}

	//=================================== 이미지10과 글 ================================
	if (sceneChange == SCENE10)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면10")->alphaRender(getMemDC(), image10RECT.left, image10RECT.top, image10Alpha);
	}

	//=================================== 이미지11과 글 ================================
	if (sceneChange == SCENE11)
	{
		//그림
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("화면11")->render(getMemDC(), image11RECT.left, image11RECT.top, 0, imageindex11, 600, 300);
	}

	//==================================== pressEnter ===================================
	//Rectangle(getMemDC(),pressEnter); //pressEnter확인용
	IMAGEMANAGER->findImage("pressEnter")->alphaRender(getMemDC(), pressEnter.left, pressEnter.top, pressEnterAlpha);

	//치트키모드
	//sprintf_s(str, "%d", sceneChange);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));

}

//인트로 영상
void intro2::imageAtoZ()
{
	//================== 1번째장면 ==================
	if (sceneChange == SCENE1)
	{
		if (image1Alpha < 255)
		{
			image1Alpha++;
		}
		if (image1Alpha > 100)
		{
			if (image1fontAlpha < 255)
			{
				image1fontAlpha++;
			}
		}
		if (image1fontAlpha == 255) // 255된순간부터
		{
			count1++;
		}
		if (count1 > SCENE_COUNT) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = SCENE2;
		}
	}


	//================== 2번째장면 ==================
	if (sceneChange == SCENE2)
	{
		if (image2Alpha < 255)
		{
			image2Alpha++;
		}
		if (image2Alpha > 100)
		{
			if (image2fontAlpha < 255)
			{
				image2fontAlpha++;
			}
		}
		if (image2fontAlpha == 255) // 255된순간부터
		{
			count2++;
		}
		if (count2 > SCENE_COUNT) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 3;
		}
	}


	//================== 3번째장면 ==================
	if (sceneChange == SCENE3)
	{
		if (image3Alpha < 255)
		{
			image3Alpha++;
		}
		if (image3Alpha > 100)
		{
			if (image3fontAlpha < 255)
			{
				image3fontAlpha++;
			}
		}
		if (image3fontAlpha == 255) // 255된순간부터
		{
			count3++;
		}
		if (count3 > SCENE_COUNT) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 4;
		}
	}


	//================== 4번째장면 ==================
	if (sceneChange == SCENE4)
	{
		if (image4fontAlpha < 255)
		{
			image4fontAlpha++;
		}
		if (image4fontAlpha == 255) // 255된순간부터
		{
			count4++;
		}
		if (count4 > SCNEN_COUNT_2) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 5;
		}
	}


	//================== 5번째장면 ==================
	if (sceneChange == SCENE5)
	{
		if (image5fontAlpha < 255)
		{
			image5fontAlpha++;
		}
		if (image5fontAlpha == 255) // 255된순간부터
		{
			count5point++;

		}
		if (count5 > SCNEN_COUNT_2) // 200프레임 넘어가면 다음씬 보여줌
		{

			//sceneChange = 6;
		}
	}

	//================== 6번째장면 ==================
	if (sceneChange == SCENE6)
	{
		if (image6Alpha < 255)
		{
			image6Alpha++;
		}
		if (image6Alpha > 100)
		{
			if (image6fontAlpha < 255)
			{
				image6fontAlpha++;
			}
		}
		if (image6fontAlpha == 255) // 255된순간부터
		{
			count6++;
		}
		if (count6 > SCENE_COUNT) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 7;
		}
	}

	//================== 7번째장면 ==================
	if (sceneChange == SCENE7)
	{
		if (image7Alpha < 255)
		{
			image7Alpha++;
		}
		if (image7Alpha > 100)
		{
			if (image7fontAlpha < 255)
			{
				image7fontAlpha++;
			}
		}
		if (image7fontAlpha == 255) // 255된순간부터
		{
			count7++;
		}
		if (count7 > SCENE_COUNT) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 8;
		}
	}

	//================== 8번째장면 ==================
	if (sceneChange == SCENE8)
	{
		if (image8Alpha < 255)
		{
			image8Alpha++;
		}
		if (image8Alpha == 255) // 255된순간부터
		{
			count8++;
		}
		if (count8 > SCNEN_COUNT_2) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 9;
		}
	}

	//================== 9번째장면 ==================
	if (sceneChange == SCENE9)
	{
		if (image9Alpha < 255)
		{
			image9Alpha++;
		}
		if (image9Alpha == 255) // 255된순간부터
		{
			count9++;
		}
		if (count9 > SCNEN_COUNT_2) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 10;
		}
	}

	//================== 10번째장면 ==================
	if (sceneChange == SCENE10)
	{
		if (image10Alpha < 255)
		{
			image10Alpha++;
		}
		if (image10Alpha == 255) // 255된순간부터
		{
			count10++;
		}
		if (count10 > SCNEN_COUNT_2) // 200프레임 넘어가면 다음씬 보여줌
		{
			sceneChange = 11;
		}
	}

	//================== 11번째장면 ==================
	if (sceneChange == SCENE11)
	{
		if (image11Alpha < 255)
		{
			image11Alpha++;
		}
		if (image11Alpha > 100) // 255된순간부터
		{
			count11++;
		}
		if (count11 > SCNEN_COUNT_3) // 200프레임 넘어가면 다음씬 보여줌
		{
			if (imageindex11 < 600)
			{
				imageindex11++;
			}
		}
		if (imageindex11 == 600)
		{
			imageindex112++;
		}
		if (imageindex112 == 200)
		{
			sceneChange = 12;
		}
	}
}

void intro2::pressEnterG2()
{
	pressEnterAlpha += PRESS_ENTER_BLINK_SPEED2;
}
