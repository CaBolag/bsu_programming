package com.company;

public class Linear extends Series  {
    public Linear(double startElement, int size, double step){
        super(startElement,size,step);
        for(int i=1;i<size;i++){
            getData().add(getData().get(i-1)+step);
        }
    }

    @Override
    public double getElementByNumber(int n){
        double element;
        if(n<getSize()){
            element=getData().get(n-1);
            return element;
        }

        element=getData().get(getSize()-1)+(n-getSize())*getStep();
        return element;
    }
}

