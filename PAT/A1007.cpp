#include <iostream>
#include <vector>

using std::vector;

int n;
int main(int argc, char** argv){
	
	int temp=0,left=0,sum=-1;
	
	scanf("%d",&n);
	
	int right=n-1;
	int index=0;
	int value=0;
	vector<int> array;
	
	for(int i=0;i<n;++i){
		scanf("%d",&value);
		array.push_back(value);
		temp += array[i];
		if(temp<=0){
			temp=0;
			index++;
		}
		if(temp>sum){
			sum=temp;
			left=index;
			right=i;
		}
	}
	
	if(sum<0){
		sum=0;
	}
	
	printf("%d %d %d",sum,array[left],array[right]);
	
	return 0;
}


