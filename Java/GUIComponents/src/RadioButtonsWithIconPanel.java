import javax.swing.*;

public class RadioButtonsWithIconPanel extends JPanel {
    private ButtonGroup radioButtonGroup;
    private JRadioButton[] radioButtons;
    private ImageIcon[] icons;
    public final static int ICONSAMOUNT = 3;
    public RadioButtonsWithIconPanel() {
        radioButtonGroup = new ButtonGroup();
        icons = new ImageIcon[ICONSAMOUNT + 1];
        for (int i = 0 ; i < ICONSAMOUNT + 1 ; i++){
            String path = "src\\icon" + i +".png";
            icons[i] = new ImageIcon(path);
        }

        radioButtons = new JRadioButton[ICONSAMOUNT];
        for (int i = 0 ; i <ICONSAMOUNT ; i++){
            radioButtons[i] = new JRadioButton("Click");
            radioButtons[i].setIcon(icons[0]);
            radioButtons[i].setSelectedIcon(icons[1]);
            radioButtons[i].setPressedIcon(icons[2]);
            radioButtons[i].setRolloverIcon(icons[3]);
            radioButtonGroup.add(radioButtons[i]);
            add(radioButtons[i]);
        }
    }
}
