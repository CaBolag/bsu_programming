package com.company;

public class Exponential extends Series {
    public Exponential(double startElement, int size, double step){
        super(startElement,size,step);
        for(int i=1;i<size;i++){
            getData().add(getData().get(i-1)*step);
        }
    }
    @Override
    public double getElementByNumber(int n) {
        if(n<getSize()){
            return getData().get(n-1);
        }
        double element;
        element=getData().get(getSize()-1)*Math.pow(getStep(),n-getSize());
        return element;
    }
}
