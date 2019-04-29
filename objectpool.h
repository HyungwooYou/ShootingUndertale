#pragma once
#include "gameNode.h"

class Bullet : public gameNode
{
private:
	image* _bulletImage;		// �Ѿ��̹���
	RECT _rc;
	float _x, _y;						// �Ѿ� ��ǥ
	float _fireX, _fireY;			// �Ѿ� �߻���ġ(X,Y)
	float _angle;						// �Ѿ� ����
	float _radius;					// �Ѿ� ������
	float _speed;					// �Ѿ� ���ǵ�
	float _range;					// �Ѿ� �ִ� ��Ÿ�

	bool _isActive;					// �Ѿ��� Ȱ��ȭ �Ǿ� �ִ��� �ƴ���


public:
	Bullet();
	~Bullet();

	void init(image* image, float radius, float range);		// ������, ��Ÿ�
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float angle, float speed);			// �Ѿ� �߻� �Լ�

	void bulletMove();

public:
	void setActive(bool isActive) { _isActive = isActive; }					// _isActive�� setter �Լ�
	bool getActive() const { return _isActive; }						// _isActive�� getter �Լ�

	RECT getRC() const { return _rc; }
};

// ������ƮǮ~
class objectpool : public gameNode
{
private:


	float _defaultRange;
	float _defaultRadius;

	const char* _imageName;							// �̹��� �̸�

	vector<Bullet*> _disableBullets;				// �Ⱦ��� �Ѿ��� ��Ƶδ� ��
	vector<Bullet*> _enableBullets;				// ���� �Ѿ��� ��Ƶδ� ��


	char str[128];//���ڸ� ����غ���
public:
	objectpool();
	~objectpool();

	void init(const char* imageName, int createBullet = 16000, float range = 1200.0f, float radius = 10.0f);
	virtual void release();
	virtual void update();
	virtual void render();

	// �Ѿ� �߻�
	void fire(float x, float y, float angle, float speed);

public:
	// �� �Լ��� ����, ���� ������� �Ѿ˵��� ��Ƴ��� _enableBullets ���� ������ ���� �� �ִ�.
	vector<Bullet*> getActiveBullets() const { return _enableBullets; }
};

