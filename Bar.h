#pragma once
#include "gameNode.h"
class Bar : public gameNode
{
private:
	RECT _rcProgress; // ���α׷����ٷ�Ʈ
	float _x, _y; //���α׷����� ��ǥ
	float _width; //���α׷����� ����ũ��

	//Ű������ �����ϱ����� ���ڿ� ������ �������
	string _topImgName;	//��� �̹��� ���ڿ�
	string _backImgName; //�ϴ� �̹��� ���ڿ�

	image* _progressBarTop; //��� ü�¹� �̹���
	image* _progressBarBottom; //�ϴ� ü�¹� �̹���

public:
	Bar();
	~Bar();

	HRESULT init(int x, int y, int width, int height);
	HRESULT init(const char* backImgName, const char* frontImgName, int x, int y,int width, int height);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);
	
	void setX(int x){_x = x;}
	void setY(int y){_y = y;}
};

