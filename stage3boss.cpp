#include "stdafx.h"
#include "stage3boss.h"


stage3boss::stage3boss()
{

}


stage3boss::~stage3boss()
{

}

HRESULT stage3boss::init()
{
	IMAGEMANAGER->addImage("��������3", "stage3.bmp", 1280, 768, true, RGB(255, 0, 255));

	//�÷��̾� �浹ó��
	//����
	stage3hill1 = RectMake(0,0,180,240);
	stage3hill2 = RectMake(stage3hill1.right, 0, 10, 230);
	stage3hill3 = RectMake(stage3hill2.right, 0, 520, 50);
	stage3hill4 = RectMake(stage3hill3.right, 0, 10, 230);
	stage3hill5 = RectMake(stage3hill4.right, stage3hill4.bottom, 10, 10);
	stage3hill6 = RectMake(stage3hill5.right, stage3hill5.bottom, 700, 10);

	//�Ʒ���
	stage3hill7 = RectMake(stage3hill5.right+30, stage3hill5.bottom+200, 700, 10);
	stage3hill8 = RectMake(stage3hill7.left-10, stage3hill7.bottom, 10, 10);
	stage3hill9 = RectMake(stage3hill8.left - 10, stage3hill8.bottom, 10, 10);
	stage3hill10 = RectMake(stage3hill9.left - 10, stage3hill9.bottom, 10, 10);
	stage3hill11 = RectMake(stage3hill10.left - 10, stage3hill10.bottom, 10, 10);
	stage3hill12 = RectMake(stage3hill11.left - 10, stage3hill11.bottom, 10, 10);
	stage3hill13 = RectMake(stage3hill12.left - 10, stage3hill12.bottom, 10, 10);
	stage3hill14 = RectMake(stage3hill13.left - 10, stage3hill13.bottom, 10, 10);
	stage3hill15 = RectMake(stage3hill14.left - 10, stage3hill14.bottom, 10, 10);
	stage3hill16 = RectMake(stage3hill15.left - 10, stage3hill15.bottom, 10, 10);
	stage3hill17 = RectMake(stage3hill16.left - 10, stage3hill16.bottom, 10, 10);

	stage3hill18 = RectMake(stage3hill17.left - 470, stage3hill17.bottom, 470, 10);
	stage3hill19 = RectMake(stage3hill18.left-10, stage3hill18.bottom-150, 10, 150);
	stage3hill20 = RectMake(stage3hill19.left - 200, stage3hill19.top-10, 200, 10);

	stage3hill21 = RectMake(-10,0, 10, 768);

	undyne1x = WINSIZEX + 50;
	babymonster = RectMakeCenter(WINSIZEX/2,WINSIZEY/2-50, 60,80);
	undyne1 = RectMakeCenter(undyne1x, WINSIZEY / 2 - 50, 80, 100);

	stage3scene = RectMakeCenter(WINSIZEX / 2, 200, 730, 300);
	stage3scene2fontrc = RectMake(stage3scene.left + 50, stage3scene.top, 200, 120);
	undynetalk = RectMake(stage3scene.right - 250, stage3scene.top, 300, 300);

	monsterkidx = stage3scene.left;
	monsterkidy = stage3scene.top;

	monsterkid = RectMake(monsterkidx, monsterkidy, 730, 300);

	IMAGEMANAGER->addImage("Ű��", "monsterbaby.bmp", 60, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���̺�����", "saveundyne.bmp", 100, 120, true, RGB(255, 0, 255));

	//ȭ�� ��ȯȿ��
	whiteout = IMAGEMANAGER->addImage("ȭ��Ʈ�ƿ�", "whiteout.bmp", 1280, 768, true, RGB(255, 0, 255));
	
	whiteoutalpha = 0;
	whiteout->setAlpahBlend(true, whiteoutalpha);


	blackout = IMAGEMANAGER->addImage("���ƿ�", "background.bmp", 1280, 768, true, RGB(255, 0, 255));
	blackoutalpha = 0;
	blackout->setAlpahBlend(true, blackoutalpha);

	//�� �̹��� ����
	stage3scene1 = IMAGEMANAGER->addImage("��1", "stage3scene1.bmp", 730, 300, true, RGB(255, 0, 255));
	stage3scene1alpha = 0;
	stage3scene1->setAlpahBlend(true, stage3scene1alpha);

	//��2
	stage3scene2 = IMAGEMANAGER->addImage("��2", "stage3scene2.bmp", 730, 300, true, RGB(255, 0, 255));
	
	//��2��Ʈ
	stage3fontscene2 = IMAGEMANAGER->addImage("��2��Ʈ", "stage3scene2font.bmp", 200, 120, true, RGB(255, 0, 255));
	stage3fontalphascene2 = 0;
	stage3fontscene2->setAlpahBlend(true, stage3fontalphascene2);

	//��3
	IMAGEMANAGER->addImage("��3", "stage3scene3.bmp", 730, 300, true, RGB(255, 0, 255));

	//��3��Ʈ
	scene3font = IMAGEMANAGER->addImage("��3��Ʈ", "stage3scene3font.bmp", 300, 300, true, RGB(255, 0, 255));
	scene3fontalpha = 0;
	scene3font->setAlpahBlend(true, scene3fontalpha);

	//��3��Ʈ2
	scene3font2 = IMAGEMANAGER->addImage("��3��Ʈ2", "stage3scene3font2.bmp", 300, 300, true, RGB(255, 0, 255));
	scene3fontalpha2 = 0;
	scene3font2->setAlpahBlend(true, scene3fontalpha2);

	//��4��Ʈ
	scene4font = IMAGEMANAGER->addImage("��4��Ʈ", "stage3scene4font.bmp", 200, 120, true, RGB(255, 0, 255));
	scene4fontalpha = 0;
	scene4font->setAlpahBlend(true, scene4fontalpha);

	//��5
	IMAGEMANAGER->addImage("��5", "stage3scene5.bmp", 730, 300, true, RGB(255, 0, 255));

	scene5font = IMAGEMANAGER->addImage("��5��Ʈ", "stage3scene5font.bmp", 300, 300, true, RGB(255, 0, 255));
	scene5fontalpha = 0;
	scene5font->setAlpahBlend(true, scene5fontalpha);

	//��6
	scene6font = IMAGEMANAGER->addImage("��6��Ʈ", "stage3scene5font2.bmp", 300, 300, true, RGB(255, 0, 255));
	scene6fontalpha = 0;
	scene6font->setAlpahBlend(true, scene6fontalpha);

	//��7
	IMAGEMANAGER->addImage("���̹���", "nonimage.bmp", 730, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��7", "stage3scene7.bmp", 730, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������Ű��", "stage3scene7kid.bmp", 730, 300, true, RGB(255, 0, 255));

	//��8
	scene8 = IMAGEMANAGER->addImage("��8", "stage3scene8.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene8alpha = 255;
	scene8->setAlpahBlend(true, scene8alpha);

	scene8font = IMAGEMANAGER->addImage("��8��Ʈ", "stage3scene8font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene8alphafont = 0;
	scene8font->setAlpahBlend(true, scene8alphafont);

	//��9
	scene9 = IMAGEMANAGER->addImage("��9", "stage3scene9.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene9alpha = 255;
	scene9->setAlpahBlend(true, scene9alpha);

	scene9font = IMAGEMANAGER->addImage("��9��Ʈ", "stage3scene9font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene9alphafont = 0;
	scene9font->setAlpahBlend(true, scene9alphafont);

	//��10
	scene10font = IMAGEMANAGER->addImage("��10��Ʈ", "stage3scene10font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene10alphafont = 0;
	scene10font->setAlpahBlend(true, scene10alphafont);

	//��11
	scene11font = IMAGEMANAGER->addImage("��11��Ʈ", "stage3scene11font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene11alphafont = 0;
	scene11font->setAlpahBlend(true, scene11alphafont);

	//��12
	scene12font = IMAGEMANAGER->addImage("��12��Ʈ", "stage3scene12font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene12alphafont = 0;
	scene12font->setAlpahBlend(true, scene12alphafont);

	//��13
	scene13 = IMAGEMANAGER->addImage("��13", "stage3scene13.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene13alpha = 255;
	scene13->setAlpahBlend(true, scene13alpha);

	scene13font = IMAGEMANAGER->addImage("��13��Ʈ", "stage3scene13font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene13alphafont = 0;
	scene13font->setAlpahBlend(true, scene13alphafont);

	//��14
	scene14font = IMAGEMANAGER->addImage("��14��Ʈ", "stage3scene14font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene14alphafont = 0;
	scene14font->setAlpahBlend(true, scene14alphafont);

	//��15
	scene15font = IMAGEMANAGER->addImage("��15��Ʈ", "stage3scene15font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene15alphafont = 0;
	scene15font->setAlpahBlend(true, scene15alphafont);

	//��16
	scene16 = IMAGEMANAGER->addImage("��16", "stage3scene16.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene16alpha = 255;
	scene16->setAlpahBlend(true, scene16alpha);

	//��17
	scene17 = IMAGEMANAGER->addImage("��17", "stage3scene17.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene17alpha = 255;
	scene17->setAlpahBlend(true, scene13alpha);

	scene17font = IMAGEMANAGER->addImage("��17��Ʈ", "stage3scene17font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene17alphafont = 0;
	scene17font->setAlpahBlend(true, scene17alphafont);

	//��18
	scene18 = IMAGEMANAGER->addImage("��18", "stage3scene18.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene18alpha = 255;
	scene18->setAlpahBlend(true, scene18alpha);

	scene18font = IMAGEMANAGER->addImage("��18��Ʈ", "stage3scene18font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene18alphafont = 0;
	scene18font->setAlpahBlend(true, scene18alphafont);

	//��19
	scene19 = IMAGEMANAGER->addImage("��19", "stage3scene19.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene19alpha = 255;
	scene19->setAlpahBlend(true, scene18alpha);

	scene19font = IMAGEMANAGER->addImage("��19��Ʈ", "stage3scene19font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene19alphafont = 0;
	scene19font->setAlpahBlend(true, scene19alphafont);

	//��20
	scene20font = IMAGEMANAGER->addImage("��20��Ʈ", "stage3scene20font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene20alphafont = 0;
	scene20font->setAlpahBlend(true, scene20alphafont);

	//��21
	scene21font = IMAGEMANAGER->addImage("��21��Ʈ", "stage3scene21font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene21alphafont = 0;
	scene21font->setAlpahBlend(true, scene21alphafont);

	//��22
	scene22font = IMAGEMANAGER->addImage("��22��Ʈ", "stage3scene22font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene22alphafont = 0;
	scene22font->setAlpahBlend(true, scene22alphafont);

	//��23
	scene23 = IMAGEMANAGER->addImage("��23", "stage3scene23.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene23alpha = 255;
	scene23->setAlpahBlend(true, scene23alpha);

	scene23font = IMAGEMANAGER->addImage("��23��Ʈ", "stage3scene23font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene23alphafont = 0;
	scene23font->setAlpahBlend(true, scene23alphafont);

	//��24
	scene24 = IMAGEMANAGER->addImage("��24", "stage3scene24.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene24alpha = 255;
	scene24->setAlpahBlend(true, scene24alpha);

	scene24font = IMAGEMANAGER->addImage("��24��Ʈ", "stage3scene24font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene24alphafont = 0;
	scene24font->setAlpahBlend(true, scene24alphafont);

	//��25
	scene25font = IMAGEMANAGER->addImage("��25��Ʈ", "stage3scene25font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene25alphafont = 0;
	scene25font->setAlpahBlend(true, scene25alphafont);

	//��26
	scene26font = IMAGEMANAGER->addImage("��26��Ʈ", "stage3scene26font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene26alphafont = 0;
	scene26font->setAlpahBlend(true, scene26alphafont);

	//��27
	scene27font = IMAGEMANAGER->addImage("��27��Ʈ", "stage3scene27font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene27alphafont = 0;
	scene27font->setAlpahBlend(true, scene27alphafont);

	//��28
	scene28font = IMAGEMANAGER->addImage("��28��Ʈ", "stage3scene28font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene28alphafont = 0;
	scene28font->setAlpahBlend(true, scene28alphafont);

	//��29
	scene29 = IMAGEMANAGER->addImage("��29", "stage3scene29.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene29alpha = 255;
	scene29->setAlpahBlend(true, scene29alpha);

	scene29font = IMAGEMANAGER->addImage("��29��Ʈ", "stage3scene29font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene29alphafont = 0;
	scene29font->setAlpahBlend(true, scene29alphafont);

	//��30
	scene30font = IMAGEMANAGER->addImage("��30��Ʈ", "stage3scene30font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene30alphafont = 0;
	scene30font->setAlpahBlend(true, scene30alphafont);

	//��31
	scene31 = IMAGEMANAGER->addImage("��31", "stage3scene31.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene31alpha = 255;
	scene31->setAlpahBlend(true, scene31alpha);

	scene31font = IMAGEMANAGER->addImage("��31��Ʈ", "stage3scene31font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene31alphafont = 0;
	scene31font->setAlpahBlend(true, scene31alphafont);

	//��32
	scene32font = IMAGEMANAGER->addImage("��32��Ʈ", "stage3scene32font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene32alphafont = 0;
	scene32font->setAlpahBlend(true, scene32alphafont);

	//��33
	scene33 = IMAGEMANAGER->addImage("��33", "stage3scene33.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene33alpha = 255;
	scene33->setAlpahBlend(true, scene33alpha);

	scene33font = IMAGEMANAGER->addImage("��33��Ʈ", "stage3scene33font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene33alphafont = 0;
	scene33font->setAlpahBlend(true, scene33alphafont);

	//��34
	scene34 = IMAGEMANAGER->addImage("��34", "stage3scene34.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene34alpha = 255;
	scene34->setAlpahBlend(true, scene34alpha);

	scene34font = IMAGEMANAGER->addImage("��34��Ʈ", "stage3scene34font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene34alphafont = 0;
	scene34font->setAlpahBlend(true, scene34alphafont);

	//��35
	scene35 = IMAGEMANAGER->addImage("��35", "stage3scene35.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene35alpha = 255;
	scene35->setAlpahBlend(true, scene35alpha);

	scene35font = IMAGEMANAGER->addImage("��35��Ʈ", "stage3scene35font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene35alphafont = 0;
	scene35font->setAlpahBlend(true, scene35alphafont);

	//��36
	scene36 = IMAGEMANAGER->addImage("��36", "stage3scene36.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene36alpha = 255;
	scene36->setAlpahBlend(true, scene36alpha);

	scene36font = IMAGEMANAGER->addImage("��36��Ʈ", "stage3scene36font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene36alphafont = 0;
	scene36font->setAlpahBlend(true, scene36alphafont);
	return S_OK;
}

void stage3boss::release()
{

}

void stage3boss::update(bool whiteouton)
{
	

	undyne1 = RectMakeCenter(undyne1x, WINSIZEY / 2 - 50, 100, 120);

	//ȭ����ȯȿ�� -> ������
	
	if (lock1 == false)
	{
		if (whiteouton == true)
		{
			if (whiteoutalpha >= 255)
			{
				lock1 = true;
				blackouton = true;
			}
			if (whiteoutalpha < 255)
			{
				whiteoutalpha++;
			}
		}
	}


	//ȭ����ȯȿ�� -> ����ȭ�鿡�� ������
	
	if (lock2 == false)
	{
		if (blackouton == true)
		{
			if (blackoutalpha < 255)
			{
				blackoutalpha++;
				stage3scene1alpha++;
			}
			if (blackoutalpha >= 255)
			{
				blackoutend = true;
				lock2 = true;
			}
		}
	}

	//ȭ����ȯȿ�� -> �ι�°������γѾ
	if (lock3 == false)
	{
		if (blackoutend == true)
		{
			stage3boolscene2 = true;
			stage3scene1fontcount++;
		}
	}

	//�ι�°��� ��Ʈ����
	if (lock4 == false)
	{
		if (stage3scene1fontcount > 50)
		{
			lock3 = true;
			if (scene2fontbool == false)
			{
				if (stage3fontalphascene2 >= 255)
				{
					scene2fontbool = true;
				}
				if (stage3fontalphascene2 < 255)
				{
					stage3fontalphascene2+= CHAT_UP_SPEED;
				}
			}

			if (scene2fontbool == true)
			{
				if (stage3fontalphascene2 > 0)
				{
					stage3fontalphascene2 -= CHAT_DOWN_SPEED;
				}
				if (stage3fontalphascene2 <= 0)
				{
					scene3bool = true;
					lock4 = true;
				}
			}
		}
	}

	if (lock5 == false)
	{
		if (scene3bool == true)
		{
			scene3boolcount++;
		}
	}
	//��3��Ʈ
	if (lock6 == false)
	{
		if (scene3boolcount > 50)
		{
			lock5 = true;
			if (scene3fontalphabool == false)
			{
				if (scene3fontalpha < 255)
				{
					scene3fontalpha += CHAT_UP_SPEED;
				}
				if (scene3fontalpha >= 255)
				{
					scene3fontalphabool = true;
				}
			}
			if (scene3fontalphabool == true)
			{
				if (scene3fontalpha > 0)
				{
					scene3fontalpha -= CHAT_DOWN_SPEED;
				}
				if (scene3fontalpha <= 0)
				{
					scene3fontalphabool2 = true;
					lock6 = true;
				}
			}
		}
	}

	//��3��Ʈ2
	if (lock7 == false)
	{
		if (scene3fontalphabool2 == true)
		{
			if (scene3fontalphabool21 == false)
			{
				if (scene3fontalpha2 < 255)
				{
					scene3fontalpha2 += CHAT_UP_SPEED;
				}
				if (scene3fontalpha2 >= 255)
				{
					scene3fontalphabool21 = true;
				}
			}

			if (scene3fontalphabool21 == true)
			{
				if (scene3fontalpha2 > 0)
				{
					scene3fontalpha2 -= CHAT_DOWN_SPEED;
				}
				if (scene3fontalpha2 <= 0)
				{
					lock7 = true;
					scene4bool = true;
				}
			}
		}
	}

	//��4
	if (lock8 == false)
	{
		if (scene4bool == true)
		{
			if (scene4boo2 == false)
			{
				if (scene4fontalpha < 255)
				{
					scene4fontalpha += CHAT_UP_SPEED;
				}
				if (scene4fontalpha >= 255)
				{
					scene4boo2 = true;
				}
			}

			if (scene4boo2 == true)
			{
				if (scene4fontalpha > 0)
				{
					scene4fontalpha -= CHAT_DOWN_SPEED;
				}
				if (scene4fontalpha <= 0)
				{
					scene5bool = true;
				}
			}
		}

		//��5
		if (scene5bool == true)
		{
			if (scene5bool2 == false)
			{
				if (scene5fontalpha < 255)
				{
					scene5fontalpha += CHAT_UP_SPEED;
				}
				if (scene5fontalpha >= 255)
				{
					scene5bool2 = true;
				}
			}

			if (scene5bool2 == true)
			{
				if (scene5fontalpha > 0)
				{
					scene5fontalpha -= CHAT_DOWN_SPEED;
				}
				if (scene5fontalpha <= 0)
				{
					scene6bool = true;
				}
			}
		}

		//��6
		if (scene6bool == true)
		{
			if (scene6bool2 == false)
			{
				if (scene6fontalpha < 255)
				{
					scene6fontalpha += CHAT_UP_SPEED;
				}
				if (scene6fontalpha >= 255)
				{
					scene6bool2 = true;
				}
			}
			if (scene6bool2 == true)
			{
				if (scene6fontalpha > 0)
				{
					scene6fontalpha -= CHAT_DOWN_SPEED;
				}
				if (scene6fontalpha <= 0)
				{
					scene7bool = true;
					lock8 = true;
				}
			}
		}
	}
	
	//��7
	if (scene7bool == true && scene8bool == false)
	{
		scene7boolcount++;

		if (scene7boolcount > 100 && scene7boolcount < 200)
		{
			monsterkidx--;
		}

		if (scene7boolcount > 200)
		{
			monsterkidx-=3;
		}
	}

	monsterkid = RectMake(monsterkidx, monsterkidy, 730, 300);


	if (monsterkidx == -400)
	{
		scene8bool = true;
	}

	//��8
	if (scene8bool == true)
	{
		scene8alpha-=2;

		scene7bool = false;

		if (scene8bool2 == false)
		{
			if (scene8alphafont < 255)
			{
				scene8alphafont+= CHAT_UP_SPEED;
			}
			if (scene8alphafont >= 255)
			{
				scene8bool2 = true;
			}
		}

		if (scene8bool2 == true)
		{
			if (scene8alphafont > 0)
			{
				scene8alphafont-=5;
			}
			if (scene8alphafont <= 0)
			{
				scene9bool = true;
			}
		}
	}

	//��9
	if (scene9bool == true)
	{
		scene9alpha -= 2;
		scene8bool = false;

		if (scene9bool2 == false)
		{
			if (scene9alphafont < 255)
			{
				scene9alphafont+= CHAT_UP_SPEED;
			}
			if (scene9alphafont >= 255)
			{
				scene9bool2 = true;
			}
		}

		if (scene9bool2 == true)
		{
			if (scene9alphafont > 0)
			{
				scene9alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene9alphafont <= 0)
			{
				scene10bool = true;
			}
		}
	}

	//��10
	if (scene10bool == true)
	{
		scene9bool = false;

		if (scene10bool2 == false)
		{
			if (scene10alphafont < 255)
			{
				scene10alphafont+= CHAT_UP_SPEED;
			}
			if (scene10alphafont >= 255)
			{
				scene10bool2 = true;
			}
		}
		if (scene10bool2 == true)
		{
			if (scene10alphafont > 0)
			{
				scene10alphafont-=5;
			}
			if (scene10alphafont <= 0)
			{
				scene11bool = true;
			}
		}
	}

	//��11
	if (scene11bool == true)
	{
		scene10bool = false;

		if (scene11bool2 == false)
		{
			if (scene11alphafont < 255)
			{
				scene11alphafont+= CHAT_UP_SPEED;
			}
			if (scene11alphafont >= 255)
			{
				scene11bool2 = true;
			}
		}
		if (scene11bool2 == true)
		{
			if (scene11alphafont > 0)
			{
				scene11alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene11alphafont <= 0)
			{
				scene12bool = true;
			}
		}
	}

	//��12
	if (scene12bool == true)
	{
		scene11bool = false;

		if (scene12bool2 == false)
		{
			if (scene12alphafont < 255)
			{
				scene12alphafont+= CHAT_UP_SPEED;
			}
			if (scene12alphafont >= 255)
			{
				scene12bool2 = true;
			}
		}
		if (scene12bool2 == true)
		{
			if (scene12alphafont > 0)
			{
				scene12alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene12alphafont <= 0)
			{
				scene13bool = true;
			}
		}
	}

	//��13
	if (scene13bool == true)
	{
		scene13alpha -= 2;

		scene12bool = false;

		if (scene13bool2 == false)
		{
			if (scene13alphafont < 255)
			{
				scene13alphafont+= CHAT_UP_SPEED;
			}
			if (scene13alphafont >= 255)
			{
				scene13bool2 = true;
			}
		}

		if (scene13bool2 == true)
		{
			if (scene13alphafont > 0)
			{
				scene13alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene13alphafont <= 0)
			{
				scene14bool = true;
			}
		}
	}

	//��14
	if (scene14bool == true)
	{
		scene13bool = false;

		if (scene14bool2 == false)
		{
			if (scene14alphafont < 255)
			{
				scene14alphafont+= CHAT_UP_SPEED;
			}
			if (scene14alphafont >= 255)
			{
				scene14bool2 = true;
			}
		}
		if (scene14bool2 == true)
		{
			if (scene14alphafont > 0)
			{
				scene14alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene14alphafont <= 0)
			{
				scene15bool = true;
			}
		}
	}

	//��15
	if (scene15bool == true)
	{
		scene14bool = false;

		if (scene15bool2 == false)
		{
			if (scene15alphafont < 255)
			{
				scene15alphafont+= CHAT_UP_SPEED;
			}
			if (scene15alphafont >= 255)
			{
				scene15bool2 = true;
			}
		}
		if (scene15bool2 == true)
		{
			if (scene15alphafont > 0)
			{
				scene15alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene15alphafont <= 0)
			{
				scene16bool = true;
			}
		}
	}

	//��16
	if (lock9 == false)
	{
		if (scene16bool == true)
		{
			scene15bool = false;

			scene16alpha -= 9;

			scene16count++;

			if (scene16count > 100)
			{
				scene17bool = true;
				lock9 = true;
			}
		}
	}

	//��17
	if (scene17bool == true)
	{
		scene17alpha -= 9;

		scene16bool = false;

		if (scene17bool2 == false)
		{
			if (scene17alphafont < 255)
			{
				scene17alphafont+= CHAT_UP_SPEED;
			}
			if (scene17alphafont >= 255)
			{
				scene17bool2 = true;
			}
		}

		if (scene17bool2 == true)
		{
			if (scene17alphafont > 0)
			{
				scene17alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene17alphafont <= 0)
			{
				scene18bool = true;
			}
		}
	}

	//��18
	if (scene18bool == true)
	{
		scene18alpha -= 3;

		scene17bool = false;

		if (scene18bool2 == false)
		{
			if (scene18alphafont < 255)
			{
				scene18alphafont+= CHAT_UP_SPEED;
			}
			if (scene18alphafont >= 255)
			{
				scene18bool2 = true;
			}
		}

		if (scene18bool2 == true)
		{
			if (scene18alphafont > 0)
			{
				scene18alphafont -= CHAT_DOWN_SPEED ;
			}
			if (scene18alphafont <= 0)
			{
				scene19bool = true;
			}
		}
	}

	//��19
	if (scene19bool == true)
	{
		scene19alpha -= 3;

		scene18bool = false;

		if (scene19bool2 == false)
		{
			if (scene19alphafont < 255)
			{
				scene19alphafont+= CHAT_UP_SPEED;
			}
			if (scene19alphafont >= 255)
			{
				scene19bool2 = true;
			}
		}

		if (scene19bool2 == true)
		{
			if (scene19alphafont > 0)
			{
				scene19alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene19alphafont <= 0)
			{
				scene20bool = true;
			}
		}
	}

	//��20
	if (scene20bool == true)
	{
		scene19alpha = 255;

		scene19bool = false;

		if (scene20bool2 == false)
		{
			if (scene20alphafont < 255)
			{
				scene20alphafont += CHAT_UP_SPEED;
			}
			if (scene20alphafont >= 255)
			{
				scene20bool2 = true;
			}
		}

		if (scene20bool2 == true)
		{
			if (scene20alphafont > 0)
			{
				scene20alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene20alphafont <= 0)
			{
				scene21bool = true;
			}
		}
	}

	//��21
	if (scene21bool == true)
	{
		scene20bool = false;

		if (scene21bool2 == false)
		{
			if (scene21alphafont < 255)
			{
				scene21alphafont += CHAT_UP_SPEED;
			}
			if (scene21alphafont >= 255)
			{
				scene21bool2 = true;
			}
		}

		if (scene21bool2 == true)
		{
			if (scene21alphafont > 0)
			{
				scene21alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene21alphafont <= 0)
			{
				scene22bool = true;
			}
		}
	}

	//��22
	if (scene22bool == true)
	{
		scene21bool = false;

		if (scene22bool2 == false)
		{
			if (scene22alphafont < 255)
			{
				scene22alphafont += CHAT_UP_SPEED;
			}
			if (scene22alphafont >= 255)
			{
				scene22bool2 = true;
			}
		}

		if (scene22bool2 == true)
		{
			if (scene22alphafont > 0)
			{
				scene22alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene22alphafont <= 0)
			{
				scene23bool = true;
			}
		}
	}

	//��23
	if (scene23bool == true)
	{
		scene22bool = false;

		if (scene23bool2 == false)
		{
			if (scene23alphafont < 255)
			{
				scene23alphafont += CHAT_UP_SPEED;
			}
			if (scene23alphafont >= 255)
			{
				scene23bool2 = true;
			}
		}

		if (scene23bool2 == true)
		{
			if (scene23alphafont > 0)
			{
				scene23alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene23alphafont <= 0)
			{
				scene24bool = true;
			}
		}
	}

	//��24
	if (scene24bool == true)
	{
		scene23bool = false;

		if (scene24bool2 == false)
		{
			if (scene24alphafont < 255)
			{
				scene24alphafont += CHAT_UP_SPEED;
			}
			if (scene24alphafont >= 255)
			{
				scene24bool2 = true;
			}
		}

		if (scene24bool2 == true)
		{
			if (scene24alphafont > 0)
			{
				scene24alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene24alphafont <= 0)
			{
				scene25bool = true;
			}
		}
	}

	//��25
	if (scene25bool == true)
	{
		scene24bool = false;

		if (scene25bool2 == false)
		{
			if (scene25alphafont < 255)
			{
				scene25alphafont += CHAT_UP_SPEED;
			}
			if (scene25alphafont >= 255)
			{
				scene25bool2 = true;
			}
		}

		if (scene25bool2 == true)
		{
			if (scene25alphafont > 0)
			{
				scene25alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene25alphafont <= 0)
			{
				scene26bool = true;
			}
		}
	}

	//��26
	if (scene26bool == true)
	{
		scene25bool = false;

		if (scene26bool2 == false)
		{
			if (scene26alphafont < 255)
			{
				scene26alphafont += CHAT_UP_SPEED;
			}
			if (scene26alphafont >= 255)
			{
				scene26bool2 = true;
			}
		}

		if (scene26bool2 == true)
		{
			if (scene26alphafont > 0)
			{
				scene26alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene26alphafont <= 0)
			{
				scene27bool = true;
			}
		}
	}

	//��27
	if (scene27bool == true)
	{
		// 26������ ������ 
		// ��~
		scene26bool = false;

		if (scene27bool2 == false)
		{
			if (scene27alphafont < 255)
			{
				scene27alphafont += CHAT_UP_SPEED;
			}
			if (scene27alphafont >= 255)
			{
				scene27bool2 = true;
			}
		}

		if (scene27bool2 == true)
		{
			if (scene27alphafont > 0)
			{
				scene27alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene27alphafont <= 0)
			{
				scene28bool = true;
			}
		}
	}

	//��28
	if (scene28bool == true)
	{
		scene27bool = false;

		if (scene28bool2 == false)
		{
			if (scene28alphafont < 255)
			{
				scene28alphafont += CHAT_UP_SPEED;
			}
			if (scene28alphafont >= 255)
			{
				scene28bool2 = true;
			}
		}

		if (scene28bool2 == true)
		{
			if (scene28alphafont > 0)
			{
				scene28alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene28alphafont <= 0)
			{
				scene29bool = true;
			}
		}
	}

	//��29
	if (scene29bool == true)
	{
		scene28bool = false;

		if (scene29bool2 == false)
		{
			if (scene29alphafont < 255)
			{
				scene29alphafont += CHAT_UP_SPEED;
			}
			if (scene29alphafont >= 255)
			{
				scene29bool2 = true;
			}
		}

		if (scene29bool2 == true)
		{
			if (scene29alphafont > 0)
			{
				scene29alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene29alphafont <= 0)
			{
				scene30bool = true;
			}
		}
	}

	//��30
	if (scene30bool == true)
	{
		scene29bool = false;

		if (scene30bool2 == false)
		{
			if (scene30alphafont < 255)
			{
				scene30alphafont += CHAT_UP_SPEED;
			}
			if (scene30alphafont >= 255)
			{
				scene30bool2 = true;
			}
		}

		if (scene30bool2 == true)
		{
			if (scene30alphafont > 0)
			{
				scene30alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene30alphafont <= 0)
			{
				scene31bool = true;
			}
		}
	}

	//��31
	if (scene31bool == true)
	{
		scene30bool = false;

		if (scene31bool2 == false)
		{
			if (scene31alphafont < 255)
			{
				scene31alphafont += CHAT_UP_SPEED;
			}
			if (scene31alphafont >= 255)
			{
				scene31bool2 = true;
			}
		}

		if (scene31bool2 == true)
		{
			if (scene31alphafont > 0)
			{
				scene31alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene31alphafont <= 0)
			{
				scene32bool = true;
			}
		}
	}

	//��32
	if (scene32bool == true)
	{
		scene31bool = false;

		if (scene32bool2 == false)
		{
			if (scene32alphafont < 255)
			{
				scene32alphafont += CHAT_UP_SPEED;
			}
			if (scene32alphafont >= 255)
			{
				scene32bool2 = true;
			}
		}

		if (scene32bool2 == true)
		{
			if (scene32alphafont > 0)
			{
				scene32alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene32alphafont <= 0)
			{
				scene33bool = true;
			}
		}
	}

	//��33
	if (scene33bool == true)
	{
		scene32bool = false;

		if (scene33bool2 == false)
		{
			if (scene33alphafont < 255)
			{
				scene33alphafont += CHAT_UP_SPEED;
			}
			if (scene33alphafont >= 255)
			{
				scene33bool2 = true;
			}
		}

		if (scene33bool2 == true)
		{
			if (scene33alphafont > 0)
			{
				scene33alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene33alphafont <= 0)
			{
				scene34bool = true;
			}
		}
	}

	//��34
	if (scene34bool == true)
	{
		scene33bool = false;

		if (scene34bool2 == false)
		{
			if (scene34alphafont < 255)
			{
				scene34alphafont += CHAT_UP_SPEED;
			}
			if (scene34alphafont >= 255)
			{
				scene34bool2 = true;
			}
		}

		if (scene34bool2 == true)
		{
			if (scene34alphafont > 0)
			{
				scene34alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene34alphafont <= 0)
			{
				scene35bool = true;
			}
		}
	}

	//��35
	if (scene35bool == true)
	{
		scene34bool = false;

		if (scene35bool2 == false)
		{
			if (scene35alphafont < 255)
			{
				scene35alphafont += CHAT_UP_SPEED;
			}
			if (scene35alphafont >= 255)
			{
				scene35bool2 = true;
			}
		}

		if (scene35bool2 == true)
		{
			if (scene35alphafont > 0)
			{
				scene35alphafont -= CHAT_DOWN_SPEED;
			}
			if (scene35alphafont <= 0)
			{
				scene36bool = true;
				whiteoutalpha = 0;
			}
		}
	}

	//��36
	if (scene36bool == true)
	{
		scene35bool = false;

		if (scene36bool2 == false)
		{
			if (scene36alphafont < 255)
			{
				scene36alphafont += CHAT_UP_SPEED;
			}
			if (scene36alphafont >= 255)
			{
				scene36alphafont = 255;
				scene36bool2 = true;
			}
		}

		if (scene36bool2 == true)
		{
			if (whiteoutalpha < 255)
			{
				whiteoutalpha++;
			}
			if (whiteoutalpha >= 255)
			{
				stage3bosscount++;

				if (stage3bosscount > 150)
				{
					stage3bossend = true;
				}
			}
		}
	}

	
	if (stage3bossend == true)
	{
		//������������
		scene36bool = false;
	}
}

void stage3boss::render()
{

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
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
		//�÷��̾� �浹ó��
		//����
		Rectangle(getMemDC(), stage3hill1);
		Rectangle(getMemDC(), stage3hill2);
		Rectangle(getMemDC(), stage3hill3);
		Rectangle(getMemDC(), stage3hill4);
		Rectangle(getMemDC(), stage3hill5);
		Rectangle(getMemDC(), stage3hill6);
		
		//�Ʒ���
		Rectangle(getMemDC(), stage3hill7);
		Rectangle(getMemDC(), stage3hill8);
		Rectangle(getMemDC(), stage3hill9);
		Rectangle(getMemDC(), stage3hill10);
		Rectangle(getMemDC(), stage3hill11);
		Rectangle(getMemDC(), stage3hill12);
		Rectangle(getMemDC(), stage3hill13);
		Rectangle(getMemDC(), stage3hill14);
		Rectangle(getMemDC(), stage3hill15);
		Rectangle(getMemDC(), stage3hill16);
		Rectangle(getMemDC(), stage3hill17);
		Rectangle(getMemDC(), stage3hill18);
		Rectangle(getMemDC(), stage3hill19);
		Rectangle(getMemDC(), stage3hill20);
		Rectangle(getMemDC(), stage3scene);
		Rectangle(getMemDC(), babymonster);

		Rectangle(getMemDC(), undyne1);

		Rectangle(getMemDC(), monsterkid);
	}

	if (stage3bossend == false)
	{
		IMAGEMANAGER->findImage("��������3")->render(getMemDC()); //���׸�
		IMAGEMANAGER->findImage("Ű��")->render(getMemDC(), babymonster.left, babymonster.top);
		
		IMAGEMANAGER->findImage("���̺�����")->render(getMemDC(), undyne1.left, undyne1.top);
		//ȭ����ȯȿ��
		IMAGEMANAGER->findImage("ȭ��Ʈ�ƿ�")->alphaRender(getMemDC(), 0, 0, whiteoutalpha);
		IMAGEMANAGER->findImage("���ƿ�")->alphaRender(getMemDC(), 0, 0, blackoutalpha);


		if (blackouton == true && stage3boolscene2 == false)
		{
			IMAGEMANAGER->findImage("��1")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
		}
		if (stage3boolscene2 == true && scene3bool == false)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��2")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��2��Ʈ")->alphaRender(getMemDC(), stage3scene2fontrc.left, stage3scene2fontrc.top, stage3fontalphascene2);
		}
		if (scene3bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��3")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);

			if (scene3fontalphabool21 == false)
			{
				IMAGEMANAGER->findImage("��3��Ʈ")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene3fontalpha);
			}
			if (scene4bool == false)
			{
				IMAGEMANAGER->findImage("��3��Ʈ2")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene3fontalpha2);
			}
			if (scene4bool == true)
			{
				IMAGEMANAGER->findImage("��4��Ʈ")->alphaRender(getMemDC(), stage3scene2fontrc.left, stage3scene2fontrc.top, scene4fontalpha);
			}
		}

		if (scene5bool == true && scene7bool == false)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��5")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top);

			if (scene6bool == false)
			{
				IMAGEMANAGER->findImage("��5��Ʈ")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene5fontalpha);
			}
			if (scene6bool == true && scene7bool == false)
			{
				IMAGEMANAGER->findImage("��6��Ʈ")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene6fontalpha);
			}
		}

		if (scene7bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��7")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top);
			IMAGEMANAGER->findImage("��������Ű��")->alphaRender(getMemDC(), monsterkid.left, monsterkid.top);
		}

		if (scene8bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��8")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene8alpha);
			IMAGEMANAGER->findImage("��8��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene8alphafont);
		}

		if (scene9bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("��9��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alphafont);
		}

		if (scene10bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("��10��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene10alphafont);
		}

		if (scene11bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("��11��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene11alphafont);
		}

		if (scene12bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("��12��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene12alphafont);
		}

		if (scene13bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("��13��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alphafont);
		}

		if (scene14bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("��14��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene14alphafont);
		}

		if (scene15bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("��15��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene15alphafont);
		}

		if (scene16bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��16")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene16alpha);
		}

		if (scene17bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��17")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene17alpha);
			IMAGEMANAGER->findImage("��17��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene17alphafont);
		}

		if (scene18bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��18")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene18alpha);
			IMAGEMANAGER->findImage("��18��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene18alphafont);
		}

		if (scene19bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("��19��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alphafont);
		}


		if (scene20bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("��20��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene20alphafont);
		}

		if (scene21bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("��21��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene21alphafont);
		}

		if (scene22bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("��22��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene22alphafont);
		}

		if (scene23bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��23")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene23alpha);
			IMAGEMANAGER->findImage("��23��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene23alphafont);
		}

		if (scene24bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("��24��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alphafont);
		}

		if (scene25bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("��25��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene25alphafont);
		}

		if (scene26bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("��26��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene26alphafont);
		}

		if (scene27bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("��27��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene27alphafont);
		}

		if (scene28bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("��28��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene28alphafont);
		}

		if (scene29bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��29")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alpha);
			IMAGEMANAGER->findImage("��29��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alphafont);
		}

		if (scene30bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��29")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alpha);
			IMAGEMANAGER->findImage("��30��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene30alphafont);
		}

		if (scene31bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��31")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alpha);
			IMAGEMANAGER->findImage("��31��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alphafont);
		}

		if (scene32bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��31")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alpha);
			IMAGEMANAGER->findImage("��32��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene32alphafont);
		}

		if (scene33bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��33")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene33alpha);
			IMAGEMANAGER->findImage("��33��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene33alphafont);
		}

		if (scene34bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��34")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene34alpha);
			IMAGEMANAGER->findImage("��34��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene34alphafont);
		}

		if (scene35bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��35")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene35alpha);
			IMAGEMANAGER->findImage("��35��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene35alphafont);
		}

		if (scene36bool == true)
		{
			IMAGEMANAGER->findImage("���̹���")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("��36")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene36alpha);
			IMAGEMANAGER->findImage("��36��Ʈ")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene36alphafont);
			IMAGEMANAGER->findImage("ȭ��Ʈ�ƿ�")->alphaRender(getMemDC(), 0, 0, whiteoutalpha);
		}
	}

	//sprintf_s(str, "������ī��Ʈ: %d  , �� : %d ", stage3bosscount , stage3bossend);
	//TextOut(getMemDC(), 100, 100, str, strlen(str));

}
