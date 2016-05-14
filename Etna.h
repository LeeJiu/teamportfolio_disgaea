#pragma once
#include "character.h"
class Etna :
	public character
{
public:
	Etna();
	~Etna();

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
};
