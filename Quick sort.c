#include <stdio.h>
#include <stdlib.h>
void quicksort(int p[],int left,int right);
int main(void)
{
	int n,i;
	scanf("%d",&n);
	int *p = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	quicksort(p,0,n-1);
	printf("After sorted\n");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	return 0;
}
/*���ҽ����Ŀ�������*/
void quicksort(int p[],int left,int right)
{
	if(left>=right){
		return;
	}
	int stand=p[left];
	int i=left,j=right;
	while(i<j){
		//ע�⣬�˴���ȡ���Ԫ����Ϊ��׼��Ҫ����ָ������ 
		while(p[j]>=stand&&j>i){
			j--;
		}
		while(p[i]<=stand&&j>i){
			i++;
		}
		if(i!=j){
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
	int temp = p[left];
	p[left] = p[i];
	p[i]=temp;
	quicksort(p,left,i-1);
	quicksort(p,i+1,right);
}
/*ͬ������Ŀ�������*/
void quicksort(int p[],int left,int right)
{
	if(left>=right){
		return;
	}
	int temp;
	int l=left-1,r=left,stand=p[right];
	while(r<right){
		if(p[r]<stand&&(++l)!=r){
			temp=p[l];
			p[l]=p[r];
			p[r]=temp;
		}
		r++;
	}
	l++;
	temp = p[l];
	p[l] = p[right];
	p[right] = temp;
	quicksort(p,l+1,right);
	quicksort(p,left,l-1);
 } 
