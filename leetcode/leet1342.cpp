#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int count=0;
        if(!num){
            return 0;
        }
        while(num){
            if(!(num%2)){
                num/=2;
                count+=1;
            }
            else{
                num-=1;
                count+=1;
            }
        }
    return count;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().numberOfSteps (num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
