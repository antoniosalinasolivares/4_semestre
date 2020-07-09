package krylov_code;

import java.util.Formatter;

class Matrix {
    
    //Variables
    private Double matrix[][];
    private Integer renglones;
    private Integer columnas;
    
    //Constructores
    public Matrix() {
        renglones = 0;
        columnas = 0;
    }

    public Matrix(int row, int column) {
        matrix = new Double[row][column];
        renglones = row;
        columnas = column;
        for (int i = 0; i < renglones; ++i)
            for (int j = 0; j < columnas; ++j)
                matrix[i][j] = 0.;
    }

    public Matrix(double matrix[][]) {
        this.renglones = matrix.length;
        this.columnas = matrix[renglones - 1].length;
        this.matrix = new Double[renglones][columnas];
        
        for (int i = 0; i < renglones; ++i) {
            for (int j = 0; j < columnas; ++j)
                this.matrix[i][j] = matrix[i][j];
        }
    }

    
    //SETTERS AND GETTERS 
    
    public int getRows() {
        return renglones;
    }

    public int getColumns() {
        return columnas;
    }
    
    public Double[][] getMatrix() {
        return matrix;
    }
    
    public double get(int row, int column) {
        return matrix[row][column];
    }
    
    public void setRows(int row) {
        renglones = row;
    }

    public void setColumns(int column) {
        columnas = column;
    }
    
    public void set(int row, int column, double item) {
        matrix[row][column] = item;
    }
    
    
    
    
    

    //MÉTODOS ASOCIADOS
    
    public void print() {
        
        System.out.println("");
        for (int i = 0; i < renglones; ++i) {
            for (int j = 0; j < columnas; ++j) {
              
                //Mera parte de impresión
                Formatter fmt = new Formatter();
                fmt.format("%5.4g", matrix[i][j]);
                System.out.print(fmt + " ");

            }
            System.out.println();
        }
    }

    public void swapRows(int firstRow, int secondRow) {
        for (int j = 0; j < columnas; ++j) {
            double temp = matrix[firstRow][j];
            matrix[firstRow][j] = matrix[secondRow][j];
            matrix[secondRow][j] = temp;
        }
    }

    public void divRow(int row, double value) {
        for (int j = 0; j < columnas; ++j)
            matrix[row][j] /= value;
    }

    public void addColumn(int column, Matrix vector) {
        for (int i = 0; i < vector.getRows(); ++i) {
            matrix[i][column] = vector.get(i, 0);
        }
    }


    public Matrix multiplicacion(Matrix mB) throws IllegalArgumentException {
        //Excepción por si no cumple con la condición del algoritmo
        if (this.getColumns() != mB.getRows())
            throw new IllegalArgumentException("Columns!=Rows");
        
        Matrix res = new Matrix(this.getRows(), mB.getColumns());
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < mB.getColumns(); j++) {
                for (int k = 0; k < mB.getRows(); k++) {
                    res.matrix[i][j] += this.matrix[i][k] * mB.matrix[k][j];
                }
            }
        }
        return res;
    }

    public void findAndSwapMaxElementInColumn(int column, int step) {
        double max = matrix[step][column];
        int index = column;
        for (int i = step; i < renglones; ++i) {
            if (matrix[i][column] > max) {
                index = i;
                max = matrix[i][column];
            }
        }
        swapRows(step, index);
    }

    public void substractRows(int firstRow, int secondRow, int index) {
        double div = matrix[secondRow][index];
        for (int j = index; j < columnas; ++j)
            matrix[secondRow][j] -= matrix[firstRow][j] * div;
    }


}