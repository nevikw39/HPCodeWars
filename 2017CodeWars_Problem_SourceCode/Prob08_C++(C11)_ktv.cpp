#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
const int MAX = 200;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v, const vector<T> &c) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
    [&v, &c](size_t i1, size_t i2) {
      if(v[i1]==v[i2]){
        return c[i1] < c[i2];
      } else {
        return v[i1] < v[i2];
      }
    }
  );

  return idx;
}

int main() {
  int items,time,money;
  cin>>time>>money>>items;
  vector<int> length(items+1,0); //number of input lines
  vector<int> code(items+1,0);   //price of each song
  vector<int> price(items+1,0);
  vector<int> value(items+1,0);  //value of each song
  for(int i=1;i<items+1;i++) {
      cin>>length[i]>>code[i]>>price[i]>>value[i];
  }
  //dp[i][j][k], i represents the items from 1 to i, j represents length, k represents price, dp represents the best value
  vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(MAX, 0)));
  for(int i=1; i<items+1; i++) {
    for(int j=1; j<=time; j++) {
      for(int k=1 ; k<=money ; k++) {
        //consider the song only if the length is smaller than current time and price smaller than current money
        if(length[i]<=j && price[i]<=k) {
          dp[i][j][k] = max(dp[i-1][j][k] , dp[i-1][j-length[i]][k-price[i]] + value[i]);
        }
        else {
          dp[i][j][k] = dp[i-1][j][k];
        }
      }
    }
  }

  vector<int> x(MAX,0);  //1 if the song is chosen, 0 otherwise
  for(int i=items;i>1;i--) {
    if(dp[i][time][money]==dp[i-1][time][money]) {
      x[i] =0;
    }
    else {
      x[i] = 1;
      time -= length[i];
      money -= price[i];
    }
  }

  x[1]=(dp[1][time][money])?1:0;
  bool endline = false;
  for (auto i: sort_indexes(value, code)) {
    if(x[i]==1 && !endline) {
      cout << code[i];
      endline = true;
    } else if (x[i]==1){
      cout << endl << code[i];
    }
  }
}