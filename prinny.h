#pragma once
#pragma warning(disable : 4996)
#include "character.h"
#include "inventory.h"

class prinny : public character
{
private:
	int _hell;
	int _mercenaryNum;		//고용 중인 용병 수

	inventory* _inventory;

	RECT _invenExit;

	bool _isbattle;

public:
	prinny();
	~prinny();

	virtual HRESULT init();
	virtual HRESULT init(vector<TagTile*> tile);
	virtual void release();
	virtual void update();
	virtual void render();
	 
	 /*			함수 추가			*/
	virtual void keyControl();
	virtual void battleKeyControl();
	virtual void move();
	virtual void setImage();
	virtual void setFrame();
	virtual void previousState();								// 이전으로 돌아가는 함수
	virtual void showPossibleMoveTile();						// 이동가능한 타일 보여주는 함수
	virtual void setDirectionImage();
	virtual void attack(int targetX, int targetY);

	virtual void saveData();
	virtual void loadData();
	virtual void setCharacterMove(int endX, int endY, vector<TagTile*> vRoute);
	 
	virtual void setItem(const char* itemName);
	virtual void setMercenary(const char* characterName);
	virtual void setHell(int hell) { _hell = hell; }
	 
	virtual int getHell() { return _hell; }
};

