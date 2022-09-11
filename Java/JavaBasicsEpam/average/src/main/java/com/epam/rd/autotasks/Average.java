package com.epam.rd.autotasks;

import java.util.Scanner;

public class Average {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Use Scanner methods to read input
        int nextNumber=scanner.nextInt();
        int sum=0;
        int numbersAmount=0;

        while(nextNumber!=0){
            sum+=nextNumber;
            numbersAmount++;
            nextNumber=scanner.nextInt();
        }

        System.out.println(sum/numbersAmount);
    }

}