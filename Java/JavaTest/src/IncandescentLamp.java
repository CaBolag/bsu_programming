public class IncandescentLamp extends LightBulb {
    final static double IL=1.;
    private double operatingTime;

    public IncandescentLamp(String manufacturer, double power,double operatingTime) {
        super(manufacturer, power);
        this.operatingTime=operatingTime;

    }

    @Override
    public double countPrice() {
        return power*IL*operatingTime;
    }

    @Override
    public String toString() {
        return "IncandescentLamp{"+
                super.toString()+
                "operatingTime=" + operatingTime +
                '}';
    }
}
