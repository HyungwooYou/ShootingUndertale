#pragma once
#include "gameNode.h"

class stage1 : public gameNode
{
private:


	//위쪽 대나무숲 왼쪽벽
	RECT object11;
	//위쪽 대나무숲
	RECT objectUP;
	//아래쪽 대나무숲
	RECT objectDOWN;

	//왼쪽 분홍문
	RECT object2;
	RECT object3;
	RECT object4;
	RECT object5;
	RECT object6;
	RECT object7;
	RECT object8;
	RECT object9;
	RECT object10;
	//11플레이어가 쓰고잇음ㅋㅋㅋ
	RECT object12;
	RECT object13;
	RECT object14;
	RECT object15;
	RECT object16;

	//스테이지 카메라효과를 위한 좌표
	float stage1x; // stage1화면 좌표
	char str[128]; // 문자출력용
	bool recton; // 렉트확인용

	//스테이지 클리어 카메라
	int _dogdie;
	bool stageclearcamera;

	//스테이지 클리어되면 렉트
	RECT clearlocation;

	bool checkrect;

public:
	//스테이지 클리어되면 렉트
	RECT getclearlocation() { return clearlocation; }
	//스테이지 클리어 카메라
	bool getstageclearcamera() { return stageclearcamera;}
	void setstageclearcamera(bool v){ stageclearcamera = v;}
	//카메라 두개가져옴
	float getstage1x() { return stage1x; }
	void setstage1x(float _x) { stage1x = _x; }

	RECT getobject11() {return object11;}
	RECT getobjectUP() { return objectUP; }
	RECT getobjectDOWN() { return objectDOWN; }
	RECT getobject2() { return object2; }
	RECT getobject3() { return object3; }
	RECT getobject4() { return object4; }
	RECT getobject5() { return object5; }
	RECT getobject6() { return object6; }
	RECT getobject7() { return object7; }
	RECT getobject8() { return object8; }
	RECT getobject9() { return object9; }
	RECT getobject10() { return object10; }
	RECT getobject12() { return object12; }
	RECT getobject13() { return object13; }
	RECT getobject14() { return object14; }
	RECT getobject15() { return object15; }
	RECT getobject16() { return object16; }

	stage1();
	~stage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int dogdie);
	virtual void render();


};

