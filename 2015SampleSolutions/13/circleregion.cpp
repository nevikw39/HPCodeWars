#include <iostream>

using namespace std;

unsigned int calculate_edge(unsigned int n){
if (n==2){
    return 4;
}else{

    return calculate_edge(n-1)+4*(n-1);
}

}
unsigned int calculate_vetex(unsigned int n){
    if (n==2){
    return 2;
}else{

    return calculate_vetex(n-1)+2*(n-1);
}

}
unsigned int calculate_region(unsigned int n){
    unsigned int e=2*n*(n-1);
    unsigned int v=n*(n-1);

//return calculate_edge(n)-calculate_vetex(n)+2; //Euler formula R=E-V+2
return e-v+2; //Euler formula R=E-V+2
}
int main()
{
    unsigned int i ;
    while( cin >> i){

   // cout <<"edge="<< calculate_edge(i) <<endl;
  //  cout <<"vetex="<< calculate_vetex(i) <<endl;
  //  cout <<"region=" << calculate_region(i)<<endl;
      cout << calculate_region(i)<<endl;
    }
    return 0;
}
