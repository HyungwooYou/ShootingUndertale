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
	//==================================== �⺻��� ===================================
	//�⺻ ���ȭ�� ����
	IMAGEMANAGER->addImage("��׶���", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//ù�� ����
	sceneChange = STATR_SCENE;
	//==================================== ȭ��1 ===================================
	//�׸�
	image1 = IMAGEMANAGER->addImage("ȭ��1", "image1.bmp", 600, 300, true, RGB(255, 0, 255));
	image1->setAlpahBlend(true, 255);
	image1RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image1Alpha = 0;
	//����
	image1font1 = IMAGEMANAGER->addImage("ȭ��1��Ʈ", "image1font.bmp", 600, 150, true, RGB(255, 0, 255));
	image1font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image1font1->setAlpahBlend(true, 255);
	image1fontAlpha = 0;

	count1 = 0;

	//==================================== ȭ��2 ===================================
	//�׸�
	image2 = IMAGEMANAGER->addImage("ȭ��2", "image2.bmp", 600, 300, true, RGB(255, 0, 255));
	image2RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image2->setAlpahBlend(true, 255);
	image2Alpha = 0;
	//����
	image2font1 = IMAGEMANAGER->addImage("ȭ��2��Ʈ", "image2font.bmp", 600, 150, true, RGB(255, 0, 255));
	image2font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image2font1->setAlpahBlend(true, 255);
	image2fontAlpha = 0;

	count2 = 0;

	//==================================== ȭ��3 ===================================
	//�׸�
	image3 = IMAGEMANAGER->addImage("ȭ��3", "image3.bmp", 600, 300, true, RGB(255, 0, 255));
	image3RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image3->setAlpahBlend(true, 255);
	image3Alpha = 0;
	//����
	image3font1 = IMAGEMANAGER->addImage("ȭ��3��Ʈ", "image3font.bmp", 600, 150, true, RGB(255, 0, 255));
	image3font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image3font1->setAlpahBlend(true, 255);
	image3fontAlpha = 0;

	count3 = 0;

	//==================================== ȭ��4 ===================================
	//����
	image4font1 = IMAGEMANAGER->addImage("ȭ��4��Ʈ", "image4font.bmp", 600, 225, true, RGB(255, 0, 255));
	image4font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 600, 225);
	image4font1->setAlpahBlend(true, 255);
	image4fontAlpha = 0;

	count4 = 0;

	//==================================== ȭ��5 ===================================
	//����
	image5font1 = IMAGEMANAGER->addImage("ȭ��5��Ʈ", "image5font.bmp", 600, 150, true, RGB(255, 0, 255));
	image5font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image5font1->setAlpahBlend(true, 255);
	image5fontAlpha = 0;

	image5font2 = IMAGEMANAGER->addImage("ȭ��5��Ʈ2", "image5font2.bmp", 100, 150, true, RGB(255, 0, 255));
	image5font3 = RectMakeCenter(image5font.right - 200, WINSIZEY - 200, 100, 150);

	count5 = 0;

	countIndex = 0;
	//==================================== ȭ��6 ===================================
	//�׸�
	image6 = IMAGEMANAGER->addImage("ȭ��6", "image6.bmp", 600, 300, true, RGB(255, 0, 255));
	image6RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image6->setAlpahBlend(true, 255);
	image6Alpha = 0;
	//����
	image6font1 = IMAGEMANAGER->addImage("ȭ��6��Ʈ", "image6font.bmp", 600, 150, true, RGB(255, 0, 255));
	image6font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 200, 600, 150);
	image6font1->setAlpahBlend(true, 255);
	image6fontAlpha = 0;

	count6 = 0;

	//==================================== ȭ��7 ===================================
	//�׸�
	image7 = IMAGEMANAGER->addImage("ȭ��7", "image7.bmp", 600, 300, true, RGB(255, 0, 255));
	image7RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image7->setAlpahBlend(true, 255);
	image7Alpha = 0;
	//����
	image7font1 = IMAGEMANAGER->addImage("ȭ��7��Ʈ", "image7font.bmp", 600, 225, true, RGB(255, 0, 255));
	image7font = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 600, 255);
	image7font1->setAlpahBlend(true, 255);
	image7fontAlpha = 0;

	count7 = 0;

	//==================================== ȭ��8 ===================================
	//�׸�
	image8 = IMAGEMANAGER->addImage("ȭ��8", "image8.bmp", 600, 300, true, RGB(255, 0, 255));
	image8RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image8->setAlpahBlend(true, 255);
	image8Alpha = 0;

	count8 = 0;

	//==================================== ȭ��9 ===================================
	//�׸�
	image9 = IMAGEMANAGER->addImage("ȭ��9", "image9.bmp", 600, 300, true, RGB(255, 0, 255));
	image9RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image9->setAlpahBlend(true, 255);
	image9Alpha = 0;

	count9 = 0;

	//==================================== ȭ��10 ===================================
	//�׸�
	image10 = IMAGEMANAGER->addImage("ȭ��10", "image10.bmp", 600, 300, true, RGB(255, 0, 255));
	image10RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image10->setAlpahBlend(true, 255);
	image10Alpha = 0;

	count10 = 0;

	//==================================== ȭ��11 ===================================
	//�׸�
	image11 = IMAGEMANAGER->addImage("ȭ��11", "image11.bmp", 600, 900, true, RGB(255, 0, 255));
	image11RECT = RectMakeCenter(WINSIZEX / 2, 300, 600, 300);
	image11->setAlpahBlend(true, 255);
	image11Alpha = 0;

	count11 = 0;
	imageindex11 = 0;

	//==================================== pressEnter ===================================
	IMAGEMANAGER->addImage("pressEnter", "pressEnter.bmp", 344, 16, true, RGB(255, 0, 255));
	//pressEnter �ӽ�RECT
	pressEnter = RectMakeCenter(PRESS_LOCATION_X2, PRESS_LOCATION_Y2, 344, 16);
	pressEnterAlpha = 0; // pressEnter ó�����İ�


	return S_OK;
}

void intro2::release()
{
}

void intro2::update()
{
	//�����
	imageAtoZ();
	pressEnterG2();

}

void intro2::render()
{
	//==================================== �⺻��� ===================================
	//�⺻ ����̹��� ����
	IMAGEMANAGER->findImage("��׶���")->render(getMemDC()); // ������ȭ�� 

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

	//=================================== �̹���1�� �� ================================
	if (sceneChange == SCENE1)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��1")->alphaRender(getMemDC(), image1RECT.left, image1RECT.top, image1Alpha);

		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��1��Ʈ")->alphaRender(getMemDC(), image1font.left, image1font.top, image1fontAlpha);
	}

	//=================================== �̹���2�� �� ================================
	if (sceneChange == SCENE2)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��2")->alphaRender(getMemDC(), image2RECT.left, image2RECT.top, image2Alpha);

		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��2��Ʈ")->alphaRender(getMemDC(), image2font.left, image2font.top, image2fontAlpha);
	}

	//=================================== �̹���3�� �� ================================
	if (sceneChange == SCENE3 || sceneChange == SCENE4)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��3")->alphaRender(getMemDC(), image3RECT.left, image3RECT.top, image3Alpha);
	}
	if (sceneChange == SCENE3)
	{
		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��3��Ʈ")->alphaRender(getMemDC(), image3font.left, image3font.top, image3fontAlpha);
	}

	//=================================== �̹���4�� �� ================================
	if (sceneChange == SCENE4)
	{
		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��4��Ʈ")->alphaRender(getMemDC(), image4font.left, image4font.top, image4fontAlpha);
	}

	//=================================== �̹���5�� �� ================================
	if (sceneChange == SCENE5)
	{
		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��5��Ʈ")->alphaRender(getMemDC(), image5font.left, image5font.top, image5fontAlpha);


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
		IMAGEMANAGER->findImage("ȭ��5��Ʈ2")->render(getMemDC(), image5font3.left, image5font3.top, 0, 0, 30 * countIndex, 150);
		//Rectangle(getMemDC(),image5font3);
	}

	//=================================== �̹���6�� �� ================================
	if (sceneChange == SCENE6)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��6")->alphaRender(getMemDC(), image6RECT.left, image6RECT.top, image6Alpha);

		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��6��Ʈ")->alphaRender(getMemDC(), image6font.left, image6font.top, image6fontAlpha);
	}

	//=================================== �̹���7�� �� ================================
	if (sceneChange == SCENE7)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��7")->alphaRender(getMemDC(), image7RECT.left, image7RECT.top, image7Alpha);

		//����
		//Rectangle(getMemDC(),image1font);
		IMAGEMANAGER->findImage("ȭ��7��Ʈ")->alphaRender(getMemDC(), image7font.left, image7font.top, image7fontAlpha);
	}

	//=================================== �̹���8�� �� ================================
	if (sceneChange == SCENE8)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��8")->alphaRender(getMemDC(), image8RECT.left, image8RECT.top, image8Alpha);
	}

	//=================================== �̹���9�� �� ================================
	if (sceneChange == SCENE9)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��9")->alphaRender(getMemDC(), image9RECT.left, image9RECT.top, image9Alpha);
	}

	//=================================== �̹���10�� �� ================================
	if (sceneChange == SCENE10)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��10")->alphaRender(getMemDC(), image10RECT.left, image10RECT.top, image10Alpha);
	}

	//=================================== �̹���11�� �� ================================
	if (sceneChange == SCENE11)
	{
		//�׸�
		//Rectangle(getMemDC(),image1RECT);
		IMAGEMANAGER->findImage("ȭ��11")->render(getMemDC(), image11RECT.left, image11RECT.top, 0, imageindex11, 600, 300);
	}

	//==================================== pressEnter ===================================
	//Rectangle(getMemDC(),pressEnter); //pressEnterȮ�ο�
	IMAGEMANAGER->findImage("pressEnter")->alphaRender(getMemDC(), pressEnter.left, pressEnter.top, pressEnterAlpha);

	//ġƮŰ���
	//sprintf_s(str, "%d", sceneChange);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));

}

//��Ʈ�� ����
void intro2::imageAtoZ()
{
	//================== 1��°��� ==================
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
		if (image1fontAlpha == 255) // 255�ȼ�������
		{
			count1++;
		}
		if (count1 > SCENE_COUNT) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = SCENE2;
		}
	}


	//================== 2��°��� ==================
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
		if (image2fontAlpha == 255) // 255�ȼ�������
		{
			count2++;
		}
		if (count2 > SCENE_COUNT) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 3;
		}
	}


	//================== 3��°��� ==================
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
		if (image3fontAlpha == 255) // 255�ȼ�������
		{
			count3++;
		}
		if (count3 > SCENE_COUNT) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 4;
		}
	}


	//================== 4��°��� ==================
	if (sceneChange == SCENE4)
	{
		if (image4fontAlpha < 255)
		{
			image4fontAlpha++;
		}
		if (image4fontAlpha == 255) // 255�ȼ�������
		{
			count4++;
		}
		if (count4 > SCNEN_COUNT_2) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 5;
		}
	}


	//================== 5��°��� ==================
	if (sceneChange == SCENE5)
	{
		if (image5fontAlpha < 255)
		{
			image5fontAlpha++;
		}
		if (image5fontAlpha == 255) // 255�ȼ�������
		{
			count5point++;

		}
		if (count5 > SCNEN_COUNT_2) // 200������ �Ѿ�� ������ ������
		{

			//sceneChange = 6;
		}
	}

	//================== 6��°��� ==================
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
		if (image6fontAlpha == 255) // 255�ȼ�������
		{
			count6++;
		}
		if (count6 > SCENE_COUNT) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 7;
		}
	}

	//================== 7��°��� ==================
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
		if (image7fontAlpha == 255) // 255�ȼ�������
		{
			count7++;
		}
		if (count7 > SCENE_COUNT) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 8;
		}
	}

	//================== 8��°��� ==================
	if (sceneChange == SCENE8)
	{
		if (image8Alpha < 255)
		{
			image8Alpha++;
		}
		if (image8Alpha == 255) // 255�ȼ�������
		{
			count8++;
		}
		if (count8 > SCNEN_COUNT_2) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 9;
		}
	}

	//================== 9��°��� ==================
	if (sceneChange == SCENE9)
	{
		if (image9Alpha < 255)
		{
			image9Alpha++;
		}
		if (image9Alpha == 255) // 255�ȼ�������
		{
			count9++;
		}
		if (count9 > SCNEN_COUNT_2) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 10;
		}
	}

	//================== 10��°��� ==================
	if (sceneChange == SCENE10)
	{
		if (image10Alpha < 255)
		{
			image10Alpha++;
		}
		if (image10Alpha == 255) // 255�ȼ�������
		{
			count10++;
		}
		if (count10 > SCNEN_COUNT_2) // 200������ �Ѿ�� ������ ������
		{
			sceneChange = 11;
		}
	}

	//================== 11��°��� ==================
	if (sceneChange == SCENE11)
	{
		if (image11Alpha < 255)
		{
			image11Alpha++;
		}
		if (image11Alpha > 100) // 255�ȼ�������
		{
			count11++;
		}
		if (count11 > SCNEN_COUNT_3) // 200������ �Ѿ�� ������ ������
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
