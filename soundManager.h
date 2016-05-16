#pragma once
#include "singletonBase.h"
#include <map>
#include <string>

//fmod.hpp 추가
#include "inc/fmod.hpp"

//lib 링크
#pragma comment(lib, "lib/fmodex_vc.lib")

//사운드 버퍼(크기)
#define TOTAL_SOUND_CHANNEL 15

using namespace FMOD;

class soundManager
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef arrSounds::iterator arrSoundsIter;
	typedef map<string, Channel**> arrChannes;
	typedef arrChannes::iterator arrChannesIter;

private:
	System* _system;
	Sound** _sound;
	Channel** _channal;
	arrSounds _mTotalSounds;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	//사운드 추가
	void addSound(string keyName, string soundName, bool background = false, bool loop = false);
	void play(string keyName, float volume);
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);
	bool isPauseSound(string keyNmae);
	bool isPlaySound(string keyName);
};

