#pragma once
#include "gameNode.h"



class stage4 : public gameNode
{
private:
	bool checkrect;

	bool playerStart1;
	bool playerStart2;
	bool playerStart3;

	//�����������
	RECT undyneImagerc;
	image* undyneImage;
	int imagecount;
	int imageindex;

	// ====== ����� ======
	int undyneState;
	RECT undynerc;
	float x;
	float y;
	float angle;
	float hp;

	//������� �Ѿ˽�
	int undyneStatebullet;

	// ====== ����� ü�¹� =====
	RECT hpbar;
	float hpbarx;


	//������ �����ߵ�.
	RECT Startpont;
	int StartpontX;
	int StartpontCount;

	//��ݺ���������ߵɰŴ�
	bool Startpontbool2;
	RECT Startpont2;
	int StartpontX2;
	int StartpontCount2;

	//��Ʈ����
	bool GameStart;
	


	bool playerMove;

	//���Ӳ�
	bool end;
public:
	bool getend() { return end; }

	//����η�Ʈ
	RECT getundynerc(){return undynerc;}
	//�����ü��
	int getundynehp() { return hp; }
	void setundynehp(int v){hp = v;}

	bool getGameStart() { return GameStart; }

	int getundynex() { return x; }
	int getundyney() { return y; }


	int getundyneStatebullet() {return undyneStatebullet;}

	bool getplayerStart1() {return playerStart1;}
	bool getplayerMove() {return playerMove;}

	stage4();
	~stage4();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�÷��̾� ��������
	void PlayerStart();

	//�����������
	void undyneFrame();

	//����� ������
	void undyneMove();

	//������ �����ߴ�.
	void herobegin();

	//��ݺ���������ߵɰŴ�
	void herobegin2();

	//hpü�¹ٻ��ܳ�
	void hpbarbegin();
};

