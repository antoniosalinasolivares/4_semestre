#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#define size 200
typedef struct{
    char tope;
   	char lista[size];
}Pila;

Pila crearPila();
int isEmpty(Pila);
void meter(Pila*,char);
char sacar(Pila*);
char top(Pila);

Pila crearPila(){
	Pila p;
	p.tope=0;
	int i=0;
	for(i=0;i<size;i++){
		p.lista[i]=0;
	}
	return p;
}

int isEmpty(Pila p){
	if(p.tope==0)
		return 1;
	return 0;
}

void meter(Pila *p,char x){
	p->lista[p->tope]=x;
	p->tope++;
}

char sacar(Pila *p){
	if(isEmpty(*p)==1){
		printf("La pila esta vacia.\n");
		return -1;
	}
	else{
		char aux = p->lista[p->tope-1];
		p->tope--;
		return aux;
	}
}

char top(Pila p){
	if(isEmpty(p)==1){
		printf("La pila ya esta vacia.\n");
		return -1;
	}
	else{
		return p.lista[p.tope-1];
	}
}


#endif
