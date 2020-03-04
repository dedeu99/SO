#include <stdio.h>
#define MAX_VECTOR_SIZE 100000
int max(int a,int b){
	return a<b?b:a;
}
void printVector(int* a, int size){
	for(int i=0;i<size-1;i++)
		printf("%d, ",a[i]);
	printf("%d\n",a[size-1]);
}
int lerVector(int* arr){
	int size;
	scanf("%d",&size);
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);
	return size;
}
void sumVectores(int* a,int sizeA,int* b,int sizeB,int* c,int sizeC){
	for(int i=0;i<sizeC;i++)
		c[i]= (i<sizeA?a[i]:0) + (i<sizeB?b[i]:0);
}
int main(){
	int a[MAX_VECTOR_SIZE];
	int b[MAX_VECTOR_SIZE];

	int sizeA=lerVector(a);
	int sizeB=lerVector(b);

	int sizeC=max(sizeA,sizeB);
	int c[sizeC];

	sumVectores(a,sizeA,b,sizeB,c,sizeC);
	printVector(c,sizeC);
	return 0;
}

