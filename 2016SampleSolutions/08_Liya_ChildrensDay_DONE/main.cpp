#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int candy(vector<int>& ratings) {

    if (ratings.size() == 0) {
            return 0;
    }

    int candies [ratings.size()];
    candies[0] = 1;

    //from let to right
	for (int i = 1; i < ratings.size(); i++) {
		if (ratings[i] > ratings[i - 1]) {
			candies[i] = candies[i - 1] + 1;
		} else {
			// if not ascending, assign 1
			candies[i] = 1;
		}
	}

	int result = candies[ratings.size() - 1];

	//from right to left
	for (int i = ratings.size() - 2; i >= 0; i--) {
        int cur = 1;
		if (ratings[i] > ratings[i + 1]) {
			cur = candies[i + 1] + 1;
		}

		result += max(cur, candies[i]);
		candies[i] = cur;
	}

	return result;
}


int main()
{
    vector<int> ratings;

    string input;
    //cout<<"Enter the score array of children?" <<"\n";
    getline(cin , input , '\n' );

    string buf;
    stringstream ss(input);

    while (ss >> buf){
        int score = atoi(buf.c_str());
        ratings.push_back(score);
    }

    int result = candy(ratings);
    cout << result << endl;

    system("PAUSE");
    return 0;
}
