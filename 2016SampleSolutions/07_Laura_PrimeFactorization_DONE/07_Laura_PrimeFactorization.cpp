#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long int num);

int main()
{
    long long int num;
	int exp=0;
	cin>>num;
	if(num<=1)
		cout<<"0"<<endl;
	else
	{
		for(long long int i=2; i<=num; i++)
		{
			while(num%i==0 && isPrime(i))
			{
				num=num/i;
				exp++;
			}
			if(exp>0)
				cout<<i<<" "<<exp<<endl;
			exp=0;
		}
	}
    return 0;
}

bool isPrime(long long int num)
{
    for(long long int i=2; i<=sqrt(num); i++)
        if(num%i==0)
            return false;
    return true;
}
