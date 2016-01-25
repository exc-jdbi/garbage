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
#include <time.h>
#include <iostream>

#include "garbage.h"
#include "mnGarbage.h"

time_t t;
int random=0;
bool bRnd=false;

bool activateSRand(){
	time (&t);
	srand((unsigned int)t);;
	bRnd=true;
	return true;
}

int createString(const int &iSize,wchar_t **ppOut){	
	wchar_t alphanum[]=L"0123456789"
					   L"!#%^&Ύ½Ό™ή‰Ζ€#θόδ$!$£{°§1*-+±'?Ψψ}[»²³$£/&%η¬›|‹Ά@©®χ«]*"
					   L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					   L"abcdefghijklmnopqrstuvwxyz";

	int ret=-1;
	if((iSize>0)&&(ppOut)){
		if(!bRnd){activateSRand();}

		int iAlphanum=std::wcslen(alphanum);
		wchar_t *pOut=new wchar_t[iSize+1];
		wmemset(pOut,0,iSize+1);
		Garbage::setNews(pOut);

		for (int i=0;i<iSize;++i){
			random=(rand () % iAlphanum);
			if(random>=iAlphanum){i-=1;continue;}
			if(random<0){i-=1;continue;}
			pOut[i] = alphanum[random];
			if(pOut[i]==0){i-=1;}
		}
		if(std::wcslen(pOut)>0){
			*ppOut=pOut;
			ret=std::wcslen(pOut);
		}
	}
	return ret;
}
int createString(const int &iSize,char **ppOut){	
	char alphanum[]="0123456789"
					"!#%^&Ύ½Ό™ή‰Ζ€#θόδ$!$£{°§1*-+±'?Ψψ}[»²³$£/&%η¬›|‹Ά@©®χ«]*"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					"abcdefghijklmnopqrstuvwxyz";

	int ret=-1;
	if((iSize>0)&&(ppOut)){
		if(!bRnd){activateSRand();}

		int iAlphanum=std::strlen(alphanum);
		char *pOut=new char[iSize+1];
		memset(pOut,0,iSize+1);
		Garbage::setNews(pOut);

		for (int i=0;i<iSize;++i){
			random=(rand () % iAlphanum);
			if(random>=iAlphanum){i-=1;continue;}
			if(random<0){i-=1;continue;}
			pOut[i] = alphanum[random];
			if(pOut[i]==0){i-=1;}
		}
		if(std::strlen(pOut)>0){
			*ppOut=pOut;
			ret=std::strlen(pOut);
		}
	}
	return ret;
}

int create_RndStringW(const int &iLen,wchar_t **ppOut){
	return createRndStringW(iLen,ppOut);
}
int _stdcall createRndStringW(const int &iLen,wchar_t **ppOut){
	return createString(iLen,ppOut);
}

int create_RndStringA(const int &iLen,char **ppOut){
	return createRndStringA(iLen,ppOut);
}
int _stdcall createRndStringA(const int &iLen,char **ppOut){
	return createString(iLen,ppOut);
}