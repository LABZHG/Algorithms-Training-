#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isLeap(int year){
        if((!(year%4) && (year%100))|| !(year%400)){
            return true;
        }
        else{
            return false;
        }
    }
    int sectionDays(int y1,int y2){
        int ybig=max(y1,y2);
        int ysmall=min(y1,y2);
        if((ybig-ysmall) == 1){
            return 0;
        }
        int ans=0;
        ans=((ybig-ysmall)-1)*365;
        ans+=((ybig-1)/4-ysmall/4);
        ans-=((ybig-1)/100-ysmall/100);
        ans+=((ybig-1)/400-ysmall/400);
        return ans;
    }
    int datePoint(int y,int m,int d){
        int s=0;
        for(int i=1;i<m;i++){
            switch(i){
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:{
                s+=31;
                break;
            }
            case 4:case 6:case 9:case 11:{
                s+=30;
                break;
            }
            case 2:{
                if(isLeap(y)){
                    s+=29;
                    break;
                }
                else{
                    s+=28;
                    break;
                }
            }
            }
        }
        s+=d;
        return s;
    }
    int daysBetweenDates(string date1, string date2) {
        int sum=0;
        int year1=0,year2=0;
        int month1=0,month2=0;
        int day1=0,day2=0;
        year1=stoi(date1.substr(0,4));
        year2=stoi(date2.substr(0,4));
        month1=stoi(date1.substr(5,6));
        month2=stoi(date2.substr(5,6));
        day1=stoi(date1.substr(8,9));
        day2=stoi(date2.substr(8,9));
        if(year1>year2){
            if(isLeap(year2)){
                sum=datePoint(year1,month1,day1)+(366+sectionDays(year2,year1)-datePoint(year2,month2,day2));
            }
            else{
                sum=datePoint(year1,month1,day1)+(365+sectionDays(year2,year1)-datePoint(year2,month2,day2));
            }
        }
        else if(year1==year2){
            sum=abs(datePoint(year1,month1,day1)-datePoint(year2,month2,day2));
        }
        else{
            if(isLeap(year1)){
                sum=datePoint(year2,month2,day2)+(366+sectionDays(year2,year1)-datePoint(year1,month1,day1));
            }
            else{
                sum=datePoint(year2,month2,day2)+(365+sectionDays(year2,year1)-datePoint(year1,month1,day1));
            }
        }
        return sum;
        
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
        string date1 = stringToString(line);
        getline(cin, line);
        string date2 = stringToString(line);
        
        int ret = Solution().daysBetweenDates(date1, date2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
