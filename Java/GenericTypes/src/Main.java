import java.util.*;
import java.util.function.Predicate;
import java.util.stream.DoubleStream;


public class Main {
    public static void main(String[] args) {
        Collection<Integer> array = Arrays.asList(1, 2, 3, 4);
/*        int countDefaultPredicate=GenericAlgorithms.countIfDefaultPredicate(array, new Predicate<Integer>() {
            @Override
            public boolean test(Integer integer) {
                return integer% 2 != 0;
            }
        });*/

//        System.out.println("Number of odd integers = " + GenericAlgorithms.countIf(array, new OddPredicate()));
//        System.out.println("Number of odd integers = " + GenericAlgorithms.countIfDefaultPredicate(array, integer -> integer% 2 != 0));
//        Double[] emptyArray={};

        List<Integer> list1 = Arrays.asList(1, 2, 3);
        System.out.println("sum of list1 = " + GenericAlgorithms.sum(list1));
        List<Double> list2= Arrays.asList(1., 2.1, 4.3);
        System.out.println("sum of list2 = " + GenericAlgorithms.sum(list2));

        Set<Number> set=new HashSet<>(list2);
        System.out.println("sum of set = " + GenericAlgorithms.sum(List.copyOf(set)));

        System.out.println("(stream) sum = " + set.stream().mapToDouble(Number::doubleValue).sum());
        System.out.println("(stream) sum = " +list2.stream().mapToDouble(f -> f.doubleValue()).sum());

        Set<Double> treeSet=new TreeSet<>(list2);
        System.out.println("min of treeSet = " + Collections.min(treeSet));
        System.out.println("max of treeSet= " + Collections.max(treeSet));

      /*  try {
            double average=GenericAlgorithms.countAverage(emptyArray);
        } catch (GenericAlgorithmsException e) {
            e.printStackTrace();
        }*/
    }
}
