import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class RunningAwayButtonApp extends JFrame {
    private JPanel contentPane = new JPanel();
    private JLabel fieldQuestion = new JLabel();
    private JButton buttonYes = new JButton();
    private JButton buttonNo = new JButton();

    public RunningAwayButtonApp() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setContentPane(contentPane);
        contentPane.setBackground(new Color(200, 190, 250));
        setSize(700, 500);

        fieldQuestion.setBackground(new Color(190, 220, 200));
        //? TExtField.setSize()
        fieldQuestion.setPreferredSize(new Dimension(500, 50));
        fieldQuestion.setHorizontalAlignment(JTextField.CENTER);
        fieldQuestion.setFont(new Font("TimesRoman", Font.BOLD, 20));
        fieldQuestion.setText("Are you satisfied with the size of the scholarship?");

        //buttonYes.setPreferredSize(new Dimension(100,30));
        buttonYes.setText("Yes");
        buttonNo.setText("No");
        buttonYes.setBounds(250,250,100,30);
        //buttonYes.setLocation((contentPane.getPreferredSize().width/3-buttonYes.getWidth()/2),contentPane.getPreferredSize().height/3-buttonYes.getHeight()/2);
        buttonNo.setBounds(300,250,100,30);


        contentPane.add(fieldQuestion);
        contentPane.add(buttonYes);
        contentPane.add(buttonNo);
        setVisible(true);

        initListeners();
    }

    private void initListeners(){
        buttonNo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            /*    JOptionPane optionPane = new JOptionPane(new JLabel("Will have to endure for a while...",JLabel.CENTER));
                JDialog dialog=optionPane.createDialog("");
                dialog.setVisible(true);*/
                JOptionPane.showMessageDialog(null, "Will have to endure for a while...", "", JLabel.CENTER);

            }
        });

        //buttonYes.getFocusListeners().

        buttonYes.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {}

            @Override
            public void mousePressed(MouseEvent e) {}

            @Override
            public void mouseReleased(MouseEvent e) {}

            @Override
            public void mouseEntered(MouseEvent e) {
                int newX=0;
                int newY=0;
                Random rand=new Random();
                int minWindowX=contentPane.getX();
                int maxWindowX=contentPane.getX()+contentPane.getWidth()-buttonYes.getWidth();
                int minWindowY=contentPane.getY();
                int maxWindowY=contentPane.getY()+contentPane.getHeight()-buttonYes.getHeight();
                newX  =  minWindowX + rand.nextInt( maxWindowX- minWindowX + 1);
                newY  =  minWindowY + rand.nextInt( maxWindowY- minWindowY + 1);
                if(!buttonYes.contains(newX,newY)){
                    buttonYes.setLocation(newX,newY);
                } else{
                    generateRandomInt(newX,newY);
                }
            }

            @Override
            public void mouseExited(MouseEvent e) {
            }
        });

        /*        contentPane.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                Rectangle buttonBounds=buttonYes.getBounds();
                int currentX=e.getXOnScreen();
                int currentY=e.getYOnScreen();
                if(currentX>=buttonBounds.x-20 & currentX<=(buttonBounds.x+buttonBounds.width) *//*& currentY>=buttonBounds.y & currentY<=(buttonBounds.y+buttonBounds.height)*//*){
                    moveButtonRight();
                }
                if(currentX<=(buttonBounds.x+buttonBounds.width+20) & currentX>=buttonBounds.x & currentY>=buttonBounds.y & currentY<=(buttonBounds.y+buttonBounds.height)){
                    moveButtonLeft();
                }
            }
        });*/
    }
    private void generateRandomInt(int newX,int newY){
        Random rand=new Random();
        int minWindowX=contentPane.getX();
        int maxWindowX=contentPane.getX()+contentPane.getWidth()-buttonYes.getWidth();
        int minWindowY=contentPane.getY();
        int maxWindowY=contentPane.getY()+contentPane.getHeight()-buttonYes.getHeight();
        newX  =  minWindowX + rand.nextInt( maxWindowX- minWindowX + 1);
        newY  =  minWindowY + rand.nextInt( maxWindowY- minWindowY + 1);
    }

}
