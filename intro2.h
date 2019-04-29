#pragma once
#include "gameNode.h"

enum tagSceanChange
{
	STATR_SCENE = 1,

	SCENE1 = 1,
	SCENE2 = 2,
	SCENE3 = 3,
	SCENE4 = 4,
	SCENE5 = 5,
	SCENE6 = 6,
	SCENE7 = 7,
	SCENE8 = 8,
	SCENE9 = 9,
	SCENE10 = 10,
	SCENE11 = 11,

	//���� ���� �ٳ��ö�
	SCENE_COUNT = 100,
	//���ڸ� ��ȯ�Ҷ�
	SCNEN_COUNT_2 = 200,

	SCNEN_COUNT_3 = 50,


	// ...��� Ÿ�̹�
	SCENE_POINT = 50,

	PRESS_ENTER_BLINK_SPEED2 = 4,
	PRESS_LOCATION_X2 = 1100,
	PRESS_LOCATION_Y2 = WINSIZEY - 15,

};
class intro2 : public gameNode
{
private:

	RECT pressEnter; //enter�����ּ��� RECTȮ�ο�
	float pressEnterAlpha; // �ΰ���İ�

	char str[128];
	int sceneChange; // ����ȯ��

	//==== 1��° ��� ====
	//�̹��� 1 ����
	image* image1;
	RECT image1RECT;
	int image1Alpha;

	//�̹��� 1 ��������
	image* image1font1;
	RECT image1font;
	int image1fontAlpha;

	int count1; // ���ʵڿ� ���ѱ���ΰ�

	//==== 2��° ��� ====
	//�̹��� 2 ����
	image* image2;
	RECT image2RECT;
	int image2Alpha;

	//�̹��� 2 ��������
	image* image2font1;
	RECT image2font;
	int image2fontAlpha;

	int count2; // ���ʵڿ� ���ѱ���ΰ�

	//==== 3��° ��� ====
	//�̹��� 3 ����
	image* image3;
	RECT image3RECT;
	int image3Alpha;

	//�̹��� 3 ��������
	image* image3font1;
	RECT image3font;
	int image3fontAlpha;

	int count3; // ���ʵڿ� ���ѱ���ΰ�

	//==== 4��° ��� =====

	//�̹��� 4 ��������
	image* image4font1;
	RECT image4font;
	int image4fontAlpha;



	int count4; // ���ʵڿ� ���ѱ���ΰ�

	//==== 5��° ��� =====
	//�̹��� 5 ��������
	image* image5font1;
	RECT image5font;
	int image5fontAlpha;

	image* image5font2;
	RECT image5font3;

	int count5; // ���ʵڿ� ���ѱ���ΰ�

	int count5point; // ��������� ī��Ʈ
	int countIndex; // ��������� �÷��ٰž�

	//==== 6��° ��� ====
	//�̹��� 6 ����
	image* image6;
	RECT image6RECT;
	int image6Alpha;

	//�̹��� 6 ��������
	image* image6font1;
	RECT image6font;
	int image6fontAlpha;

	int count6; // ���ʵڿ� ���ѱ���ΰ�

	//==== 7��° ��� ====
	//�̹��� 7 ����
	image* image7;
	RECT image7RECT;
	int image7Alpha;

	//�̹��� 7 ��������
	image* image7font1;
	RECT image7font;
	int image7fontAlpha;

	int count7; // ���ʵڿ� ���ѱ���ΰ�

	//==== 8��° ��� ====
	//�̹��� 8 ����
	image* image8;
	RECT image8RECT;
	int image8Alpha;

	int count8; // ���ʵڿ� ���ѱ���ΰ�

	//==== 9��° ��� ====
	//�̹��� 9 ����
	image* image9;
	RECT image9RECT;
	int image9Alpha;

	int count9; // ���ʵڿ� ���ѱ���ΰ�

	//==== 10��° ��� ====
	//�̹��� 10 ����
	image* image10;
	RECT image10RECT;
	int image10Alpha;

	int count10; // ���ʵڿ� ���ѱ���ΰ�

	//==== 11��° ��� ====
	//�̹��� 11 ����
	image* image11;
	RECT image11RECT;
	int image11Alpha;

	int count11; // ���ʵڿ� ���ѱ���ΰ�
	int imageindex11;
	int imageindex112;

	RECT pressEnter2; //enter�����ּ��� RECTȮ�ο�
	float pressEnterAlpha2; // �ΰ���İ�

	bool checkrect;

public:
	//����ȣ stageManger�� �÷��� 
	int getsceneChange() { return sceneChange; }

	intro2();
	~intro2();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imageAtoZ();
	void pressEnterG2();
};

