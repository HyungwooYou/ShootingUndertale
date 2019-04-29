#pragma once
#include "gameNode.h"
class stage2 : public gameNode
{
private:
	//확인용 f5
	bool f5on;
	//스테이지2맵 메인 카메라
	int map1x;
	//충돌처리할 렉트들
	//위쪽막기
	RECT hill1;
	RECT hill2;
	RECT hill3;
	RECT hill4;
	RECT hill5;
	//아래막기
	RECT hill6;
	RECT hill7;
	RECT hill8;
	RECT hill9;
	RECT hill10;
	//아래막기2
	RECT hill11;
	RECT hill12;
	RECT hill13;
	RECT hill14;
	RECT hill15;
	RECT hill16;

	//확인용 치트키
	char str[128];

	RECT stage3go;

	int _stage3go;

	bool checkrect;

public:
	//위쪽막기
	RECT gethill1() { return hill1; }
	RECT gethill2() { return hill2; }
	RECT gethill3() { return hill3; }
	RECT gethill4() { return hill4; }
	RECT gethill5() { return hill5; }

	//아래막기
	RECT gethill6() { return hill6; }
	RECT gethill7() { return hill7; }
	RECT gethill8() { return hill8; }
	RECT gethill9() { return hill9; }
	RECT gethill10() { return hill10; }

	//아래막기2
	RECT gethill11() { return hill11; }
	RECT gethill12() { return hill12; }
	RECT gethill13() { return hill13; }
	RECT gethill14() { return hill14; }
	RECT gethill15() { return hill15; }

	//왼쪽막기
	RECT gethill16() { return hill16; }

	RECT getstage3go() { return stage3go; }

	//스테이지2맵 메인 카메라
	int getmap1x() { return map1x; }
	void setmap1x(int v) { map1x = v; }

	stage2();
	~stage2();

	virtual HRESULT init();
	virtual void release();
	virtual void update(int cleardogboss);
	virtual void render();
};

