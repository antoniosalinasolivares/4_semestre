#include <stdio.h>
#include <math.h>
#define PI 3.1416

double f (double x) {
	return (1/sqrt (2*PI))*exp (-0.5*pow(x,2));
}
double Simpson38 (double a, double b, int n) {
	int i;
	double integral,h,sumaM3,sumaOtros;
	
	h = (b-a)/n;
	sumaM3= sumaOtros= 0.0;
	for (i = 1; i < n-1; i++)
		if (i % 3 == 0)
			sumaM3= sumaM3 + f (a+ h*i);
		else
			sumaOtros= sumaOtros + f (a+ h*i);
	
	integral= 3*h/8.0 * (f(a) + 2*sumaM3+3*sumaOtros+f(b));
	return integral;
}
double Simpson13 (double a, double b, int n) {
	int i;
	double integral,h,sumaP,sumaN;
	
	h = (b-a)/n;
	sumaP= sumaN= 0.0;
	for (i = 1; i < n-1; i++)
		if (i % 2 == 0)
			sumaP= sumaP + f (a+ h*i);
		else
			sumaN= sumaN + f (a+ h*i);
	
	integral= h/3.0 * (f(a) + 4*sumaP+2*sumaN+f(b));
	return integral;
}
double Trapecio (double a, double b, int n) {
	int i;
	double integral,h,suma;
	
	h = (b-a)/n;
	suma= 0.0;
	for (i = 1; i < n-1; i++)
		suma= suma + f (a+ h*i);
	
	integral= h/2.0 * (f (a) + 2 * suma+ f (b));
	return integral;
}
int main () {
	int n;
	double a,b,I;
	
	do {
		fflush (stdin);
		printf ("Limite inf.: ");
		scanf ("%lf", &a);
		printf ("Limite sup.: ");
		scanf ("%lf", &b);
		printf ("No. de particiones: ");
		scanf ("%d", &n);
		if (n % 3 == 0) {
			I= Simpson38 (a,b,n);
			printf ("La integral aprox. S3/8= %lf\n",I);
		}
		else if (n % 2 == 0) {
			I= Simpson13 (a,b,n);
			printf ("La integral aprox. S1/3= %lf\n",I);
		}
		else {
			I= Trapecio (a,b,n);
			printf ("La integral aprox. Trapecio= %lf\n",I);
		}
		fflush (stdin);
		printf ("Repetir s/n: ");
	}
	while (getchar () == 's');
}

