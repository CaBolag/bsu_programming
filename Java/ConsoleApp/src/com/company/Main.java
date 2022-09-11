package com.company;
//lab1
public class Main {

    public static double calculateSum( double x,double eps) {
        double prev=Math.pow(x,2)/2;
        double sum=prev;
        boolean flag=true;
        int i=2;
        while(flag){
            prev*=(Math.pow(x,2)/(2*i));
            if(Math.abs(prev)>eps) {
                sum += prev;
                i++;
            }
            else{
                flag=false;
            }
        }
        return sum;
    }


    public static void main(String[] args) {
        double x=0.;
        double eps=0.1;
        try{
            x=Double.parseDouble(args[0]);
            eps=Double.parseDouble(args[1]);
        }
        catch (NumberFormatException exception) {
            System.err.println(exception.getMessage());
        }

        if(args.length!=2) {
            throw new ArrayIndexOutOfBoundsException("args.length!=2");
        }

        System.out.println("x= "+x);
        System.out.println("eps= "+eps);
        double sum=calculateSum(x,eps);
        System.out.println("Sum= "+sum);
    }
}
