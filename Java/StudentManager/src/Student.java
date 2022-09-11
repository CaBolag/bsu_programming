

import java.util.Objects;

public class Student extends Pupil{
    private int course;

    public Student(String surname, String nameOfInstitution, double rating, double averageMark,int course) {
        super(surname, nameOfInstitution, rating, averageMark);
        this.course=course;
    }

    public int getCourse() {
        return course;
    }

    public void setCourse(int course) {
        this.course = course;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Student student = (Student) o;
        return course == student.course;
    }

    @Override
    public String toString() {
        return super.toString() +
                "course=" + course +
                '}';
    }
}
