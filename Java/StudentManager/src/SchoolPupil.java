

import java.util.Objects;

public class SchoolPupil extends Pupil{
    private int form;
    private Behavior behavior;

    public int getForm() {
        return form;
    }

    public void setForm(int form) {
        this.form = form;
    }

    public Behavior getBehavior() {
        return behavior;
    }

    public void setBehavior(Behavior behavior) {
        this.behavior = behavior;
    }

    @Override
    public String toString() {
        return super.toString() +
                "form=" + form +
                ", behavior=" + behavior +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        SchoolPupil that = (SchoolPupil) o;
        return form == that.form && behavior == that.behavior;
    }


    public enum Behavior{
        GOOD, NORM, BAD
    }

    public SchoolPupil(String surname, String nameOfInstitution, double rating, double averageMark,int form,Behavior behavior) {
        super(surname, nameOfInstitution, rating, averageMark);
        this.form=form;
        this.behavior=behavior;
    }



}
