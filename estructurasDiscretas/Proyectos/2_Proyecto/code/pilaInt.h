#ifndef PILAI_H
#define PILAI_H

#include <stdio.h>
#define size 200
typedef struct{
    char tope;
   	int lista[size];
}PilaInt;

PilaInt crearPilaI();
int isEmptyI(PilaInt);
void meterI(PilaInt*,int);
int sacarI(PilaInt*);
int topI(PilaInt);

PilaInt crearPilaI(){
	PilaInt p;
	p.tope=0;
	int i=0;
	for(i=0;i<size;i++){
		p.lista[i]='\0';
	}
	return p;
}

int isEmptyI(PilaInt p){
	if(p.tope==0)
		return 1;
	return 0;
}

void meterI(PilaInt *p,int x){
	p->lista[p->tope]=x;
	p->tope++;
}

int sacarI(PilaInt *p){
	if(isEmptyI(*p)==1){
		printf("La pila esta vacia.\n");
		return -1;
	}
	else{
		int aux = p->lista[p->tope-1];
		p->tope--;
		return aux;
	}
}

int topI(PilaInt p){
	if(isEmptyI(p)==1){
		printf("La pila ya esta vacia.\n");
		return -1;
	}
	else{
		return p.lista[p.tope-1];
	}
}


#endif
