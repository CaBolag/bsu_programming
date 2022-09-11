import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class InputAndOutput {


    // Method that reads a file and returns an array list of all positive integers that were found in the file.
    // Break up floating-point numbers and numbers containing commas
    // class FindNumbers
    /**
     This class reads a file and returns an array list of all numbers in the file.
     Only numbers following the Java number convention are matched. For example,
     14.9 is recognized but 200,000 results in two numbers 200 and 0.
     @param filename the file name
     @return a list of numbers
     */
    public static ArrayList<Integer> findIntegersInAFile(String filename)  throws IOException {
        ArrayList<Integer> numbers=new ArrayList<>();
        Scanner sc =new Scanner(new File(filename));
        sc.useDelimiter("[^0-9]+");
        while(sc.hasNext()){
            numbers.add(Integer.valueOf(sc.next()));
        }
        return numbers;
    }

    //class Arithmetic
    /**
     This class reads a file containing arithmetic expressions and returns an
     array list of the results.
     @param filename the file name
     @return a list of results
     */
    public static ArrayList<Integer> readFileWithArithmeticExpressions(String filename) throws IOException
    {
        ArrayList<Integer> results=new ArrayList<>();
        ArrayList<Integer> numbers=new ArrayList<>();
        Scanner sc =new Scanner(new File(filename));
        while (sc.hasNext()) {
            String inputstring = sc.nextLine();
            StringTokenizer st = new StringTokenizer(inputstring, " [-+*] ");
            String delimiter = new String();
            Integer firstValue = 0;
            Integer secondValue = 0;
            Integer result = 0;
            while (st.hasMoreTokens()) {
                firstValue = Integer.parseInt(st.nextToken());
                secondValue = Integer.parseInt(st.nextToken(delimiter));
                if (delimiter.equals("*")) {
                    result = firstValue * secondValue;
                } else if (delimiter.equals("+")) {
                    result = firstValue + secondValue;
                } else {
                    result = firstValue + secondValue;
                }
            }
            results.add(result);
        }

        return results;
    }

    public static boolean check(String value1, String operator, String value2)
    {
        boolean flag=value1.contains("[0-9]+");
    }



}
