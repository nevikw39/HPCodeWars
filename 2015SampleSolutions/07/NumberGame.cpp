// NumberGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR *Num1, *Num2;
	Num1 = argv[1];
	Num2 = argv[2];
	int AA = 0;
	int BB = 0;
	for (int i = 0; i < _tcslen(Num1);i++)
	{
		for (int j = 0; j < _tcslen(Num1); j++)
		{
			if (Num1[i] == Num2[j])
				i == j ? AA++ : BB++;
		}
	}
	_tprintf(_T("%dA%dB"),AA,BB);
	return 0;
}

