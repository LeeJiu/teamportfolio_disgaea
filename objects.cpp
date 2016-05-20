#include "stdafx.h"
#include "objects.h"


objects::objects()
{
}


objects::~objects()
{
}

HRESULT objects::init(const char* strkey, int x, int y, int imageNum, vector<TagTile*> tile)
{
	_name = strkey;
	
	for (int i = 0; i < TOTALTILE(TILENUM); i++)
	{
		_tile[i % TILENUM][i / TILENUM] = tile[i];
	}

	_imageNum = imageNum;
	
	//_character = new image;
	_character = IMAGEMANAGER->findImage(_name);
	_indexX = x;
	_indexY = y;

	//��Ʈ������.
	if (_imageNum == 4)
	{
		_width = _character->getFrameWidth();
		_height = _character->getFrameHeight();
	}
	else
	{
		_width = _character->getWidth();
		_height = _character->getHeight();
	}

	if (_height < WIDTH / 2)
		_rc =  RectMake(_tile[_indexX][_indexY]->pivotX - _width / 2, _tile[_indexX][_indexY]->pivotY + WIDTH / 4 - _height / 2, _width, _height);
	else if (_height > WIDTH / 2)
		_rc = RectMake(_tile[_indexX][_indexY]->pivotX - _width / 2, _tile[_indexX][_indexY]->rc.bottom - _height, _width, _height);


	_isFrame = false;
	if (_imageNum == 4) _isFrame = true;

	_count = 0;
	_curFrameX = 0;
	
	_pivotY = _tile[_indexX][_indexY]->pivotY;
	return S_OK;
}

void objects::release()
{

}

void objects::update()
{
	_count++;

	//�����Ӽ���
	if (_count % 5 == 0)
	{
		_curFrameX++;
		if (_curFrameX > _character->getMaxFrameX())
		{
			_curFrameX = 0;
		}
		_character->setFrameX(_curFrameX); 
		
	}


	if (_height < WIDTH / 2)
		_rc = RectMake(_tile[_indexX][_indexY]->pivotX - _width / 2, _tile[_indexX][_indexY]->pivotY + WIDTH / 4 - _height / 2, _width, _height);
	else if (_height > WIDTH / 2)
		_rc = RectMake(_tile[_indexX][_indexY]->pivotX - _width / 2, _tile[_indexX][_indexY]->rc.bottom - _height, _width, _height);
}

void objects::render()
{
	if (_isFrame)
		_character->frameRender(getMemDC(), _rc.left, _rc.top);
	else
	{
		//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		_character->render(getMemDC(), _rc.left, _rc.top);
	}

}

void objects::previousState()
{

}

void objects::showPossibleMoveTile()
{

}

int objects::getHell()
{

	return 0;
}
void objects::setHell(int hell)
{

}

void objects::setItem(const char * itemName, bool isWear)
{
}

void objects::setMercenary(const char* characterName)
{

}