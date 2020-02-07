#include <bits/stdc++.h>

using std::vector;

vector<int> In;
vector<int> Tree;

int N=0,m=0;

bool cmp(int a,int b){
    return a<b;
}

void LevelReBuild(int r){   //相当于为CBT树上每一个位置遍历一遍中序序列，找出其中的对应值（也可以说给中序序列中的每个值按照值和编号的数量关系找树上的对应编号）
    if(r<N){
        LevelReBuild((2*r+1));
        Tree[r]=In[m];
        m+=1;
        LevelReBuild((2*r+2));
    }
}

int main(){
    int tmp=0;

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        In.push_back(tmp);
    }
    sort(In.begin(),In.end(),cmp);
    Tree.resize(In.size());
    LevelReBuild(0);

    printf("%d",Tree[0]);
    for(int j=1;j<N;j++){
        printf(" %d",Tree[j]);
    }

    return 0;
}
