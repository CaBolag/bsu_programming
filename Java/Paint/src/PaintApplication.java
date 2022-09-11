import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class PaintApplication extends JFrame{
    private ApplicationPanel mainPanel;
    //private ArrayList<ArrayList<Point>> curves;
    private JMenu menu;
    private JMenuBar menuBar;
    private JMenuItem saveMenuItem;
    private JMenuItem openMenuItem;
    private JMenuItem colorChooserMenuItem;
    private JScrollPane scrollPane;
    private boolean isPressed;


    public PaintApplication(){
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainPanel=new ApplicationPanel();
        //curves=new ArrayList<ArrayList<Point>>();
        setLayout(null);
        setBackground(new Color(200, 190, 250));
        setSize(700, 500);
        setVisible(true);

        createMenu();
        initListeners();
    }

    private void createMenu(){
        menu=new JMenu("Menu");
        menuBar=new JMenuBar();
        menuBar.add(menu);
        saveMenuItem=new JMenuItem("Save");
        openMenuItem=new JMenuItem("Open");
        colorChooserMenuItem=new JMenuItem("Choose color");
        menu.add(saveMenuItem);
        menu.add(openMenuItem);
        menu.add(colorChooserMenuItem);
        add(menuBar);
        setJMenuBar(menuBar);
    }

    private void saveToFile(){
        final JFileChooser fc = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Image file", "png", "jpg");
        fc.setFileFilter(filter);
        int returnVal = fc.showOpenDialog(saveMenuItem);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            File file = fc.getSelectedFile();
            try {
                ImageIO.write(mainPanel.getImage(), "png", file);
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void openFromFile(){
        final JFileChooser fc = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Image file", "png", "jpg", "jpeg");
        fc.setFileFilter(filter);
        int returnVal = fc.showOpenDialog(openMenuItem);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            File file = fc.getSelectedFile();
            try {
                BufferedImage image = ImageIO.read(file);
                mainPanel.setImage(image);
                mainPanel.getImage().createGraphics().drawImage(image,0,0,null);

            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void initListeners(){

        addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
            }

            @Override
            public void mousePressed(MouseEvent e) {
                isPressed=true;
                Curve newCurve=new Curve();
                newCurve.addPoint(e.getPoint());
                mainPanel.getCurves().add(newCurve);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                isPressed=false;
            }

            @Override
            public void mouseEntered(MouseEvent e) {
            }

            @Override
            public void mouseExited(MouseEvent e) {
            }
        });

        addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                if(isPressed==true){
                    Curve currentCurve=mainPanel.getCurves().get(mainPanel.getCurves().size()-1);
                    currentCurve.addPoint(e.getPoint());
                    mainPanel.paintComponent(getGraphics());
                    //repaint();
                }
            }
        });

        colorChooserMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //Color currentColor=mainPanel.getCurves().get(mainPanel.getCurves().size()).getColor();
                Curve newCurve=new Curve();
                newCurve.setColor(JColorChooser.showDialog(null,"Choose file",newCurve.getColor()));
                mainPanel.getCurves().add(newCurve);
            }
        });

        saveMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                saveToFile();
            }
        });

        saveMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {


            }
        });

        openMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                openFromFile();
            }
        });

    }


}
