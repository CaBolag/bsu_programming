import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.function.Predicate;

public class GenericAlgorithms<T> {
    public static double sum(List<? extends Number> list) {
        double sum = 0.0;
        for (Number n : list) {
            sum += n.doubleValue();
        }
        return sum;
    }


    public static <T> int countIf(Collection<T> collection, UnaryPredicate<T> condition) {
        int count = 0;
        for (T elem : collection)
            if (condition.test(elem))
                ++count;
        return count;
    }

    public static <T> int countIfDefaultPredicate(Collection<T> collection, Predicate<T> condition) {
        int count = 0;
        for (T elem : collection)
            if (condition.test(elem))
                ++count;
        return count;
    }

    public static <T extends Number> double countAverage(T[] array) throws GenericAlgorithmsException{
        double average=0;
        int sum=sum(array);
        if(array.length==0){
            throw new GenericAlgorithmsException("Division by 0");
        }else{
            average=sum/array.length;
            return average;
        }
    }


    public static<T> boolean contains (T[] array, T value){
        for(T element:array){
            if (element==value){
                return true;
            }
        }
        return false;
        /*  if(Arrays.stream(array).anyMatch());*/

    }
    public static<T> int count (T[] array, T value){
        int count=0;
        for(T element:array){
            if (element==value){
                count++;
            }
        }
        return count;
    }

    public static<T extends Number> int sum(T[] array){
        int sum=0;

        for(T element:array){
            sum+=element.intValue();
        }
        return sum;
    }

    public static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}