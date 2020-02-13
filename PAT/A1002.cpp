#include <iostream>
#include <cstdlib>
#include <cstdio>

typedef struct PolyNode * Poly;
struct PolyNode{
    double cof;
    int exp;
    struct PolyNode * P;
};

void attach(int e,double c,Poly *p);

void creat(Poly &line){
    int K=0,e=0;
    double c=0;
    Poly tmp,head;
    line=(Poly)malloc(sizeof(PolyNode));
    line->P=NULL;
    tmp=line;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d %lf",&e,&c);
        attach(e,c,&tmp);
    }

    head=line;
    line=line->P;
    free(head);
}

void attach(int e,double c,Poly *p){
    Poly NEW;
    NEW=(Poly)malloc(sizeof(PolyNode));

    NEW->cof=c;
    NEW->exp=e;
    NEW->P=NULL;

    (*p)->P=NEW;
    *p=NEW;
}

int polysize(Poly N){
    int len=0;
    Poly ptr;

    ptr=N;
    while(ptr){
        ptr=ptr->P;
        len++;
    }

    return len;
}

Poly Merge(Poly A,Poly B){
    Poly t1,t2,Solve,PtrSolve,Ptrhead;
    int i=0,j=0,N1=0,N2=0;
    t1=A;
    t2=B;
    N1=polysize(A);
    N2=polysize(B);
    Solve=(Poly)malloc(sizeof(PolyNode));
    Solve->P=NULL;
    PtrSolve=Solve;

    while(t1 || t2){
        if((i<N1)&&(j<N2)){
            double sum=0;
            if(t1->exp == t2->exp){
                sum=t1->cof+t2->cof;
                if(sum){
                    attach(t1->exp,sum,&Solve);
                    t1=t1->P;
                    t2=t2->P;
                    i++,j++;
                }
                else{
                    t1=t1->P;
                    t2=t2->P;
                    i++,j++;
                }
            }
            else if(t1->exp > t2->exp){
                attach(t1->exp,t1->cof,&Solve);
                t1=t1->P;
                i++;
            }
            else{
                attach(t2->exp,t2->cof,&Solve);
                t2=t2->P;
                j++;
            }
        }
        else if((i>=N1)&&(j<N2)){
            attach(t2->exp,t2->cof,&Solve);
            t2=t2->P;
            j++;
        }
        else if((i<N1)&&(j>=N2)){
            attach(t1->exp,t1->cof,&Solve);
            t1=t1->P;
            i++;
        }
        else{
            break;
        }
    }

    Solve->P=NULL;    //?
    Ptrhead=PtrSolve;
    PtrSolve=PtrSolve->P;
    free(Ptrhead);

    return PtrSolve;
}

void output(Poly ans){
    int ansK=0;
    ansK=polysize(ans);

    if(ansK){
        printf("%d ",ansK);
    }
    else{
        printf("0");
        return;
    }

    for(int i=0;i<ansK;i++){
        printf("%d %.1f",ans->exp,ans->cof);
        if(i != ansK-1) printf(" ");
        ans=ans->P;
    }
}

int main(int argc, char** argv){
    Poly p1,p2,ansPoly;
    creat(p1);
    creat(p2);
    ansPoly=Merge(p1,p2);

    output(ansPoly);

    return 0;
}


