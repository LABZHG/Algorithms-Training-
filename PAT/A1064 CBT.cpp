#include <bits/stdc++.h>

using std::vector;

vector<int> In;
vector<int> Tree;

int N=0,m=0;

bool cmp(int a,int b){
    return a<b;
}

void LevelReBuild(int r){   //�൱��ΪCBT����ÿһ��λ�ñ���һ���������У��ҳ����еĶ�Ӧֵ��Ҳ����˵�����������е�ÿ��ֵ����ֵ�ͱ�ŵ�������ϵ�����ϵĶ�Ӧ��ţ�
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
