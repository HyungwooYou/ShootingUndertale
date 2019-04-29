#pragma once
#include "gameNode.h"

class Bullet : public gameNode
{
private:
	image* _bulletImage;		// 총알이미지
	RECT _rc;
	float _x, _y;						// 총알 좌표
	float _fireX, _fireY;			// 총알 발사위치(X,Y)
	float _angle;						// 총알 각도
	float _radius;					// 총알 반지름
	float _speed;					// 총알 스피드
	float _range;					// 총알 최대 사거리

	bool _isActive;					// 총알이 활성화 되어 있는지 아닌지


public:
	Bullet();
	~Bullet();

	void init(image* image, float radius, float range);		// 반지름, 사거리
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float angle, float speed);			// 총알 발사 함수

	void bulletMove();

public:
	void setActive(bool isActive) { _isActive = isActive; }					// _isActive의 setter 함수
	bool getActive() const { return _isActive; }						// _isActive의 getter 함수

	RECT getRC() const { return _rc; }
};

// 오브젝트풀~
class objectpool : public gameNode
{
private:


	float _defaultRange;
	float _defaultRadius;

	const char* _imageName;							// 이미지 이름

	vector<Bullet*> _disableBullets;				// 안쓰는 총알을 모아두는 곳
	vector<Bullet*> _enableBullets;				// 쓰는 총알을 모아두는 곳


	char str[128];//문자를 출력해보쟈
public:
	objectpool();
	~objectpool();

	void init(const char* imageName, int createBullet = 16000, float range = 1200.0f, float radius = 10.0f);
	virtual void release();
	virtual void update();
	virtual void render();

	// 총알 발사
	void fire(float x, float y, float angle, float speed);

public:
	// 이 함수를 쓰면, 현재 사용중인 총알들을 모아놓은 _enableBullets 벡터 정보를 얻을 수 있다.
	vector<Bullet*> getActiveBullets() const { return _enableBullets; }
};

