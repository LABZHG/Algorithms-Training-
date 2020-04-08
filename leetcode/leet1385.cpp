#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        if(!arr1.size() || !arr2.size()){
            return 0;
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        if(abs(arr1[0]-arr2.back())<=d && abs(arr1.back()-arr2[0])<=d){
            return 0;
        }
        int count=0,flag;
        for(int num:arr1){
            flag=1;
            for(int i=0;i<arr2.size();i++){
                if(abs(num-arr2[i])<=d){
                    flag=0;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> arr2 = stringToIntegerVector(line);
        getline(cin, line);
        int d = stringToInteger(line);
        
        int ret = Solution().findTheDistanceValue(arr1, arr2, d);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
