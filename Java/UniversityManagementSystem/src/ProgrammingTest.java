import javax.sql.RowSet;
import javax.sql.rowset.Predicate;
import java.io.FileNotFoundException;
import java.sql.SQLException;
import java.util.*;

public class ProgrammingTest {
    public static void main(String[] args){

        Academic paulDeitel=new Academic("Paul Deitel");
        Academic cayHorstmann=new Academic("Cay Horstmann");


        Undergraduate undergraduate1=new Undergraduate("gg4","u1");
        undergraduate1.setName("u1");
        undergraduate1.setTutor(paulDeitel);

        Undergraduate undergraduate2=new Undergraduate("pr3","u2");
        undergraduate2.setName("u2");
        undergraduate2.setTutor(cayHorstmann);

        Postgraduate postgraduate1=new Postgraduate("te2","p1");
        postgraduate1.setName("p1");
        postgraduate1.setSupervisor(paulDeitel);

        Postgraduate postgraduate2=new Postgraduate("yj34","p2");
        postgraduate2.setName("p2");
        postgraduate2.setSupervisor(cayHorstmann);

        Postgraduate postgraduate3=new Postgraduate("jj8","p3");
        postgraduate3.setName("p3");
        postgraduate3.setSupervisor(cayHorstmann);

        Set<Student> allStudents =new HashSet<>(Arrays.asList(undergraduate1,undergraduate2,postgraduate1,postgraduate2,postgraduate3));
        Course programming=new Course(allStudents,"Programming");
        Set<Postgraduate> cayHorstmannStudents=programming.getPostgraduates("Cay Horstmann");

        for(Postgraduate student:cayHorstmannStudents){
            System.out.println(student.getName());
        }

        Notifier notifier=new Notifier((allStudents));
        notifier.doNotifyAll("Hello, Students!");
    /*    for(Student student:allStudents){
            System.out.println(student.getName());
        }*/

    /*    while(programming.iterator().hasNext()){
            System.out.println(programming.iterator().next());
        }*/

        Writer writer=new Writer(programming);
        try {
            writer.saveToFile("Output.txt");
        } catch (FileNotFoundException ex){
            System.out.println(ex.getMessage());
        }

        System.out.println(programming.studentsByCondition(student -> student.getName().charAt(0)=='p'));


    }
}