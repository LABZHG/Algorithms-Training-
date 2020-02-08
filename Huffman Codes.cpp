#include <bits/stdc++.h>

using std::priority_queue;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

typedef struct TreeNode* Huff_Tree;
struct TreeNode{
    char Element;
    int Weight;
    Huff_Tree Left;
    Huff_Tree Right;
};

struct cmp{
    bool operator()(TreeNode *a, TreeNode *b){
        return a->Weight>b->Weight;
    }
};

typedef priority_queue< int,vector<Huff_Tree>,cmp > Tree;

class VER{
public:
    char Element;
    string route;
    int len(){
        return route.length();
    }
};

bool vcmp(VER V1,VER V2){
    return V1.len() < V2.len();
}

Tree T;
vector<VER> InArray;
map<char,TreeNode> SYM;  //��һ��ӳ�䣬�����������������ݵĴ�Ȩ·����

void Creat_Huffman(Tree &t){ //��ָ��д�ɿɸ��õĺ�����ֵ�ͻ�Ī������+1/*2 ԭ�������顭��
    int cnt=1;
    int all=t.size();
    while(cnt<all){
        Huff_Tree NN;
        NN=new TreeNode;
        NN->Left=NN->Right=NULL;
        NN->Weight=0;
        NN->Element='0';

        NN->Left=t.top();
        //cout<<t.top()->Element<<" ";
        //cout<<t.top()->Weight<<endl;
        t.pop();
        NN->Right=t.top();
        //cout<<t.top()->Element<<" ";
        //cout<<t.top()->Weight<<endl;
        t.pop();
        NN->Weight=(NN->Left->Weight)+(NN->Right->Weight);
        t.push(NN);

        //cout<<NN->Weight<<endl;
        cnt++;
    }
    return;
}

void Read(int cnt){
    char str;
    int tmp=0;
    for(int i=0;i<cnt;i++){
        Huff_Tree NT;
        NT=new TreeNode;
        NT->Left=NT->Right=NULL;
        scanf("\n%c %d",&str,&tmp);
        NT->Element=str;
        NT->Weight=tmp;
        T.push(NT);
        SYM[str]=*NT;
    }
}

void pad(int cnt){
    string R;
    char test;
    for(int k=0;k<cnt;k++){
        cin>>test>>R;
        VER *NV;
        NV=new VER;
        NV->Element=test;
        NV->route=R;
        InArray.push_back(*NV);
        delete NV;
        NV=NULL;
    }
}

bool isPre(vector<VER> ARR){
    vector<VER> JUD=ARR;
    int c=JUD.size();
    sort(JUD.begin(),JUD.end(),vcmp);  //�����Ϳ��Դ�ǰ���˳����в��ظ�ö�٣������ռ任ȡ����������

    for(int i=0;i<c-1;i++){
        int ans=0;
        for(int j=i+1;j<c;j++){
            for(int k=0;k<JUD[i].len();k++){
                //cout<< JUD[i].Element << " " << JUD[j].Element <<endl;
                if(JUD[i].route[k]!=JUD[j].route[k]){
                    ans+=1;
                    break;
                }
            }
        }
        if(ans<(c-(i+1))){    //������������Ҫ�ȶԵ����������һ��������ȷ�ϱ��ȶԵ�ǰ׺���Ƿ�ϸ񡭡���ѭ����ͷ�����ȷ��©�������������
            return false;
        }
    }
    return true;

}

void MinCost(Huff_Tree &p,int &s,int now){
    //cout<<p->Element<<" "<<p->Weight<<endl;
    if(!p->Left){
        s+=now*(p->Weight);
        //cout<<s<<endl;
        return;
    }
    now++;                          //�ر�ע�⣺ֻ���ڷǷ���״̬�¼�·��������Ȼ���׻�+1�������
    MinCost(p->Left,s,now);
    MinCost(p->Right,s,now);
}

int WPL(Tree t){
    int sum=0;
    int id=0;
    Huff_Tree ptr=t.top();
    MinCost(ptr,sum,id);
    return sum;
}

int main(){

    int N=0,M=0,MinLen=0;
    scanf("%d",&N);
    Read(N);
    Creat_Huffman(T);
    MinLen=WPL(T);
    //printf("%d",MinLen);
    scanf("%d",&M);

    for(int j=0;j<M;j++){
        pad(N);
        if(isPre(InArray)){
            int inlen=0;
            for(int l=0;l<N;l++){
                inlen+=(InArray[l].len()*SYM[InArray[l].Element].Weight);
            //printf("%c ",InArray[l].Element);
            //printf("%s ",InArray[l].route.c_str());
            }
            if(inlen == MinLen){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            printf("No\n");
        }
        InArray.clear();
    }


    return 0;

}

