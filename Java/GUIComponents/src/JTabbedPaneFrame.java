import javax.swing.*;
import java.awt.*;

public class JTabbedPaneFrame extends JFrame {
    private JTabbedPane pane;
    private MoveFromListToListApplication moveFromListToListApp;
    private ButtonClickPanel buttonClickPanel;
    private RadioButtonsWithIconPanel radioButtonsWithIconPanel;
    public JTabbedPaneFrame(int diagonallyInt,int verticalInt){
        super("JTabbedPaneFrame Demo ");
        pane=new JTabbedPane();
        moveFromListToListApp=new MoveFromListToListApplication();
        buttonClickPanel=new ButtonClickPanel(diagonallyInt,verticalInt);
        radioButtonsWithIconPanel=new RadioButtonsWithIconPanel();

        pane.addTab("Lists",null,moveFromListToListApp);
        pane.addTab("Buttons",null,buttonClickPanel);
        pane.addTab("Radio buttons",null,radioButtonsWithIconPanel);

        add(pane);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500,500);
        setVisible(true);


/*        JLabel label2=new JLabel("panel two",SwingConstants.CENTER);
        JPanel panel2=new JPanel();
        panel2.setBackground(Color.YELLOW);
        panel2.add(label2);
        tabbedPane.addTab("Tab two",null,panel2,"Second panel");*/
        /*JPanel panel3=new JPanel();
        panel3.setLayout(new BorderLayout());
        JList rightList=new JList();
        rightList.setVisibleRowCount(5);
        panel3.add(rightList,BorderLayout.EAST);
        panel3.add(new JList(),BorderLayout.WEST);*/



    }

}
