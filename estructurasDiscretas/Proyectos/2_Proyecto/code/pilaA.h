#ifndef PILAA_H
#define PILAA_H

#include <stdio.h>
#include <stdio.h>
#define size 200
typedef struct{
    char tope;
   	char lista[200][20];
}PilaA;

PilaA crearPilaA();
int isEmptyA(PilaA);
void meterA(PilaA*,char x[20]);
void sacarA(PilaA*,char x[20]);
char topA(PilaA);

PilaA crearPilaA(){
	PilaA p;
	p.tope=0;
	int i=0,j=0;
	for(i=0;i<size;i++){
		for(j=0;j<20;j++){
			p.lista[i][j]='\0';
		}
	}
	return p;
}

int isEmptyA(PilaA p){
	if(p.tope==0)
		return 1;
	return 0;
}

void meterA(PilaA *p,char x[20]){
	int i=0,m;
	if(x[0]=='0'||x[0]=='1'||x[0]=='2'||x[0]=='3'||x[0]=='4'||x[0]=='5'||x[0]=='6'||x[0]=='7'||x[0]=='8'||x[0]=='9'){
		i=0;
		while(x[i]=='0'||x[i]=='1'||x[i]=='2'||x[i]=='3'||x[i]=='4'||x[i]=='5'||x[i]=='6'||x[i]=='7'||x[i]=='8'||x[i]=='9'){
		//printf("Dato %c",x[i]);
			p->lista[p->tope][i]=x[i];
			//printf("Lista %c",p->lista[p->tope][i]);
			i++;
		}
	}else if(x[0]=='('||x[0]==')'||x[0]=='+'||x[0]=='-'||x[0]=='*'||x[0]=='/'||x[0]=='^'){
		//printf("DatoM %c\n",x[0]);
		p->lista[p->tope][0]=x[0];
		for(m=1;m<20;m++){
			p->lista[p->tope][m]='\0';
		}
		//printf("DatoM %c\n",p->lista[p->tope][0]);
	}
	
	p->tope++;
}

void sacarA(PilaA *p, char copia[20]){
	if(isEmptyA(*p)==1){
		printf("La pila esta vacia");
		
	}
	else{
		
		char x [20];
		
		int i=0;
	    while(p->lista[p->tope-1][i]!='\0'){
			//printf("dato %",p->lista[p->tope][i]);
			copia[i] = p->lista[p->tope-1][i];
			//printf("%d Lista %\n",i,x[i]);
			i++;
		}
		
		
		if(x[0]=='0'||x[0]=='1'||x[0]=='2'||x[0]=='3'||x[0]=='4'||x[0]=='5'||x[0]=='6'||x[0]=='7'||x[0]=='8'||x[0]=='9'){
			while(p->lista[p->tope-1][i]=='0'||p->lista[p->tope-1][i]=='1'||p->lista[p->tope-1][i]=='2'||p->lista[p->tope-1][i]=='3'||p->lista[p->tope-1][i]=='4'||p->lista[p->tope-1][i]=='5'||p->lista[p->tope-1][i]=='6'||p->lista[p->tope-1][i]=='7'||p->lista[p->tope-1][i]=='8'||p->lista[p->tope-1][i]=='9'){
				//printf("Dato %c",x[i]);
				copia[i]=p->lista[p->tope-1][i];
				//printf("Lista %c",p->lista[p->tope][i]);
				i++;
			}
		}else if(p->lista[p->tope-1][0]=='('||p->lista[p->tope-1][0]==')'||p->lista[p->tope-1][0]=='+'||p->lista[p->tope-1][0]=='-'||p->lista[p->tope-1][0]=='*'||p->lista[p->tope-1][0]=='/'||p->lista[p->tope-1][0]=='^'){
			//printf("DatoS %c\n",p->lista[p->tope-1][0]);
			copia[0]=p->lista[p->tope-1][0];
			//printf("DatoS %c\n",copia[0]);
			for(i=1;i<20;i++){
				copia[i]='\0';
			}
			
		}
		
		
		
		
		
		p->tope--;
	
		
			
		
	}
}

char topA(PilaA p){
	if(isEmptyA(p)==1){
		printf("La pila ya esta vacia.");
		return 0;
	}
	else{
		char aux[20] ;
		
		int i;
	    for(i=0;i<20;i++){
		
			aux[i] = p.lista[p.tope-1][i];
		
		}
		
		
		return *aux;
	}
}


#endif
