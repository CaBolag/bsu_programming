import javax.swing.*;

public class Main {
    public static void main(String[] args) {
     /*   MouseDragDropApp mouseDragDropApp=new MouseDragDropApp();
        mouseDragDropApp.pack();
        mouseDragDropApp.setVisible(true);*/
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
               MouseDragDropApp mouseDragDropApp=new MouseDragDropApp();
               mouseDragDropApp.pack();
               mouseDragDropApp.setVisible(true);
               //RunningAwayButtonApp runningAwayButtonApp=new RunningAwayButtonApp();


            }
        });
    }
}
