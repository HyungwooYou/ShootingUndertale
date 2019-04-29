#include "stdafx.h"
#include "player.h"
#include "Stage1.h" // 상호참조할녀석
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
	//플레이어 살아있음
	playerlive = 1;
	//플레이어 기본 알파값
	playeralpha = 255;
	//플레이어 체력
	hp = 100;

	IMAGEMANAGER->addImage("플레이어빨간바", "frontbar.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어초록바", "bottombar.bmp", 200, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hp폰트", "hp.bmp", 60, 28, true, RGB(255, 0, 255));
	//플레이어 기본위치
	x = WINSIZEX / 2 - 500;
	y = WINSIZEY / 2;

	//플레이어바
	playerbar = RectMake(0, WINSIZEY - 200, WINSIZEX, 200);
	IMAGEMANAGER->addImage("플레이어바", "playerbar.bmp", WINSIZEX, 200, true, RGB(255, 0, 255));

	camerax = WINSIZEX / 2;
	cameray = WINSIZEY / 2;

	//플레이어 오른쪽이동중
	playerstate = PLAYER_STATE_IDLE_RIGHT;

	//플레이어 이미지 생성
	image0 = IMAGEMANAGER->addFrameImage("플레이어대기상태", "playeridle.bmp", 240, 80,4,1, true, RGB(255, 0, 255));
	image0->setAlpahBlend(true,255);
	
	//프레임 이미지
	image1 = IMAGEMANAGER->addFrameImage("아래로움직임", "movedown.bmp", 240, 80, 4, 1, true, RGB(255, 0, 255));
	image1->setAlpahBlend(true, 255);
	image1->SetFrameX(0);
	image1->SetFrameY(0);

	image2 = IMAGEMANAGER->addFrameImage("위로움직임", "moveup.bmp", 240, 80, 4, 1, true, RGB(255, 0, 255));
	image2->setAlpahBlend(true, 255);
	image2->SetFrameX(0);
	image2->SetFrameY(0);

	image3 = IMAGEMANAGER->addFrameImage("왼쪽으로움직임", "moveleft.bmp", 120, 80, 2, 1, true, RGB(255, 0, 255));
	image3->setAlpahBlend(true, 255);
	image3->SetFrameX(0);
	image3->SetFrameY(0);

	image4 = IMAGEMANAGER->addFrameImage("오른쪽으로움직임", "moveright.bmp", 120, 80, 2, 1, true, RGB(255, 0, 255));
	image4->setAlpahBlend(true, 255);
	image4->SetFrameX(0);
	image4->SetFrameY(0);

	_playerBullet = new playerBullet;
	_playerBullet->init(50);


	//스테이지1클리어하면 대사를 뱉는다.
	clearfontimage = IMAGEMANAGER->addImage("플레이어stage1클리어","playerstage1clear.bmp",385,55,true,RGB(255,0,255));
	clearfont = RectMake(500, 600, 385, 55);
	_imageindex2 = 0;
	clearfonton = false;
	imageend = false;

	//파워아이템
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

	IMAGEMANAGER->addImage("아이템1", "item1.bmp", 50, 50, true, RGB(255, 0, 255));
	
	//실드아이템
	shildcount = 0;
	_imageshild = IMAGEMANAGER->addFrameImage("쉴드", "shildsprite.bmp", 500, 100, 5, 1, true, RGB(255, 0, 255));
	_imageshild->SetFrameX(0);
	_imageshild->SetFrameY(0);
	_imageshildindex = 0;
	_imageshildcount = 0;

	//소지아이템
	IMAGEMANAGER->addImage("가지고있는아이템1", "haveitem1.bmp", 240, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("가지고있는아이템2", "haveitem2.bmp", 240, 80, true, RGB(255, 0, 255));

	return S_OK;
}

void player::release()
{
}

void player::update(int goLR)
{
	//플레이어 살아있으면 움직일수있음.
	if (playerlive == 1)
	{
		playerMove(); // 플레이어 움직임
	}

	_imagecount++;
	_imageshildcount++;

	if (_imageshildcount % 10 == 0) // 10초마다
	{
		if (_imageshildindex > 4) // index 3보다 크면
		{
			_imageshildindex = 0; // 일단 이미지 0으로만들고
		}
		_imageshild->SetFrameX(_imageshildindex); //이미지입히고

		_imageshildindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		
	}


	//아래로 움직임
	if (_imagecount % 10 == 0) // 10초마다
	{
		if (playerstate == PLAYER_STATE_MOVE_DOWN) //상태이면
		{
			if (_imageindex > 3) // index 3보다 크면
			{
				_imageindex = 0; // 일단 이미지 0으로만들고
			}
			image1->SetFrameX(_imageindex); //이미지입히고

			_imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		}
	}

	//아래로 움직임
	if (_imagecount % 10 == 0) // 10초마다
	{
		if (playerstate == PLAYER_STATE_MOVE_UP) //상태이면
		{
			if (_imageindex > 3) // index 3보다 크면
			{
				_imageindex = 0; // 일단 이미지 0으로만들고
			}
			image2->SetFrameX(_imageindex); //이미지입히고

			_imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		}
	}

	//왼쪽으로 움직임
	if (_imagecount % 10 == 0) // 10초마다
	{
		if (playerstate == PLAYER_STATE_MOVE_LEFT) //상태이면
		{
			if (_imageindex > 1) // index 3보다 크면
			{
				_imageindex = 0; // 일단 이미지 0으로만들고
			}
			image3->SetFrameX(_imageindex); //이미지입히고

			_imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		}
	}

	//오른쪽으로 움직임
	if (_imagecount % 10 == 0) // 10초마다
	{
		if (playerstate == PLAYER_STATE_MOVE_RIGHT) //상태이면
		{
			if (_imageindex > 1) // index 3보다 크면
			{
				_imageindex = 0; // 일단 이미지 0으로만들고
			}
			image4->SetFrameX(_imageindex); //이미지입히고

			_imageindex++; //다음 이미지를쓰기위해 인덱스를 늘린다.
		}
	}

	

	//플레이어 총알
	_playerBullet->update(goLR);

	//스테이지1클리어하면 대사를 뱉는다.
	stage1cleartalk();

	//파워아이템
	playeritem1();

	//실드아이템
	player2item2();

	if (hp < 0)
	{
		hp++;
	}

}

void player::render()
{
	//플레이어 바 이미지
	IMAGEMANAGER->findImage("플레이어바")->render(getMemDC(), playerbar.left, playerbar.top);
	
	//Rectangle(getMemDC(), camera);
	//Rectangle(getMemDC(), rc);
	//Rectangle(getMemDC(), playerbar);
	//sprintf_s(str, "실드횟수 :%d",shildcount);
	//TextOut(getMemDC(), WINSIZEX/2, 100, str, strlen(str));
	


	// ======================= 플레이어 상태에따른 이미지 ==============


	if (playerstate == PLAYER_STATE_IDLE_RIGHT)
	{
		IMAGEMANAGER->findImage("플레이어대기상태")->alphaFrameRender(getMemDC(),rc.left,rc.top,0,0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_LEFT)
	{
		IMAGEMANAGER->findImage("플레이어대기상태")->alphaFrameRender(getMemDC(), rc.left, rc.top, 1, 0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_UP)
	{
		IMAGEMANAGER->findImage("플레이어대기상태")->alphaFrameRender(getMemDC(), rc.left, rc.top, 2, 0, playeralpha);
	}
	if (playerstate == PLAYER_STATE_IDLE_DOWN)
	{
		IMAGEMANAGER->findImage("플레이어대기상태")->alphaFrameRender(getMemDC(), rc.left, rc.top, 3, 0, playeralpha);
	}


	if (playerstate == PLAYER_STATE_MOVE_DOWN)
	{
		IMAGEMANAGER->findImage("아래로움직임")->alphaFrameRender(getMemDC(),rc.left,rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_UP)
	{
		IMAGEMANAGER->findImage("위로움직임")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_LEFT)
	{
		IMAGEMANAGER->findImage("왼쪽으로움직임")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}
	if (playerstate == PLAYER_STATE_MOVE_RIGHT)
	{
		IMAGEMANAGER->findImage("오른쪽으로움직임")->alphaFrameRender(getMemDC(), rc.left, rc.top, playeralpha);
	}


	//플레이어 체력바
	playerHPbar1 = RectMake(PLAYER_HP_BAR_X, PLAYER_HP_BAR_Y, 200, 50);
	playerHPbar2 = RectMake(PLAYER_HP_BAR_X, PLAYER_HP_BAR_Y, 200, 50);
	hpfont = RectMake(playerHPbar1.left - 80,playerHPbar1.top+12,60,28);

	IMAGEMANAGER->findImage("플레이어빨간바")->render(getMemDC(), playerHPbar1.left, playerHPbar1.top);
	IMAGEMANAGER->findImage("플레이어초록바")->render(getMemDC(), playerHPbar2.left, playerHPbar2.top,0,0,hp*2,50);
	IMAGEMANAGER->findImage("hp폰트")->render(getMemDC(), hpfont.left, hpfont.top);
	//Rectangle(getMemDC(), hpfont);
	//플레이어 총알
	_playerBullet->render();

	//스테이지 클리어 카메라
	//Rectangle(getMemDC(), clearfont);

	//스테이지1클리어하면 대사를 뱉는다.
	IMAGEMANAGER->findImage("플레이어stage1클리어")->render(getMemDC(), clearfont.left, clearfont.top,0,0, _imageindex2,55);

	//파워아이템
	if (player1item == 1)
	{
		//가지고있는아이템1
		//가지고있는아이템2
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item1.left, item1.top);
		//Rectangle(getMemDC(), item1);
		IMAGEMANAGER->findImage("가지고있는아이템1")->render(getMemDC(), haveitem1.left, haveitem1.top,0,0,80,80);
	}
	else if (player1item == 2)
	{
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item1.left, item1.top);
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item2.left, item2.top);
		IMAGEMANAGER->findImage("가지고있는아이템1")->render(getMemDC(), haveitem1.left, haveitem1.top, 0, 0, 160, 80);
		//Rectangle(getMemDC(), item1);
		//Rectangle(getMemDC(), item2);
	}
	else if (player1item == 3)
	{
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item1.left, item1.top);
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item2.left, item2.top);
		IMAGEMANAGER->findImage("아이템1")->render(getMemDC(), item3.left, item3.top);
		IMAGEMANAGER->findImage("가지고있는아이템1")->render(getMemDC(), haveitem1.left, haveitem1.top, 0, 0, 240, 80);
		//Rectangle(getMemDC(), item1);
		//Rectangle(getMemDC(), item2);
		//Rectangle(getMemDC(), item3);
	}

	if (shildcount > 0)
	{
		if (shildcount == 1)
		{
			IMAGEMANAGER->findImage("가지고있는아이템2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 80, 80);
		}
		else if (shildcount == 2)
		{
			IMAGEMANAGER->findImage("가지고있는아이템2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 160, 80);
		}
		else if (shildcount == 3)
		{
			IMAGEMANAGER->findImage("가지고있는아이템2")->render(getMemDC(), haveitem2.left, haveitem2.top, 0, 0, 240, 80);
		}
		IMAGEMANAGER->findImage("쉴드")->frameRender(getMemDC(), shild.left, shild.top);
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


//============================== 각종 함수들 ==============================
//플레이어 키입력관련
void player::playerMove()
{
		rc = RectMakeCenter(x, y, PLAYER_SIZE_X, PLAYER_SIZE_Y);
		camera = RectMakeCenter(camerax, cameray, 400, 768);

		if (playerstop == false)
		{
			//위쪽
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				if (y > PLAYER_SIZE_Y/2)
				{
					playerstate = PLAYER_STATE_MOVE_UP; //가만히잇는다
					y -= PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				playerstate = PLAYER_STATE_IDLE_UP; //움직인다.
			}

			//아래쪽
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				if (y < WINSIZEY/2+143)
				{
					playerstate = PLAYER_STATE_MOVE_DOWN; //가만히잇는다
					y += PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				playerstate = PLAYER_STATE_IDLE_DOWN; //움직인다.
			}

			//왼쪽
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				if (x > PLAYER_SIZE_X/2)
				{
					playerstate = PLAYER_STATE_MOVE_LEFT; //가만히잇는다
					x -= PLAYER_SPEED;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				playerstate = PLAYER_STATE_IDLE_LEFT; //움직인다.
			}


			//오른쪽 (스테이지2일때 수정필요)!!!!!!!!!!!!!!!
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				//stage1 1일때
				if (x < WINSIZEX - PLAYER_SIZE_X / 2)
				{
					if (x < 1250)
					{
						playerstate = PLAYER_STATE_MOVE_RIGHT; //가만히잇는다
						x += PLAYER_SPEED;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				playerstate = PLAYER_STATE_IDLE_RIGHT; //움직인다.
			}



			//총알누루면 총알나감
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

			//파워아이템
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



			//파워아이템 실험용 
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

//스테이지1클리어하면 대사를 뱉는다.
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

//파워아이템
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

