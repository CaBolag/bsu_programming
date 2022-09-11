import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        DataManager<LightBulb> dataManagerIncandescentLamps=new DataManager<>();
        try {
            dataManagerIncandescentLamps.readIncandescentLamps("input1.txt");
            System.out.println(dataManagerIncandescentLamps.findSortedDataByPrice());
            System.out.println(dataManagerIncandescentLamps.findSortedDataByPriceAndPower());
            System.out.println(dataManagerIncandescentLamps.findManufacturerList());
            System.out.println(dataManagerIncandescentLamps.countAveragePriceByManufacturer("ILA"));

        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());;
        } catch (DataManagerException e){
            System.out.println(e.getMessage());
        }

        DataManager<LightBulb> dataManagerLEDLamps=new DataManager<>();
        try {
            dataManagerLEDLamps.readLEDLamps("input2.txt");
            System.out.println(dataManagerLEDLamps.findSortedDataByPrice());
            System.out.println(dataManagerLEDLamps.findSortedDataByPriceAndPower());
            System.out.println(dataManagerLEDLamps.findManufacturerList());
            System.out.println(dataManagerLEDLamps.countAveragePriceByManufacturer("LEDLA"));
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());;
        } catch (DataManagerException e) {
            System.out.println(e.getMessage());
        }
    }
}
