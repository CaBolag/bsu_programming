

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException, MyException {
	// write your code here
        /*Student st1=new Student("A","BSU",5,7.8,1);
        Student st2=new Student("B","BSUIR",4,6.7,2);
        Student st3=new Student("C","BSU",5,8.4,1);
        Student st4=new Student("D","BNTU",3,9.2,3);
        Student st5=new Student("E","BSEU",5,7.8,1);*/
        MyCollection<Pupil> collection=new MyCollection<Pupil>();
        collection.readStudents("inputStudent.txt");
        /*collection.add(st1);
        collection.add(st2);
        collection.add(st3);
        collection.add(st4);
        collection.add(st5);*/
        System.out.println(collection);
        System.out.println(collection.sort());
        System.out.println("count="+collection.count(new Student("A","BSU",5,7.8,1)));
        System.out.println(collection.findBestPupils());
        System.out.println(collection.countAverage("BSU"));
        System.out.println(collection.frequencyByAverageMark(7.8));
        System.out.println(collection.frequencyByPredicate(p->p.getAverageMark()==7.8));

        MyCollection<Pupil> collection2=new MyCollection<>();
        collection2.readSchoolPupils("inputSchoolPupil.txt");
        System.out.println(collection2);
        System.out.println(collection2.findBestStudents());
        try{
        System.out.println(collection2.countAverage("BSTU"));
        }catch (MyException ex){
            System.out.println(ex.getMessage());
        }

    }
}
