#include <bits/stdc++.h>

using std::stack;
using std::string;

stack<int> TravST;

typedef struct TreeNode * Tree;
struct TreeNode{
    int data;
    Tree Left;
    Tree Right;
};

Tree T;
int N=0,sum=0;


void creat(Tree &S){
    string quiz;
    int tmp;
    Tree NewT;

    quiz.resize(7);
    int ctr=2*N;

    if(sum==ctr){
        return;
    }

    scanf("%s",&quiz[0]);
    sum+=1;

    if(quiz[1]=='u'){
        tmp=0;
        NewT=(TreeNode*)malloc(sizeof(TreeNode));
        NewT->Left=NewT->Right=NULL;

        scanf("%d",&tmp);
        TravST.push(tmp);
        S=NewT;
        creat(S->Left);
        S->data=TravST.top();
        TravST.pop();
        creat(S->Right);
        }

    return;
}

void PostOrder(Tree Tr){
    stack<TreeNode*> ST;
    int tick=0;
    Tree cur,Last;
    cur=Tr;
    Last=NULL;
    while(cur || !ST.empty()){
        while(cur){
            ST.push(cur);   //��������һ��ֻѹ���ݣ�������������ж����Ҷ��Ӽ���һ���ʽ��,�Ա���������ұ����������
            cur=cur->Left;
        }
        while(!ST.empty()){
            cur=ST.top();
            ST.pop();
            if(cur->Right==NULL || cur->Right==Last){
                tick+=1;
                if(tick<N){
                    printf("%d ",cur->data);
                }
                else{
                    printf("%d",cur->data);
                }
                Last=cur;
            }
            else{
                ST.push(cur);
                cur=cur->Right;
                while(cur){
                    ST.push(cur);
                    cur=cur->Left;   //β�ݹ�ת�����ģ�ѭ�������Ҷ���ͻ������һ���жϷ�֧����Ҷ�ӻ������
                    /*����ı������̺Ϳ�ͷһ������ʱ�벻���ð취�򻯣�ֻ��ʹ�ú�����װ�������������岻��*/
                }
            }
        }
    return;
    }
}

void Recur(Tree Tr){
    if(!Tr){
        return;
    }
    Recur(Tr->Left);
    Recur(Tr->Right);
    if(sum>2){
        printf("%d ",Tr->data);
    }
    else{
        printf("%d",Tr->data);
    }
    sum-=2;
}

int main(){
    scanf("%d",&N);
    T=(TreeNode*)malloc(sizeof(TreeNode));
    T->Left=T->Right=NULL;

    creat(T);
    /* Recur(T); */
    PostOrder(T);


    return 0;
}
