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
	IMAGEMANAGER->addImage("½ºÅ×ÀÌÁö3", "stage3.bmp", 1280, 768, true, RGB(255, 0, 255));

	//ÇÃ·¹ÀÌ¾î Ãæµ¹Ã³¸®
	//À§ÂÊ
	stage3hill1 = RectMake(0,0,180,240);
	stage3hill2 = RectMake(stage3hill1.right, 0, 10, 230);
	stage3hill3 = RectMake(stage3hill2.right, 0, 520, 50);
	stage3hill4 = RectMake(stage3hill3.right, 0, 10, 230);
	stage3hill5 = RectMake(stage3hill4.right, stage3hill4.bottom, 10, 10);
	stage3hill6 = RectMake(stage3hill5.right, stage3hill5.bottom, 700, 10);

	//¾Æ·¡ÂÊ
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

	IMAGEMANAGER->addImage("Å°µå", "monsterbaby.bmp", 60, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¼¼ÀÌºê¾ð´ÙÀÎ", "saveundyne.bmp", 100, 120, true, RGB(255, 0, 255));

	//È­¸é ÀüÈ¯È¿°ú
	whiteout = IMAGEMANAGER->addImage("È­ÀÌÆ®¾Æ¿ô", "whiteout.bmp", 1280, 768, true, RGB(255, 0, 255));
	
	whiteoutalpha = 0;
	whiteout->setAlpahBlend(true, whiteoutalpha);


	blackout = IMAGEMANAGER->addImage("ºí·¢¾Æ¿ô", "background.bmp", 1280, 768, true, RGB(255, 0, 255));
	blackoutalpha = 0;
	blackout->setAlpahBlend(true, blackoutalpha);

	//¾À ÀÌ¹ÌÁö ¸ðÀ½
	stage3scene1 = IMAGEMANAGER->addImage("¾À1", "stage3scene1.bmp", 730, 300, true, RGB(255, 0, 255));
	stage3scene1alpha = 0;
	stage3scene1->setAlpahBlend(true, stage3scene1alpha);

	//¾À2
	stage3scene2 = IMAGEMANAGER->addImage("¾À2", "stage3scene2.bmp", 730, 300, true, RGB(255, 0, 255));
	
	//¾À2ÆùÆ®
	stage3fontscene2 = IMAGEMANAGER->addImage("¾À2ÆùÆ®", "stage3scene2font.bmp", 200, 120, true, RGB(255, 0, 255));
	stage3fontalphascene2 = 0;
	stage3fontscene2->setAlpahBlend(true, stage3fontalphascene2);

	//¾À3
	IMAGEMANAGER->addImage("¾À3", "stage3scene3.bmp", 730, 300, true, RGB(255, 0, 255));

	//¾À3ÆùÆ®
	scene3font = IMAGEMANAGER->addImage("¾À3ÆùÆ®", "stage3scene3font.bmp", 300, 300, true, RGB(255, 0, 255));
	scene3fontalpha = 0;
	scene3font->setAlpahBlend(true, scene3fontalpha);

	//¾À3ÆùÆ®2
	scene3font2 = IMAGEMANAGER->addImage("¾À3ÆùÆ®2", "stage3scene3font2.bmp", 300, 300, true, RGB(255, 0, 255));
	scene3fontalpha2 = 0;
	scene3font2->setAlpahBlend(true, scene3fontalpha2);

	//¾À4ÆùÆ®
	scene4font = IMAGEMANAGER->addImage("¾À4ÆùÆ®", "stage3scene4font.bmp", 200, 120, true, RGB(255, 0, 255));
	scene4fontalpha = 0;
	scene4font->setAlpahBlend(true, scene4fontalpha);

	//¾À5
	IMAGEMANAGER->addImage("¾À5", "stage3scene5.bmp", 730, 300, true, RGB(255, 0, 255));

	scene5font = IMAGEMANAGER->addImage("¾À5ÆùÆ®", "stage3scene5font.bmp", 300, 300, true, RGB(255, 0, 255));
	scene5fontalpha = 0;
	scene5font->setAlpahBlend(true, scene5fontalpha);

	//¾À6
	scene6font = IMAGEMANAGER->addImage("¾À6ÆùÆ®", "stage3scene5font2.bmp", 300, 300, true, RGB(255, 0, 255));
	scene6fontalpha = 0;
	scene6font->setAlpahBlend(true, scene6fontalpha);

	//¾À7
	IMAGEMANAGER->addImage("ºóÀÌ¹ÌÁö", "nonimage.bmp", 730, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¾À7", "stage3scene7.bmp", 730, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("µµ¸Á°¡´ÂÅ°µå", "stage3scene7kid.bmp", 730, 300, true, RGB(255, 0, 255));

	//¾À8
	scene8 = IMAGEMANAGER->addImage("¾À8", "stage3scene8.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene8alpha = 255;
	scene8->setAlpahBlend(true, scene8alpha);

	scene8font = IMAGEMANAGER->addImage("¾À8ÆùÆ®", "stage3scene8font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene8alphafont = 0;
	scene8font->setAlpahBlend(true, scene8alphafont);

	//¾À9
	scene9 = IMAGEMANAGER->addImage("¾À9", "stage3scene9.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene9alpha = 255;
	scene9->setAlpahBlend(true, scene9alpha);

	scene9font = IMAGEMANAGER->addImage("¾À9ÆùÆ®", "stage3scene9font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene9alphafont = 0;
	scene9font->setAlpahBlend(true, scene9alphafont);

	//¾À10
	scene10font = IMAGEMANAGER->addImage("¾À10ÆùÆ®", "stage3scene10font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene10alphafont = 0;
	scene10font->setAlpahBlend(true, scene10alphafont);

	//¾À11
	scene11font = IMAGEMANAGER->addImage("¾À11ÆùÆ®", "stage3scene11font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene11alphafont = 0;
	scene11font->setAlpahBlend(true, scene11alphafont);

	//¾À12
	scene12font = IMAGEMANAGER->addImage("¾À12ÆùÆ®", "stage3scene12font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene12alphafont = 0;
	scene12font->setAlpahBlend(true, scene12alphafont);

	//¾À13
	scene13 = IMAGEMANAGER->addImage("¾À13", "stage3scene13.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene13alpha = 255;
	scene13->setAlpahBlend(true, scene13alpha);

	scene13font = IMAGEMANAGER->addImage("¾À13ÆùÆ®", "stage3scene13font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene13alphafont = 0;
	scene13font->setAlpahBlend(true, scene13alphafont);

	//¾À14
	scene14font = IMAGEMANAGER->addImage("¾À14ÆùÆ®", "stage3scene14font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene14alphafont = 0;
	scene14font->setAlpahBlend(true, scene14alphafont);

	//¾À15
	scene15font = IMAGEMANAGER->addImage("¾À15ÆùÆ®", "stage3scene15font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene15alphafont = 0;
	scene15font->setAlpahBlend(true, scene15alphafont);

	//¾À16
	scene16 = IMAGEMANAGER->addImage("¾À16", "stage3scene16.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene16alpha = 255;
	scene16->setAlpahBlend(true, scene16alpha);

	//¾À17
	scene17 = IMAGEMANAGER->addImage("¾À17", "stage3scene17.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene17alpha = 255;
	scene17->setAlpahBlend(true, scene13alpha);

	scene17font = IMAGEMANAGER->addImage("¾À17ÆùÆ®", "stage3scene17font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene17alphafont = 0;
	scene17font->setAlpahBlend(true, scene17alphafont);

	//¾À18
	scene18 = IMAGEMANAGER->addImage("¾À18", "stage3scene18.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene18alpha = 255;
	scene18->setAlpahBlend(true, scene18alpha);

	scene18font = IMAGEMANAGER->addImage("¾À18ÆùÆ®", "stage3scene18font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene18alphafont = 0;
	scene18font->setAlpahBlend(true, scene18alphafont);

	//¾À19
	scene19 = IMAGEMANAGER->addImage("¾À19", "stage3scene19.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene19alpha = 255;
	scene19->setAlpahBlend(true, scene18alpha);

	scene19font = IMAGEMANAGER->addImage("¾À19ÆùÆ®", "stage3scene19font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene19alphafont = 0;
	scene19font->setAlpahBlend(true, scene19alphafont);

	//¾À20
	scene20font = IMAGEMANAGER->addImage("¾À20ÆùÆ®", "stage3scene20font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene20alphafont = 0;
	scene20font->setAlpahBlend(true, scene20alphafont);

	//¾À21
	scene21font = IMAGEMANAGER->addImage("¾À21ÆùÆ®", "stage3scene21font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene21alphafont = 0;
	scene21font->setAlpahBlend(true, scene21alphafont);

	//¾À22
	scene22font = IMAGEMANAGER->addImage("¾À22ÆùÆ®", "stage3scene22font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene22alphafont = 0;
	scene22font->setAlpahBlend(true, scene22alphafont);

	//¾À23
	scene23 = IMAGEMANAGER->addImage("¾À23", "stage3scene23.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene23alpha = 255;
	scene23->setAlpahBlend(true, scene23alpha);

	scene23font = IMAGEMANAGER->addImage("¾À23ÆùÆ®", "stage3scene23font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene23alphafont = 0;
	scene23font->setAlpahBlend(true, scene23alphafont);

	//¾À24
	scene24 = IMAGEMANAGER->addImage("¾À24", "stage3scene24.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene24alpha = 255;
	scene24->setAlpahBlend(true, scene24alpha);

	scene24font = IMAGEMANAGER->addImage("¾À24ÆùÆ®", "stage3scene24font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene24alphafont = 0;
	scene24font->setAlpahBlend(true, scene24alphafont);

	//¾À25
	scene25font = IMAGEMANAGER->addImage("¾À25ÆùÆ®", "stage3scene25font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene25alphafont = 0;
	scene25font->setAlpahBlend(true, scene25alphafont);

	//¾À26
	scene26font = IMAGEMANAGER->addImage("¾À26ÆùÆ®", "stage3scene26font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene26alphafont = 0;
	scene26font->setAlpahBlend(true, scene26alphafont);

	//¾À27
	scene27font = IMAGEMANAGER->addImage("¾À27ÆùÆ®", "stage3scene27font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene27alphafont = 0;
	scene27font->setAlpahBlend(true, scene27alphafont);

	//¾À28
	scene28font = IMAGEMANAGER->addImage("¾À28ÆùÆ®", "stage3scene28font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene28alphafont = 0;
	scene28font->setAlpahBlend(true, scene28alphafont);

	//¾À29
	scene29 = IMAGEMANAGER->addImage("¾À29", "stage3scene29.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene29alpha = 255;
	scene29->setAlpahBlend(true, scene29alpha);

	scene29font = IMAGEMANAGER->addImage("¾À29ÆùÆ®", "stage3scene29font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene29alphafont = 0;
	scene29font->setAlpahBlend(true, scene29alphafont);

	//¾À30
	scene30font = IMAGEMANAGER->addImage("¾À30ÆùÆ®", "stage3scene30font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene30alphafont = 0;
	scene30font->setAlpahBlend(true, scene30alphafont);

	//¾À31
	scene31 = IMAGEMANAGER->addImage("¾À31", "stage3scene31.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene31alpha = 255;
	scene31->setAlpahBlend(true, scene31alpha);

	scene31font = IMAGEMANAGER->addImage("¾À31ÆùÆ®", "stage3scene31font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene31alphafont = 0;
	scene31font->setAlpahBlend(true, scene31alphafont);

	//¾À32
	scene32font = IMAGEMANAGER->addImage("¾À32ÆùÆ®", "stage3scene32font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene32alphafont = 0;
	scene32font->setAlpahBlend(true, scene32alphafont);

	//¾À33
	scene33 = IMAGEMANAGER->addImage("¾À33", "stage3scene33.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene33alpha = 255;
	scene33->setAlpahBlend(true, scene33alpha);

	scene33font = IMAGEMANAGER->addImage("¾À33ÆùÆ®", "stage3scene33font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene33alphafont = 0;
	scene33font->setAlpahBlend(true, scene33alphafont);

	//¾À34
	scene34 = IMAGEMANAGER->addImage("¾À34", "stage3scene34.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene34alpha = 255;
	scene34->setAlpahBlend(true, scene34alpha);

	scene34font = IMAGEMANAGER->addImage("¾À34ÆùÆ®", "stage3scene34font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene34alphafont = 0;
	scene34font->setAlpahBlend(true, scene34alphafont);

	//¾À35
	scene35 = IMAGEMANAGER->addImage("¾À35", "stage3scene35.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene35alpha = 255;
	scene35->setAlpahBlend(true, scene35alpha);

	scene35font = IMAGEMANAGER->addImage("¾À35ÆùÆ®", "stage3scene35font.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene35alphafont = 0;
	scene35font->setAlpahBlend(true, scene35alphafont);

	//¾À36
	scene36 = IMAGEMANAGER->addImage("¾À36", "stage3scene36.bmp", 730, 300, true, RGB(255, 0, 255));;
	scene36alpha = 255;
	scene36->setAlpahBlend(true, scene36alpha);

	scene36font = IMAGEMANAGER->addImage("¾À36ÆùÆ®", "stage3scene36font.bmp", 730, 300, true, RGB(255, 0, 255));;
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

	//È­¸éÀüÈ¯È¿°ú -> Èò¹è°æÁß
	
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


	//È­¸éÀüÈ¯È¿°ú -> °ËÀºÈ­¸é¿¡¼­ º¸¿©Áü
	
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

	//È­¸éÀüÈ¯È¿°ú -> µÎ¹øÂ°Àå¸éÀ¸·Î³Ñ¾î°¨
	if (lock3 == false)
	{
		if (blackoutend == true)
		{
			stage3boolscene2 = true;
			stage3scene1fontcount++;
		}
	}

	//µÎ¹øÂ°Àå¸é ÆùÆ®³ª¿È
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
	//¾À3ÆùÆ®
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

	//¾À3ÆùÆ®2
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

	//¾À4
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

		//¾À5
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

		//¾À6
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
	
	//¾À7
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

	//¾À8
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

	//¾À9
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

	//¾À10
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

	//¾À11
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

	//¾À12
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

	//¾À13
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

	//¾À14
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

	//¾À15
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

	//¾À16
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

	//¾À17
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

	//¾À18
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

	//¾À19
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

	//¾À20
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

	//¾À21
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

	//¾À22
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

	//¾À23
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

	//¾À24
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

	//¾À25
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

	//¾À26
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

	//¾À27
	if (scene27bool == true)
	{
		// 26»çÁøÀ» Áö¿ö¶ó 
		// »½~
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

	//¾À28
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

	//¾À29
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

	//¾À30
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

	//¾À31
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

	//¾À32
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

	//¾À33
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

	//¾À34
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

	//¾À35
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

	//¾À36
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
		//¸¶Áö¢²¨²¨ÁÜ
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
		//ÇÃ·¹ÀÌ¾î Ãæµ¹Ã³¸®
		//À§ÂÊ
		Rectangle(getMemDC(), stage3hill1);
		Rectangle(getMemDC(), stage3hill2);
		Rectangle(getMemDC(), stage3hill3);
		Rectangle(getMemDC(), stage3hill4);
		Rectangle(getMemDC(), stage3hill5);
		Rectangle(getMemDC(), stage3hill6);
		
		//¾Æ·¡ÂÊ
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
		IMAGEMANAGER->findImage("½ºÅ×ÀÌÁö3")->render(getMemDC()); //¹è°æ±×¸²
		IMAGEMANAGER->findImage("Å°µå")->render(getMemDC(), babymonster.left, babymonster.top);
		
		IMAGEMANAGER->findImage("¼¼ÀÌºê¾ð´ÙÀÎ")->render(getMemDC(), undyne1.left, undyne1.top);
		//È­¸éÀüÈ¯È¿°ú
		IMAGEMANAGER->findImage("È­ÀÌÆ®¾Æ¿ô")->alphaRender(getMemDC(), 0, 0, whiteoutalpha);
		IMAGEMANAGER->findImage("ºí·¢¾Æ¿ô")->alphaRender(getMemDC(), 0, 0, blackoutalpha);


		if (blackouton == true && stage3boolscene2 == false)
		{
			IMAGEMANAGER->findImage("¾À1")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
		}
		if (stage3boolscene2 == true && scene3bool == false)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À2")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À2ÆùÆ®")->alphaRender(getMemDC(), stage3scene2fontrc.left, stage3scene2fontrc.top, stage3fontalphascene2);
		}
		if (scene3bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À3")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);

			if (scene3fontalphabool21 == false)
			{
				IMAGEMANAGER->findImage("¾À3ÆùÆ®")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene3fontalpha);
			}
			if (scene4bool == false)
			{
				IMAGEMANAGER->findImage("¾À3ÆùÆ®2")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene3fontalpha2);
			}
			if (scene4bool == true)
			{
				IMAGEMANAGER->findImage("¾À4ÆùÆ®")->alphaRender(getMemDC(), stage3scene2fontrc.left, stage3scene2fontrc.top, scene4fontalpha);
			}
		}

		if (scene5bool == true && scene7bool == false)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À5")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top);

			if (scene6bool == false)
			{
				IMAGEMANAGER->findImage("¾À5ÆùÆ®")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene5fontalpha);
			}
			if (scene6bool == true && scene7bool == false)
			{
				IMAGEMANAGER->findImage("¾À6ÆùÆ®")->alphaRender(getMemDC(), undynetalk.left, undynetalk.top, scene6fontalpha);
			}
		}

		if (scene7bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À7")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top);
			IMAGEMANAGER->findImage("µµ¸Á°¡´ÂÅ°µå")->alphaRender(getMemDC(), monsterkid.left, monsterkid.top);
		}

		if (scene8bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À8")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene8alpha);
			IMAGEMANAGER->findImage("¾À8ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene8alphafont);
		}

		if (scene9bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("¾À9ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alphafont);
		}

		if (scene10bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("¾À10ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene10alphafont);
		}

		if (scene11bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("¾À11ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene11alphafont);
		}

		if (scene12bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À9")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene9alpha);
			IMAGEMANAGER->findImage("¾À12ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene12alphafont);
		}

		if (scene13bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("¾À13ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alphafont);
		}

		if (scene14bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("¾À14ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene14alphafont);
		}

		if (scene15bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À13")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene13alpha);
			IMAGEMANAGER->findImage("¾À15ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene15alphafont);
		}

		if (scene16bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À16")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene16alpha);
		}

		if (scene17bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À17")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene17alpha);
			IMAGEMANAGER->findImage("¾À17ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene17alphafont);
		}

		if (scene18bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À18")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene18alpha);
			IMAGEMANAGER->findImage("¾À18ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene18alphafont);
		}

		if (scene19bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("¾À19ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alphafont);
		}


		if (scene20bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("¾À20ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene20alphafont);
		}

		if (scene21bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("¾À21ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene21alphafont);
		}

		if (scene22bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À19")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene19alpha);
			IMAGEMANAGER->findImage("¾À22ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene22alphafont);
		}

		if (scene23bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À23")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene23alpha);
			IMAGEMANAGER->findImage("¾À23ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene23alphafont);
		}

		if (scene24bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("¾À24ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alphafont);
		}

		if (scene25bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("¾À25ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene25alphafont);
		}

		if (scene26bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("¾À26ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene26alphafont);
		}

		if (scene27bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("¾À27ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene27alphafont);
		}

		if (scene28bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À24")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene24alpha);
			IMAGEMANAGER->findImage("¾À28ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene28alphafont);
		}

		if (scene29bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À29")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alpha);
			IMAGEMANAGER->findImage("¾À29ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alphafont);
		}

		if (scene30bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À29")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene29alpha);
			IMAGEMANAGER->findImage("¾À30ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene30alphafont);
		}

		if (scene31bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À31")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alpha);
			IMAGEMANAGER->findImage("¾À31ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alphafont);
		}

		if (scene32bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À31")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene31alpha);
			IMAGEMANAGER->findImage("¾À32ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene32alphafont);
		}

		if (scene33bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À33")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene33alpha);
			IMAGEMANAGER->findImage("¾À33ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene33alphafont);
		}

		if (scene34bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À34")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene34alpha);
			IMAGEMANAGER->findImage("¾À34ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene34alphafont);
		}

		if (scene35bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À35")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene35alpha);
			IMAGEMANAGER->findImage("¾À35ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene35alphafont);
		}

		if (scene36bool == true)
		{
			IMAGEMANAGER->findImage("ºóÀÌ¹ÌÁö")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, stage3scene1alpha);
			IMAGEMANAGER->findImage("¾À36")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene36alpha);
			IMAGEMANAGER->findImage("¾À36ÆùÆ®")->alphaRender(getMemDC(), stage3scene.left, stage3scene.top, scene36alphafont);
			IMAGEMANAGER->findImage("È­ÀÌÆ®¾Æ¿ô")->alphaRender(getMemDC(), 0, 0, whiteoutalpha);
		}
	}

	//sprintf_s(str, "¸¶Áö¸·Ä«¿îÆ®: %d  , ²ý : %d ", stage3bosscount , stage3bossend);
	//TextOut(getMemDC(), 100, 100, str, strlen(str));

}
