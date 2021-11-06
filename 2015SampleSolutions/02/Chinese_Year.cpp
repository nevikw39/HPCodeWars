// Chinese_Year.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"

int _tmain(int argc, _TCHAR* argv[])
{
    int year = 0;

	scanf_s("%d",&year);

	int sky;
	if (year<=3)
	{
	sky = (year+57-1)%10;
	}
	else
    {
	sky = (year-3)%10-1;
	}
	if (sky==-1)
	{
	sky=9;
	}

    int ground;
	if (year<=3)
	{
	ground = (year+57)%12;
	}
	else
	{
	ground = (year-3)%12;	
	}

    char c_ground;
	
	if (ground==0)
	{
    c_ground = char(toascii(76));
	}
	else
	{
    c_ground = char(toascii(ground+64));
	}
	printf("\n%d%c\n", sky, c_ground);

	system("PAUSE"); 

	return 0;

}