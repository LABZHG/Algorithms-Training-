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

void Perc(vector<int> &H, int p){  //���ˣ���num��С��ɸ��ɸ������СԪ�أ�һ��һ����������
    int Par=0,Chil=0;
    int num=H[p];
    for(Par=p;(Par*2)<H.size();Par=Chil){
        Chil=Par*2;
        if((Chil<H.size())&&(H[Chil]>H[Chil+1])){  //ָ�����С���Ǹ������Ҳ�Խ�磨�������һ��Ԫ�أ����˴��ڱ��������ò�������
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
    for(int j=((H.size()-1)/2);j>0;j--){ //�ڱ�������
        Perc(H,j);
    }
}

void Increat(int c){
    int tmp;
    H.push_back(-32766);  //�ڱ������㹻С��ȡ��-1000û�ã�����Ȼ���ݴﵽ�����޶ȵ�ʱ���ɵ��ڱ����º����޷����룬��ʱ��ѭ��
    for(int i=0;i<c;i++){
        scanf("%d",&tmp);
        In(tmp);
    }
}

int main(){
    int ctr=0;
    scanf("%d %d ",&N,&m);
    /*creat(N);*/  //�ѱ������ж����Եġ������˽��ѺͲ��뽨�ѵ����һ��Ҷ�ӽڵ����л������������������->���⣡
    Increat(N);
    for(int k=0;k<m;k++){
        scanf("%d",&ctr);
        printf("%d",H[ctr]);
        for(int l=(ctr/2);l>=1;l/=2){ //�Թ��ڱ������
            printf(" %d",H[l]);
        }
        printf("\n");
    }

    return 0;
}


