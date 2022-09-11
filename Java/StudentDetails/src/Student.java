public class Student  {
    private int recordBookNumber;
    private String surname;
    private int courseNumber;
    private int groupNumber;


    public Student(int recordBookNumber, String surname, int courseNumber, int groupNumber) {
        this.recordBookNumber = recordBookNumber;
        this.surname = surname;
        this.courseNumber = courseNumber;
        this.groupNumber = groupNumber;
    }

    public Student() {

    }


    public int getRecordBookNumber() {
        return recordBookNumber;
    }

    public void setRecordBookNumber(int recordBookNumber) {
        this.recordBookNumber = recordBookNumber;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public int getCourseNumber() {
        return courseNumber;
    }

    public void setCourseNumber(int courseNumber) {
        this.courseNumber = courseNumber;
    }

    public int getGroupNumber() {
        return groupNumber;
    }

    public void setGroupNumber(int groupNumber) {
        this.groupNumber = groupNumber;
    }

    @Override
    public String toString() {
        return  recordBookNumber + " "
                + surname + " "
                + "course: " + courseNumber +" "
                + "groupNumber: " + groupNumber+"\n";
    }
}
