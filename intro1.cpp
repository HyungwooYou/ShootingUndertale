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
	//==================================== �⺻��� ===================================
	//�⺻ ���ȭ�� ����
	IMAGEMANAGER->addImage("��׶���", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));


	//==================================== undertaleLogo ===================================
	//������� �⺻�ΰ�
	undertaleLoge = IMAGEMANAGER->addImage("������Ϸΰ�", "undertaleLogo.bmp", 902, 61, true, RGB(255, 0, 255));
	undertaleLoge->setAlpahBlend(true, 255);
	//�ΰ���ġ ���� �ӽ�RECT
	undertaleLogoRECT = RectMakeCenter(WINSIZEX / 2, LOGO_LOCATION_Y, 902, 61);

	undertaleLogoAlpha = 0; // �ΰ� ó�����İ�

	//==================================== pressEnter ===================================
	_pressEnter = IMAGEMANAGER->addImage("pressEnter", "pressEnter.bmp", 344, 16, true, RGB(255, 0, 255));
	_pressEnter->setAlpahBlend(true,255);
	//pressEnter �ӽ�RECT
	pressEnter = RectMakeCenter(WINSIZEX / 2, PRESS_LOCATION_Y, 344, 16);
	pressEnterAlpha = 0; // pressEnter ó�����İ�
	return S_OK;
}

void intro1::release()
{
}

void intro1::update()
{
	Logo(); // �ΰ� ���İ��� ��ȭ�ؼ� �������
	pressEnterG(); // pressEnter�� ���������� ���ڰŷ���
}

void intro1::render()
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
		Rectangle(getMemDC(), undertaleLogoRECT);
		Rectangle(getMemDC(), pressEnter);
	}

	//==================================== undertaleLogo ===================================
	//������� �ΰ�
	IMAGEMANAGER->findImage("������Ϸΰ�")->alphaRender(getMemDC(), undertaleLogoRECT.left, undertaleLogoRECT.top, undertaleLogoAlpha);
	//Rectangle(getMemDC(),undertaleLogoRECT); //�ΰ��� ��� �ӽ�RECT

	//==================================== pressEnter ===================================
	//Rectangle(getMemDC(),pressEnter); //pressEnterȮ�ο�
	IMAGEMANAGER->findImage("pressEnter")->alphaRender(getMemDC(), pressEnter.left, pressEnter.top, pressEnterAlpha);
	//sprintf_s(str, "%f", undertaleLogoAlpha);
	//TextOut(getMemDC(), 100, 100, str, strlen(str));
}

void intro1::Logo()
{
	//ó���� �Ⱥ����ٰ� ������ Ű�� �ΰ� ���ķ������� �����þ
	if (undertaleLogoAlpha < 255)
	{
		undertaleLogoAlpha++;
	}
}

void intro1::pressEnterG()
{
	//pressEnter �׸��� ��� ���ڰŸ�
	pressEnterAlpha += PRESS_ENTER_BLINK_SPEED;
}
