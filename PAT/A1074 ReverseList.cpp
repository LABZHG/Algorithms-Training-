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

List creat(int &ct,int &K){   //����ȫ�ֱ�����ַ�����滹����
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
            attach(tmp[i].address,tmp[i].Data,tmp[i].nextaddress,&p);     /*��һ���Ժ��ٹ���addressΪ��ǰnextaddress�Ŀս��Ӧ��Ҳ����ʵ��ͬ����������Ҫ��һ��ר�ŵ�����ṹ��ʡ��nextaddress���ռ俪��δ������С*/
            ct+=1;
            if(tmp[i].nextaddress==-1){flag=1;}   //����������������Ȼ�Ը���������N���е����ʽڵ�.������while(N-ct)������ʽ������
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

List ReverseList(List &L,int KV){   //���Ǵ���ַ����ס����һ������ַ����Ȼ�����޸����ݡ�ͬ���ӡ����ֱ��������ָ�롣
    List old,fresh,tmpNode;
    int cnt=1;

    fresh=L;
    old=L->Next;
        while(cnt<KV){
            tmpNode=old->Next;    //theory?proof? ���������Ǽ���λ����
            old->nextaddress=fresh->address;  //����������������ַҲҪ��ת
            old->Next=fresh;
            fresh=old;
            old=tmpNode;
            cnt++;
        }
    //printf("%d",cnt);  !!!�´��ύһ���ǵð����ֲ������ע����
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
            printf("%.5d %d %d\n",ptr->address,ptr->Data,ptr->nextaddress);  //-1û��ʽ������ǰ�ڵ�ĵ�ǰ��ַ�а���û��-1�ϵĽڵ㰡��
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
        rev+=K_test;                       /*û��ͷ�ڵ������˴��Ƚ��鷳������ֱ������󷵻ؽڵ㣬���ҷǵݹ���������һ��Ҫ��ͷ������Ҫ���־λ*/
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
            tmp=tmp->Next;                  //��Ҫ������ѭ����ȱ�ٵ�һ�Σ�����ᶪʧ�м�ڵ�
            }
        for(int k=0;k<K_test;k++){
            rest=rest->Next;                //��;ͬ�飺ѭ�������ؽڵ����һ�ڵ㣬������һ���ӱ�
        }
    }
    printList(Test);


    return 0;
}
