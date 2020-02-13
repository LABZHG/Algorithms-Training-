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
    printf("%d ",num);  //被遍历==被访问
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
        printf("%d ",vnum);  //牢记：出队==访问，入队==被遍历
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
        sort(G[start].begin(),G[start].end());  //一定要排序,因为题意是从小到大的顺序遍历
        sort(G[dist].begin(),G[dist].end());
    }
    Traversal_D(G);
    bool cnt[N]={false}; //一定要初始化……但是clang++编译器不允许这种方式，得g++（最快、最省事），或者用下面这几行注释
    /*
    方法一：const指针创建，循环初始化
    bool* const cnt=(bool*)malloc((sizeof(bool))*N);
    for(int k=0;k<N;k++){
        cnt[k]=false;
    }
    */
    /*
    方法二：使用C++特性，new加默认构造函数（非基本类型不需要括号调用），但比上面那种C方法还慢
    bool * cnt;
    cnt=new bool[N]();
    */
    Traversal_B(cnt);
    return 0;
}
