
package newtonrhapson;

import java.util.Scanner;

public class NewtonRhapson {

	public static double Calcular(double A[], double x) {
		double Ap[] = new double[A.length];
		int num = A.length;
		double F = 0;
		for (int i = 0; i < A.length; i++) {
			if (num > 1) {
				Ap[i] = A[i] * Math.pow(x, num-1);
				num--;
			} else {
				Ap[i] = A[i];
			}
			F = F + Ap[i];
		}
		return F;
	}

	public static double Calcular_derivada(double A[], double x) {
		double Ap[] = new double[A.length - 1];
		int num = A.length - 1;
		double Fd = 0;
		for (int i = 0; i < A.length - 1; i++) {
			if (num > 1) {
				Ap[i] = num*A[i]*Math.pow(x, num-1);
				num--;
			}else{
				Ap[i] = A[i];
			}
			Fd = Fd + Ap[i];
		}
		return Fd;

	}

	public static void main(String[] args) {
		double vini, raiz, errorPropuesto;
		double error = 0;
		double apoyo = 0;
		int i = 0;
		
		int iteraciones;
		int grado = 0;
		
		char respuesta;
		do{
		int contador = 0;
		boolean check = true;
		iteraciones = 0;
		Scanner sc = new Scanner(System.in);

		System.out.println("Bienvenido al programa de calculo de raices utilizando Newton-Raphson \n");
		
		System.out.println("Introduzca el grado mas alto que quiere para su funcion: ");
		grado = sc.nextInt();
		
		double n[] = new double[grado + 1];
		
		System.out.println("Introduzca los coeficientes de mayor a menor grado: ");
		for (int j = 0; j < n.length; j++) {
			System.out.println("Introduzca coeficiente para x^ " + (n.length - (j + 1)));
			n[j] = sc.nextDouble();
		}
		
		System.out.println("Introduzca un valor inicial para arrancar la iteración: ");
		vini = sc.nextDouble();

		System.out.println("Introduzca la precision con la que desea calcular "
				+ "la raiz: \n(Formato ejemplo: 0,1;0,01;0,001...)");
		errorPropuesto = sc.nextDouble();

		System.out.println("Introduzca un maximo de iteraciones: ");
		iteraciones = sc.nextInt();




		while (check == true && iteraciones >= i) {

			raiz = vini - (Calcular(n, vini) / Calcular_derivada(n, vini));
			vini = raiz;
			System.out.println("Iteracion nº: " + i++);
			System.out.println("La raiz de esta iteración es: " + raiz);

			if (contador > 0) {
				error = Math.abs(apoyo - raiz);
				System.out.println("El error es: " + error);
				if (error < errorPropuesto) {					
					System.out.println("\nEl resultado de tu raiz con una "
							+ "precisión de " + errorPropuesto + " es " + raiz + "\n" );
					check = false;
					
				}
			}

			apoyo = raiz;
			contador++;

			}
		i = 0;
		if(contador-1==iteraciones){
			System.out.println("No se ha encontrado una raiz correspondiente"
					+ " a la precision fijada para este numero de iteraciones");
		}
		System.out.println("¿Desea volver a ejecutar el programa? (s/n)");
		respuesta = sc.next().charAt(0);

	
		}while(respuesta != 'n');
		System.out.println("Gracias por utilizar el programa. Hasta la vista !!!");
	}
}
    

