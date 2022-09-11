import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class Writer {
    private Course course;

    public Writer(Course course) {
        this.course = course;
    }

    public void saveToFile(String fileName) throws FileNotFoundException {
        File file=new File(fileName);
        try (PrintWriter writer = new PrintWriter(file)) {
            writer.println(course);
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException();
        }
    }
}
