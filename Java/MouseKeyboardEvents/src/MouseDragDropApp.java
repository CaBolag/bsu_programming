import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseDragDropApp extends JFrame {
    //private JFrame frame=new  JFrame("TopLevelDemo");
    private JPanel contentPane = new JPanel();
    private JButton button = new JButton("Drag and drop");
    private JLabel labelMouseCoordinates = new JLabel();
    private boolean changeButtonName=false;
    int xComponent = 0;
    int yComponent = 0;

    public MouseDragDropApp() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(contentPane);
        contentPane.setLayout(null);
        contentPane.setPreferredSize(new Dimension(600, 300));
        contentPane.setBackground(new Color(250,170,170));
        button.setSize(150,50);
        int h=contentPane.getPreferredSize().width/2-button.getWidth()/2;
        button.setLocation((contentPane.getPreferredSize().width/2-button.getWidth()/2),contentPane.getPreferredSize().height/2-button.getHeight()/2);
        contentPane.add(labelMouseCoordinates);
        contentPane.add(button);
        labelMouseCoordinates.setSize(200,50);
        labelMouseCoordinates.setLocation(0,(contentPane.getPreferredSize().height-labelMouseCoordinates.getHeight()));
        labelMouseCoordinates.setFont(new Font("TimesRoman", Font.BOLD, 18));
        labelMouseCoordinates.setOpaque(true);
        labelMouseCoordinates.setBackground(new Color(200,200,220));

        initListeners();
    }

    private void initListeners() {
        contentPane.addMouseListener(new MouseAdapter() {
            int maxXToMoveButton=contentPane.getWidth()-button.getWidth();
            int maxYToMoveButton=contentPane.getHeight()-button.getHeight();
            @Override
            public void mouseClicked(MouseEvent e) {

                int x=contentPane.getMousePosition().x;
                int y=contentPane.getMousePosition().y;
                if(contentPane.getMousePosition().x<maxXToMoveButton ||contentPane.getMousePosition().y>maxYToMoveButton){
                    button.setLocation(contentPane.getMousePosition());
                    changeButtonName=false;
                } else{
                    changeButtonName=false;
                }

            }
        });

        contentPane.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                labelMouseCoordinates.setText("X = " + e.getX() + "; Y = " + e.getY());
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                button.setLocation(contentPane.getMousePosition());
                changeButtonName=false;
            }
        });

        contentPane.addComponentListener(new ComponentListener() {
            @Override
            public void componentResized(ComponentEvent e) {
                labelMouseCoordinates.setLocation(0,(contentPane.getHeight()-labelMouseCoordinates.getHeight()));
                button.setLocation((contentPane.getSize().width/2-button.getWidth()/2),contentPane.getSize().height/2-button.getHeight()/2);

            }

            @Override
            public void componentMoved(ComponentEvent e) {

            }

            @Override
            public void componentShown(ComponentEvent e) {

            }

            @Override
            public void componentHidden(ComponentEvent e) {

            }
        });

        MouseAdapter mouseDragDropAdapter = new MouseAdapter() {
            int clickXComponent=0;
            int clickYComponent=0;
            @Override
            public void mousePressed(MouseEvent e) {
                if (e.isControlDown() ) {
                    clickXComponent=e.getX();
                    clickYComponent=e.getY();
                }
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                labelMouseCoordinates.setText("X="+e.getXOnScreen()+" Y="+e.getYOnScreen());
            }
            @Override
            public void mouseDragged(MouseEvent e) {
                if(e.isControlDown()){
                    int xAdded = e.getX() - clickXComponent;
                    int yAdded = e.getY() - clickYComponent;
                    button.setLocation( button.getX() + xAdded, button.getY() + yAdded);
                    labelMouseCoordinates.setText("X="+button.getX()+" Y="+button.getY());
                }
            }
        };

        button.addMouseListener( mouseDragDropAdapter );
        button.addMouseMotionListener( mouseDragDropAdapter );

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                changeButtonName=true;
            }
        });

        button.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                if(changeButtonName==true){
                    if (e.getKeyChar() == KeyEvent.VK_BACK_SPACE) {
                        String newText = new String(button.getText());
                        if (newText.length() > 0){
                            button.setText(newText.substring(0,newText.length()-1));
                        }

                    } else {
                        StringBuffer newText = new StringBuffer();
                        newText.append(button.getText());
                        newText.append(e.getKeyChar());
                        button.setText(newText.toString());
                    }
                }
            }
        });
    }
}
