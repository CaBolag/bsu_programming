import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.function.Predicate;

public class Course implements Iterable<Student> {

    private Set<Student> students=new HashSet<>();
    private String name=new String();


    public String getName() {
        return name;
    }

    public Set<Student> getStudents() {
        return students;
    }

    public Course(Set<Student> students, String name) {
        this.students = students;
        this.name = name;
    }

    public void addStudent(Student newStudent){
        students.add(newStudent);
    }

    @Override
    public String toString() {
        Set<String> academicsString=new HashSet<>();
        for(Student student:students){
            if(student.getClass()==Postgraduate.class){
                academicsString.add(((Postgraduate) student).getSupervisor().getName());
            }
        }

        Set<Postgraduate> postgraduates=new HashSet<>();
        for(String academic:academicsString){
            for(Postgraduate postgraduate:getPostgraduates(academic))
                postgraduates.add(postgraduate);
        }

        Set<Undergraduate> undergraduates=new HashSet<>();
        for(Student student:students){
            if(!postgraduates.contains(student)){
                undergraduates.add((Undergraduate)student);
            }
        }


        return "Course name: " +name+ "\n"+
                "Academics: " + academicsString.toString().replaceAll("[\\,\\[\\]]","") + "\n"+
                "Students:\n" + students.toString().replaceAll("[\\,\\[\\]]","")+"\n"+
                "Postgraduates:\n"+postgraduates.toString().replaceAll("[\\,\\[\\]]","")+"\n"+
                "Undergraduates:\n"+undergraduates.toString().replaceAll("[\\,\\[\\]]","")+"\n";
    }


    public Set<Postgraduate> getPostgraduates(String nameOfSupervisor){
        Set<Postgraduate> studentsBySupervisor= new HashSet<>();
        for(Student student:students){
            if (student.getClass() == Postgraduate.class && ((Postgraduate) student).getSupervisor().getName()==nameOfSupervisor) {
                studentsBySupervisor.add((Postgraduate) student);
            } else{
                continue;
            }
        }
        return studentsBySupervisor;
    }

    @Override
    public Iterator<Student> iterator() {
        return students.iterator();
    }

/*    @Override
    public Iterator<Student> iterator() {
        Iterator<Student> studentIterator=new Iterator<Student>() {
            private static int currentIndex = 0;
            @Override
            public boolean hasNext() {
                return currentIndex<students.size() && students.toArray()[currentIndex]!=null;
            }

            @Override
            public Student next() {
                Student student=(Student) students.toArray()[currentIndex];
                currentIndex++;
                return student;
            }
        };
        return studentIterator;
    }*/

    public Set<Student> studentsByCondition (Predicate<Student> condition){
        Set<Student> studentsByCondition=new HashSet<>();
        for(Student student:students){
            if(condition.test(student)){
                studentsByCondition.add(student);
            }
        }
        return studentsByCondition;
    }


}
