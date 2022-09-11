package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args){

        String[] words={"aa","aaaa","aaa"};
        removeShortWords(words);
        System.out.println(words);

        public static String check(String filename)
        {
            try
            {
                return (filename).toString();
            }
            catch (IOException ex)
            {
                return "I/O exception thrown";
            }
            catch (Exception ex)
            {
                return ex.getMessage();
            }
        }
    }




    public static void removeShortWords(String[] words)
    {
      /*  for(int i=0;i<words.length;i++){
            if(words[i].length()<=3){
                words[i]=words[i].replace(words[i],"");
            }
        }
        Arrays.sort(words);*/
        List<String> result=(ArrayList<String>) Arrays.stream(words).filter(word->word.length()<=3).collect(Collectors.toList());

    }
    public ArrayList<String> shortWords(String[] words)
    {
        /*ArrayList<String> result=new ArrayList<>();
        for(String word:words){
            if(word.length()<=3){
                result.add(word);
            }
        }*/
        ArrayList<String> result=(ArrayList<String>) Arrays.stream(words).filter(word->word.length()>=3).collect(Collectors.toList());
        return result;
    }
    public String separateWithCommas(int[] values)
    {
        StringBuilder result=new StringBuilder();
        if(values.length>=1) {
            result.append(values[0]);
            for (int i = 1; i < values.length; i++) {
                result.append("," + values[i]);
            }
        }
        //Arrays.stream(values).map(Object::toString).collect(Collectors.joining(", "));

        return result.toString();
    }
}
