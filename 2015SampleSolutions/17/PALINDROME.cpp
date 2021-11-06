// PALINDROME_v2.cpp : Defines the entry point for the console application.
//
#pragma warning (disable : 4996)
#include "stdafx.h"

#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

char NUMS[17] = "0123456789ABCDEF";
char data[21];
char base[3];

char *reverseST(char *ARR)
{
    for(int i=0; i<strlen(ARR)/2; i++)
    {
        swap(ARR[i], ARR[strlen(ARR)-i-1]);
    }
    return ARR;
}

int bitmatch(char letter)
{
    for(int i=0; i < strlen(NUMS); i++)
    {
        if( letter == NUMS[i])
            return i;
    }
    return 0;
}

bool palindrone(char *Marray)
{
    for(int i=0; i<strlen(Marray); i++)
    {
        if(Marray[i] == '0')
            continue;
        else
        {
            for(int j=0; j<(strlen(Marray)-i)/2; j++)
            {
                if(Marray[i+j] != Marray[strlen(Marray)-j-1])
                    return false;
            }
            break;
        }
    }
    return true;
}

char *detectD(char *num)
{
    int i = 0;
    while(1)
    {
       if(num[i] != '0')
            break;
       else
        i++;
    }

    int range = 20-i+1;     //VIP
    char *temp = new char[range];
    for(int j=0; j<range; j++)
    {
        temp[j] = num[i];
        i++;
    }

    return temp;
}

int main()
{
    int baseN, sum = 0, did = 0, rem = 0;
    char *num;
    char num1[21] = "";
    char num2[21] = "";
	char str[21] = ""; 
    char overflow[2] = "0";          
    
    char results[21] = "00000000000000000000";
    bool match = 1, found = 0;
	int round = 10;
    
	cin.getline(str, 21);    
    sscanf(str, "%s %s", data, base);

    baseN = atoi(base);
    
    strcpy(num1, data);
    strcpy(num2, num1);
    strcpy(num2, reverseST(data));

    while(match && round >0)
    {
        for(int i=0; i<=strlen(num1); i++)
        {
            sum = bitmatch(num2[strlen(num2)-i-1]) + bitmatch(num1[strlen(num1)-i-1]) + bitmatch(overflow[0]);
            if(sum >= baseN)
            {
                did = sum/baseN;
                rem = sum%baseN;
                _itoa(did, overflow, 10);
                results[20-i-1] = NUMS[rem];
            }
            else
            {
                _itoa(0, overflow, 10);
                results[20-i-1] = NUMS[sum];
            }
        }

        if(!palindrone(results))
        {
            char *num = new char[21];
            cout << results << endl;
            num = detectD(results);
            strcpy(num1, num);
            strcpy(num2, reverseST(num));
            delete [] num;
        }
        else
        {
			found = 1;
            match = 0;
        }

		round--;
    }

	if(found)
	{
		num = detectD(results);
		cout << num << endl;
		delete [] num;
	}
	else
	{
		cout << "NONE" << endl;
	}        		
     
	//delete [] str;   
	system("pause");
    return 0;
}


