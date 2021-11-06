#include <stdio.h>
#include <math.h>
using namespace std;
#define pi 3.141592653
#define const_e 2.718281828

int main() {
    double answer=0.0;
    double cosine_value=0.0;
    double y_time=0.0;
    double e_t=0.0;
    
    scanf("%lf",&y_time);
    
    if ((y_time<=0) || (y_time>5))
    {
        printf("Input time error!");
        return 1;
    }

    cosine_value = (double) cos(2*pi*y_time);
    
    e_t = (double) pow(const_e, (double) ((-1)*y_time));
  
    answer = (double) (e_t * cosine_value);
    
    printf("%.8lf\n",answer);
    
	return 0;
}
