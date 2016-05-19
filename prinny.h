#pragma once
#pragma warning(disable : 4996)
#include "character.h"
#include "inventory.h"

class prinny : public character
{
private:
	int _hell;
	int _itemNum;			//소지 중인 아이템 수
	int _mercenaryNum;		//고용 중인 용병 수
	int _characterNum;		//용병을 포함한 캐릭터 수 / 정보 로드를 위한 인덱스

	inventory* _inventory;

	RECT _invenExit, _invenNext;

	bool _isbattle, _isOpenInven;

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
	virtual void move(int endX, int endY);
	virtual void setImage();
	virtual void setFrame();
	virtual void previousState();								// 이전으로 돌아가는 함수
	virtual void showPossibleMoveTile();						// 이동가능한 타일 보여주는 함수

	virtual void saveData();
	virtual void loadData();
	void loadItemData();
	void saveItemData();
	void changeSaveData();
	void changeLoadData(int arrNum);
	 
	virtual void setItem(const char* itemName, bool isWear);
	virtual void setMercenary(const char* characterName);
	virtual void setHell(int hell) { _hell = hell; }
	void setInventory();
	void setChangeData();
	 
	virtual int getHell() { return _hell; }
};

