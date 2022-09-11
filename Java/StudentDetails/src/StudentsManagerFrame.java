import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;

public class StudentsManagerFrame extends JFrame {
    private JPanel mainPanel;
    private JList modifiedDataList;
    private JList originalDataList;
    private JButton addStudentButton;
    private JButton showButton;
    private JList byCourseNumberList;
    private JTextField courseNumberTextField;

    private JMenu menu;
    private JMenuBar menuBar;
    private JMenuItem fileMenuItem;
    private JMenuItem openMenuItem;


    public void setStudentsManager(StudentsManager studentsManager) {
        this.studentsManager = studentsManager;
    }

    private StudentsManager studentsManager;

    StudentsManagerFrame(){
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(mainPanel);
        setTitle("Series");
        setSize(700, 500);
        courseNumberTextField.setBounds(new Rectangle(200,100));
        /*getRootPane().setDefaultButton(buttonO);*/


        menu=new JMenu("File");
        menuBar=new JMenuBar();
        menuBar.add(menu);
        openMenuItem=new JMenuItem("Open");
        menu.add(openMenuItem);
        add(menuBar);
        setJMenuBar(menuBar);
        setVisible(true);
        initListeners();
    }
    public void initListeners(){
        //??????
        StudentsManagerFrame studentsManagerFrame=this;
        /////
        addStudentButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    NewStudentDialog newStudentPanel=new NewStudentDialog(studentsManagerFrame);
                    updateFields();
                } catch (NullPointerException ex){
                    studentsManager=new StudentsManager();
                    NewStudentDialog newStudentPanel=new NewStudentDialog(studentsManagerFrame);
                    updateFields();
                }

            }
        });

        openMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                openFromFile();
                originalDataList.setListData(studentsManager.getStudents().toString().replaceAll("[\\,\\[\\]]","").split("\n"));
                modifiedDataList.setListData(studentsManager.getSortedStudents().toString().replaceAll("[\\,\\[\\]]","").split("\n"));
            }
        });

        //???????

/*        courseNumberTextField.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {

            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                byCourseNumberList.setListData(studentsManager.getStudents().toArray());
            }

            @Override
            public void changedUpdate(DocumentEvent e) {

            }
        });*/

        showButton.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                        int courseNumber=Integer.parseInt(courseNumberTextField.getText());
                        byCourseNumberList.setListData(studentsManager.studentsByCourseNumber(courseNumber).toArray());
                } catch (NullPointerException ex){
                    JOptionPane.showMessageDialog(studentsManagerFrame,
                            "There is no students!",
                            "ERROR", JOptionPane.ERROR_MESSAGE);
                } catch (NumberFormatException ex){
                    JOptionPane.showMessageDialog(studentsManagerFrame,
                            "Enter a course number!",
                            "ERROR", JOptionPane.ERROR_MESSAGE);
                }

            }
        });

    }

    private void openFromFile() {
        final JFileChooser fc = new JFileChooser();
        int returnVal = fc.showOpenDialog(openMenuItem);
        try {
            if (studentsManager == null) {
                studentsManager = new StudentsManager();
            }
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                studentsManager.readFromFile(fc.getSelectedFile().getName());
            }
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(this,"File not found!",
                    "ERROR", JOptionPane.ERROR_MESSAGE);
        }
    }

    public void updateFields(){
        try{
            originalDataList.setListData(studentsManager.getStudents().toString().replaceAll("[\\,\\[\\]]","").split("\n"));
            modifiedDataList.setListData(studentsManager.getSortedStudents().toString().replaceAll("[\\,\\[\\]]","").split("\n"));
            byCourseNumberList.setListData(studentsManager.studentsByCourseNumber(Integer.parseInt(courseNumberTextField.getText())).toArray());
        } catch (NumberFormatException ex){
        }
    }

    public StudentsManager getStudentsManager() {
        return studentsManager;
    }

}
