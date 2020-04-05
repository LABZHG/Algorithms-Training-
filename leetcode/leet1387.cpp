#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    struct Num{
        int priority;
        int value;
        friend bool operator < (const Num &a, const Num &b) {
            if(a.priority==b.priority) return a.value > b.value;
            else{
                return a.priority > b.priority;
            }
        }
    };
    
    int getWeight(int num){
        int count=0;
        while(num!=1){
            if(num%2){
                num=3*num+1;
            }
            else{
                num/=2;
            }
            count++;
        }
        return count;
    }
    int getKth(int lo, int hi, int k) {
        if(lo==hi){
            return lo;
        }
        priority_queue<Num> Array;
        for(int i=lo;i<=hi;i++){
            int p=getWeight(i);
            Num *n=new Num; 
            n->priority=p;
            n->value=i;
            Array.push((*n));
        }
        for(int j=0;j<k-1;j++){
            Array.pop();
        }
        Num ans=Array.top();
        return ans.value;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int lo = stringToInteger(line);
        getline(cin, line);
        int hi = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().getKth(lo, hi, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
