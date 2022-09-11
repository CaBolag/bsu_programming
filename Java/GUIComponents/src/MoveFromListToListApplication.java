import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

public class MoveFromListToListApplication extends JPanel{
    private JList<String> rightList;
    private JList<String> leftList;
    private JPanel centerPanel;
    private String[] data1 = { "1" ,"2"  ,"3","4"};
    private String[] data2 = { "1*","2*", "3*", "5*", "6*"};
    private DefaultListModel<String> listModel1 = new DefaultListModel<String>());
    private DefaultListModel<String> listModel2 = new DefaultListModel<String>();
    private JButton toTheRightButton;
    private JButton toTheLeftButton;


    public MoveFromListToListApplication(){
        for (String string : data1) {
            listModel1.add(0, string);
        }
        rightList=new JList(listModel1);
        rightList.setFixedCellWidth(100);


        for (String string : data2) {
            listModel2.add(0, string);
        }
        
        leftList=new JList(listModel2);
        leftList.setFixedCellWidth(100);


        setLayout(new BorderLayout());
        rightList.setVisibleRowCount(5);
        rightList.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        add(new JScrollPane(rightList));

        leftList.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        add(new JScrollPane(leftList));

        centerPanel =new JPanel();
        centerPanel.setLayout(new BorderLayout());

        toTheRightButton=new JButton(">>");
        centerPanel.add(toTheRightButton,BorderLayout.NORTH);

        toTheLeftButton=new JButton("<<");
        centerPanel.add(toTheLeftButton,BorderLayout.SOUTH);

        add(rightList,BorderLayout.EAST);
        add(leftList,BorderLayout.WEST);
        add(centerPanel,BorderLayout.CENTER);

        initListeners();

    }
    private void initListeners(){
        toTheRightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                rightList.setListData(leftList.getSelectedValuesList().toArray(new String[0]));
                for (Object selectedValue:leftList.getSelectedValuesList()){
                    listModel2.removeElement(selectedValue);
                }
            }
        });
        toTheLeftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                leftList.setListData(rightList.getSelectedValuesList().toArray(new String[0]));
                for (Object selectedValue:rightList.getSelectedValuesList()){
                    listModel1.removeElement(selectedValue);
                }
            }
        });
    }
}
