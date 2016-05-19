#include "stdafx.h"
#include "etna.h"


etna::etna()
{
}


etna::~etna()
{
}

HRESULT etna::init()
{
	return S_OK;
}

HRESULT etna::init(vector<TagTile*> tile)
{
	_name = "etna";

	loadData();

	_isCharacter = true;
	_character = IMAGEMANAGER->findImage("etna_idle");
	_characterState = IDLE;
	_characterDir = LB;
	_curFrameX = 0;
	_count = 0;

	_isShow = false;

	for (int i = 0; i < TOTALTILE(TILENUM); i++)
	{
		_tile[i % TILENUM][i / TILENUM] = tile[i];
	}

	_vTile = tile;

	_moveSpeed = 3;

	return S_OK;
}

void etna::release()
{
}

void etna::update()
{
	setImage();

	if (!_isMove)
	{
		_rc = RectMakeIso(_tile[_indexX][_indexY]->pivotX, _tile[_indexX][_indexY]->pivotY, _character->getFrameWidth(), _character->getFrameHeight());
		_x = (_rc.right + _rc.left) / 2;
		_y = (_rc.top + _rc.bottom) / 2;
	}
	battleKeyControl();
	gameObject::move();
}

void etna::render()
{
	if (_isShow)
	{
		if (_isShowPossibleMoveTile) gameObject::showPossibleMoveTile();
		if (_isShowPossibleAttackTile) gameObject::showPossibleAttackTile();
		_character->frameRender(getMemDC(), _rc.left, _rc.top, _curFrameX, _curFrameY);
	}
}

void etna::keyControl()
{
}

void etna::battleKeyControl()
{
}


void etna::setImage()
{
	if (_isRight)
	{
		if (_isUp)
		{
			_characterDir = RT;
		}
		else _characterDir = RB;
	}
	else
	{
		if (_isUp)
		{
			_characterDir = LT;
		}
		else _characterDir = LB;
	}

	switch (_characterState)
	{
	case IDLE:
		_character = IMAGEMANAGER->findImage("etna_idle");
		break;

	case WALK:
		_character = IMAGEMANAGER->findImage("etna_walk");
		break;

	case ATTACK:
		_character = IMAGEMANAGER->findImage("etna_attack");
		break;

	case LIFT:
		_character = IMAGEMANAGER->findImage("etna_lift");
		break;

	case ETC:
		_character = IMAGEMANAGER->findImage("etna_etc");
		break;
	}

	setFrame();
}

void etna::setFrame()
{
	_count++;

	switch (_characterDir)
	{
	case LB:
		_curFrameY = 0;
		_character->setFrameY(_curFrameY);
		break;

	case RB:
		_curFrameY = 1;
		_character->setFrameY(_curFrameY);
		break;

	case RT:
		_curFrameY = 2;
		_character->setFrameY(_curFrameY);
		break;

	case LT:
		_curFrameY = 3;
		_character->setFrameY(_curFrameY);
		break;
	}

	if (_count % 7 == 0)
	{
		_curFrameX++;
		if (_curFrameX > _character->getMaxFrameX())
		{
			_curFrameX = 0;
		}
		_character->setFrameX(_curFrameX);
	}
}

void etna::saveData()
{
	vector<string> vStr;

	vStr.push_back(std::to_string(_level));
	vStr.push_back(std::to_string(_counter));
	vStr.push_back(std::to_string(_mv));
	vStr.push_back(std::to_string(_jm));
	vStr.push_back(std::to_string(_hp));
	vStr.push_back(std::to_string(_sp));
	vStr.push_back(std::to_string(_atk));
	vStr.push_back(std::to_string(_int));
	vStr.push_back(std::to_string(_def));
	vStr.push_back(std::to_string(_spd));
	vStr.push_back(std::to_string(_hit));
	vStr.push_back(std::to_string(_res));
	vStr.push_back(std::to_string(_exp));
	vStr.push_back(std::to_string(_next));
	vStr.push_back(std::to_string(_equipWeapon));

	TXTDATA->txtSave("etna.txt", vStr);
}

void etna::loadData()
{
	vector<string> vStr;

	vStr = TXTDATA->txtLoad("etna.txt");

	int idx = 0;

	_level = atoi(vStr[idx++].c_str());
	_counter = atoi(vStr[idx++].c_str());
	_mv = atoi(vStr[idx++].c_str());
	_jm = atoi(vStr[idx++].c_str());
	_hp = atoi(vStr[idx++].c_str());
	_sp = atoi(vStr[idx++].c_str());
	_atk = atoi(vStr[idx++].c_str());
	_int = atoi(vStr[idx++].c_str());
	_def = atoi(vStr[idx++].c_str());
	_spd = atoi(vStr[idx++].c_str());
	_hit = atoi(vStr[idx++].c_str());
	_res = atoi(vStr[idx++].c_str());
	_exp = atoi(vStr[idx++].c_str());
	_next = atoi(vStr[idx++].c_str());
	_equipWeapon = (WEAPON_TYPE)atoi(vStr[idx++].c_str());
}

void etna::setItem(const char * itemName, bool isWear)
{
}

void etna::setMercenary(const char * characterName)
{
}

void etna::setHell(int hell)
{
}

int etna::getHell()
{
	return 0;
}
