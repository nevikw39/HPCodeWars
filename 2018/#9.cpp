#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <cstring>
#include <limits>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.

uint64_t popUntilHigher (stack<int> &myStack, int tip){
    if (myStack.empty())
        return 0;
    uint64_t result =0, count =0;
    int currentHeight = -1;
    //cout<<"Entering pop: "<<myStack.top()<<", "<<tip<<endl;
    while (!myStack.empty()){
        int temp = myStack.top();
        //cout<<"Current top = "<<temp<<", currentHeight = "<<currentHeight<<"count = "<<count<<endl;
        if (temp == currentHeight)
            count+=1;
        else{
            result+=count*(count-1);
            //cout<<currentHeight<<", "<<count<<endl;
            currentHeight = temp;
            count =1;
        }        
        if (myStack.top() >= tip)
            break;
        else
            myStack.pop();
        
    }    
    if (count >1)
        result+=count*(count-1);
    //cout<<"returning result = "<<result<<endl;
    return result;
}

uint64_t solve(vector<int> arr) {
    if (arr.size() <2)
        return 0;
    if (arr.size() ==2) {
        if (arr[1]==arr[0])
            return 1;
        else
            return 0;
    }
    uint64_t result =0;
    stack<int> myStack;
    myStack.push(arr[0]);
    for (int i=1; i<arr.size(); ++i){

        if (arr[i]<=myStack.top())
            myStack.push(arr[i]);
        else{
            result+=popUntilHigher(myStack, arr[i]);
            myStack.push(arr[i]);
        }
    }
    result+=popUntilHigher(myStack, 1000000);
    cout<<result<<endl;
    return result;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    uint64_t result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
