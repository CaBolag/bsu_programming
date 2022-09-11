import javax.swing.*;

public class JTabbedPaneDemo {
    public static void main(String[] args) {
        try {
            JTabbedPaneFrame tabbedPaneFrame=new JTabbedPaneFrame(Integer.parseInt(args[0]),Integer.parseInt(args[1]));
        } catch (NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Enter correct size!", "ERROR", JOptionPane.ERROR_MESSAGE);
        } catch (ArrayIndexOutOfBoundsException e){
            JOptionPane.showMessageDialog(null, "Enter diagonal and vertical size!", "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }
}
