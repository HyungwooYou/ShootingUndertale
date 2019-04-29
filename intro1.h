#pragma once
#include "gameNode.h"

enum tagStageManger
{
	//�ΰ� Y��ġ
	LOGO_LOCATION_Y = 300,

	// pressEnter ���ڰŸ��� ���ǵ�
	PRESS_ENTER_BLINK_SPEED = 4,
	// pressEnter Y��ġ
	PRESS_LOCATION_Y = 500,
};

class intro1 : public gameNode
{
private:
	image* undertaleLoge;//�ΰ� ��ƺ�����
	RECT undertaleLogoRECT; //�ΰ� RECTȮ�ο�

	float undertaleLogoAlpha; // �ΰ���İ�

	image* _pressEnter;
	RECT pressEnter; //enter�����ּ��� RECTȮ�ο�
	float pressEnterAlpha; // �ΰ���İ�
	char str[128]; // ������¿�

	bool checkrect;

public:
	intro1();
	~intro1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void Logo(); //�ΰ� õõ�� ������� 
	void pressEnterG();// pressEnter�ݺ������� ���ڰŷ���
};

