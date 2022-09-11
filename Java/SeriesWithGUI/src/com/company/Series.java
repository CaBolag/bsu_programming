package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

public abstract class Series implements Comparable<Series> {
    private ArrayList<Double> data;
    private int size;
    private double step;

    public Series(double startElement,int size,double step){
        this.data=new ArrayList<>();
        this.data.add(startElement);
        this.size=size;
        this.step=step;
    }

    public ArrayList<Double> getData(){
        return data;
    }
    public double getFirstElement(){return data.get(0);}
    public int getSize(){
        return size;
    }
    public double getStep(){
        return step;
    }

    @Override
    public int compareTo(Series another) {
        if(another.getData().equals(data)){
            return 1;
        }else {
            return 0;
        }
    }

    public double findSum(){
        double sum=0.;
        sum = data.stream().reduce(0., Double::sum);
        return sum;
    }

    public String toStringRange(int n) throws IndexOutOfBoundsException{
        String dataString="";
        try {
            dataString = data.subList(0,n).stream()
                    .map(Object::toString)
                    .collect(Collectors.joining(", ","{","}"));
            //data.forEach(System.out::println);
        } catch (IndexOutOfBoundsException e){
            throw new IndexOutOfBoundsException("Range is too big");
        }
/*        String dataString = data.toString();
        dataString = dataString.replace("[", "")
                .replace("]", "")
                .replace(" ", "");*/
        return dataString;
    }

    public String toString(){
        String dataString=toStringRange(data.size());
        return dataString;
    }

    public void saveToFile(File file) throws FileNotFoundException {
        try (PrintWriter writer = new PrintWriter(file)) {
            String stringData = this.toString();
            writer.println(stringData);
            double sum=this.findSum();
            writer.println("Sum = "+sum);
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException();
        }
    }

    public abstract double getElementByNumber(int n);
}

