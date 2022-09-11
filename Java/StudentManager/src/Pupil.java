

import java.util.Objects;

public abstract class Pupil implements Comparable<Pupil> {
    private String surname;
    private String nameOfInstitution;
    private double rating;
    private double averageMark;


    public Pupil(String surname, String nameOfInstitution, double rating, double averageMark) {
        this.surname = surname;
        this.nameOfInstitution = nameOfInstitution;
        this.rating = rating;
        this.averageMark = averageMark;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getNameOfInstitution() {
        return nameOfInstitution;
    }

    public void setNameOfInstitution(String nameOfInstitution) {
        this.nameOfInstitution = nameOfInstitution;
    }

    public double getRating() {
        return rating;
    }

    public void setRating(double rating) {
        this.rating = rating;
    }

    public double getAverageMark() {
        return averageMark;
    }

    public void setAverageMark(double averageMark) {
        this.averageMark = averageMark;
    }

    @Override
    public String toString() {
        return "Pupil{" +
                "surname='" + surname + '\'' +
                ", nameOfInstitution='" + nameOfInstitution + '\'' +
                ", rating=" + rating +
                ", averageMark=" + averageMark +
                ' ';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pupil pupil = (Pupil) o;
        return Double.compare(pupil.rating, rating) == 0 && Double.compare(pupil.averageMark, averageMark) == 0 && Objects.equals(surname, pupil.surname) && Objects.equals(nameOfInstitution, pupil.nameOfInstitution);
    }

    @Override
    public int compareTo(Pupil o) {
        return Double.compare(averageMark,o.getAverageMark());
    }
}
