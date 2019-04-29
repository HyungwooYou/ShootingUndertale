#include "stdafx.h"
#include "playerDeath.h"


playerDeath::playerDeath()
{
}


playerDeath::~playerDeath()
{
}

HRESULT playerDeath::init()
{
	_pressEnter = IMAGEMANAGER->addImage("pressEnter", "pressEnter.bmp", 344, 16, true, RGB(255, 0, 255));
	_pressEnter->setAlpahBlend(true, 255);
	//pressEnter 임시RECT
	pressEnter = RectMakeCenter(WINSIZEX / 2, 500, 344, 16);
	pressEnterAlpha = 0; // pressEnter 처음알파값
	//이미지세팅~
	_playerheart = IMAGEMANAGER->addFrameImage("심장", "playerdeath.bmp", 100, 50, 2, 1, true, RGB(255, 0, 255));
	backgroundDeath = IMAGEMANAGER->addImage("백그라운드", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_crackheart1 = IMAGEMANAGER->addFrameImage("심장1", "playerdeath2.bmp", 100, 25, 4, 1, true, RGB(255, 0, 255));
	_crackheart2 = IMAGEMANAGER->addFrameImage("심장1", "playerdeath2.bmp", 100, 25, 4, 1, true, RGB(255, 0, 255));
	//렉트빼둠
	crackheart1 = RectMake(-100,0,0,0);
	crackheart2 = RectMake(-100,0,0,0);
	_gameover = IMAGEMANAGER->addImage("게임오버", "gameover.bmp", 600, 300, true, RGB(255, 0, 255));
	_gameover->setAlpahBlend(true, 255);
	backgroundd = RectMake(0,0,WINSIZEX,WINSIZEY);
	//======================= 초기화중 ========================
	count = 0;
	savexy = false;
	Scene1 = false;
	gravity = 0;
	gameoveralpha = 0;
	_playerheart->SetFrameX(0);
	gameoverEnter = false;
	//======================= 초기화중 ========================

	return S_OK;
}

void playerDeath::release()
{
}

void playerDeath::update(float playerx, float playery ,int Scene)
{

	if (savexy == false)
	{
		_playerx = playerx;
		_playery = playery;
		_saveScene = Scene;
		savexy = true;
	}
	if (Scene1 == false)
	{
		playerheart = RectMakeCenter(_playerx, _playery, 50, 50);
	}
	count++;
	if (count == 50)
	{
		_playerheart->SetFrameX(2);

		//첫셋팅
		_crackheart1->SetFrameX(0);//0번동작부터
		_crackheart1->SetFrameY(0);
		_crackheart2->SetFrameX(2);//2번동작부터
		_crackheart2->SetFrameY(0);
	}
	if (count == 100)
	{
		if (Scene1 == false)
		{
			//첫생성
			crackheart1 = RectMakeCenter(_playerx - 25, _playery, 25, 25);
			crackheart2 = RectMakeCenter(_playerx + 25, _playery, 25, 25);

			h1x = _playerx - 25;
			h1y = _playery;
			h2x = _playerx + 25;
			h2y = _playery;
			angle1 = 3*(PI / 4); //오른쪽대각선
			angle2 = PI/4; //왼쪽대각선
			speed = 3.0f;

			Scene1 = true;
		}
	}
	if (Scene1 == true)
	{
		playerheart = RectMakeCenter(1000, 1000, 50, 50);
		gravity+= 0.07;
		crackheart1 = RectMakeCenter(h1x, h1y, 25, 25);
		crackheart2 = RectMakeCenter(h2x, h2y, 25, 25);

		h1x = h1x + cosf(angle1)*speed;
		h1y = h1y - sinf(angle1)*speed + gravity;
		h2x = h2x + cosf(angle2)*speed;
		h2y = h2y - sinf(angle2)*speed + gravity;
		if (gameoveralpha < 255)
		{
			gameoveralpha++;
			if (gameoveralpha == 255)
			{
				gameoverEnter = true;
			}
		}
	}

	if (gameoverEnter == true)
	{
		pressEnterAlpha += 4;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			gameoverend2 = 1;
		}
	}

	//이미지 렌더
	_imagecount++;
	if (_imagecount % 2 == 0) // 10초마다
	{
		
		if (_imageindex > 4) // index 3보다 크면
		{
			_imageindex = 0; // 일단 이미지 0으로만들고
		}
		_crackheart1->SetFrameX(_imageindex); //이미지입히고

		_imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
	}





}

void playerDeath::render()
{
	Rectangle(getMemDC(), playerheart);
	IMAGEMANAGER->findImage("백그라운드")->render(getMemDC(),backgroundd.left,backgroundd.top); // 검은색화면 
	
	
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
		Rectangle(getMemDC(),playerheart);
		Rectangle(getMemDC(),crackheart1);
		Rectangle(getMemDC(),crackheart2);
		Rectangle(getMemDC(),gameover);
		Rectangle(getMemDC(),pressEnter);
	}
	
	
	IMAGEMANAGER->findImage("심장")->frameRender(getMemDC(),playerheart.left,playerheart.top);
	
	IMAGEMANAGER->findImage("심장1")->frameRender(getMemDC(), crackheart1.left, crackheart1.top);
	IMAGEMANAGER->findImage("심장1")->frameRender(getMemDC(), crackheart2.left, crackheart2.top);
	//Rectangle(getMemDC(),crackheart1);
	//Rectangle(getMemDC(),crackheart2);
	//Rectangle(getMemDC(),gameover);
	gameover = RectMakeCenter(WINSIZEX/2, WINSIZEY/2-150, 600,300);

	IMAGEMANAGER->findImage("게임오버")->alphaRender(getMemDC(),gameover.left,gameover.top, gameoveralpha);
	IMAGEMANAGER->findImage("pressEnter")->alphaRender(getMemDC(), pressEnter.left, pressEnter.top, pressEnterAlpha);
	//sprintf_s(str, "%d  %f", gameoverend2, gameoveralpha);
	//TextOut(getMemDC(), 200, 200, str, strlen(str));
}
