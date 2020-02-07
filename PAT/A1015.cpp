#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

typedef unordered_map<int,bool> PrimeList;

PrimeList L;

bool isPrime(int n){
    if(n==1) return false;
    int sqr=(int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){  //根号n要遍历到 不然打的表是错的……太低级了
        if(!(n%i)){
            return false;
        }
    }
    return true;
}

void Build(int n){
    for(int i=1;i<n;i++){  //0放进去干啥？？？干啥？？？低级错误……
        if(isPrime(i)){
            L[i]=true;
        }
    }
}

int convert(int n,int d){
    vector<int> arr;
    while(n){
        arr.push_back(n%d);
        n/=d;
    }
    int val=0;
    for(int i=0;i<arr.size();i++){
        val*=d;
        val+=arr[i];
    }
    return val;
}

int main(){
    int N=0,D=0;
    Build(100000);
    while(scanf("%d",&N)!=EOF){
        if(N<0){
            break;
        }
        bool now=L[N];
        scanf("%d",&D);
        int judge_val=convert(N,D);
        if(L[judge_val]&&now){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
