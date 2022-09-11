public class LEDLamp extends LightBulb {
    final static double LEDL=4.;
    private int LEDsAmount;

    public LEDLamp(String manufacturer, double power, int LEDsAmount) {
        super(manufacturer,power);
        this.LEDsAmount = LEDsAmount;
    }

    @Override
    public double countPrice() {
        return  power*LEDsAmount/LEDL*100;

    }

    @Override
    public String toString() {
        return "LEDLamp{" +
                super.toString()+
                "LEDsAmount=" + LEDsAmount +
                '}';
    }
}
