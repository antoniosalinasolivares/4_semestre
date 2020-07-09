package krylov_code;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Alfonso
 */
public class Krylov_Code {

    
    public static void main(String[] args) {
        
        //{8.30, 2.62, 4.10, 1.90}, {3.92, 8.45, 7.78, 2.46}, {3.77, 7.21, 8.04, 2.28}, {2.21, 2.65, 1.69, 6.99}
        Scanner sc = new Scanner(System.in);
        //Valores generales
        
        System.out.print("Introduzca el tamaño: ");
        int size = sc.nextInt();
        double[][] matrizG = new double[size][size]; 
        for (int x=0; x < size; x++) {
            for (int y=0; y < size; y++) {
                System.out.print("Introduzca el elemento [" + x + "," + y + "]: ");
                matrizG[x][y] = sc.nextFloat();
            }
        }
        
        //Final matrix
        Matrix vector0 = new Matrix(size, 1);
        
        //Vector unitario
        List<Matrix> vectors = new LinkedList<>();
        vector0.set(0, 0, 1);
        vector0.print();
        vectors.add(vector0);
        
        //LENADO DE LA MATRIZ AUX 
        for (int i = 1; i <= size; ++i) {
            Matrix temp = new Matrix(matrizG);
            vectors.add(temp.multiplicacion(vectors.get(i - 1)));
        }
        Matrix matrizAux = new Matrix(size, size + 1);
        for (int i = 0; i < size; ++i) {
            matrizAux.addColumn(i, vectors.get(size - 1 - i));
        }
        matrizAux.addColumn(size, vectors.get(size));
        matrizAux.print();
        
        
        //PARTE DE LAS OPERACIONES
        for (int cont = 0; cont < size; ++cont) {
            
            matrizAux.findAndSwapMaxElementInColumn(cont, cont);
            System.out.println();
            matrizAux.print();
            double div = matrizAux.get(cont, cont);
            matrizAux.divRow(cont, div);
            
            for (int i = cont; i < size - 1; ++i) {
                matrizAux.substractRows(cont, i + 1, cont);
            }
            
            System.out.println();
            matrizAux.print();
        }
        Matrix finalMatrix = new Matrix(size, 1);
        
        //MATRIZ FINAL 
        for (int count2 = size - 1; count2 >= 0; --count2) {
            double value = matrizAux.get(count2, size);
            for (int j = count2 + 1; j < size; j++) {
                value -= matrizAux.get(count2, j) * finalMatrix.get(j, 0);
            }
            finalMatrix.set(count2, 0, value);
        }
        
        System.out.println("Valores de las raíces: ");
        finalMatrix.print();
        
        
    }
    
}
