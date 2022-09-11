package com.company;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.event.*;
import java.io.File;
import java.io.FileNotFoundException;

public class GUI extends JFrame {
    private JPanel contentPane;
    private JButton buttonOK;
    private JButton buttonCancel;
    private JComboBox comboBoxChooseTypeOfProgression;
    private JTextField inputFirstElement;
    private JTextField inputStep;
    private JTextField inputSize;
    private JButton buttonGenerate;
    private JLabel labelTypeOfProgression;
    private JLabel labelFistElement;
    private JLabel labelStep;
    private JLabel labelSize;
    private JTextField inputOutputSize;
    private JButton buttonShow;
    private JLabel labelOutputSize;
    private JLabel labelNumberOfElement;
    private JTextField inputNumberOfElement;
    private JTextField inputElementByNumber;
    private JLabel labelElementByNumber;

    private Series progression;
    private int progressionValue;
    private File file;
    private boolean filled;

    public GUI() {
        filled=false;
        setContentPane(contentPane);
        setTitle("Series");
        setSize(700, 500);
        getRootPane().setDefaultButton(buttonOK);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        initListeners();
    }

    private void initListeners() {
        buttonOK.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                onOK();
            }
        });

        buttonCancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        });


        buttonGenerate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (filled == true) {
                    generate();
                }
            }
        });

        buttonShow.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    if (progression == null) {
                        JOptionPane.showMessageDialog(null, "Generate progression!", "ERROR", JOptionPane.ERROR_MESSAGE);
                        inputOutputSize.setText("");
                    } else {
                        if (filled == true) {
                            showRangeOfElements();
                        } else {
                            JOptionPane.showMessageDialog(null, "Fill in all fields!", "ERROR", JOptionPane.ERROR_MESSAGE);
                            inputOutputSize.setText("");
                        }
                    }
            }
        });

        comboBoxChooseTypeOfProgression.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (progressionValue != comboBoxChooseTypeOfProgression.getSelectedIndex()) {
                        updateTypeOfProgression();
                    }
                } catch (NullPointerException ex) {}
            }
        });


        inputFirstElement.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                update();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                remove();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {}
        });

        inputStep.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                update();
            }
            @Override

            public void removeUpdate(DocumentEvent e) {
                remove();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
            }
        });

        inputSize.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                update();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                remove();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {}
        });

        inputNumberOfElement.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                if(progression==null){
                    JOptionPane.showMessageDialog(null, "Generate progression!", "ERROR", JOptionPane.ERROR_MESSAGE);
                    inputNumberOfElement.setText("");
                }else {
                    if (filled == true) {
                        showElementByNumber();
                    } else {
                        JOptionPane.showMessageDialog(null, "Fill in all fields!", "ERROR", JOptionPane.ERROR_MESSAGE);
                        inputNumberOfElement.setText("");
                    }
                }
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                inputElementByNumber.setText("");
            }

            @Override
            public void changedUpdate(DocumentEvent e) {}
        });

    }


    private void updateTypeOfProgression() {
        generate();
        showElementByNumber();
    }

    private void onOK() {
        dispose();
    }

    private void onCancel() {
        dispose();
    }

    private void generate() {
        if(filled==true) {
            try {
                double firstElement = Double.parseDouble(inputFirstElement.getText());
                double step = Double.parseDouble(inputStep.getText());
                int size = Integer.parseInt(inputSize.getText());
                int typeOfProgression = comboBoxChooseTypeOfProgression.getSelectedIndex();
                if (typeOfProgression == 1) {
                    progression = new Exponential(firstElement, size, step);
                } else {
                    progression = new Linear(firstElement, size, step);
                }
                progressionValue = typeOfProgression;
                saveFile();
                filled = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null,
                        "Сheck if the entered values are correct and all fields are filled",
                        "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        }

    }

    private void saveFile() {
        JFileChooser fileChooser = new JFileChooser();
        if (file == null) {
            int returnVal = fileChooser.showOpenDialog(buttonGenerate);
            FileNameExtensionFilter filter = new FileNameExtensionFilter(
                    "Text file", "txt");
            fileChooser.setFileFilter(filter);
            file = fileChooser.getSelectedFile();
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    progression.saveToFile(file);
                } catch (FileNotFoundException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                }
            }
        } else {
            try {
                progression.saveToFile(file);
            } catch (FileNotFoundException ex) {
                JOptionPane.showMessageDialog(null, "File error!", "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void showRangeOfElements() {
        {
            try {
                int countOfElements = Integer.parseInt(inputOutputSize.getText());
                String elements = progression.toStringRange(countOfElements);
                JOptionPane.showMessageDialog(null, elements, "Elements of progression", JOptionPane.PLAIN_MESSAGE);
            } catch (IndexOutOfBoundsException e) {
                JOptionPane.showMessageDialog(null, "Size is too big!", "ERROR", JOptionPane.ERROR_MESSAGE);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Сheck if the entered values are correct",
                        "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        }

    }

    private void showElementByNumber() {
        if (filled) {
            try {
                int numberOfElement = Integer.parseInt(inputNumberOfElement.getText());
                inputElementByNumber.setText(Double.toString(progression.getElementByNumber(numberOfElement)));
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Сheck if the entered values are correct!",
                        "ERROR", JOptionPane.ERROR_MESSAGE);
            }
        } else {
            inputElementByNumber.setText("");
            inputNumberOfElement.setText("");
        }
    }

    private void update() {
        try {
            filled = true;
            if (progression.getData().get(0) != Double.parseDouble(inputFirstElement.getText())
                    || Double.parseDouble(inputStep.getText()) != progression.getStep()
                    || Integer.parseInt(inputSize.getText()) != progression.getSize()) {
                generate();
            }
            if (!inputNumberOfElement.getText().isEmpty()) {
                showElementByNumber();
            }
        } catch (NullPointerException ex) {
        }
    }

    private void remove(){
        try {
            if (inputFirstElement.getText().isEmpty() || inputSize.getText().isEmpty() || inputStep.getText().isEmpty()) {
                filled = false;
            } else {
                generate();
            }
            showElementByNumber();
        } catch (NullPointerException ex) {
        }
    }


/*    private boolean checkfilled() {
        double firstElement = Double.parseDouble(inputFirstElement.getText());
        double step = Double.parseDouble(inputStep.getText());
        int size = Integer.parseInt(inputSize.getText());
        int comboBoxValue = comboBoxChooseTypeOfProgression.getSelectedIndex();
        Series comparableProgression;
        if (comboBoxValue == 1) {
            comparableProgression = new Exponential(firstElement, size, step);
        } else {
            comparableProgression = new Linear(firstElement, size, step);
        }

        if (comparableProgression.compareTo(progression) == 0 || comboBoxValue != progressionValue) {
            return false;
        }
        return true;
    }*/

}


