package com.company;

/*import java.util.Scanner;
import com.company.Inverse;
import com.company.Matrix;
import com.company.MatrixException;
import com.company.MatrixCreator;*/


import java.io.File;

public class Main {

    public static void main(String[] args) {
        try {
            MatrixCreator creator = new MatrixCreator();
            Matrix matrix = new Matrix(3,3);
            File file = new File("C:\\Users\\Victor\\java\\bsu\\lab3\\src\\com\\company\\Matrix.txt");
            //String fileName="C:\\Users\\Victor\\java\\bsu\\lab3\\src\\com\\company\\Matrix.txt";
            //Matrix matrix=creator.createFromFile(fileName);
            creator.createFromFile(matrix,file);
            System.out.println("Matrix is: " + matrix);
            Inverse inverseMatrix= new Inverse();
            Matrix result = inverseMatrix.inverse(matrix);
            result.writeToFile("InverseMatrix");
            System.out.println("InverseMatrix of x is " + result);
        } catch (MatrixException e) {
            System.err.println("Error of creating matrix " + e);
        }
    }

}
