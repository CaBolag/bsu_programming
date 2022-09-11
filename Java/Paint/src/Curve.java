import java.awt.*;
import java.util.ArrayList;

public class Curve {
    private ArrayList<Point> points;
    private Color color;

    public Curve(){
        points=new ArrayList<>();
        color=Color.RED;
    }
    public Color getColor() {
        return color;
    }

    public ArrayList<Point>  getPoints(){
        return points;
    }

    public void setColor(Color inputColor){
        color=inputColor;
    }

    public void addPoint(Point newPoint){
        points.add(newPoint);
    }

}
