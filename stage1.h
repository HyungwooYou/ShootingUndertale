#pragma once
#include "gameNode.h"

class stage1 : public gameNode
{
private:


	//���� �볪���� ���ʺ�
	RECT object11;
	//���� �볪����
	RECT objectUP;
	//�Ʒ��� �볪����
	RECT objectDOWN;

	//���� ��ȫ��
	RECT object2;
	RECT object3;
	RECT object4;
	RECT object5;
	RECT object6;
	RECT object7;
	RECT object8;
	RECT object9;
	RECT object10;
	//11�÷��̾ ��������������
	RECT object12;
	RECT object13;
	RECT object14;
	RECT object15;
	RECT object16;

	//�������� ī�޶�ȿ���� ���� ��ǥ
	float stage1x; // stage1ȭ�� ��ǥ
	char str[128]; // ������¿�
	bool recton; // ��ƮȮ�ο�

	//�������� Ŭ���� ī�޶�
	int _dogdie;
	bool stageclearcamera;

	//�������� Ŭ����Ǹ� ��Ʈ
	RECT clearlocation;

	bool checkrect;

public:
	//�������� Ŭ����Ǹ� ��Ʈ
	RECT getclearlocation() { return clearlocation; }
	//�������� Ŭ���� ī�޶�
	bool getstageclearcamera() { return stageclearcamera;}
	void setstageclearcamera(bool v){ stageclearcamera = v;}
	//ī�޶� �ΰ�������
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

