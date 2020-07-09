
#include<stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "pilaA.h"
#include "pilaInt.h"

#define size 200
#include <string.h>
#include<math.h>

int longitud(char *c);
char lectura(int espacio, char *pila, int ln);
int deteccion(char *c, int ln);
void separacion(char *pila,Pila * p,Pila * aux, int s);
void separacionA(char pila[][20],PilaA *p,PilaA *aux, int s);
int valor(char c);
void modificar(char *c, char cN[][20], int side, int *lon);
char cambioNumero(char c[], int ln);
int operacion(int dato1, char operando, int dato);
int escritura(char*c);
void operacionPolaca(PilaA *p);

int main(){
	char  cadena[size];
	char cadenaProx[size][20];
	int ln,NuevoTam=0,a;
	Pila Notacion;
	Notacion=crearPila();
	Pila auxP;
	auxP=crearPila();
	Pila auxN;
	auxN=crearPila();
    
  
    	
	PilaA NotacionA;
	NotacionA=crearPilaA();
	PilaA auxPA;
	auxPA=crearPilaA();
	PilaA auxNA;
	auxNA=crearPilaA();
	PilaA operacion;
	operacion=crearPilaA();
	char d;
	char cad[20];
	int j,i,k;	
	for(i=0;i<size;i++){
		cadena[i]='\0';
		
		for(j=0;j<20;j++){
			cad[j]='\0';
			cadenaProx[i][j]='\0';
			
		}
	}
	
	printf("Ingrese la expresion aritm%ctica:\n", 130);
	scanf("%[^\n]",cadena);
	
	ln=longitud(cadena);
	printf("%s\n",cadena);
	printf("longitud %d\n",ln);
	
	
	
	
	if(escritura(cadena)==0){
		printf("Operaci%cn escrita correctamente\n",162);
		switch(deteccion(cadena,ln)){
			case 0:
				printf("Operaci%cn\n",162);
				
				modificar(cadena,cadenaProx,ln,&NuevoTam);
				separacionA(cadenaProx,&NotacionA,&auxPA,NuevoTam);
				printf("Ingreso\n");
				
				for (j=0;j<NuevoTam;j++){
					k=0;
					while(cadenaProx[j][k]!='\0'){
						printf("%c",cadenaProx[j][k]);
						k++;
						
					}
					printf("\n");
				}
				printf("Vaciar Auc");
				while(isEmptyA(NotacionA)==0){
					sacarA(&NotacionA,cad);
				    
				    meterA(&operacion,cad);
					meterA(&auxNA,cad);
					for(j=0;j<20;j++){
						cad[j]='\0';	
					}
				}
				
				printf("Notaci%cn polaca: \n",162);
				i=0;
				while(isEmptyA(auxNA)==0){
					
					sacarA(&auxNA,cad);
					i=0;
					while(cad[i]!='\0'){	
						printf("%c",cad[i]);
						i++;
					}
					for(j=0;j<20;j++){
						cad[j]='\0';	
					}
					
				}
				
				printf("\n");
			
				  
				  operacionPolaca(&operacion);
				
			
			break;
				
				
			case 1:
				printf("Operaci%cn con variables\n",162);
				separacion(cadena,&Notacion,&auxP,ln);
		
		
				printf("Vaciar aux\n");
				while(isEmpty(Notacion)==0){
					
					d=sacar(&Notacion);
					
					meter(&auxN,d);
				}
				
				printf("Notaci%cn polaca: ",162);
				while(isEmpty(auxN)==0){
					d=sacar(&auxN);
					printf("%c",d);
					
				}
				printf("\n");
			break;
			
		}

	}else{
		printf("Operaci%cn incorrecta",162);
	}
	
	
	
	
	return 0;
}


int escritura(char *c){
	int i=0, cont=0;
	while(c[i]!='\0'){
		if (c[i]=='('){
			cont++;
			i++;
		}else if(c[i]==')'){
			cont--;
			i++;
		}else{
			i++;
		}
	}
	if(cont==0){
		return 0;
	}
		return 1;
	
}


int longitud(char *c){
	int cant=0;
	int i=0;
	while(c[i]!='\0'){
		cant++;
		i++;
	}
	return cant;	
}


int deteccion(char *c, int ln){
	int detected=0;
	int i=0;
	while(detected!=1 && ln>i){
		if(c[i]!='('&&c[i]!=')'&&c[i]!='+'&&c[i]!='-'&&c[i]!='*'&&c[i]!='/'&&c[i]!='^'&&c[i]!='0'&&c[i]!='1'&&c[i]!='2'&&c[i]!='3'&&c[i]!='4'&&c[i]!='5'&&c[i]!='6'&&c[i]!='7'&&c[i]!='8'&&c[i]!='9'){
			detected=1;
			return detected;
		}
		i++;
	}
	return detected;
	
}


void modificar(char *c, char cN[][20], int side, int *lon){
	int cant=0;
	int finCadena=0;
	int numeroFin;
	int i=0,k,j,m;
	
	while(finCadena==0){
		if(c[i]!='0'&&c[i]!='1'&&c[i]!='2'&&c[i]!='3'&&c[i]!='4'&&c[i]!='5'&&c[i]!='6'&&c[i]!='7'&&c[i]!='8'&&c[i]!='9'&&c[i]!='\0'){
			printf("Cad\n");
			printf("No numero: %c",c[i]);
			cN[cant][0]=c[i];
			for(m=1;m<20;m++){
				cN[cant][m]='\0';
			}
			printf("%c\n",cN[cant]);
			cant++;
			i++;

		}else if (c[i]=='0'||c[i]=='1'||c[i]=='2'||c[i]=='3'||c[i]=='4'||c[i]=='5'||c[i]=='6'||c[i]=='7'||c[i]=='8'||c[i]=='9'){
			k=i;
			numeroFin=0;
			printf("Numero: %c\n",c[i]);
			while(numeroFin==0){
				
				if(c[i+1]=='0'||c[i+1]=='1'||c[i+1]=='2'||c[i+1]=='3'||c[i+1]=='4'||c[i+1]=='5'||c[i+1]=='6'||c[i+1]=='7'||c[i+1]=='8'||c[i+1]=='9'){
					
					i++;
					printf("Dato siguiente: %c\n",c[i]);
				}else if(c[i+1]=='+'||c[i+1]=='-'||c[i+1]=='*'||c[i+1]=='/'||c[i+1]=='^'||c[i+1]=='\0'||c[i+1]==')'){
					
					numeroFin=1;
					
				}
				
			}
			printf("Cad\n");
			for(j=0;k<=i;k++){
				cN[cant][j]=c[k];
				printf("%c\n",cN[cant][j]);
				j++;
			}
			cant++;
			i++;
		}else{
			finCadena=1;
			
			
		}
	}
	
	printf("Cantidad: %d\n",cant);
	
	
	*lon=cant;
}


int valor(char c){
	if(c=='^'){
		return 3;
	}else if(c=='*'||c=='/'){
		return 2;
	}else if(c=='+'||c=='-'){
		return 1;
	}else{
		return 0;
	} 
		
		
}

void separacion(char *pila,Pila *p,Pila *aux, int s){
	printf("Separacion\n");
	int i=0;
	char c,d,tope;
	for(i=0;i<s;i++){
		c=pila[i];
		printf("Dato: %c\n",c);
		switch(c){
			case '+': case '-': case '*': case '/': case '^':
				printf("%c se metio en aux\n",c);
				int tp, prio;
				
				
				if(isEmpty(*aux)){
					meter(aux,c);
					
				}else{
					tp=valor(top(*aux));
					prio=valor(c);
					printf("Valor tope de %c es %d\n",top(*aux),tp);
					printf("Valor c de %c es %d\n",c,prio);
					while(tp>=prio){
						d=sacar(aux);
						meter(p,d);
						tp=valor(top(*aux));
					}
					meter(aux,c);
				}
				
				break;
				
			case '(':
				meter(aux,c);
				printf("%c se metio en aux\n",c);
				
				break;
				
			case ')':
				
				do{
					printf("Tope %c\n",top(*aux));
					char d=sacar(aux);
					meter(p,d);
					printf("New tope %c\n", top(*aux));
				}while(top(*aux)!='(');
				d=sacar(aux);
				break;
			
			default:
				meter(p,c);
				printf("Numero %c se metio en Notaci%cn\n",c,162);
				break;
		}
	}
	while(!isEmpty(*aux)){
		d=sacar(aux);
		meter(p,d);		
	}
}
//
void separacionA(char pila[][20],PilaA *p,PilaA *aux, int s){
	printf("SeparacionA\n");
	int i=0,j, m,n;
	char c[20],d[20],tope;
	for(i=0;i<s;i++){
		
		for(n=0;n<20;n++){
			d[n]='\0';
			c[n]='\0';
		}
		
		j=0;
		while(pila[i][j]!='\0'){
		
			c[j]=pila[i][j];
			j++;
		}
		
		printf("Dato a ingresar: ");
		m=0;
		
		for(m=0;m<j;m++){
			printf("%c",c[m]);
		}
		
		printf("\n");
		
		
		switch(c[0]){
			case '+': case '-': case '*': case '/': case '^':
				printf("Caso operando %c se metio en aux\n",c[0]);
				int tp, prio;
				
				
				if(isEmptyA(*aux)){
					meterA(aux,c);
					
				}else{
					tp=valor(topA(*aux));
					prio=valor(c[0]);
					m=0;
					printf("Valor tope de %c es %d\n",topA(*aux),tp);
					printf("Valor c de %c es %d\n",c,prio);
					while(tp>=prio){
						sacarA(aux,d);
						meterA(p,d);
						tp=valor(topA(*aux));
					}
					meterA(aux,c);
				}
				
				break;
				
			case '(':
				meterA(aux,c);
				printf("caso ( %s se metio en aux\n",c);
				
				break;
				
			case ')':
				
				do{
					printf("Tope %c\n",topA(*aux));
					sacarA(aux,d);
					meterA(p,d);
					printf("New tope %c\n", topA(*aux));
				}while(topA(*aux)!='(');
					sacarA(aux,d);
				break;
			
			default:
				meterA(p,c);
				printf("g%s se metio en Notaci%cn\n",c,162);
				
				
				break;
		}
	}printf("datos separados");
	i=0;
	for(n=0;n<20;n++){
			d[n]='\0';
			//c[n]='\0';
	}
	while(!isEmptyA(*aux)){
		sacarA(aux,d);
		meterA(p,d);	
			
	}
				
	
	
}


int operacion(int dato1, char operando, int dato2){
	
	int i=0;
	switch(operando){
		case '+':
			i=dato1+dato2;
			break;
		case '-':
			i=dato1-dato2;
			break;
		case '*':
			i=dato1*dato2;
			break;
		case '/':
			i=dato1/dato2;
			break;
		case '^':
			i=pow(dato1,dato2);
			break;
		
		
	}	
	return i;
}


int operador(char dato1[], int sizeNum){
	int i, dato=0;
	for(i=0; i<sizeNum;i++){
		switch(dato1[i]){
			case '1':
				dato+=(1*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '2':
				dato+=(2*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '3':
				dato+=(3*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '4':
				dato+=(4*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '5':
				dato+=(5*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '6':
				dato+=(6*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '7':
				dato+=(7*pow(10,(sizeNum-1)-i));
				printf("%d\n",dato);
				break;
			case '8':
				dato+=(8*pow(10,(sizeNum-1)-i));
				printf("%d",dato);
				break;
			case '9':
				dato+=(9*pow(10,(sizeNum-1)-i));
				printf("%d",dato);
				break;
			
		}
	}
	
	return dato;
	
}


void operacionPolaca(PilaA *pila){
	
    PilaInt auxInt;
    auxInt =crearPilaI();
    Pila  operadores;
	operadores = crearPila();
	char numeroC[20];
	int resultado,i;
	
	while(isEmptyA(*pila)==0){
		sacarA(pila,numeroC);
		if(numeroC[0] == '+'||numeroC[0] =='-'||numeroC[0] =='/'||numeroC[0] =='*'||numeroC[0] =='^'){
			resultado=  operacion(sacarI(&auxInt),numeroC[0],sacarI(&auxInt));
			meterI(&auxInt,resultado);
		}
		else{
			meterI(&auxInt,operador(numeroC,longitud(numeroC)));
		} 
		for(i=0;i<20;i++){
			numeroC[i]='\0';
		}
	  
	}
	
	printf("Resultado: %d",sacarI(&auxInt));
	
}
