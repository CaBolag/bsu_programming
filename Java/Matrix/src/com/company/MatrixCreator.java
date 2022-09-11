package com.company;

import com.company.Matrix;
import com.company.MatrixException;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class MatrixCreator {
    public void fillRandomized(Matrix matrix, double minValue, double maxValue) {
        int v = matrix.getVerticalSize();
        int h = matrix.getHorizontalSize();
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < h; j++) {
                try {
                    double value = (double) ((Math.random() * (maxValue - minValue)) + minValue);
                    matrix.setElement(i, j, value);
                } catch (MatrixException e) {
                    // log: exception impossible
                }
            }
        }
    }

    public void createFromFile(Matrix matrix, File file) throws MatrixException{
        try {
            Scanner scanner = new Scanner(file);
            int v = matrix.getVerticalSize();
            int h = matrix.getHorizontalSize();
                for (int i = 0; i < v; i++) {
                    for (int j = 0; j < h; j++) {
                        try {
                            matrix.setElement(i, j, scanner.nextDouble());
                        } catch (NoSuchElementException e) {
                            throw new MatrixException("Error!");
                        }
                    }
                }
        } catch (FileNotFoundException ex) {
           System.err.println("File not found");
        }

    }

    /*    public Matrix createFromFile(File file)  {
            try {
                Scanner scanner = new Scanner(file);
                String nextRow=scanner.nextLine();
                int rowSize=nextRow.length();
                for(int i = 0; i < rowSize; i++) {
                        matrix.setElement();[i] = Integer.valueOf(stringResult[i]);

                        try {
                            matrix.setElement(i, j, scanner.nextDouble());
                        } catch (MatrixException e) {
                            System.err.println("Insufficient data"+e);
                        }
                    }

            } catch(FileNotFoundException ex){
                System.err.println("File not found");
            }

        }*/
    public Matrix createFromFile(String fileName) throws MatrixException {
        String stringResult = "";
        int rowSize = 0;
        int columnSize = 0;
        Matrix matrix = null;
        try (BufferedReader reader =
                     new BufferedReader(new FileReader(fileName))) {

            String tmp;
            List<List<Double>> elements = new ArrayList<List<Double>>();
            while ((tmp = reader.readLine()) != null) { //java 2
                String[] elementsString = tmp.split(" ");
                List<Double> elementsRow = new ArrayList<Double>();
                for (int i = 0; i < elementsString.length; i++) {
                    elementsRow.add(Double.parseDouble(elementsString[i]));
                }
                elements.add(elementsRow);
            }

            rowSize = elements.get(0).size();
            columnSize = elements.size();
            for (List<Double> row : elements) {
                if (row.size() != rowSize) {
                    throw new MatrixException("Insufficient data");
                }
            }
            matrix = new Matrix(rowSize, columnSize);
            try {
                for (int i = 0; i < columnSize; i++) {
                    for (int j = 0; j < rowSize; i++) {
                        matrix.setElement(i, j, matrix.getElement(i, j));
                    }
                }
            } catch (MatrixException e) {
                System.err.println("Insufficient data" + e);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return matrix;
    }
}
