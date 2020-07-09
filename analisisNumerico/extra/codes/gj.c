#include <stdio.h>
#include <math.h>
#define DIM 10

double A[DIM][DIM+1];

void imprimeMatriz (int n) {
     int i,j;
      
     for (i= 0; i < n; i++) {
         for (j= 0; j <= n; j++)
             printf("%.4lf\t",A[i][j]);
         printf ("\n");
     } 
}
void leeMatriz (int n) {
     int i,j;
      
     for (i= 0; i < n; i++)
         for (j= 0; j <= n; j++) {
             printf("Elemento %d,%d: ",i+1,j+1);
             scanf ("%lf",&A[i][j]);
             } 
}
void Pivoteo (int p, int n) {
    double temp;
    int i,j,mayor;
     
    mayor= p;
    for (i= p+1; i < n; i++)
        if (fabs (A[i][p]) > fabs (A[mayor][p]))
            mayor= i;
    if (mayor != p) {
        for (j= 0; j <= n; j++) {
            temp= A[p][j];
            A[p][j]= A[mayor][j];
            A[mayor][j]= temp;
        }
    }
}

void GaussJordan (int n) {
	int i,j,k;
	double cte;
	
	for (i = 0; i < n; i++)	{	// Pivote
		Pivoteo (i,n);			// Parcial
		// Normalizar el renglon
		cte= A[i][i];		// Elemento pivote
		for (j= 0; j <= n; j++)
			A[i][j] /= cte;
		for (j = 0; j < n; j++) {
			if (i != j) {
				cte = A[j][i];
				for (k = i; k <= n; k++)
					A[j][k] -= cte*A[i][k];
			}
		}
	}
}
int main () {
	int n;
	do {
		printf ("No de ecuaciones: ");
		scanf ("%d", &n);
		if (n > 1 && n <= DIM) break;
		
		printf ("No. de ecs. invalido, maximo %d\n", DIM);
	} while (1);
	leeMatriz (n);
	imprimeMatriz (n);
	GaussJordan (n);
	printf ("\n");
	imprimeMatriz (n);
}











