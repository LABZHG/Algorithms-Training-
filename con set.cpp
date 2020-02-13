#include <bits/stdc++.h>

using std::vector;
using std::queue;
using std::cout;
/*
typedef struct GNode *Graph;
struct GNode{
    int v;
    int weight;
    GNode(){};
    GNode(int _a,int _b): v(_a),weight(_b){}
};

vector<vector<GNode> > G;
*/
typedef vector<vector<int> > Graph;
Graph G;
int N=0,E=0;
vector<bool> visit;

void DFS(int num,int dep,Graph LG){
    visit[num]=true;
    printf("%d ",num);  //������==������
    for(int i=0;i<(LG[num].size());i++){
        int vnum=LG[num][i];
        if(!visit[vnum]){
            DFS(vnum,dep++,LG);
        }
    }
}

void Traversal_D(Graph L){
    for(int j=0;j<N;j++){
        if(!(visit[j])){
            printf("{ ");
            DFS(j,1,L);
            printf("}\n");
        }
    }
}

void BFS(int id,bool flag[]){
    queue<int> tmp;
    int vnum=0;
    tmp.push(id);
    flag[id]=true;
    while(!tmp.empty()){
        vnum=tmp.front();
        tmp.pop();
        printf("%d ",vnum);  //�μǣ�����==���ʣ����==������
        int bnum=0;
        for(int i=0;i<G[vnum].size();i++){
            bnum=G[vnum][i];
            if(!(flag[bnum])){
                tmp.push(bnum);
                flag[bnum]=true;
            }
        }

    }

}

void Traversal_B(bool in[]){
    for(int j=0;j<N;j++){
        if(!in[j]){
            printf("{ ");
            BFS(j,in);
            printf("}\n");
        }
    }

}

int main(){
    scanf("%d",&N);
    G.resize(N);
    visit.resize(N+5,false);

    scanf("%d",&E);
    int start=0,dist=0;
    for(int i=0;i<E;i++){
        scanf("%d %d",&start,&dist);
        G[start].push_back(dist);
        G[dist].push_back(start);
        sort(G[start].begin(),G[start].end());  //һ��Ҫ����,��Ϊ�����Ǵ�С�����˳�����
        sort(G[dist].begin(),G[dist].end());
    }
    Traversal_D(G);
    bool cnt[N]={false}; //һ��Ҫ��ʼ����������clang++���������������ַ�ʽ����g++����졢��ʡ�£��������������⼸��ע��
    /*
    ����һ��constָ�봴����ѭ����ʼ��
    bool* const cnt=(bool*)malloc((sizeof(bool))*N);
    for(int k=0;k<N;k++){
        cnt[k]=false;
    }
    */
    /*
    ��������ʹ��C++���ԣ�new��Ĭ�Ϲ��캯�����ǻ������Ͳ���Ҫ���ŵ��ã���������������C��������
    bool * cnt;
    cnt=new bool[N]();
    */
    Traversal_B(cnt);
    return 0;
}
