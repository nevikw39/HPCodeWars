#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define point_size 3

int result = 1000;

struct point{
  int x;
  int y;     
  bool lock;
};

int distance(int x1, int y1, int x2, int y2){
    //printf("[(%d,%d)->(%d,%d)]",x1,y1,x2,y2);
    return (abs(x2-x1) + abs(y2-y1));   
}

void calculate (struct point *points, int count, int last, int dist) {
    int level = 0;
    for (int i=0; i<count;i++) {
        if (points[i].lock == true) {
           level = level + 1;                   
        }    
    }
    //printf ("level:%d\n",level);
    
    if (level == 0) {//first
        for (int i=0; i< count; i++){
            points[i].lock = true;
            //printf("level 0, lock %d, (%d,%d)\n", i, points[i].x,points[i].y);
            //system ("pause");
            calculate (points, count, i, distance(0,0,points[i].x,points[i].y));
            //system ("pause");
            points[i].lock = false;
            //printf("level 0, unlock %d\n", i);
        }      
    }
    
    else if (level == count) {//last
       int temp = dist + distance(points[last].x,points[last].y,0,0);
       if (temp < result) {
          result = temp;         
       } 
      //system ("pause");
    }
    
    else if (level > 0 && level < count){
      for (int i=0;i < count; i++) {
          if (points[i].lock == false) {
                points[i].lock = true;
                //printf ("level %d, lock %d\n", level, i);
                calculate (points, count, i, dist + distance(points[last].x,points[last].y,points[i].x,points[i].y));
                points[i].lock = false;
                //printf ("level %d, unlock %d\n", level, i);
          } 
      }        
    }
}


int parse (char* ptr) { 
    //printf ("input: %s\n", ptr);
    //printf ("string lenth: %d\n", strlen(ptr)); 
    bool flag = false;
    int count = 0;
    for (int i = 0; i < strlen(ptr); i++) {
        if (!flag && ptr[i] == '(') {
           flag = true;          
        } else if (flag && ptr[i] == ')') {
               flag = false;
               count = count + 1;       
        }
    }
    //printf("() count:%d\n", count);
    struct point points[count];
  
    int temp = 0;
    flag = false;
    char tempstr[point_size];
    int j = 0;
    for (int i = 0; i < strlen(ptr); i++) {
        if (!flag && ptr[i] == '(') {
           flag = true; 
           temp = i;         
        } else if (flag && ptr[i] == ')') {
               flag = false;
               memset( tempstr,'\0',point_size);
               strncpy (tempstr,&ptr[temp+1], i-temp-1);
               points[j].y = atoi (tempstr); 
               points[j].lock = false;
               //printf("Y:%d\n", points[j].y);
               j = j+1; 
        } else if (flag && ptr[i] == ',') {
            memset( tempstr,'\0',point_size);
            strncpy (tempstr,&ptr[temp+1], i-temp-1);
            points[j].x = atoi (tempstr);
            //printf("X:%d,", points[j].x);
            temp = i;   
        }
    }  
    
    calculate (points, count,0 , 0);
    
}

int main (void) {
 //FILE *file = NULL;
 //file = fopen("input.txt","r");
 
 char in[50];
 fgets (in, 50, stdin);
 
 //char in[] = "(1,1)(1,4)(2,4)(3,1)(3,3)(3,5)(4,2)(5,5)";
 int count = 0;
 struct point *points;
 parse (in);
 printf ("%d\n", result);
 //fclose(file);
 //system ("pause");
 return 0;
}
