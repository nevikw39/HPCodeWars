#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string s;
stack<char> S;

int main() {
	cin >> s;
	for(auto c: s) {
		if(S.empty()) S.push(c);
		else if(S.top() == c) S.pop();
		else S.push(c);
	}
	puts(S.empty()? "Saved!": "BOOOOOOOOM!");
}