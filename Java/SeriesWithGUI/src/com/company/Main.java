package com.company;


import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
/*        Linear progressionLinear=new Linear(1,5,2);
        File fileLinear=new File("OutputLinear.txt");
        try {
            progressionLinear.saveToFile(fileLinear);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(progressionLinear);
        System.out.println(progressionLinear.getElementByNumber(4));
        System.out.println(progressionLinear.toStringRange(3));

        System.out.println("Exponential");
        Exponential progressionExponential=new Exponential(1,5,2);
        File fileExponential=new File("OutputExponential.txt");
        try {
            progressionExponential.saveToFile(fileExponential);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(progressionExponential);
        System.out.println(progressionExponential.getElementByNumber(6));
        System.out.println(progressionExponential.toStringRange(4));
        *//*SeriesGUI app=new SeriesGUI();
        app.setVisible(true);*/
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                GUI app = new GUI();
                app.setVisible(true);
            }
        });


    }
}
