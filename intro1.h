#pragma once
#include "gameNode.h"

enum tagStageManger
{
	//로고 Y위치
	LOGO_LOCATION_Y = 300,

	// pressEnter 깜박거리는 스피드
	PRESS_ENTER_BLINK_SPEED = 4,
	// pressEnter Y위치
	PRESS_LOCATION_Y = 500,
};

class intro1 : public gameNode
{
private:
	image* undertaleLoge;//로고를 담아볼께요
	RECT undertaleLogoRECT; //로고 RECT확인용

	float undertaleLogoAlpha; // 로고알파값

	image* _pressEnter;
	RECT pressEnter; //enter눌러주세요 RECT확인용
	float pressEnterAlpha; // 로고알파값
	char str[128]; // 문자출력용

	bool checkrect;

public:
	intro1();
	~intro1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void Logo(); //로고를 천천히 보여줘요 
	void pressEnterG();// pressEnter반복적으로 깜박거려요
};

