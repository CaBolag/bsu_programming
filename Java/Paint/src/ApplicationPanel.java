import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class ApplicationPanel extends JPanel {
    private BufferedImage image;
    private ArrayList<Curve> curves;


    ApplicationPanel(){
        setPreferredSize(new Dimension(500, 700));
        curves=new ArrayList<Curve>();
        image = new BufferedImage(1000, 1000, BufferedImage.TYPE_INT_ARGB);
    }

    @Override
    protected void paintComponent(Graphics g) {
        int currentIndex = 0;
        for (Curve curve : curves) {
            for (Point currentPoint : curve.getPoints()) {
                image.getGraphics().setColor(curve.getColor());
                if (currentIndex + 1 < curve.getPoints().size()) {
                    image.getGraphics().drawLine(currentPoint.x, currentPoint.y, curve.getPoints().get(currentIndex + 1).x, curve.getPoints().get(currentIndex + 1).y);
                    currentIndex++;
                }
            }
        }

       // super.paintComponent(g);
        g.drawImage(image,0,0,null);
    }

    public BufferedImage getImage(){
        return image;
    }
    public ArrayList<Curve> getCurves(){
        return curves;
    }

    public void setImage(BufferedImage newImage){
        image=newImage;
        setPreferredSize(new Dimension(image.getWidth(),image.getHeight()));
        repaint();
        revalidate();
    }
}
