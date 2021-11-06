// 2015codewar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
using namespace std;
#define MAX_SIZE 256
bool verifyID(char location, int number);
void load_file(char* file_path);

int _tmain(int argc, _TCHAR* argv[])
{

	std::string input;
	cout << "Please enter the employee ID:" << "\n";
	cin >> input;

	if (input.size() > 9 || input.size() < 9){
		cout << "Fail" << "\n";
		system("Pause");
		return 0;
	}

	char *id = new char[input.length() + 1];
	memcpy(id, input.c_str(), input.size());
	
	char location = id[0];
	memmove(id, id + 1, strlen(id));

	int id_number = atoi(id);

	if (verifyID(location, id_number)){
		cout << "Sucess\n";
	}else{
		cout << "Fail\n";
	}
	system("Pause");
	return 0;
}

bool verifyID(char location, int id_number){

	int location_number = 0;

	switch (location){
	case 'A':
	case 'a':
		location_number = 10;
		break;
	case 'E':
	case 'e':
		location_number = 11;
		break;
	case 'P':
	case 'p':
		location_number = 12;
		break;
	case 'M':
	case 'm':
		location_number = 13;
		break;

	default:
		return false;
	}

	location_number = (location_number / 10) + (location_number % 10) * 8;
	int code = id_number % 10;
	id_number /= 10;
	int count = 1;
	int sum = 0;
	for (int i = 1000000; i > 0; i /= 10){
		int temp = (id_number / i)*count;
		id_number = id_number % i;
		sum += temp;
		count++;
	}
	sum = (sum + location_number) % 10;
	if ((10 - sum) == code){
		return true;
	}
	
return false;
}