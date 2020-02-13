#include <bits/stdc++.h>

bool Judge(long long a,long long b,long long c){
    if((a>0)&&(b>0)&&(a+b)<0){
        return true;
    }
    else if((a<0)&&(b<0)&&(a+b)>=0){   //不要只想溢出，还要想源操作数是什么样子（起-终）PS：相加等于0也是负溢出（非负）
        return false;
    }
    else{
        return ((a+b)>c);  //直接在外面不传参比较可能有问题，需要临时变量……函数内无此问题
    }
}

int main(){

    int T=0;
    scanf("%d",&T);
    long long A=0,B=0,C=0;
    for(int i=0;i<T;i++){
        scanf("%lld %lld %lld",&A,&B,&C);
        if(Judge(A,B,C)){
            printf("Case #%d: true\n",i+1);
        }
        else{
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}
