#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_VECTOR_SIZE 100000

#ifndef NUM_THREADS
#define NUM_THREADS 5
#endif
/**************************	Intervalo       ************************/
typedef struct intervalo{
	unsigned int inicio;
	unsigned int fim;
}Intervalo;
Intervalo* createIntervalo(int inicio, int fim){
	Intervalo* i = (Intervalo*) malloc(sizeof(Intervalo));
	i->inicio=inicio;
	i->fim=fim;
	return i;
}
void freeIntervalo(Intervalo* i){
	free(i);
}
/*************************     Vetor     **************************************/
typedef struct vetor{
	int* v;
	int size;
}Vetor;
Vetor* createVetor(int size){
	Vetor* vect=(Vetor*) malloc(sizeof(Vetor));
	vect->v=(int*) malloc(sizeof(int)*size);
	vect->size=size;
	return vect;
}
void freeVetor(Vetor* v){
	free(v->v);
	free(v);
}
void printVector(Vetor* v){
	for(int i=0;i<v->size;i++)
		printf("%d\n",v->v[i]);
}
Vetor* lerVector(Vetor* v){

	for(int i=0;i<v->size;i++)
		scanf("%d",v->v+i);
	return v;
}


/********************************** Param   ************************************/


typedef struct param{
	Intervalo* intervalo;
	Vetor* a;
	Vetor* b;
	Vetor* c;
}Param;
Param* createParam(int inicio,int fim, Vetor* a, Vetor* b, Vetor* c){
	Param* p=(Param*)malloc(sizeof(Param));
	p->intervalo=createIntervalo(inicio,fim);
	p->a=a;
	p->b=b;
	p->c=c;
	return p;
}
void freeParam(Param* p){
	free(p);
}

int max(int a,int b){
	return a<b?b:a;
}
void* sumVectores(void* param){
	Param* p=(Param*)param;
//	printf("Inicio:%d\nFim:%d\n",p->intervalo->inicio,p->intervalo->fim);
	for(int i=p->intervalo->inicio;i<p->intervalo->fim;i++){
//		printf("i:%d\n",i);
		p->c->v[i]= (i<p->a->size?p->a->v[i]:0) + (i<p->b->size?p->b->v[i]:0);
	}
	pthread_exit(0);
}
int main(){
	int size;
	scanf("%d",&size);
	Vetor* a=createVetor(size);
	Vetor* b=createVetor(size);
	lerVector(a);
	lerVector(b);
	int sizeC=max(a->size,b->size);
	Vetor* c=createVetor(sizeC);

	pthread_t threads[NUM_THREADS];
	int rc;
	Param** params=(Param**)malloc(NUM_THREADS*sizeof(Param**));
	for(int i=0;i<NUM_THREADS;i++)
	{
		params[i]=createParam(i*c->size/NUM_THREADS,(i+1)*c->size/NUM_THREADS,a,b,c);
		rc=pthread_create(&threads[i],NULL,sumVectores,(void*) params[i]);
		if (rc){
          		printf("ERROR; return code from pthread_create() is %d\n", rc);
          		exit(-1);
       		}
	}
	for(int i=0;i<NUM_THREADS;i++)
		pthread_join(threads[i],NULL);

	printVector(c);
	freeVetor(a);
	freeVetor(b);
	freeVetor(c);
	for(int i=0;i<NUM_THREADS;i++){
		freeIntervalo(params[i]->intervalo);
		freeParam(params[i]);
	}

	return 0;
}
