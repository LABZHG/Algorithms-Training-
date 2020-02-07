#include <bits/stdc++.h>

using std::vector;
using std::stack;


vector<vector<int> > POP;
int M=0,N=0,K=0;

void Read(){
    scanf("%d %d %d",&M,&N,&K);
    vector<int> RE(N);
    POP.resize(K,RE);
    RE.clear();
    vector<int>().swap(RE);
    if(N && K){
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&POP[i][j]);
        }
      }
    }
    else{
        return;
    }
}

bool is_possible(int ROW){
    stack<int> ST;    //is the single row conform to the designative stack
    int cnt=0;
    for(int j=1;j<=N;j++){
        ST.push(j);           //'random' pop check for every push
        if(ST.size()<=M){
            while((!ST.empty()) && (POP[ROW][cnt]==ST.top())){
                ST.pop();
                cnt+=1;
            }
        }
        else{
            while(!ST.empty()){ ST.pop(); }           //clear the space to avoid residual element which leads to wrong answer
            return false;
        }
    }
    if(cnt==N){       //N in and N out, no NEED to pop clear
        return true;
    }
    else{
        while(!ST.empty()){ ST.pop(); }
        return false;
    }
}

int main(){
    int flag=0;
    //int input;
    Read();
    /**
    if(input){
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            printf("%d ",POP[i][j]);
        }
        printf("\n");
      }
    }
    **/
    for(int r=0;r<K;r++){
        flag=is_possible(r);
        if(flag){
            printf("Yes\n");    //PTA上的题目是YES……这种全对变全错的哑巴亏不能再吃了……必须中文注释……
        }
        else{
            printf("No\n");
        }
    }
}
