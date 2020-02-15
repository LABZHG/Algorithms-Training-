#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DPTable;
        int MAXN=INT_MAX/2;
        DPTable.push_back(0);
        DPTable.resize(amount+1,MAXN);
        for(int i=1;i<=amount;i++){
            for(int j:coins){
                if(j<=i){
                    DPTable[i]=min(DPTable[i],(DPTable[i-j]+1));
                }
            }
        }
        if(DPTable[amount]>amount){
            return -1;
        }
        else{
            return DPTable[amount];
        }
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
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
