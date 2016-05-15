#pragma once
#include "character.h"
class etna : public character
{
public:
	etna();
	~etna();

	HRESULT init();
	void release();
	void update();
	void render();

	/*			�Լ� �߰�			*/
	virtual void keyControl();
	virtual void battleKeyControl();
	virtual void move(int endX, int endY);
	virtual void setImage();
	virtual void setFrame();

	virtual void saveData();
	virtual void loadData();

	virtual RECT getRect() { return _rc; }
};

