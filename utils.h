#pragma once


#include <cmath>

#define PI      3.141592654f
#define PI2      (PI * 2)
#define PI8      float(PI / 8.0f)
#define PI16   float(PI / 16.f)
#define PI32   float(PI / 32.f)
#define PI64   float(PI / 64.f)
#define PI128   float (PI / 128.f)

#define ONE_RAD (PI / 180)

//실수 대소비교하기 위한 변수 (가장 작은 단위라고 보자)
#define FLOAT_EPSILON 0.001f 
#define FLOAT_EQUAL(f1, f2)      (fabs(f1 - f2) <= FLOAT_EPSILON) //두 실수가 같은지 확인

#define TILENUM 12
#define WIDTH 128
#define OFFSET 48
#define TOTALTILE(tileNum) (tileNum) * (tileNum)

enum TILESTATE
{
	S_NONE, S_ECT, S_ONOBJ, S_ONENM, ZEN_POINT, BOSS, S_ONCHAR
};

enum OBJSTATE
{
	S_NOMAL, S_ZEN, E_NORMAL, E_BOSS
};

struct TagTile
{
	image* image;			// 타일의 이미지
	RECT rc;				// 타일의 렉트 (아이소타일이라해서 보여지는 부분만 렉트라 생각하면 ㄴㄴ)
	float pivotX;			// 타일의 중심 x
	float pivotY;			// 타일의 중심 y
	TILESTATE state;		// 타일의 상태
	TagTile* parent;		// A* 해당타일의 부모
	int x, y;				// 타일의인덱스 x, y
	int width;				// 타일의 폭
	int height;				// 타일의 높이
	int imageNum;			// 이미지 가져오기
	int number;				// 타일의 고유 넘버값 
	float f, g, h, d;		// A* 필요한 변수값
	bool draw;				// 타일 그려진 유무 ( 이 타일위에 이미지가 그려져있는지 확인 유무)
};

struct TagObject
{
	image* image;			// 타일의 이미지
	RECT rc;				// 타일의 렉트 (아이소타일이라해서 보여지는 부분만 렉트라 생각하면 ㄴㄴ)
	POINT pivot;			// 타일 렉트의 중심점
	int x, y;				// 타일의인덱스 x, y
	int width;				// 타일의 폭
	int height;				// 타일의 높이
	int imageNum;			// 이미지 가져오기
	int number;				// 타일의 고유 넘버값 
	bool draw;
	OBJSTATE state;
};

<<<<<<< HEAD
=======


>>>>>>> refs/remotes/origin/jihyun
enum WEAPON_TYPE
{
	NONE, SWORD, WAND, STAFF, BOW
};

struct OBJ_Y_RENDER
{
	bool operator()(const TagObject* obj1, const TagObject* obj2)
	{
		return obj1->pivot.y < obj2->pivot.y;
	}
};

struct OBJ_NUM
{
	bool operator()(const TagObject* obj1, const TagObject* obj2)
	{
		return obj1->number < obj2->number;
	}
};

struct tagItem
{
	image* image;
	RECT rc;
	char* name;
	char* info;
	int atk;
	int intel;
	int def;
	int spd;
	int hit;
	int res;
	int buyPrice;	//플레이어가 살 때 가격
	int sellPrice;	//플레이어가 팔 때 가격
	bool isWear;
	WEAPON_TYPE type;
};

namespace MY_UTIL
{
	//거리 구하는 함수
	float getDistance(float startX, float startY, float endX, float endY);

	//각도 구하는 함수
	float getAngle(float startX, float startY, float endX, float endY);
}

enum CHARACTER_STATE
{
	IDLE, WALK, ATTACK, LIFT, PAIN, ETC
};

enum CHARACTER_DIRECTION
{
	LB, RB, RT, LT
};