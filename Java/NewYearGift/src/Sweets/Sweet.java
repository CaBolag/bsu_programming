package Sweets;

import java.util.Locale;

public abstract class Sweet  {

    private String name;
    private double weight;
    private double sugar;
    private double price;

    public Sweet(String name, double weight, double sugar, double price) {
        this.name = name;
        this.weight = weight;
        this.sugar = sugar;
        this.price = price;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public double getWeight() {
        return weight;
    }
    public void setWeight(Double weight) {
        this.weight = weight;
    }

    public double getSugar() {
        return sugar;
    }

    public void setSugar(Double sugar) {
        this.sugar = sugar;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }
    @Override
    public String toString() {
        return  this.getClass().getName() +
                " \""+name +"\""+
                " weight = " + weight +
                " sugar = " + sugar +
                " price = " + price;
    }

}

