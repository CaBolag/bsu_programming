import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class DataManager<T extends LightBulb> {
    private ArrayList<T> data=new ArrayList<>();


    public void add(T newElement) {
        data.add(newElement);
    }

    public ArrayList<T> findSortedDataByPrice() throws DataManagerException {
        if(data.isEmpty()){
            throw new DataManagerException("There is no elements!");
        }
  /*      ArrayList<T> sortedData=new ArrayList<>(data);
        sortedData.stream().sorted(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return Double.compare(o2.countPrice(),o2.countPrice());
            }
        }).collect(Collectors.toCollection(ArrayList::new)).sort(Collections.reverseOrder());*/
        ArrayList<T> sortedData=new ArrayList<>(data);
        sortedData.stream().sorted(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return Double.compare(o2.countPrice(),o2.countPrice());
            }
        }).collect(Collectors.toCollection(ArrayList::new));
        return sortedData;
    }

    public ArrayList<T> findSortedDataByPriceAndPower() throws DataManagerException {
        if(data.isEmpty()){
            throw new DataManagerException("There is no elements!");
        }
        ArrayList<T> sortedData=new ArrayList<>(data);
        sortedData.sort(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return Double.compare(o2.countPrice()/o2.getPower(),o1.countPrice()/o1.getPower());
            }
        });
        return sortedData;
    }

    public Set<String> findManufacturerList(){
       return data
               .stream()
               .collect(Collectors.groupingBy(lamp->lamp.getManufacturer()))
               .entrySet()
               .stream()
               .map(Map.Entry::getKey)
               .collect(Collectors.toSet());
    }

    public double countAveragePriceByManufacturer(String manufacturer) throws DataManagerException{
        if(data.isEmpty()){
            throw new DataManagerException("There is no elements!");
        }
       return data
               .stream()
               .filter(lamp->lamp.getManufacturer().equals(manufacturer))
               .mapToDouble(lamp -> lamp.countPrice())
               .average()
               .getAsDouble();

    }

    public void readLEDLamps(String filename) throws FileNotFoundException {
        File file = new File(filename);
        Scanner sc = new Scanner(file);
        while (sc.hasNextLine()) {
            try {
                String currentLine = sc.nextLine();
                Scanner scLine = new Scanner(currentLine);
                add((T) new LEDLamp(scLine.next(), scLine.nextDouble(), scLine.nextInt()));
            } catch (InputMismatchException ex) {
                continue;
            } catch (NumberFormatException ex) {
                continue;
            }
        }
    }

    public void readIncandescentLamps(String filename) throws FileNotFoundException {
        File file = new File(filename);
        Scanner sc = new Scanner(file);
        while (sc.hasNextLine()) {
            try {
                String currentLine = sc.nextLine();
                Scanner scLine = new Scanner(currentLine);
                add((T) new IncandescentLamp(scLine.next(), scLine.nextDouble(), scLine.nextDouble()));
            } catch (InputMismatchException ex) {
                continue;
            } catch (NumberFormatException ex) {
                continue;
            }
        }
    }


}