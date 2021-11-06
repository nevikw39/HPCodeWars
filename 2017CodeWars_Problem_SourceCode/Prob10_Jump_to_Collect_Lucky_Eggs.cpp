#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n=0;
    cin>>n;

    if(n<=0)
        cout<<"0"<<endl;
    else
    {
        vector<int> eggs(n);
        for(int i=0; i<n; i++)
            cin>>eggs[i];

        int dropMax=0, pickMax=0, temp=0;
        for(int i=0; i<eggs.size(); i++)
        {
            temp = pickMax;
            if(dropMax + eggs[i] > pickMax)
                pickMax = dropMax + eggs[i];
            dropMax = temp;
        }
        cout<<pickMax<<endl;
    }

    return 0;
}
