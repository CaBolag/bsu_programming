import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.Collectors;

public class StudentsManager {
    private final ArrayList<Student> students;
    private ArrayList<Student> sortedStudents;

    StudentsManager() {
        students = new ArrayList<>();
        sortedStudents = new ArrayList<>();
    }


    public ArrayList<Student> getStudents() {
        return students;
    }

    public ArrayList<Student> getSortedStudents() {
        return sortedStudents;
    }

    public void setSortedStudents(ArrayList<Student> sortedStudents) {
        this.sortedStudents = sortedStudents;
    }

    public void addStudent(Student student) throws InvalidParameterException {
        if (students.stream()
                .map(Student::getRecordBookNumber)
                .toList().contains(student.getRecordBookNumber()) || !student.getSurname().matches("[A-Z,a-z]")) {
            throw new InvalidParameterException();
        } else {
            students.add(student);
            sortedStudents.add(student);
            sortByCourseGroupNumberSurname();
        }
    }

    //??????
    public void readFromFile(String filename) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(filename));
        while (sc.hasNextLine()) {
            Scanner scLine = new Scanner(sc.nextLine());
            Student newStudent = new Student(sc.nextInt(), sc.next(), sc.nextInt(), sc.nextInt());
            students.add(newStudent);
            sortedStudents.add(newStudent);
        }
    }

    public void saveToFile(File file) throws FileNotFoundException {
        PrintWriter writer = new PrintWriter(file);
        writer.println(this.toString());
    }

    public void sortByCourseGroupNumberSurname() {
        sortedStudents.sort(Comparator.comparing(Student::getCourseNumber)
                .thenComparing(Student::getGroupNumber)
                .thenComparing(Student::getSurname));
    }

    public ArrayList<Student> studentsByCourseNumber(int courseNumber) {
        return sortedStudents.stream().filter(student -> student.getCourseNumber() == courseNumber).collect(Collectors.toCollection(ArrayList::new));

    }



}
