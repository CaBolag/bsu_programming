import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.event.*;
import java.security.InvalidParameterException;
import java.util.TreeSet;

public class NewStudentDialog extends JDialog {
    private JPanel contentPane;
    private JButton buttonOK;
    private JButton buttonCancel;
    private JTextField recordBookNumberTextField;
    private JTextField surnameTextField;
    private JLabel surnameLabel;
    private JLabel recordBookNumberLabel;
    private JTextField courseNumberTextField;
    private JTextField groupNumberTextField;
    private JLabel courseNumberLabel;
    private JLabel groupNumberLabel;

    private Student newStudent;
    private StudentsManagerFrame studentsManagerFrameParent;

    public NewStudentDialog(StudentsManagerFrame studentsManagerFrameParent){
        //super(studentsManagerFrameParent);
        if(studentsManagerFrameParent.getStudentsManager()==null){
            studentsManagerFrameParent.setStudentsManager(new StudentsManager());
        }
        newStudent=new Student();

        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setContentPane(contentPane);
        setModal(true);
        getRootPane().setDefaultButton(buttonOK);
        this.studentsManagerFrameParent=studentsManagerFrameParent;
        initListeners();
        pack();
        setVisible(true);

    }

    private void initListeners() {
        NewStudentDialog thisDialog=this;
        buttonOK.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                create();
                clearFields();
            }
        });

        buttonCancel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

    }
    private void create() {
            try {
                String surname = surnameTextField.getText();
                int recordBookNumber = Integer.parseInt(recordBookNumberTextField.getText());
                int courseNumber = Integer.parseInt(courseNumberTextField.getText());
                int groupNumber = Integer.parseInt(groupNumberTextField.getText());
                newStudent = new Student(recordBookNumber, surname, courseNumber, groupNumber);
                studentsManagerFrameParent.getStudentsManager().addStudent(newStudent);
                studentsManagerFrameParent.updateFields();
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(this,
                        "Сheck if the entered values are correct and all fields are filled",
                        "ERROR", JOptionPane.ERROR_MESSAGE);


            } catch (InvalidParameterException ex){
                JOptionPane.showMessageDialog(this,
                        "Invalid entered values",
                        "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        }


    private void clearFields(){
        recordBookNumberTextField.setText(null);
        surnameTextField.setText(null);
        courseNumberTextField.setText(null);
        groupNumberTextField.setText(null);

    }
}
