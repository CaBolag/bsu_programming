import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

public class ButtonClickPanel extends JPanel {
    private ArrayList<JButton> buttons;
    private Color defaultColor=Color.PINK;

    public ButtonClickPanel(int diagonallyAmount, int verticalAmount){

        MouseListener mouseListener=new MouseListener(){
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {
                JButton currentButton=(JButton)e.getSource();
                currentButton.setText("Clicked");
            }

            @Override
            public void mouseReleased(MouseEvent e){
                JButton currentButton=(JButton)e.getSource();
                currentButton.setText(Integer.toString(buttons.indexOf(currentButton)+1));
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                JButton currentButton=(JButton)e.getSource();
                currentButton.setBackground(Color.YELLOW);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                JButton currentButton=(JButton)e.getSource();
                currentButton.setBackground(defaultColor);

            }
        };

        UIManager.put( "Button.select", Color.YELLOW);
        buttons=new ArrayList<>();
        JButton button;
        setLayout(new GridLayout(diagonallyAmount,verticalAmount));
        for(int i=1;i<diagonallyAmount*verticalAmount+1;i++){
            button = new JButton(Integer.toString(i));
            button.setBackground(defaultColor);
            button.addMouseListener(mouseListener);

            buttons.add(button);
            add(button);
        }
    }


}
