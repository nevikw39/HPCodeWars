// HP_Code_War_Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"

struct point
{
  double x, y;
};

double Area(point A, point B, point C)
{
  double a = 0 , b = 0 ,c = 0;

  a = sqrt ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
  b = sqrt ((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
  c = sqrt ((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));

  double p = (a+b+c)/2;

  return sqrt((p-a)*(p-b)*(p-c)*p);
}

bool isInTriangle(point A, point B, point C, point D)
{
   if (Area(A,B,D) +  Area(B,C,D) + Area(C,A,D) > Area (A,B,C))
   {
	   return false;
   }
   return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	struct point H,P,C,W;
	
	scanf_s("(%d,%d) (%d,%d) (%d,%d) (%d,%d)",&(H.x),&(H.y),&(P.x),&(P.y),&(C.x),&(C.y),&(W.x),&(W.y));

	double TriangleArea = Area(H,P,C);

	if (TriangleArea == 0)
	{
    printf("Triangle doesn't exist.\n");
	}
	else
    {
	bool isT = isInTriangle(H, P, C, W);

	if (isT == true)
	{
	printf("Point is within the Triangle.\n");
	}
	else
	{
	printf("Point is NOT within the Triangle.\n");	
	}
	
	}

	system("PAUSE"); 
	return 0;
}

