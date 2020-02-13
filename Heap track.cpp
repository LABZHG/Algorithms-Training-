#include <bits/stdc++.h>

using std::vector;

vector<int> H;
int N=0,m=0;

void In(int a){
    int o;
    o=H.size();
    H.resize(o+1);
    for(;H[o/2]>a;o/=2){
        H[o]=H[o/2];
    }
    H[o]=a;
}

void Perc(vector<int> &H, int p){  //下滤，用num大小的筛子筛除所有小元素，一层一层留在上面
    int Par=0,Chil=0;
    int num=H[p];
    for(Par=p;(Par*2)<H.size();Par=Chil){
        Chil=Par*2;
        if((Chil<H.size())&&(H[Chil]>H[Chil+1])){  //指向相对小的那个，并且不越界（超过最后一个元素），此处哨兵发挥作用参与排序
            Chil+=1;
        }
        if(num<=H[Chil]){
            break;
        }
        else{
            H[Par]=H[Chil];
        }
    }
    H[Par]=num;
}

void creat(int c){
    int tmp;
    H.push_back(-32766);
    for(int i=0;i<c;i++){
        scanf("%d",&tmp);
        H.push_back(tmp);
    }
    for(int j=((H.size()-1)/2);j>0;j--){ //哨兵起作用
        Perc(H,j);
    }
}

void Increat(int c){
    int tmp;
    H.push_back(-32766);  //哨兵必须足够小（取个-1000没用），不然数据达到正负限度的时候会干掉哨兵导致后续无法插入，超时死循环
    for(int i=0;i<c;i++){
        scanf("%d",&tmp);
        In(tmp);
    }
}

int main(){
    int ctr=0;
    scanf("%d %d ",&N,&m);
    /*creat(N);*/  //堆本身是有二义性的……下滤建堆和插入建堆的最后一层叶子节点排列会有两种以上情况差异->看题！
    Increat(N);
    for(int k=0;k<m;k++){
        scanf("%d",&ctr);
        printf("%d",H[ctr]);
        for(int l=(ctr/2);l>=1;l/=2){ //略过哨兵不输出
            printf(" %d",H[l]);
        }
        printf("\n");
    }

    return 0;
}


