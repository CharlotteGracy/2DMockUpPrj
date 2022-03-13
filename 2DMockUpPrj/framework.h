﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <assert.h>


//STL
#include <vector>

//UTIL

#include "SingleTon.h"
#include "struct.h"
#include "Logger.h"



//=======================================
// ## 게임 그룹 ##
//=======================================

enum class GROUP_GAMEOBJ {
	DEFAULT,
	PLAYER,
	SIZE,
};

enum class GROUP_SCENE {
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	SIZE,
};


//===============================
// ##		디파인문		##
//===============================

#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1280
#define WINSIZEY 720
#define WINSTYLE		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


//=======================================
// ## 전역변수(인스턴스, 윈도우 핸들) ##
//=======================================

extern HINSTANCE hInst;
extern HWND hWnd;




//Core & Manager
#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CResourceManager.h"
using namespace std;
