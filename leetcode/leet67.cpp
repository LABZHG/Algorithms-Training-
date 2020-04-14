#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        ans.reserve(max(a.size(),b.size())+1);
        int i=a.size()-1,j=b.size()-1,c=0;
        while(i>=0 || j>=0 || c){
            c+=( j>=0? (b[j]-'0'):0 );
            c+=( i>=0? (a[i]-'0'):0 );
            ans.push_back((c&1)+'0');
            c>>=1;
            j--;
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
