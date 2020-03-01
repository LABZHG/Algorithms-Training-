#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        int DP[nums.size()]={0};
        int ext=0;
        DP[0]=nums[0];
        for(int n:nums){
            if(n>DP[ext]){
                ext++;
                DP[ext]=n;
            }
            else{
                int left=0,right=ext;
                while(left<right){
                    int mid=left+(right-left)/2;
                    if(DP[mid]<n){
                        left=mid+1;
                    }
                    else{
                        right=mid;
                    }
                }
            DP[left]=n;
            }  
        }
        return ext+1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().lengthOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
