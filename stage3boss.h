#pragma once
#include "gameNode.h"

enum tagchar
{
	//255����ߵ�
	//��ǳ�� ����� �ӵ�
	CHAT_UP_SPEED = 1,


	//��ǳ�� ������� �ӵ�
	CHAT_DOWN_SPEED = 5,

};

class stage3boss : public gameNode
{
private:


	char str[128];
	//�÷��̾� �浹ó��
	//����
	RECT stage3hill1;
	RECT stage3hill2;
	RECT stage3hill3;
	RECT stage3hill4;
	RECT stage3hill5;
	RECT stage3hill6;

	//�Ʒ���
	RECT stage3hill7;
	RECT stage3hill8;
	RECT stage3hill9;
	RECT stage3hill10;
	RECT stage3hill11;
	RECT stage3hill12;
	RECT stage3hill13;
	RECT stage3hill14;
	RECT stage3hill15;
	RECT stage3hill16;
	RECT stage3hill17;
	RECT stage3hill18;
	RECT stage3hill19;
	RECT stage3hill20;

	RECT stage3hill21;

	//��������
	RECT babymonster;
	//�����
	RECT undyne1;
	float undyne1x;

	//ȭ�� ��ȯȿ��
	image* whiteout;
	int whiteoutalpha;
	
	image* blackout;
	bool blackouton;
	int blackoutalpha;

	bool blackoutend;

	image* bossimage;

	//����ȭ�鷺Ʈ
	RECT stage3scene;
	
	//��1
	image* stage3scene1;
	int stage3scene1alpha;
	int stage3scene1count;

	//��2
	image* stage3scene2;
	bool stage3boolscene2;

	//��2��Ʈ
	RECT stage3scene2fontrc;
	image* stage3fontscene2;
	int stage3scene1fontcount;
	int stage3fontalphascene2;
	int scene2fontbool;
	
	//��3
	bool scene3bool;
	RECT undynetalk;
	int scene3boolcount;

	//��3��Ʈ
	image* scene3font;
	int scene3fontalpha;
	bool scene3fontalphabool;

	//��3��Ʈ2(���žƴϾ�)
	image* scene3font2;
	int scene3fontalpha2;
	bool scene3fontalphabool2;
	bool scene3fontalphabool21;

	//��4��Ʈ(����γ�..)
	bool scene4bool;
	image* scene4font;
	int scene4fontalpha;
	bool scene4boo2;

	//��5 ����Ʈ
	bool scene5bool;

	image* scene5font;
	int scene5fontalpha;
	bool scene5bool2;

	//��6
	bool scene6bool;
	image* scene6font;
	int scene6fontalpha;
	bool scene6bool2;

	//��7
	bool scene7bool;
	RECT monsterkid;
	float monsterkidx, monsterkidy;

	int scene7boolcount;

	//��8
	bool scene8bool;
	image* scene8;
	int scene8alpha;

	image* scene8font;
	int scene8alphafont;
	bool scene8bool2;

	//��9
	bool scene9bool;
	image* scene9;
	int scene9alpha;

	image* scene9font;
	int scene9alphafont;
	bool scene9bool2;

	//��10
	bool scene10bool;

	image* scene10font;
	int scene10alphafont;
	bool scene10bool2;

	//��11
	bool scene11bool;

	image* scene11font;
	int scene11alphafont;
	bool scene11bool2;
	
	//��12
	bool scene12bool;

	image* scene12font;
	int scene12alphafont;
	bool scene12bool2;

	//��13
	bool scene13bool;
	image* scene13;
	int scene13alpha;

	image* scene13font;
	int scene13alphafont;
	bool scene13bool2;

	//��14
	bool scene14bool;

	image* scene14font;
	int scene14alphafont;
	bool scene14bool2;

	//��15
	bool scene15bool;

	image* scene15font;
	int scene15alphafont;
	bool scene15bool2;

	//��16
	bool scene16bool;
	image* scene16;
	int scene16alpha;

	int scene16count;

	//��17
	bool scene17bool;
	image* scene17;
	int scene17alpha;

	image* scene17font;
	int scene17alphafont;
	bool scene17bool2;

	//��18
	bool scene18bool;
	image* scene18;
	int scene18alpha;

	image* scene18font;
	int scene18alphafont;
	bool scene18bool2;

	//��19
	bool scene19bool;
	image* scene19;
	int scene19alpha;

	image* scene19font;
	int scene19alphafont;
	bool scene19bool2;

	//��20
	bool scene20bool;

	image* scene20font;
	int scene20alphafont;
	bool scene20bool2;

	//��21
	bool scene21bool;

	image* scene21font;
	int scene21alphafont;
	bool scene21bool2;

	//��22
	bool scene22bool;

	image* scene22font;
	int scene22alphafont;
	bool scene22bool2;

	//��23
	bool scene23bool;
	image* scene23;
	int scene23alpha;

	image* scene23font;
	int scene23alphafont;
	bool scene23bool2;

	//��24
	bool scene24bool;
	image* scene24;
	int scene24alpha;

	image* scene24font;
	int scene24alphafont;
	bool scene24bool2;

	//��25
	bool scene25bool;
	image* scene25;
	int scene25alpha;

	image* scene25font;
	int scene25alphafont;
	bool scene25bool2;

	//��26
	bool scene26bool;

	image* scene26font;
	int scene26alphafont;
	bool scene26bool2;

	//��27
	bool scene27bool;

	image* scene27font;
	int scene27alphafont;
	bool scene27bool2;

	//��28
	bool scene28bool;

	image* scene28font;
	int scene28alphafont;
	bool scene28bool2;

	//��29
	bool scene29bool;
	image* scene29;
	int scene29alpha;

	image* scene29font;
	int scene29alphafont;
	bool scene29bool2;

	//��30
	bool scene30bool;

	image* scene30font;
	int scene30alphafont;
	bool scene30bool2;

	//��31
	bool scene31bool;
	image* scene31;
	int scene31alpha;

	image* scene31font;
	int scene31alphafont;
	bool scene31bool2;

	//��32
	bool scene32bool;

	image* scene32font;
	int scene32alphafont;
	bool scene32bool2;

	//��33
	bool scene33bool;
	image* scene33;
	int scene33alpha;

	image* scene33font;
	int scene33alphafont;
	bool scene33bool2;

	//��34
	bool scene34bool;
	image* scene34;
	int scene34alpha;

	image* scene34font;
	int scene34alphafont;
	bool scene34bool2;

	//��35
	bool scene35bool;
	image* scene35;
	int scene35alpha;

	image* scene35font;
	int scene35alphafont;
	bool scene35bool2;

	//��36
	bool scene36bool;
	image* scene36;
	int scene36alpha;

	image* scene36font;
	int scene36alphafont;
	bool scene36bool2;


	//�� �ѱ���۾�
	int stage3bosscount;
	bool stage3bossend;




	//===========���� ��״��۾�==========
	bool lock1;
	bool lock2;
	bool lock3;
	bool lock4;
	bool lock5;
	bool lock6;
	bool lock7;
	bool lock8;
	bool lock9;

	bool checkrect;

public:
	//stage3boss �����°ɾ˸�
	bool getstage3bossend() { return stage3bossend; }
	void setstage3bossend(bool v) { stage3bossend = v; }

	//�����
	int get_undyne1x() { return undyne1x; }
	void set_undyne1x(int v) { undyne1x = v; }

	//�÷��̾� �浹ó��
	RECT getstage3hill1() { return stage3hill1; }
	RECT getstage3hill2() { return stage3hill2; }
	RECT getstage3hill3() { return stage3hill3; }
	RECT getstage3hill4() { return stage3hill4; }
	RECT getstage3hill5() { return stage3hill5; }
	RECT getstage3hill6() { return stage3hill6; }
	RECT getstage3hill7() { return stage3hill7; }
	RECT getstage3hill8() { return stage3hill8; }
	RECT getstage3hill9() { return stage3hill9; }
	RECT getstage3hill10() { return stage3hill10; }
	RECT getstage3hill11() { return stage3hill11; }
	RECT getstage3hill12() { return stage3hill12; }
	RECT getstage3hill13() { return stage3hill13; }
	RECT getstage3hill14() { return stage3hill14; }
	RECT getstage3hill15() { return stage3hill15; }
	RECT getstage3hill16() { return stage3hill16; }
	RECT getstage3hill17() { return stage3hill17; }
	RECT getstage3hill18() { return stage3hill18; }
	RECT getstage3hill19() { return stage3hill19; }
	RECT getstage3hill20() { return stage3hill20; }
	RECT getstage3hill21() { return stage3hill21; }

	//��������
	RECT getbabymonster() { return babymonster; }

	stage3boss();
	~stage3boss();

	virtual HRESULT init();
	virtual void release();
	virtual void update(bool whiteouton);
	virtual void render();
};

