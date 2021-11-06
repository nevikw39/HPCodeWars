// rail_fence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
	int num_of_columns = 0;
	unsigned int length_of_input_string = 0;

	string input_string;
 
	std::getline(std::cin, input_string);

	std::size_t begin_of_string = input_string.find('"');
	std::size_t end_of_string = input_string.rfind('"');

	// Format checking
	if (begin_of_string != 0)
	{
		printf("Syntax Error!!\n");
		_getch();
		exit(1);
	}
	if (begin_of_string == end_of_string)
	{
		printf("The string is empty!!\n");
		_getch();
		exit(1);
	}

	if (input_string.substr(end_of_string + 1).length() == 0)
	{
		printf("No column number!!\n");
		_getch();
		exit(1);
	}

	// Get the number of columns
	num_of_columns = std::stoi(input_string.substr(end_of_string+1));
	
	if (num_of_columns <= 0)
	{
		printf("Column number Incorrect!!\n");
		_getch();
		exit(1);
	}


	//Replace space with star
	for (unsigned int i = begin_of_string+1; i < end_of_string; i++)
	{
		if (input_string.at(i) == ' ')
			input_string.at(i) = '*';
	}
	//remove the number of column from the string
	input_string = input_string.substr(begin_of_string, end_of_string + 1);

	//std::cout << input_string << input_string.length() << "\n";
	//Add * to the end of the string
	int num_of_left = (input_string.length() - 2) % num_of_columns;
	if (num_of_left != 0)
		input_string.insert(end_of_string, num_of_columns - num_of_left, '*');

	//Get the number of rows
	int num_of_rows = (input_string.length()-2) / num_of_columns;

	//print the encyrpted string
	std::cout << "\"";
	for (int j = 0; j < num_of_columns; j++)
	{
		for (int k = 0; k < num_of_rows; k++)
		{
			std::cout << input_string.at(k*num_of_columns + j + 1);
		}
	}
	std::cout << "\"";

	int standby = _getch();
	return 0;
}

