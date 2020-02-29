include <bits/stdc++.h>

using namespace std;

int numofOne(int n){
        int count=0;
        while(n){
            if((n%2)==1){
                count+=1;
            }
            n /=2;
        }
        return count;
    }
    bool cmpOne(int a,int b){
        int numA=0,numB=0;
        numA=numofOne(a);
        numB=numofOne(b);
        if(numA == numB){
            return a<b;
        }
        else{
            return numA < numB;
        }
    }
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmpOne);
        return arr;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        
        vector<int> ret = Solution().sortByBits(arr);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
