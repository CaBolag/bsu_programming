package Sweets;

public class Cookie extends Sweet{
    private String form;
    private String filling;

    public Cookie(String name, double weight, double sugar, double price, String form, String filling) {
        super(name, weight, sugar, price);
        this.form = form;
        this.filling = filling;
    }


    public String getForm() {
        return form;
    }

    public void setForm(String form) {
        this.form = form;
    }

    public String getFilling() {
        return filling;
    }

    public void setFilling(String filling) {
        this.filling = filling;
    }


    @Override
    public String toString() {
        return super.toString()+" form = " + form + "" + " filling = "+filling+"\n";
    }

}
