#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	int length, num;
	string s;
	cin>>length;
	vector<vector<int> > board(length, vector<int>(length)), check(length, vector<int>(length, 0));
	vector<int> lucky_num;

	for(int i=0; i<length; i++)
    {
		for(int j=0; j<length; j++)
        {
			cin>>s;
			if(s=="*")
			{
                board[i][j] = 0;
                check[i][j] = 1;
			}
            else
            {
                stringstream ss;
                ss << s;
                ss >> board[i][j];
            }
        }
    }
    while(cin>>num && num!=0)
        lucky_num.push_back(num);

    for(int k=0; k<lucky_num.size(); k++)
        for(int i=0; i<length; i++)
            for(int j=0; j<length; j++)
                if(lucky_num[k]==board[i][j])
                    check[i][j] = 1;

    int line=0, sum=0;
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
            sum += check[i][j];
        if(sum==length)
            line++;
        sum=0;
    }

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
            sum += check[j][i];
        if(sum==length)
            line++;
        sum=0;
    }

    for(int i=0; i<length; i++)
        sum += check[i][i];
    if(sum==length)
        line++;
    sum = 0;

    for(int i=0; i<length; i++)
        sum += check[i][length-i-1];
    if(sum==length)
        line++;

    cout<<line<<endl;

    return 0;
}

