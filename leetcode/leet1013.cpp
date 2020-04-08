#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(!A.size()){
            return false;
        }
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        if(sum%3){
            return false;
        }
        int part=sum/3;
        int count=0,partSum=0;
        for(int i=0;i<A.size();i++){
            partSum+=A[i];
            if(partSum==part){
                count++;
                partSum=0;
                if((count == 2) && (A.size()-i-1)){
                    return true;
                }
            }
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        
        bool ret = Solution().canThreePartsEqualSum(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
