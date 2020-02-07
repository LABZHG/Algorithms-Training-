#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using std::vector;

typedef struct Node * List;
struct Node{
    int address;
    int Data;
    int nextaddress;
    Node * Next;
};

void attach(int a,int d,int na,List *p);

List creat(int &ct,int &K){   //传入全局变量地址，后面还得用
    List L,p,head;
    ct=0,K=0;
    int N=0,flag=0;
    vector<Node> tmp;

    L=(List)malloc(sizeof(Node));
    L->Next=NULL;
    p=L;

    scanf("%d %d %d",&p->nextaddress,&N,&K);
    tmp.resize(N);

    for(int i=0;i<N;i++){
        scanf("%d %d %d",&tmp[i].address,&tmp[i].Data,&tmp[i].nextaddress);
    }
    while(!flag){
    for(int i=0;i<N;i++){
        if(flag){break;}
        if(tmp[i].address==p->nextaddress){
            attach(tmp[i].address,tmp[i].Data,tmp[i].nextaddress,&p);     /*这一步以后再挂载address为当前nextaddress的空结点应当也可以实现同样的链表，但要多一个专门的链表结构体省略nextaddress，空间开销未必明显小*/
            ct+=1;
            if(tmp[i].nextaddress==-1){flag=1;}   //必须设置跳出，不然对付不了输入N个中的杂质节点.不能用while(N-ct)计数方式挂链表
            }
        }
    }

    head=L;
    L=L->Next;
    free(head);

    return L;
}

void attach(int a,int d,int na,List *p){
    List NEW;
    NEW=(List)malloc(sizeof(Node));

    NEW->address=a;
    NEW->Data=d;
    NEW->nextaddress=na;
    NEW->Next=NULL;

    (*p)->Next=NEW;
    *p=NEW;
}

List ReverseList(List &L,int KV){   //还是传地址。记住链表一定传地址！不然不能修改数据。同理打印可以直接用链表指针。
    List old,fresh,tmpNode;
    int cnt=1;

    fresh=L;
    old=L->Next;
        while(cnt<KV){
            tmpNode=old->Next;    //theory?proof? ———就是简单移位……
            old->nextaddress=fresh->address;  //审题审样例……地址也要翻转
            old->Next=fresh;
            fresh=old;
            old=tmpNode;
            cnt++;
        }
    //printf("%d",cnt);  !!!下次提交一定记得把这种测试语句注掉！
    L->Next=old;
    if(old !=NULL){
        L->nextaddress=old->address;
    }
    else{
        L->nextaddress=-1;
    }
    return fresh;
}

void printList(List L){
    List ptr=L;
    while(ptr){
        if(ptr->nextaddress != -1){
            printf("%.5d %d %.5d\n",ptr->address,ptr->Data,ptr->nextaddress);
        }
        else{
            printf("%.5d %d %d\n",ptr->address,ptr->Data,ptr->nextaddress);  //-1没格式，但当前节点的当前地址有啊！没有-1上的节点啊！
        }
        ptr=ptr->Next;
    }
}

int main(){

    List Test,rest,tmp;
    int N_test=0,K_test=0;
    int rev=0,flag=0,j=0;


    Test=creat(N_test,K_test);
    while((N_test-rev)>=K_test){
        rev+=K_test;                       /*没有头节点的链表此处比较麻烦，不能直接用最后返回节点，而且非递归做法，第一次要动头，所以要设标志位*/
        if(!flag){
            Test=ReverseList(Test,K_test);
            rest=Test;
            tmp=rest;
            flag=1;
        }
        else{
            rest=ReverseList(rest,K_test);
            j=0;
            while(j<K_test-1){
                tmp=tmp->Next;
                j++;
            }
            tmp->Next=rest;
            tmp->nextaddress=rest->address;
            tmp=tmp->Next;                  //必要！补足循环中缺少的一次，否则会丢失中间节点
            }
        for(int k=0;k<K_test;k++){
            rest=rest->Next;                //殊途同归：循环到返回节点的下一节点，进入下一个子表
        }
    }
    printList(Test);


    return 0;
}
