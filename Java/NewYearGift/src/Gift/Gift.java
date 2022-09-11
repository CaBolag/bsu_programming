package Gift;

import Sweets.Chocolate;
import Sweets.Cookie;
import Sweets.LollyPop;
import Sweets.Sweet;

import java.awt.*;
import java.io.*;
import java.time.temporal.ValueRange;
import java.util.*;
import java.util.List;
import java.util.stream.Collectors;

public class Gift extends ArrayList<Sweet> {

    private double weight;
    private double sugar;
    private double price;

    public Gift(){
        super();
    }

    @Override
    public boolean add(Sweet sweet) {
        weight += sweet.getWeight();
        sugar += sweet.getSugar();
        price += sweet.getPrice();
        return super.add(sweet);
    }


    public void sortByWeight() {
        Comparator<Sweet> comparator = new Comparator<Sweet>() {
            @Override
            public int compare(final Sweet sweet1, final Sweet sweet2) {
                return Double.compare(sweet1.getWeight(), sweet2.getWeight());
            }
        };
        this.sort(comparator);
    }

    public void sortBySugar() {
        this.sort(Comparator.comparingDouble(Sweet::getSugar));
    }

    public ArrayList<Sweet> findSweetWithSugarInTheRange(double minValue, double maxValue) {
        return this.stream().filter(sweet -> ValueRange.of((long) minValue, (long) maxValue)
                .isValidValue((long) sweet.getSugar())).collect(Collectors.toCollection(ArrayList::new));
    }

    public double findFrequency(Class type) {
        int amount = this.stream().filter(sweet -> sweet.getClass() == type).toList().size();
        return (double) amount/this.size();
    }


    public void ReadFromFile(String filename) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(filename));
        sc.useDelimiter("\n");
        Sweet newSweet;
        Double weight=0.;
        Double sugar=0.;
        Double price=0.;
        String name="";

        while (sc.hasNext()) {
            String str = sc.next();
            List<String>strList=Arrays.asList(str.split(" "));
            try {
                name=Arrays.asList(str.split("\"")).get(1);
                weight = Double.parseDouble(strList.stream().filter(s -> s.contains("weight")).findAny().get().replaceAll("[^0.-9.]+", " "));
                sugar = Double.parseDouble(strList.stream().filter(s -> s.contains("sugar")).findAny().get().replaceAll("[^0.-9.]+", " "));
                price = Double.parseDouble(strList.stream().filter(s -> s.contains("price")).findAny().get().replaceAll("[^0.-9.]+", " "));
                switch (strList.get(0)) {
                    case "CH" -> {
                        Double cocoa=0.;
                        try{
                            cocoa=Double.parseDouble(strList.stream().filter(s -> s.contains("cocoa")).findAny().get().replaceAll("[^0.-9.]+", " "));
                            newSweet=new Chocolate(name,weight,sugar,price,cocoa);
                            add(newSweet);
                        } catch (NoSuchElementException ex){
                            newSweet=new Chocolate(name,weight,sugar,price,cocoa);
                            add(newSweet);
                        }

                    }
                    case "LP" -> {
                        String form="no info";
                        LollyPop.Color color=null;
                        try{
                            form=strList.stream().filter(s -> s.contains("form")).findAny().get().replaceAll("form=","");
                            color= LollyPop.Color.valueOf(strList
                                    .stream()
                                    .filter(s -> s.contains("color"))
                                    .findAny()
                                    .get()
                                    .replaceAll("color=","")
                                    .trim()
                                    .toUpperCase(Locale.ROOT));
                            newSweet = new LollyPop(name,weight,sugar,price,form,color);
                            add(newSweet);

                        } catch (NoSuchElementException ex){
                            newSweet = new LollyPop(name,weight,sugar,price,form,color);
                            add(newSweet);

                        }

                    }
                    case "CK" -> {
                        String form="no info";
                        String filling="no info";
                        try{
                            form=strList.stream().filter(s -> s.contains("form")).findAny().get().replaceAll("form=","");
                            filling=strList.stream().filter(s -> s.contains("filling")).findAny().get().replaceAll("filling=","");
                            newSweet = new Cookie(name,weight,sugar,price,form,filling);
                            add(newSweet);
                        } catch (NoSuchElementException ex){
                            newSweet = new Cookie(name,weight,sugar,price,form,filling);
                            add(newSweet);
                        }
                    }
                }
            } catch (IllegalArgumentException ex){
                System.out.println("Input error");
            }
        }
    }

    public void saveToFile(String filename) throws FileNotFoundException{
        PrintWriter printWriter=new PrintWriter(filename);
        printWriter.println(toString());
    }
    @Override
    public String toString() {
      /*  String str=String.join("@",sweets.toString());
        String str1 = Arrays.asList(sweets.toString()).stream().collect(Collectors.joining("@"));
        String str2=sweets.toString();*/
        String str=super.toString();

        return "------------------" +"\n"+
                "Gift:"+"\n"+
                "Sweets:"+"\n"+super.toString().replaceAll("[,\\[\\]]","")+"\n"+
                "Total:"+"\n"+
                "Weight=" + weight +"\n"+
                "Sugar=" + sugar +"\n"+
                "Price=" + price +"\n"+
                "------------------" +"\n";

    }
}