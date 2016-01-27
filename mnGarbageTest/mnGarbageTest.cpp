/*
 * Copyright © exc-jdbi 2016
 *
 * © mnGarbage 2016
 *
 * mnGarbage - www.github.com/exc-jdbi/garbage
 *
 * mnGarbage is Free and Opensource Software
*/

#include "stdafx.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "mnGarbage.h"

time_t t;
#define IMIN 30
#define IMAX (80-IMIN)

int _tmain(int argc, _TCHAR* argv[]){	
	time (&t);
	srand((unsigned int)t);
	Sleep(3);
		
	std::string sRnd1,sRnd2;
	std::wstring wsRnd1,wsRnd2;

	int iStrLen=(rand()%IMAX)+IMIN;
	wchar_t *bufferW1=0,**pOutW1=&bufferW1;
	int iRndStrW1=createRndStringW(iStrLen,pOutW1);
	wsRnd1.assign(*pOutW1);

	iStrLen=(rand()%IMAX)+IMIN;
	char *bufferA1=0,**pOutA1=&bufferA1;
	int iRndStrA1=createRndStringA(iStrLen,pOutA1);
	sRnd1.assign(*pOutA1);

	iStrLen=(rand()%IMAX)+IMIN;
	wchar_t *bufferW2=0,**pOutW2=&bufferW2;
	int iRndStrW2=createRndStringW(iStrLen,pOutW2);
	wsRnd2.assign(*pOutW2);

	iStrLen=(rand()%IMAX)+IMIN;
	char *bufferA2=0,**pOutA2=&bufferA2;
	int iRndStrA2=createRndStringA(iStrLen,pOutA2);
	sRnd2.assign(*pOutA2);
	closeGarbage();

	startGarbage();
	int iCount=10;
	int iCrs=0;

	std::vector<std::wstring>vwcRnd;
	wchar_t *bufferW3=0,**pOutW3=&bufferW3;
	for(int i=0;i<iCount;i++){
		iStrLen=(rand()%IMAX)+IMIN;
		iCrs=createRndStringW(iStrLen,pOutW3);
		if((iCrs>=IMIN)&&(iCrs<=(IMAX+IMIN))){
			vwcRnd.push_back(*pOutW3);
		}else{i--;}
	}
	std::vector<std::string>vcRnd;
	char *bufferA3=0,**pOutA3=&bufferA3;
	for(int i=0;i<iCount;i++){
		iStrLen=(rand()%IMAX)+IMIN;
		iCrs=createRndStringA(iStrLen,pOutA3);
		if((iCrs>=IMIN)&&(iCrs<=(IMAX+IMIN))){
			vcRnd.push_back(*pOutA3);
		}else{i--;}
	}
	closeGarbage();

	getchar();
	return 0;
}

/*
Start GarbageStart ...
... Exit GarbageStart.

SetNews 00A123A0
SetNews 00A123B0
SetNews 00A123C0
SetNews 00A123D0

Start GarbageClose ...
00A123A0 delete ...
00A123B0 delete ...
00A123C0 delete ...
00A123D0 delete ...
... Exit GarbageClose.


Start GarbageStart ...
... Exit GarbageStart.

SetNews 00A123AA
SetNews 00A124AB
SetNews 00A125AC
SetNews 00A126AD
SetNews 00A127AE
SetNews 00A128AF
SetNews 00A129AG
SetNews 00A130AH
SetNews 00A131AI
SetNews 00A132AJ
SetNews 00A133AK
SetNews 00A134AL
SetNews 00A135AM
SetNews 00A136AN
SetNews 00A137AO
SetNews 00A138AP
SetNews 00A139BA
SetNews 00A140BB
SetNews 00A141BC
SetNews 00A142BD

Start GarbageClose ...
00A123AA delete ...
00A124AB delete ...
00A125AC delete ...
00A126AD delete ...
00A127AE delete ...
00A128AF delete ...
00A129AG delete ...
00A130AH delete ...
00A131AI delete ...
00A132AJ delete ...
00A133AK delete ...
00A134AL delete ...
00A135AM delete ...
00A136AN delete ...
00A137AO delete ...
00A138AP delete ...
00A139BA delete ...
00A140BB delete ...
00A141BC delete ...
00A142BD delete ...
... Exit GarbageClose.
*/
