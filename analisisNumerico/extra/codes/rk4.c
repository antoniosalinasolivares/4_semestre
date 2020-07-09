#include <stdio.h>
#include <math.h>

double f (double x, double y) {//Escribir la ecuación diferencial
	return x+(2*x*y); 
}
double vr (double x) {
	return 2*exp (x)-x-1;
}
double rk4 (double x0,double y0,double h,double xn) {
	double xr,xi,yi,er,k1,k2,k3,k4;
	int i= 0;
	
	printf ("i\tXi\tYi\tXr\tEr\n");	// Encabezado
	while (xi <= xn) {
		xr= vr (x0);	// valor real
		er = fabs (xr - y0) / xr;
		printf ("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n",i,x0,y0,xr,er);
			
		k1 = f (x0,y0);
		printf("%f\n",k1);
		k2 = f (x0 + 0.5*h, y0 + 0.5*k1*h);
		printf("%f\n",k2);
		k3 = f (x0 + 0.5*h, y0 + 0.5*k2*h);
		printf("%f\n",k3);
		k4 = f (x0+h,y0+k3*h);
		printf("%f\n",k4);
		
		xi = x0 + h;
		yi = y0 + h/6.0 * (k1 + 2*k2 + 2*k3 + k4);


		x0 = xi;
		y0 = yi;
		i++;
	}

	return yi;
}

/*
double EulerM (double x0,double y0,double h,double xn) {
	double xi,yi,ui;
	int i= 0;
	
	printf ("i\tXi\tYi\tUi\n");	// Encabezado
	while (xi <= xn) {
		if (i == 0)
			printf ("%d\t%.4lf\t%.4lf\n",i,x0,y0);
		else
			printf ("%d\t%.4lf\t%.4lf\t%.4lf\n",i,x0,y0,ui);
		ui = y0 + h * f (x0,y0);
		xi = x0 + h;
		yi = y0 + h/2.0 * (f (x0,y0) + f (xi,ui));
		x0 = xi;
		y0 = yi;
		i++;
	}
	printf ("%d\t%.4lf\t%.4lf\t%.4lf\n",i,x0,y0,ui);
	return yi;
}
*/
int main () {
	double x0,y0,h,xn;
	
	printf ("Condicion inicial x0,y0: ");
	scanf ("%lf,%lf",&x0,&y0);
	printf ("Valor final de x: ");
	scanf ("%lf",&xn);
	do {
		printf ("Valor de h: ");
		scanf ("%lf",&h);
		rk4 (x0,y0,h,xn);
		printf ("Repetir s/n: ");
		fflush (stdin);
	} while (getchar () == 's');
}









