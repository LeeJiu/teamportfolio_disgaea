#pragma once
#include "gameObject.h"

enum WEAPON_TYPE
{
	WEAPON_NONE, WEAPON_SWORD, WEAPON_WAND, WEAPON_STAFT, WEAPON_BOW
};

enum CHARACTER_STATE
{
	IDLE, WALK, ATTACK, LIFT, ETC
};

enum CHARACTER_DIRECTION
{
	LB, RB, RT, LT
};


class character : public gameObject
{
protected:
	const char* _fileName;
	image* _character;
	RECT _rc;
	int _x, _y;
	char* _name;				//캐릭터 이름
	int _level, _counter, _mv, _jm;									//캐릭터 능력치 1
	int _hp, _sp, _atk, _int, _def, _spd, _hit, _res, _exp, _next;  //캐릭터 능력치 2
	bool _isWeaponEquip;		//장비 장착여부
	bool _isUp, _isRight, isShow;

	CHARACTER_STATE _characterState;
	CHARACTER_DIRECTION _characterDir;
	WEAPON_TYPE _weaponType;	//장착 무기 타입
	
	int _curFrameX, _curFrameY, _count;

public:
	character();
	virtual ~character();

	HRESULT init();
	void release();
	void update();
	void render();

	/*			함수 추가			*/
	virtual void keyControl();
	virtual void move();
	virtual void setImage();
	virtual void setFrame();
};

