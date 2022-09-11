package Sweets;

public class Chocolate extends Sweet{
    private double cocoa;

    public Chocolate(String name, double weight, double sugar, double price, double cocoa) {
        super(name, weight, sugar, price);
        this.cocoa = cocoa;
    }


    public double getCocoa() {
        return cocoa;
    }

    public void setCocoa(double cocoa) {
        this.cocoa = cocoa;
    }

    @Override
    public String toString() {
        return super.toString()+" cocoa = " + cocoa + "\n";
    }
}

