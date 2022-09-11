package com.company;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class Main {

    public static void deleteSpace(StringBuilder stringB){
        //delete leading spaces
        int i = 0;
        int j = 0;
        while(i==0) {
            i = 0;
            if (Character.isWhitespace(stringB.charAt(i))) {
                stringB.deleteCharAt(i);
            } else {
                break;
            }
        }
        //delete trailing spaces
        j = stringB.length() - 1;
        while(j==(stringB.length() - 1)) {
            if (Character.isWhitespace(stringB.charAt(j))) {
                stringB.deleteCharAt(j);
                j = stringB.length() - 1;
            } else {
                break;
            }
        }

        //delete spaces between words
        int index=stringB.indexOf("  ");
        while(index>0){
            stringB.deleteCharAt(index);
            index=stringB.indexOf("  ");
        }
    }

    public static StringBuilder deleteOneCharacterWord(StringBuilder stringB){
        StringBuilder stringCopy=new StringBuilder(stringB);
        deleteSpace(stringCopy);
        if(stringCopy.length()>2) {
            for (int i = 1; i < stringCopy.length() - 1; i++) {
                if (Character.isWhitespace(stringCopy.charAt(i - 1))) {
                    if (Character.isWhitespace(stringCopy.charAt(i + 1))) {
                        stringCopy.delete(i - 1, i + 1);
                        i--;
                    }
                }
            }
        }

        //delete first one character word
        if(!Character.isAlphabetic(stringCopy.charAt(1))){
            stringCopy.delete(0,2);
        }

        //delete last one character word
        if(Character.isWhitespace(stringCopy.charAt(stringCopy.length()-2))){
            stringCopy.delete(stringCopy.length()-2,stringCopy.length());
        }
        return stringCopy;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        //String  inputString=sc.nextLine();

        String  inputString=" a  aa a  a aa aa a a";
        System.out.println("Input string:"+inputString);

        //using StringTokenizer
        StringTokenizer stringT=new StringTokenizer(inputString);
        StringBuilder transformedStringB=new StringBuilder();
        while(stringT.hasMoreTokens()) {
            String word=stringT.nextToken();
            if(word.length()>1){
                transformedStringB.append(word);
                transformedStringB.append(" ");
            }
        }

        System.out.println("Transformed string(StringTokenizer):"+transformedStringB);

        //using String.replaceAll
        String transformedString=inputString.replaceAll("(^|\\s+)([A-Za-z](\\s+|$))+"," ").trim();
        System.out.println("Transformed string (String method):"+transformedString);

        //using pattern
        Pattern pattern=Pattern.compile("(^|\\s+)([A-Za-z](\\s+|$))+");
        transformedString=pattern.matcher(inputString).replaceAll(" ").trim();
        System.out.println("Transformed string (pattern):"+transformedString);

        //using functions
        StringBuilder stringB=new StringBuilder(inputString);
        deleteSpace(stringB);
        System.out.println("InputString without spaces(function):"+stringB);
        transformedStringB=deleteOneCharacterWord(stringB);
        System.out.println("InputString without one character word(function):"+transformedStringB);


    }
}
