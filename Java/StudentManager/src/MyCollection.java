
import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.function.Predicate;

public class MyCollection<T extends Pupil> {
    private ArrayList<T> collection = new ArrayList<>();

    public void add(T elem) {
        collection.add(elem);
    }

    public TreeSet<T> sort() {
        TreeSet<T> sortingCollection = new TreeSet<T>(collection);
        return sortingCollection;
    }

    public int count(Pupil p) throws MyException {
        if (collection.isEmpty()) {
            throw new MyException("Empty collection");
        }
        return Collections.frequency(collection, p);
    }


    public ArrayList<T> findBestPupils() {
        TreeSet<T> pupils = new TreeSet<>(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                int comparisonIndex;
                //Comparator.comparing()
                if (Double.compare(o1.getAverageMark() * o1.getRating(), o2.getAverageMark() * o2.getRating()) == 0) {
                    comparisonIndex = o1.getSurname().compareTo(o2.getSurname());
                } else {
                    comparisonIndex = Double.compare(o2.getAverageMark() * o2.getRating(), o1.getAverageMark() * o1.getRating());
                }
                return comparisonIndex;
            }
        });
        //TreeSet<T> pupils=new TreeSet<>((p1,p2)->Double.compare
        //        (p2.getAverageMark()* p2.getRating(),p1.getAverageMark()* p1.getRating()));
        pupils.addAll(collection);
        ArrayList<T> result = new ArrayList<>();
        int count = 0;
        for (Iterator<T> it = pupils.iterator(); count < 2; count++) {
            result.add(it.next());
        }
        return result;
    }

    //два лучших ученика по среднему баллу
    public ArrayList<T> findBestStudents() {
        ArrayList<T> copy_collection = new ArrayList<>(collection);
        ArrayList<T> result = new ArrayList<>();
        copy_collection.sort(Comparator.comparing(Pupil::getAverageMark));
        Collections.reverse(copy_collection);
        result.add(copy_collection.get(0));
        result.add(copy_collection.get(1));
        return result;
    }

    public int frequencyByAverageMark(double average) {
        int count = (int) collection.stream().filter(p -> p.getAverageMark() == average).count();
        return count;
    }

    public int frequencyByPredicate(Predicate<T> predicate) {
        int count = (int) collection.stream().filter(predicate).count();
        return count;
    }

    public T binarySearch(T student) {
        return collection.get(Collections.binarySearch(collection, student));
    }

    public double countAverage(String name) throws MyException {
        if (collection.isEmpty()) {
            throw new MyException("Empty collection");
        }
        var average = collection.stream().filter(p -> p.getNameOfInstitution().equals(name)).mapToDouble(p -> p.getAverageMark()).average();
        if (!average.isEmpty()) {
            return average.getAsDouble();
        } else throw new MyException("Nothing find");
    }

    public void readStudents(String filename) throws IOException {
        File file = new File(filename);
        try (Scanner sc = new Scanner(file)) {
            while (sc.hasNextLine()) {
                try {
                    String lines = sc.nextLine();
                    Scanner scLine = new Scanner(lines);
                    add((T) new Student(scLine.next(), scLine.next(), scLine.nextDouble(), scLine.nextDouble(), scLine.nextInt()));
                } catch (InputMismatchException ex) {
                    //throw new InputMismatchException(ex.getMessage());
                    continue;
                }
            }
        }
    }

    public void readSchoolPupils(String filename) throws IOException {
        File file = new File(filename);
        try (Scanner sc = new Scanner(file)) {
            while (sc.hasNextLine()) {
                try {
                    String lines = sc.nextLine();
                    Scanner scLine = new Scanner(lines);
                    SchoolPupil pupil = new SchoolPupil(scLine.next(), scLine.next(), scLine.nextDouble(), scLine.nextDouble(), scLine.nextInt(), SchoolPupil.Behavior.valueOf(scLine.next()));
                    add((T) pupil);
                } catch (InputMismatchException ex) {
                    //throw new InputMismatchException(ex.getMessage());
                    continue;
                }
            }
        }
    }

    @Override
    public String toString() {
        return "MyCollection{" +
                "collection=" + collection +
                '}';
    }
}
