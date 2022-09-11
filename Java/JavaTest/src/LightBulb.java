public abstract class LightBulb {
    private String manufacturer;
    double power;

    public LightBulb(String manufacturer, double power) {
        this.manufacturer = manufacturer;
        this.power = power;
    }

    abstract public double countPrice();

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public double getPower() {
        return power;
    }

    public void setPower(double power) {
        this.power = power;
    }

    @Override
    public String toString() {
        return "Manufacturer='" + manufacturer + '\'' +
                ", power=" + power+
                ", price="+ String.format("%.2f",countPrice());
    }
}
