#include <stdio.h>
#include <stdlib.h>
void mergesort(int p[],int left,int right);
void merge(int p[],int left,int mid,int right);
//利用分治法排序 
int main(void)
{
	int n,i;
	scanf("%d",&n);
	int *p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	mergesort(p,0,n-1);//merge算法 
	printf("After sorted:\n");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	return 0;
}
//分治排序 
 void mergesort(int p[],int left,int right)
{
	if(left>=right){
		return;
	}
	int mid = (left+right)/2;
	mergesort(p,left,mid);
	mergesort(p,mid+1,right);
	merge(p,left,mid,right);
}
//合并 
void merge(int p[],int left,int mid,int right){
	int *x = (int*)malloc(sizeof(int)*(mid-left+2));
	int *y = (int*)malloc(sizeof(int)*(right-mid+1));
	int i,j,k=left;
	for(i=left;i<=mid;i++){
		x[i-left]=p[i];
	}
	for(j=mid+1;j<=right;j++){
		y[j-mid-1]=p[j];
	}
	i=0;
	j=0;
	while(i<mid-left+1&&j<right-mid){
		if(x[i]>y[j]){
			p[k++]=y[j++];
		}else{
			p[k++]=x[i++];
		}
	}
	while(i<mid-left+1){
		p[k++]=x[i++];
	}
	while(j<right-mid){
		p[k++]=y[j++];
	}
}
