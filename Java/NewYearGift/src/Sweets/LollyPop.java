package Sweets;

public class LollyPop extends Sweet {
    public enum Color{
        GREEN,
        RED,
        BLUE
    }
    private String form;
    private Color color;

    public LollyPop(String name, double weight, double sugar, double price, String form,Color color) {
        super(name, weight, sugar, price);
        this.form = form;
        this.color=color;
    }


    public String getForm() {
        return form;
    }

    public void setForm(String form) {
        this.form = form;
    }

    @Override
    public String toString() {
        return super.toString()+" form = " + form + " color = "+color+"\n";
    }
}
