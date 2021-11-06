#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int coin, amount, number=0;
	vector<int> coins;
	cin>>amount;
	while(cin>>coin && coin>0)
        coins.push_back(coin);
	if (coins.size()==0)
		number = -1;

	vector<vector<int> > arr;
	vector<int> vec(amount+1);
	for(int i=0; i<=coins.size(); i++)
		arr.push_back(vec);

	for(int i=0; i<=coins.size(); i++)
	{
		for(int j=0; j<=amount; j++)
		{
			if (i==0)
				arr[i][j] = -1;
			else if (j==0)
				arr[i][j] = 0;
			else if (j<coins[i-1])
				arr[i][j] = arr[i-1][j];
			else
			{
				if (arr[i][j-coins[i-1]] < 0)
					arr[i][j] = arr[i-1][j];
				else
				{
					if(arr[i-1][j] < 0)
						arr[i][j] = 1+arr[i][j-coins[i-1]];
					else
						arr[i][j] = min(arr[i-1][j], 1+arr[i][j-coins[i-1]]);
				}
			}
		}
	}

	number = arr[coins.size()][amount];
	cout<<number<<endl;

	return 0;
}

