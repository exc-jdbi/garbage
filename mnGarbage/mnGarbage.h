/*
 * Copyright © exc-jdbi 2016
 *
 * © mnGarbage 2016
 *
 * mnGarbage - www.github.com/exc-jdbi/garbage
 *
 * mnGarbage is Free and Opensource Software
*/

#pragma once
#ifndef __MY_GARBAGE_DLL_H__
#define __MY_GARBAGE_DLL_H__
#include "garbage.h"
#define EXP32  extern "C" __declspec(dllexport)

//Widestrings
EXP32 int create_RndStringW(const int &iLen,wchar_t **ppOut);
EXP32 int _stdcall createRndStringW(const int &iLen,wchar_t **ppOut);


//Ansistrings
EXP32 int create_RndStringA(const int &iLen,char **ppOut);
EXP32 int _stdcall createRndStringA(const int &iLen,char **ppOut);

//Garbage
EXP32 bool start_Garbage();
EXP32 bool _stdcall startGarbage();

EXP32 bool close_Garbage();
EXP32 bool _stdcall closeGarbage();
#endif