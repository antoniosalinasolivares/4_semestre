#include <stdio.h>
#include <math.h>

double f (double x) {
	return exp (x) - 5;
}
double a,b,tol;


double biseccion () {
	double c,error;
	double fa,fb,fc;
	int iter= 1;
	
	printf ("It.\ta\tb\tc\tf(a)\tf(b)\tf(c)\tEr.\n");
	do {
		c = (a + b) / 2.0;
		fa = f (a);
		fb = f (b);
		fc = f (c);
		if (fa * fc < 0)// Aqui esta el cambio de signo
				b = c;
		else	a = c;
		error = fabs (a - b);
		printf ("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t",
				iter,a,b,c,fa,fb);
		printf ("%.4lf\t%.4lf\n",fc,error);
		iter++;
	} while (error > tol);
	return c;
}

int main ()
{
	do {
		printf ("Limite inferior: ");
		scanf ("%lf",&a);
		printf ("Limite superior: ");
		scanf ("%lf",&b);
		if (f (a) * f (b) < 0) break;
	} while (1);
	
	printf ("Error estimado: ");
	scanf ("%lf",&tol);
	biseccion ();
}













