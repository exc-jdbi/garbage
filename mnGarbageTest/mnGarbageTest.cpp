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

