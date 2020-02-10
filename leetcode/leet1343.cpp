#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int count=0,sum=(k*threshold);
        int tempSum=0;
        for(int j=0;j<k;j++){
            tempSum+=arr[j];
        }
        count=(tempSum>=sum);
        for(int i=k;i<arr.size();i++){
            tempSum-=arr[i-k];
            tempSum+=arr[i];
        count+=(tempSum>=sum);
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int threshold = stringToInteger(line);

        int ret = Solution().numOfSubarrays(arr, k, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
