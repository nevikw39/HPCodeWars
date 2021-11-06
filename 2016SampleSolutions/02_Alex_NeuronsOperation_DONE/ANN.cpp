// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning (disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int num_of_vectors=0;
	float bias=0;
	float *input_vectors=NULL, *weight=NULL;

	scanf("%d %f \n", &num_of_vectors, &bias);

	input_vectors = (float *) malloc(sizeof(float)*num_of_vectors);
	weight = (float *) malloc(sizeof(float)*num_of_vectors);

	if (input_vectors == NULL)
		exit(0);

	for (int i = 0; i < num_of_vectors; i++)
	{
		scanf("%f", &(input_vectors[i]));
	}


	for (int i = 0; i < num_of_vectors; i++)
	{
		scanf("%f", &(weight[i]));
	}

	// Calculate result
	float result = 0;
	result += bias;

	for (int i = 0; i < num_of_vectors; i++)
	{
		result += input_vectors[i] * weight[i];
	}

	if (result >= 0)
		printf("1");
	else
		printf("0");

	//Release memory which were allocated
	free(input_vectors);
	free(weight);
	int standby = _getch();
	return 0;
}

