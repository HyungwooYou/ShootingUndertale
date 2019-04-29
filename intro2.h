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

	//사진 글자 다나올때
	SCENE_COUNT = 100,
	//글자만 변환할때
	SCNEN_COUNT_2 = 200,

	SCNEN_COUNT_3 = 50,


	// ...찍는 타이밍
	SCENE_POINT = 50,

	PRESS_ENTER_BLINK_SPEED2 = 4,
	PRESS_LOCATION_X2 = 1100,
	PRESS_LOCATION_Y2 = WINSIZEY - 15,

};
class intro2 : public gameNode
{
private:

	RECT pressEnter; //enter눌러주세요 RECT확인용
	float pressEnterAlpha; // 로고알파값

	char str[128];
	int sceneChange; // 씬전환용

	//==== 1번째 장면 ====
	//이미지 1 정보
	image* image1;
	RECT image1RECT;
	int image1Alpha;

	//이미지 1 글자정보
	image* image1font1;
	RECT image1font;
	int image1fontAlpha;

	int count1; // 몇초뒤에 씬넘길것인가

	//==== 2번째 장면 ====
	//이미지 2 정보
	image* image2;
	RECT image2RECT;
	int image2Alpha;

	//이미지 2 글자정보
	image* image2font1;
	RECT image2font;
	int image2fontAlpha;

	int count2; // 몇초뒤에 씬넘길것인가

	//==== 3번째 장면 ====
	//이미지 3 정보
	image* image3;
	RECT image3RECT;
	int image3Alpha;

	//이미지 3 글자정보
	image* image3font1;
	RECT image3font;
	int image3fontAlpha;

	int count3; // 몇초뒤에 씬넘길것인가

	//==== 4번째 장면 =====

	//이미지 4 글자정보
	image* image4font1;
	RECT image4font;
	int image4fontAlpha;



	int count4; // 몇초뒤에 씬넘길것인가

	//==== 5번째 장면 =====
	//이미지 5 글자정보
	image* image5font1;
	RECT image5font;
	int image5fontAlpha;

	image* image5font2;
	RECT image5font3;

	int count5; // 몇초뒤에 씬넘길것인가

	int count5point; // 점찍기위한 카운트
	int countIndex; // 점찍기위해 늘려줄거야

	//==== 6번째 장면 ====
	//이미지 6 정보
	image* image6;
	RECT image6RECT;
	int image6Alpha;

	//이미지 6 글자정보
	image* image6font1;
	RECT image6font;
	int image6fontAlpha;

	int count6; // 몇초뒤에 씬넘길것인가

	//==== 7번째 장면 ====
	//이미지 7 정보
	image* image7;
	RECT image7RECT;
	int image7Alpha;

	//이미지 7 글자정보
	image* image7font1;
	RECT image7font;
	int image7fontAlpha;

	int count7; // 몇초뒤에 씬넘길것인가

	//==== 8번째 장면 ====
	//이미지 8 정보
	image* image8;
	RECT image8RECT;
	int image8Alpha;

	int count8; // 몇초뒤에 씬넘길것인가

	//==== 9번째 장면 ====
	//이미지 9 정보
	image* image9;
	RECT image9RECT;
	int image9Alpha;

	int count9; // 몇초뒤에 씬넘길것인가

	//==== 10번째 장면 ====
	//이미지 10 정보
	image* image10;
	RECT image10RECT;
	int image10Alpha;

	int count10; // 몇초뒤에 씬넘길것인가

	//==== 11번째 장면 ====
	//이미지 11 정보
	image* image11;
	RECT image11RECT;
	int image11Alpha;

	int count11; // 몇초뒤에 씬넘길것인가
	int imageindex11;
	int imageindex112;

	RECT pressEnter2; //enter눌러주세요 RECT확인용
	float pressEnterAlpha2; // 로고알파값

	bool checkrect;

public:
	//씬번호 stageManger를 올려줌 
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

