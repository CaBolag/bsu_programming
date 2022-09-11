package ProgramTest;

import Gift.Gift;
import Sweets.Chocolate;
import Sweets.Cookie;
import Sweets.LollyPop;

import java.io.FileNotFoundException;

public class GiftTest {
    public static void main(String[] args){
        try {
            Gift gift=new Gift();
            gift.ReadFromFile("giftData.txt");
            System.out.println("Sweets with sugar in the range 19-21:\n"+gift.findSweetWithSugarInTheRange(19,21).toString().replaceAll("[,\\[\\]]",""));
            gift.sortByWeight();
            System.out.println("Sorted gift by weight:\n"+gift);
            gift.sortBySugar();
            System.out.println("Sorted gift by sugar:\n"+gift);
            System.out.println("Frequency of LollyPop: "+gift.findFrequency(LollyPop.class));
            System.out.println("Frequency of Chocolate: "+gift.findFrequency(Chocolate.class));
            System.out.println("Frequency of Cookie: "+gift.findFrequency(Cookie.class));


        } catch (FileNotFoundException e){
            System.out.println("File not found");
        }

    }
}
